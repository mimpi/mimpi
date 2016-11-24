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

      T_BOOL   L_NODECMD_receive_X_async
      (
        INOUT    t_nodeInfo     *node_info,
        INOUT    t_nodeReq      *receive,
        INOUT    T_INT          *nodeli
      )
      {
        t_mtsda        *reqmtsda ;
        t_reqli        *reqli ;
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
                         "receive_X_async begin (from %i, tagX=%i tagY=%i)",
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
                                 "receive_X_async 'from' (%i) not at nodeList",
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
                                "receive_X_async BAD 'from' (%i) param",
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
        peslabon = L_REQMAN_submit(reqli,receive,TRUE,NULL) ;
        if (peslabon == NULL)
           {
             X_THREAD_unlock( reqmtsda ) ;
             return FALSE ;
           }
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "receive_X_async inserted in reqli[%i] = %i",
                       chn,
                       reqli->nreqli) ;
        X_THREAD_signalReady( reqmtsda ) ;
        X_THREAD_unlock( reqmtsda ) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                           "receive_X_async end (from %i, tagX=%i tagY=%i)",
                           receive->from,
                           receive->tagX,
                           receive->tagY) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

