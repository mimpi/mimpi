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



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/xmp/map/node/l_nodes/l_nodecmd.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODECMD_wait
      (
        INOUT    t_nodeReq      *preq
      )
      {
        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                           "wait (from %i, to %i, tagX=%i tagY=%i)",
                            preq->from,
                            preq->to,
                            preq->tagX,
                            preq->tagY) ;

        /*
         *  sleep till snoopy read all
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "wait go sleep ...") ;
        X_THREAD_lock( &(preq->mtsda) ) ;
        X_THREAD_waitReady( &(preq->mtsda) ) ;
        X_THREAD_unlock( &(preq->mtsda) ) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                           "wait end (from %i, to %i, tagX=%i tagY=%i)",
                            preq->from,
                            preq->to,
                            preq->tagX,
                            preq->tagY) ;

        /*
         *  finish
         */
        X_THREAD_destroy( &(preq->mtsda) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

