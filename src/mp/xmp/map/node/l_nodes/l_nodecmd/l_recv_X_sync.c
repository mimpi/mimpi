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

      T_BOOL   L_NODECMD_receive_X_sync
      (
        INOUT    t_nodeInfo     *node_info,
        INOUT    t_nodeReq      *receive,
        INOUT    T_INT          *nodeli
      )
      {
        t_mtsda        *reqmtsda ;
        t_reqli        *reqli ;
        t_reqRef        eslabon ;
        t_reqRef       *peslabon ;
 	    int             chn ;
        t_params_xmp   *XMP_params ;
        T_INT           lessJump ;
	    T_BOOL          ok ;
        t_nodeHeader   *inHeader ;    /* ptr to my header */
        T_BOOL         *isinHeader ;  /* ptr to my isheader */

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                         "receive_X_sync begin (from %i, tagX=%i tagY=%i)",
                          receive->from,
                          receive->tagX,
                          receive->tagY) ;

        /*
         *  get configuration
         */
        XMP_params = L_NODECMD_getParams() ;
        lessJump   = XMP_params->MAX_RECV_THROUGH ;

        /*
         *  in list ?
         */
        ok = L_NODEGRP_isMember(nodeli,receive->from) ;
        if (ok == FALSE)
           {
             L_TRACE_MSG_PrintF(DBG_ERROR,TRUE,
                                 "'from' (%i) is not at nodeList",
                                 (receive->from)) ;
             return FALSE ;
           }

        /*
         *  is connected ?
         */
        chn = L_NETMAN_getSock(node_info,(receive->from)) ;
        if (chn == NID_NULL)
           {
             ok  = L_NETMAN_linkTo(node_info,(receive->from)) ;
             FALSE_RET_FALSE(ok) ;
             chn = L_NETMAN_getSock(node_info,(receive->from)) ;
             ok  = L_SNOOPY_createComunicationDaemons(node_info,chn) ;
             FALSE_RET_FALSE(ok) ;
           }
        if (chn == NID_ERROR)
           {
             L_TRACE_MSG_PrintF(DBG_ERROR,TRUE,
                                "receive_X_sync BAD 'from' (%i) param",
                                (receive->from)) ;
             return FALSE ;
           }

        /*
         *  hand on !
         */
        reqmtsda   = L_REQMAN_get_receive_mtsda(node_info,chn) ;
        reqli      = L_REQMAN_get_receive_reqli(node_info,chn) ;
        inHeader   = L_REQMAN_get_inHeader(node_info,chn) ;
        isinHeader = L_REQMAN_get_isinHeader(node_info,chn) ;

        /*
         *  dispatch request
         */
        X_THREAD_lock( reqmtsda ) ;
        if (

             ((*isinHeader) == TRUE)
                  &&
             (L_REQLI_isEmpty(reqli) == TRUE)  
                  &&
             (L_REQMAN_TAGEquals(receive,inHeader) == TRUE)
                  &&
             ((inHeader->size) <= lessJump)
           )
           {
             ok = L_REQMAN_receive_direct(node_info,
                                          receive->from,
                                          chn,
                                          inHeader,
                                          receive) ;
             L_TRACE_MSG_PrintF(DEFCON_1,
                              "receive_X_sync signal re-read header [%i]",
                              chn) ;
             (*isinHeader) = FALSE ;
             X_THREAD_signalReady( reqmtsda ) ;
             X_THREAD_unlock( reqmtsda ) ;
           }
        else {
               peslabon = L_REQMAN_submit(reqli,receive,FALSE,&eslabon) ;
               if (peslabon == NULL)
                  {
                    X_THREAD_unlock( reqmtsda ) ;
                    return FALSE ;
                  }
               L_TRACE_MSG_PrintF(DEFCON_1,
                              "receive_X_sync inserted in reqli[%i] = %i",
                              chn,
                              reqli->nreqli) ;
               X_THREAD_signalReady( reqmtsda ) ;
               X_THREAD_unlock( reqmtsda ) ;

               /* ... sleep till snoopy read all ... */
               X_THREAD_lock( &(receive->mtsda) ) ;
               X_THREAD_waitReady( &(receive->mtsda) ) ;
               X_THREAD_unlock( &(receive->mtsda) ) ;
             }

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                           "receive_X_sync end (from %i, tagX=%i tagY=%i)",
                           receive->from,
                           receive->tagX,
                           receive->tagY) ;

        /*
         *  finish
         */
        X_THREAD_destroy( &(receive->mtsda) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

