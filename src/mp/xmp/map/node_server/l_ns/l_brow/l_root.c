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

      #include "mp/xmp/map/node_server/l_ns/l_brow/l_root.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_ROOT_root             
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      )
      {
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
        write( (*dsd), 
               HTTP_WELCOME, 
               strlen(HTTP_WELCOME) ) ;

        write( (*dsd), 
               HTTP_NODEREF("dump_all.html","dump all nodes"), 
               strlen(HTTP_NODEREF("dump_all.html","dump all nodes")) ) ;
        write( (*dsd), 
               HTTP_NODEREF("trace_all.html","trace all nodes"), 
               strlen(HTTP_NODEREF("trace_all.html","trace all nodes")) ) ;
        write( (*dsd), 
               HTTP_NODEREF("authors.html","authors"), 
               strlen(HTTP_NODEREF("authors.html","authors")) ) ;

        /*
         *  say "bye" to browser
         */
        write( (*dsd), 
               HTTP_SIGN,
               strlen(HTTP_SIGN) ) ;
#if defined(SIGPIPE)
        signal(SIGPIPE,oldSigPipe) ;
#endif
        L_SB_unplug( &(nsinfo->sb), 
                     (*dsd) ) ;
        (*dsd) = 0 ;

        /*
         *  return ok
         */
        return TRUE ;
      }


  /* .................................................................... */


