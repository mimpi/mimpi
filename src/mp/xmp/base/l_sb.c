/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/base/l_sb/l_sb_alives.c"
      #include "mp/xmp/base/l_sb/l_sb_broadcast.c"
      #include "mp/xmp/base/l_sb/l_sb_select.c"


   /* ... Funtions / Funciones ........................................ */

      /*          
       *   auxiliar functions
       *  --------------------  
       */

      int     L_SB_setSbs     
      ( 
        INOUT  t_sb                *sb,
        IN     t_sb_sock           *sbs 
      )
      {
        /*
         *  check params  
         */
        if (sb == NULL)
           {
             L_DEBUG_MSG_Write(DBG_ERROR,FALSE,"(sb==NULL)") ;
             return -1 ;
           }
        if (sbs == NULL)
           {
             L_DEBUG_MSG_Write(DBG_ERROR,FALSE,"(sbs==NULL)") ;
             return -1 ;
           }
        if (L_SB_SOCK_getFd(sbs) == NULL_SOCKET) 
           {
             L_DEBUG_MSG_Write(DBG_ERROR,FALSE,"(sbs->fd==NULL)") ;
             return -1 ;
           }

        /*
         *  check last value 
         */
        if ( 
             (sb->last < 0) 
                   || 
             (sb->last >= MAX_SOCKS) 
           )
           {
             L_DEBUG_MSG_Write(DBG_ERROR,FALSE,"invalid sb->last") ;
             return -1 ;
           }

        /*
         *  store fd<->sbs  
         */
        (sb->sock_set)[(sb->last)] = sbs ;
		(sb->last) ++ ;

        /*
         *  return ok  
         */
        return ((sb->last) - 1) ;
      }


      /*          
       *   setup   
       *  -------   
       */

      T_BOOL  L_SB_init      
      ( 
        INOUT  t_sb    *sb 
      )
      {
        int i ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;

        /*
         *  setup values
         */
        sb->my   = -1 ;
        sb->ns   = -1 ;
        sb->last = 0 ;
        for (i = 0; i < MAX_SOCKS; i++)
            {
              (sb->sock_set)[i] = NULL ;
            }

        /*
         *  init socket library
         */
        X_SOCKET_init() ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL  L_SB_finalize  
      ( 
        INOUT  t_sb    *sb 
      )
      {
        int i ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;

        /*
         *  finalize components
         */
        for (i = 0; i < sb->last; i++)
            {
              L_SB_SOCK_Destroy( &((sb->sock_set)[i]) ) ;
            }
        sb->my   = -1 ;
        sb->ns   = -1 ;
        sb->last = 0 ;

        /*
         *  end socket library
         */
        X_SOCKET_finalize() ;

        /*
         *  return ok  
         */
        return TRUE ;
      }


      /*          
       *   my/ns 
       *  -------   
       */

      T_BOOL  L_SB_creatMy   
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *my 
      )
      {
        T_BOOL          ok ;
        T_SOCKADDR_IN   myaddr ;
        t_sb_sock      *sbs ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(my) ;

        /*
         *  bind locally  
         */
        ok = X_SOCKET_local2address(&(myaddr),0) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_SB_SOCK_beeper(&(myaddr),&sbs) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  set new sock  
         */
        (sb->my) = L_SB_setSbs(sb,sbs) ;

        /*	
         *  ret values  
         */
        (*my) = (sb->my) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL  L_SB_creatMy_2 
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *ns,
        INOUT  T_CHAR  *ns_host,
        INOUT  int      ns_port 
      )
      {
        T_BOOL          ok ;
        T_SOCKADDR_IN   ns_addr ;
        t_sb_sock      *sbs ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(ns) ;

        /*
         *  link to ns  
         */
        ok = X_SOCKET_local2address(&(ns_addr),ns_port) ;
        FALSE_RET_TRUE(ok) ;
        ok = L_SB_SOCK_beeper(&(ns_addr),&sbs) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  set new sock  
         */
        (sb->my) = L_SB_setSbs(sb,sbs) ;

        /*	
         *  ret values  
         */
        (*ns) = (sb->my) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL  L_SB_connectToNs   
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *ns,
        INOUT  T_CHAR  *ns_host,
        INOUT  int      ns_port 
      )
      {
        T_BOOL         ok ;
        T_SOCKADDR_IN  ns_addr ;
        t_sb_sock     *sbs ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(ns) ;
        NULL__SET_ERROR__RET_FALSE(ns_host) ;

        /*
         *  connect ns  
         */
        ok = X_SOCKET_ln2address(&ns_addr,ns_host,ns_port) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_SB_SOCK_connect(&(ns_addr),&(sbs)) ;
        if (ok == TRUE)
           {
             (sb->ns) = L_SB_setSbs(sb,sbs) ;
             (*ns) = (sb->ns) ;
             return TRUE ;
           }

        /*
         *  return error  
         */
        (sb->ns) = -1 ;
        (*ns) = -1 ;
        return FALSE ;
      }


      /*          
       *   nodes
       *  -------   
       */

      T_BOOL  L_SB_connectTo 
      ( 
        INOUT  t_sb            *sb,
        INOUT  int             *fd,
        INOUT  T_SOCKADDR_IN   *fdaddr 
      )
      {
        T_BOOL       ok ;
        t_sb_sock   *sbs ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(fd) ;
        NULL__SET_ERROR__RET_FALSE(fdaddr) ;

        /*
         *  connect  
         */
        ok = L_SB_SOCK_connect(fdaddr,&sbs) ;
        if (ok == TRUE)
           {
             (*fd) = L_SB_setSbs(sb,sbs) ;
             return TRUE ;
           }

        /*
         *  return error  
         */
        (*fd) = -1 ;
        return FALSE ;
      }

      T_BOOL  L_SB_accept      
      ( 
        INOUT  t_sb         *sb,
        OUT    int          *fd 
      )
      {
        T_BOOL ok ;
        t_sb_sock  *sbs ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(fd) ;

        /*
         *  accept  
         */
        ok = L_SB_SOCK_accept(sb->sock_set[sb->my],&(sbs)) ;
        FALSE_RET_TRUE(ok) ;

        /*
         *  return ok  
         */
        (*fd) = L_SB_setSbs(sb,sbs) ;
        if ((*fd) != -1)
			return TRUE ;

        /*
         *  return error  
         */
        (*fd) = -1 ;
        return FALSE ;
      }

      T_BOOL  L_SB_unplug      
      ( 
        IN     t_sb    *sb,
        INOUT  int      fd 
      )
      {
        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        if ( (fd < 0) || (fd >= MAX_SOCKS) )
           {
             L_DEBUG_MSG_Write(DBG_ERROR,FALSE,"fd is out range") ;
             return FALSE ;
           }

        /*
         *  update references  
         */
        if ( 
             (sb->my != -1) 
                   && 
             (fd == (sb->my))
           )
           {
             (sb->my) = -1 ;
           }
        if ( 
             (sb->ns != -1) 
                   && 
             (fd == (sb->ns))
           )
           {
             (sb->ns) = -1 ;
           }

        /*
         *  unplug  
         */
        NULL_RET_TRUE( (sb->sock_set)[fd] ) ;
        L_SB_SOCK_Destroy( &((sb->sock_set)[fd]) ) ;
        (sb->sock_set)[fd] = NULL ;

        /*
         *  return ok  
         */
        return TRUE ;
      }


  /* .................................................................... */

