/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "base/l_socket/x_socket.h"


   /* ... Funciones ................................................... */

      /*  Address management *
       * ------------------- */
      T_BOOL   X_SOCKET_getSockAddr      
      ( 
        IN    T_SOCKADDR_IN       *sa,
        OUT   T_SOCKET            *sd 
      )
      {
        #define MACHINE_NAME_SIZE 1024

        char          machineName[MACHINE_NAME_SIZE] ;
        int           resultado ;
        size_t        salen ;

        /*
         *  get names
         */
        salen = c_SOCKADDR_IN ;
        resultado = getsockname((*sd),(struct sockaddr *)(sa),&salen) ;
        if (resultado < 0)
           {
             close((*sd)) ;
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At getsockname...") ;
             return FALSE ;
           }
        resultado = gethostname(machineName,MACHINE_NAME_SIZE) ;
        if (resultado < 0)
           {
             close((*sd)) ;
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At gethostname...") ;
             return FALSE ;
           }

#if ( defined(__SP2__) && defined(__SWITCH__) )

        /*
         *  force to use IBM's switch at CESCA:
         *
         *    inxx.sp.cesca.es  -> TCP/IP over ethernet
         *    cssxx.sp.cesca.es -> TCP/IP over switch
         *
         */
        if (X_STRING_Match(machineName,"css*.sp.cesca.es",FALSE) == TRUE)
           {
             L_VERBOSE_MSG_PrintF("\n") ;
             L_VERBOSE_MSG_PrintF("\tusing switch (%s)",machineName) ;
             L_VERBOSE_MSG_PrintF("\n") ;
           }
        if (X_STRING_Match(machineName,"in*.sp.cesca.es",FALSE) == TRUE)
           {
             L_VERBOSE_MSG_PrintF("\n") ;
             L_VERBOSE_MSG_PrintF("\t eth. to switch... (%s) -> ",machineName) ;
	     X_ALLOC_MemMove(machineName+3,
                             machineName+2,
                             X_STRING_StrLen(machineName)) ;
             X_ALLOC_MemMove(machineName,
                             "css",
                             X_STRING_StrLen("css")) ;
             L_VERBOSE_MSG_PrintF(" (%s)",machineName) ;
             L_VERBOSE_MSG_PrintF("\n") ;
           }
#endif

        /*
         *  set 'sa' values
         */
        X_SOCKET_ln2address(sa,
                            machineName,
                            sa->sin_port) ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   X_SOCKET_local2address    
      ( 
        IN    T_SOCKADDR_IN       *sa,
        IN    T_INT                port 
      )
      {
        NULL__SET_ERROR__RET_FALSE(sa) ;
        sa->sin_family      = AF_INET ;
        sa->sin_port        = port ;
        sa->sin_addr.s_addr = INADDR_ANY ;
        return TRUE ;
      }

      T_BOOL   X_SOCKET_ln2address       
      ( 
        IN    T_SOCKADDR_IN       *sa,
        IN    T_CHAR              *hostName,
        IN    T_INT                port 
      )
      {
        struct hostent     *hostInfo ;

        /* ... check params ... */
        NULL__SET_ERROR__RET_FALSE(sa) ;
        NULL__SET_ERROR__RET_FALSE(hostName) ;

        hostInfo = gethostbyname(hostName);
        if (hostInfo == NULL)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At gethostbyname...") ;
             return FALSE ;
           }
        sa->sin_family  = AF_INET ;
        sa->sin_port    = port ;
        memcpy(&(sa->sin_addr), 
               (hostInfo->h_addr_list[0]), 
                hostInfo->h_length) ;
        return TRUE ;
      }

      T_BOOL   X_SOCKET_env2address      
      ( 
        IN    T_SOCKADDR_IN       *sa,
        IN    T_CHAR              *hostName,
        IN    T_CHAR              *port 
      )
      {
        T_INT   aux_port ;
        T_CHAR *aux_host ;

        /* ... check params ... */
        NULL__SET_ERROR__RET_FALSE(hostName) ;
        NULL__SET_ERROR__RET_FALSE(port) ;

        if (getenv(hostName) == NULL)
           {
             L_DEBUG_MSG_PrintF(DBG_ERROR,TRUE,
                                "%s must be in enviroment\n",
                                hostName) ;
             return FALSE ;
           }
        if (getenv(port) == NULL)
           {
             L_DEBUG_MSG_PrintF(DBG_ERROR,TRUE,
                                "%s must be in enviroment\n",
                                port) ;
             return FALSE ;
           }
        aux_port = atoi(getenv(port)) ;
        aux_host = getenv(hostName) ;
        return X_SOCKET_ln2address(sa,aux_host,aux_port) ;
      }


      /*  Live Cycle Connection Oriented Socket  *
       * --------------------------------------- */
      T_BOOL   X_SOCKET_setDefaultOptForStream  
      ( 
        INOUT    T_SOCKET   socket 
      )
      {
        int  val ;
        int  ret ;
        int  int_size ;

        val      = 1 ;
        int_size = c_INT ;
        /* ... IPPROTO_TCP/TCP_NODELAY ... */
        ret = setsockopt(socket,
                         IPPROTO_TCP,
                         TCP_NODELAY,
                         (char *)&val,
                         c_INT) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At setsockopt...") ;
             return FALSE ;
           }

        /* ... SOL_SOCKET/SO_REUSEADDR ... */
        ret = setsockopt(socket,
                         SOL_SOCKET,
                         SO_REUSEADDR,
                         (char *)&val,
                         c_INT) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At setsockopt...") ;
             return FALSE ;
           }

#if (0)
        /* ... IPPROTO_TCP/TCP_MAXSEG ... */
        ret = getsockopt(socket,
                         IPPROTO_TCP,
                         TCP_MAXSEG,
                         (char *)&val, 
                         &int_size);
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At getsockopt...") ;
             return FALSE ;
           }
        /* ... SOL_SOCKET/SO_RCVBUF ... */
        val = (32 * 1024);
        ret =  setsockopt(socket, 
                          SOL_SOCKET, 
                          SO_RCVBUF,
                          (char *)&val,
                          c_INT ) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At setsockopt...") ;
             return FALSE ;
           }

        /* ... SOL_SOCKET/SO_SNDBUF ... */
        val = (32* 1024) ;
        ret =  setsockopt(socket, 
                          SOL_SOCKET, 
                          SO_SNDBUF, 
                          (char *)&val,
                          c_INT) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At setsockopt...") ;
             return FALSE ;
           }

        L_DEBUG_MSG_PrintF(DBG_DBG_INFO,TRUE,
                           "MAX_SEG FOR %d = %d\n", 
                           socket, (32* 1024)) ;
#endif

        return TRUE ;
      }

        
      T_BOOL   X_SOCKET_socketBindTo     
      ( 
        OUT   T_SOCKET            *sd,
        IN    T_SOCKADDR_IN       *sa 
      )
      {
        int resultado ;

        (*sd) =  socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) ;
        if ((*sd) < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At socket...") ;
             return FALSE ;
           }
        X_SOCKET_setDefaultOptForStream((*sd)) ;
        resultado = bind( (*sd),
                          (struct sockaddr *)(sa),
                          c_SOCKADDR_IN ) ;
        if (resultado < 0)
           {
             close((*sd)) ;
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At bind...") ;
             return FALSE ;
           }
        return TRUE ;
      }

      T_BOOL   X_SOCKET_beeper           
      ( 
        OUT   T_SOCKET            *sd,
        IN    T_SOCKADDR_IN       *sa 
      )
      {
        int    resultado ;
        T_BOOL ok ;

        /* ... check params ... */
        NULL__SET_ERROR__RET_FALSE(sd) ;
        NULL__SET_ERROR__RET_FALSE(sa) ;

        ok = X_SOCKET_socketBindTo(sd,sa) ;
        FALSE_RET_FALSE(ok) ;
        ok = X_SOCKET_getSockAddr(sa,sd) ;
        FALSE_RET_FALSE(ok) ;
        resultado = listen((*sd),SOMAXCONN) ;
        if (resultado < 0)
           {
             close((*sd));
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At listen...") ;
             return FALSE ;
           }
        return TRUE ;
      }

      T_BOOL   X_SOCKET_connect          
      ( 
        OUT   T_SOCKET            *sd,
        IN    T_SOCKADDR_IN       *sa 
      )
      {
        int ret ;

        /* ... check params ... */
        NULL__SET_ERROR__RET_FALSE(sd) ;
        NULL__SET_ERROR__RET_FALSE(sa) ;

        (*sd) = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) ;
        if ((*sd) < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At socket...") ;
             return FALSE ;
           }
        ret = connect((*sd),(struct sockaddr *)sa,c_SOCKADDR_IN) ;
        if (ret < 0)
           {
             close((*sd));
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At connect...") ;
             return FALSE ;
           }
        return X_SOCKET_setDefaultOptForStream((*sd)) ;
      }

      T_BOOL   X_SOCKET_accept           
      ( 
        OUT    T_SOCKET            *sd,
        OUT    T_SOCKADDR_IN       *sa,
        IN     T_SOCKET             beeper 
      )
      {
        size_t   size ;

        /* ... check params ... */
        NULL__SET_ERROR__RET_FALSE(sd) ;
        NULL__SET_ERROR__RET_FALSE(sa) ;

        size  = c_SOCKADDR_IN ;
        (*sd) = accept(beeper,
                       (struct sockaddr *)(sa),
                       &size ) ;
        if ((*sd) < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At accept...") ;
             return FALSE ;
           }
        return X_SOCKET_setDefaultOptForStream((*sd)) ;
      }

      T_BOOL   X_SOCKET_unplug           
      ( 
        INOUT    T_SOCKET  socket 
      )
      {
        shutdown(socket,2) ;
        close(socket) ;
        return TRUE ;
      }


      /*  Connection Oriented Socket Data Movement  *
       * ------------------------------------------ */
      T_INT    X_SOCKET_fullRead         
      ( 
        INOUT    T_SOCKET   socket,
        INOUT    T_CHAR    *buffer,
        INOUT    T_INT      size 
      )
      {
        int  ret ;
        int  size_aux ;

        ret = X_SOCKET_readAvailable(socket,buffer,size) ;
        size_aux = size - ret ;
        while (size_aux > 0)
        {
          if (ret < 0)
             {
               L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At read...") ;
               return ret ;
             }
          if (ret == 0)
              return ret ;
          buffer   += ret ;
          ret = X_SOCKET_readAvailable(socket,buffer,size_aux) ;
          size_aux -= ret ;
        }
        return size ;
      }

      T_INT    X_SOCKET_write            
      ( 
        INOUT    T_SOCKET   socket,
        INOUT    T_CHAR    *buffer,
        INOUT    T_INT      size 
      )
      {
        int ret ;
        int size_aux ;

        ret = X_SOCKET_writeAvailable(socket,buffer,size) ;
        size_aux = size - ret ;
        while (size_aux > 0)
        {
          if (ret < 0)
             {
               L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At write...") ;
               return FALSE ;
             }
          buffer   += ret ;
          ret = X_SOCKET_writeAvailable(socket,buffer,size_aux) ;
          size_aux -= ret ;
        }
        return size ;
      }

      T_INT    X_SOCKET_read             
      ( 
        INOUT    T_SOCKET   socket,
        INOUT    T_CHAR    *buffer,
        INOUT    T_INT      size 
      )
      {
        int ret, size2, i ;
        int chunk, chunkMod ;

        chunk    = size / SSIZE_MAX ;
        chunkMod = size % SSIZE_MAX ;
        if (chunkMod != 0)
           {
             ret = X_SOCKET_fullRead(socket,buffer,chunkMod) ;
             if (ret < 0)
                {
                  L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At read...") ;
                  return ret ;
                }
             if (ret == 0)
                {
                  return ret ;
                }
           }
        else  
           { 
             /* ret means allready readed, and is (0,chunkMod) */
             ret = 0 ; 
           }

        size2 = ret ;
        for (i=0; i<chunk; i++)
           {
             ret = X_SOCKET_fullRead(socket,buffer,SSIZE_MAX) ;
             if (ret < 0)
                {
                  L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At read...") ;
                  return ret ;
                }
             if (ret == 0)
                {
                  return ret ;
                }
             size2 = size2 + ret ;
           }

        return size2 ;
      }

      T_INT    X_SOCKET_writeRead        
      ( 
        INOUT    T_SOCKET   socket,
        INOUT    T_CHAR    *buffer,
        INOUT    T_INT      size 
      )
      {
        T_INT  ret ;

        /* ... check params ... */
        NULL__SET_ERROR__RET_FALSE(buffer) ;
        ret = X_SOCKET_write(socket,buffer,size) ;
        if (ret < 0)
            return FALSE ;
        ret = X_SOCKET_read(socket,buffer,size) ;
        return ret ;
      }


      /*  Live Cycle NOT Connection Oriented Socket  *
       * ------------------------------------------- */
      T_BOOL   X_SOCKET_setDefaultOptForDgram   
      ( 
        INOUT    T_SOCKET  socket 
      )
      {
        int val ;
        int ret ;
        int int_size ;

        int_size = c_INT ;
        /* ... SOL_SOCKET/SO_RCVBUF ... */
        val = (32 * 1024);
        ret =  setsockopt(socket, 
                          SOL_SOCKET, 
                          SO_RCVBUF,
                          (char *)&val,
                          c_INT ) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At setsockopt...") ;
             return FALSE ;
           }

        /* ... SOL_SOCKET/SO_SNDBUF ... */
        val = (32* 1024) ;
        ret =  setsockopt(socket, 
                          SOL_SOCKET, 
                          SO_SNDBUF, 
                          (char *)&val,
                          c_INT) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At setsockopt...") ;
             return FALSE ;
           }
        return TRUE ;
      }

      T_BOOL   X_SOCKET_creatSocket      
      ( 
        INOUT  T_SOCKET   *sockout 
      )
      {
        (*sockout) = socket( PF_INET,
                             SOCK_DGRAM,
                             0 ) ;
        if ((*sockout) < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At socket...") ;
             return FALSE ;
           }
        return X_SOCKET_setDefaultOptForDgram((*sockout)) ;
      }

      T_BOOL   X_SOCKET_close            
      ( 
        INOUT    int  socket 
      )
      {
        close(socket) ;
        return TRUE ;
      }


      /*  NOT Connection Oriented Socket Data Movement  *
       * ---------------------------------------------- */
      T_BOOL  X_SOCKET_sendMsg        
      ( 
        INOUT T_SOCKET             sockdest,
        IN    void                *msg,
        IN    T_INT                msgLen,
        IN    T_SOCKADDR_IN       *raddr 
      )
      {
        T_INT resultado ;
   
        resultado = sendto ( sockdest,
                             msg, 
  			     msgLen,
                             0,
                             (struct sockaddr *)(raddr),
                             sizeof(T_SOCKADDR_IN     ) ) ;
        if (resultado < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At sendto...") ;
             return FALSE ;
           }
        return TRUE ;
      }
  
      T_BOOL  X_SOCKET_recvMsg        
      ( 
        INOUT T_SOCKET             sockorig,
        IN    void                *msg,
        IN    T_INT                msgLen,
        IN    T_SOCKADDR_IN       *raddr 
      )
      {
        int      resultado ;
        size_t   size ;
   
        size      = sizeof(T_SOCKADDR_IN     ) ;
        resultado = recvfrom ( sockorig,
                               msg, 
  			       msgLen, 
  			       0,
                               (struct sockaddr *)(raddr),
                               &(size) ) ;
        if (resultado < 0)
           {
             L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At receive...") ;
             return FALSE ;
           }
        return TRUE ;
      }


  /* .................................................................... */

