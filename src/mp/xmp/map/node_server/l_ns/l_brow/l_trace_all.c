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

      #include "mp/xmp/map/node_server/l_ns/l_brow/l_trace_all.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_TRACE_ALL_traceAll    
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      )
      {
        t_nsHeader  nsmess ;
#if defined(SIGPIPE)
        void (*oldSigPipe) (int) ;
#endif

        /*
         *  say "ok, hi" to browser
         */
#if defined(SIGPIPE)
        oldSigPipe = signal(SIGPIPE,SIG_IGN) ;
#endif
        write( (*dsd), 
               HTTP_OK,
               strlen(HTTP_OK) ) ;
#if defined(SIGPIPE)
        signal(SIGPIPE,oldSigPipe) ;
#endif

        /*
         *  request nodes DUMP
         */
        X_ALLOC_MemSet(&nsmess,0,c_NSHEADER) ;
        nsmess.n2nH.code = NS_TRACE_ON ;
        sprintf(nsmess.n2nH.name,"node_ns_") ;
        L_SB_broadcast( &(nsinfo->sb),
                         (char *)&nsmess,
                         c_NSHEADER ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


  /* .................................................................... */


