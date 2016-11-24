/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "mp/xmp/map/node_server/l_nsi.h"


   /* ... Funciones ................................................... */

     /*  read/write command *
      * ------------------- */
      T_INT    L_NSI_read             
      ( 
        INOUT    t_sb        *sb,
        INOUT    int          nsfd,
        OUT      t_nsHeader  *nsmsg 
      )
      {
        T_INT ret ;

        /*
         *  read ns request
         */
        ret = L_SB_read(sb,nsfd,(void *)nsmsg,c_NSHEADER) ;
        if (ret < 0)
           { 
             fprintf(stderr,
                     "Can't read to NodeServer\n") ;
             return ret ;
           } 

        /*
         *  return 'ret'
         */
        return ret ;
      }

      T_INT    L_NSI_readAvailable    
      ( 
        INOUT    t_sb        *sb,
        INOUT    int          nsfd,
        OUT      t_nsHeader  *nsmsg 
      )
      {
        T_INT ret ;

        /*
         *  read ns request
         */
        ret = L_SB_readAvailable(sb,nsfd,(void *)nsmsg,c_NSHEADER) ;
        if (ret < 0)
           { 
             fprintf(stderr,
                     "Can't read to NodeServer\n") ;
             return ret ;
           } 

        /*
         *  return 'ret'
         */
        return ret ;
      }

      T_INT    L_NSI_write            
      ( 
        INOUT    t_sb        *sb,
        INOUT    int          nsfd,
        IN       t_nsHeader  *nsmsg 
      )
      {
        T_INT ret ;

        /*
         *  write ns request
         */
        ret = L_SB_write(sb,nsfd,(void *)nsmsg,c_NSHEADER) ;
        if (ret < 0)
           { 
             fprintf(stderr,
                     "Can't write to NodeServer\n") ;
             return ret ;
           } 

        /*
         *  return 'ret'
         */
        return ret ;
      }

      T_INT    L_NSI_writeRead        
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        IN       char               *nsmsg,
        IN       int                 size 
      )
      {
        T_INT ret ;

        /*
         *  write ns request
         */
        ret = L_SB_write(sb,nsfd,nsmsg,size) ;
        if (ret < 0)
           { 
             fprintf(stderr,
                     "Can't write to NodeServer\n") ;
             return ret ;
           } 

        /*
         *  read ns request
         */
        ret = L_SB_read(sb,nsfd,nsmsg,size) ;
        if (ret < 0)
           { 
             fprintf(stderr,
                     "Can't read from NodeServer\n") ;
             return ret ;
           } 

        /*
         *  return 'ret'
         */
        return ret ;
      }

      T_BOOL   L_NSI_writeInsert      
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        IN       char               *name,
        IN       struct sockaddr_in *sa,
        OUT      int                *code 
      )
      {
        t_nsHeader nsmsg ;
        T_INT      ret ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(name) ;
        NULL__SET_ERROR__RET_FALSE(code) ;

        /*
         *  insert new member
         */
        nsmsg.n2nH.code = NS_CREAT ;
        strncpy(nsmsg.n2nH.name,name,MIN(strlen(name)+1,MAX_NODE_NAME)) ;
        memmove(&(nsmsg.n2nH.sa),sa,c_SOCKADDR_IN) ;
        nsmsg.n2nH.data_size = 0 ;
        ret = L_NSI_writeRead(sb,nsfd,(char *)&nsmsg.n2nH,c_NSHEADER) ;
        if (ret < 0)
            return FALSE ;
        (*code) = nsmsg.n2nH.ret_code ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NSI_writeOpen        
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        IN       char               *name,
        OUT      struct sockaddr_in *sa,
        OUT      int                *code 
      )
      {
        t_nsHeader nsmsg ;
        T_INT      ret ;
        
        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(name) ;
        NULL__SET_ERROR__RET_FALSE(sa) ;
        NULL__SET_ERROR__RET_FALSE(code) ;

        /*
         *  search member address
         */
        nsmsg.n2nH.code = NS_OPEN ;
        strncpy(nsmsg.n2nH.name,name,MIN(strlen(name)+1,MAX_NODE_NAME)) ;
        nsmsg.n2nH.data_size = 0 ;
	nsmsg.n2nH.ret_code  = FALSE ;
	
	while (TRUE)
	{
             ret = L_NSI_writeRead(sb,nsfd,(char *)&(nsmsg.n2nH),c_NSHEADER) ;
             if (ret >= 0)
           	{
	             if (nsmsg.n2nH.ret_code == TRUE)
			{
             		  (*sa)   = nsmsg.n2nH.sa ;
             		  (*code) = nsmsg.n2nH.ret_code ;
			  return TRUE ;
			}
			else
			{
			  X_PROCESS_sleep(2) ;
			}
           	}
        	else
           	{
	          return FALSE ;
           	}
	}

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NSI_writeDisconnect  
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        OUT      int                *code 
      )
      {
        t_nsHeader nsmsg ;
        T_INT      ret ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(code) ;

        /*
         *  disconnect
         */
        X_ALLOC_MemSet(&nsmsg,0,c_NSHEADER) ;
        nsmsg.n2nH.code = NS_DISC ;
        ret = L_NSI_writeRead(sb,nsfd,(char *)&nsmsg.n2nH,c_NSHEADER) ;
        if (ret < 0)
            return FALSE ;
        (*code) = nsmsg.n2nH.ret_code ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_INT    L_NSI_writeDump        
      ( 
        INOUT    t_sb   *sb,
        IN       int     nsfd,
        IN       int     nodeid,
        IN       char   *format, ... 
      )
      {
        va_list       vl ;
        T_INT         ret ;
        T_CHAR       *str ;
        t_nsHeader    nsmess ;

        /*
         *  get dump
         */
        va_start(vl,format) ;
        str = X_STRING_Dvsprintf(format,vl) ;

        /*
         *  send dump
         */
        nsmess.n2nH.code = NS_DUMP ;
        sprintf(nsmess.n2nH.name,"node_%i_",nodeid) ;
        nsmess.n2nH.data_size = X_STRING_StrLen(str) ;

        ret = L_NSI_write(sb,nsfd,&nsmess) ;
        ret = L_SB_write(sb,nsfd,(void *)str,nsmess.n2nH.data_size) ;

        /*
         *  free dump
         */
        X_ALLOC_Free((void **)&str) ;
        va_end(vl) ;

        /*
         *  return 'ret'
         */
        return ret ;
      }

      T_INT    L_NSI_writeTrace       
      ( 
        INOUT    t_sb   *sb,
        IN       int     nsfd,
        IN       int     nodeid,
        IN       char   *str 
      )
      {
        T_INT         ret ;
        t_nsHeader    nsmess ;

        /*
         *  send trace
         */
        nsmess.n2nH.code = NS_TRACE ;
        sprintf(nsmess.n2nH.name,"node_%i_",nodeid) ;
        nsmess.n2nH.data_size = X_STRING_StrLen(str) ;

        ret = L_NSI_write(sb,nsfd,&nsmess) ;
        ret = L_SB_write(sb,nsfd,(void *)str,nsmess.n2nH.data_size) ;

        /*
         *  return 'ret'
         */
        return ret ;
      }


  /* .................................................................... */


