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

      #include "mp/xmp/map/node_server/l_ns/l_node/l_go_debug.h"


   /* ... Funciones ................................................... */

      void     L_GO_DEBUG_skipMess   
      ( 
        INOUT   int           fd,
        IN      int           size 
      )
      {
        T_CHAR  chuck[4] ;
        T_INT   nchuck, rchuck ;
        T_INT   i, ret ;

        ret    = 1 ;
        nchuck = size / 4 ;
        rchuck = size % 4 ;
        for (i=0; (ret>0) && (i<nchuck); i++)
             ret = read(fd,chuck,4) ;
        if ( (ret>0) && (rchuck != 0) )
             ret = read(fd,chuck,rchuck) ;
      }

      void     L_GO_DEBUG_pipeMess   
      ( 
        INOUT   int           fdout,
        INOUT   int           fdin,
        IN      int           size 
      )
      {
        #define BUFFIO_SIZE  1024
        T_CHAR  buffio[BUFFIO_SIZE] ;
        T_INT   i, ret ;

        ret = 1 ;
        for (i=0; (i < size) && (ret > 0); )
            {
              ret = read( fdin,buffio,MIN(BUFFIO_SIZE,(size-i)) ) ;
              write(fdout,buffio,ret) ;
              i   = i + ret ;
            }
      }

      T_BOOL   L_GO_DEBUG_dump       
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd,
        INOUT   int          *dsd 
      )
      {
        int  dump_size ;

        if ((*dsd) == ssd)
            return TRUE ;

        if ((*dsd) == 0)
           {
             dump_size = (mess->n2nH).data_size ;
             if ( dump_size <= 0 )
                  return TRUE ;

             L_GO_DEBUG_skipMess(ssd,dump_size) ;
             return TRUE ;
           }
        else
           {
             static int  ndump = 0 ;

             dump_size = (mess->n2nH).data_size ;
             if ( dump_size <= 0 )
                {
                  ndump++ ;
                  if (ndump >= (L_SB_alives(&(nsinfo->sb))-2) )
                     {
                       L_SB_unplug( &(nsinfo->sb),
                                    (*dsd) ) ;
                       (*dsd) = 0 ;
                       ndump  = 0 ;
                     }
                  return TRUE ;
                }
             L_GO_DEBUG_pipeMess((*dsd),ssd,dump_size) ;
           }

        return TRUE ;
      }

      void     L_GO_DEBUG_traceOff   
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   int          *dsd 
      )
      {
        t_nsHeader  nsmess ;

        /*
         *  request nodes DUMP
         */
        X_ALLOC_MemSet(&nsmess,0,c_NSHEADER) ;
        nsmess.n2nH.code = NS_TRACE_OFF ;
        sprintf(nsmess.n2nH.name,"node_ns_") ;
        L_SB_broadcast( &(nsinfo->sb),
                         (char *)&nsmess,
                         c_NSHEADER ) ;
      }

      T_BOOL   L_GO_DEBUG_trace      
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd,
        INOUT   int          *dsd 
      )
      {
        int  dump_size, ret ;

        if ((*dsd) == ssd)
            return TRUE ;

#if defined(SIGPIPE)
        signal(SIGPIPE,SIG_IGN) ;
#endif

        if ((*dsd) == 0)
           {
             dump_size = (mess->n2nH).data_size ;
             if ( dump_size <= 0 )
                  return TRUE ;

             L_GO_DEBUG_traceOff(nsinfo,dsd) ;
             L_GO_DEBUG_skipMess(ssd,dump_size) ;
             return TRUE ;
           }
        else
           {
             dump_size = (mess->n2nH).data_size ;

             ret = write((*dsd),"\n",1) ;
             if (ret >= 0)
                 L_GO_DEBUG_pipeMess((*dsd),ssd,dump_size) ;
             if (ret < 0)
                {
                  L_GO_DEBUG_traceOff(nsinfo,dsd) ;
                  L_GO_DEBUG_skipMess(ssd,dump_size) ;
                  L_SB_unplug( &(nsinfo->sb),
                                (*dsd) ) ;
                  (*dsd) = 0 ;
                }
           }

        return TRUE ;
      }


  /* .................................................................... */


