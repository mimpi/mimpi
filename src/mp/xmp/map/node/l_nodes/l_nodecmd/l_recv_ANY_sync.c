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

      T_BOOL   L_NODECMD_receive_ANY_sync
      (
        INOUT    t_nodeInfo     *node_info,
        INOUT    t_nodeReq      *receive,
        INOUT    T_INT          *nodeli
      )
      {
        t_mtsda       *reqmtsda ;
        t_reqli       *reqli ;
        t_nodeReq     *preceive ;
        t_reqRef      *peslabon ;
	    int            i, chn ;
        t_params_xmp  *XMP_params ;
        T_INT          lessJump ;
        T_BOOL         ok ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "receive_ANY_sync begin (from %i, tagX=%i tagY=%i)",
                       receive->from,
                       receive->tagX,
                       receive->tagY) ;

        /*
         *  get configuration
         */
        XMP_params = L_NODECMD_getParams() ;
        lessJump   = 0 ;

        /*
         *  dup receive request
         */
        preceive = L_NODEREQ_dup(receive) ;
        NULL_RET_FALSE(preceive) ;

        /*
         *  insert new request
         */
        X_THREAD_lock( &(preceive->mtsda) ) ;
        for (i=0; i<MAX_SOCKS; i++)
        {
          /* ... in list ? ... */
          ok = L_NODEGRP_isMember(nodeli,i) ;
          if (ok == FALSE)
              continue ;

          /* ... is connected ? ... */
          chn = L_NETMAN_getSock(node_info,i) ;
          if (chn == NID_ERROR)
              continue ;
          if (chn == NID_NULL)
             {
               ok  = L_NETMAN_linkTo(node_info,i) ;
               FALSE_RET_FALSE(ok) ;
               chn = L_NETMAN_getSock(node_info,i) ;
               ok  = L_SNOOPY_createComunicationDaemons(node_info,chn) ;
               FALSE_RET_FALSE(ok) ;
             }

          /*
           *  hand on !
           */
          if (
                ( chn != -1 )
                      &&
                ( chn != (node_info->nodeid) )
             )
             {
               if (preceive->isServed == TRUE)
                   break ;

               reqmtsda = L_REQMAN_get_receive_mtsda(node_info,chn) ;
               reqli    = L_REQMAN_get_receive_reqli(node_info,chn) ;

               /*
                *  dispatch request
                */
               X_THREAD_lock( reqmtsda ) ;
               peslabon = L_REQMAN_submit(reqli,preceive,TRUE,NULL) ;
               if (peslabon == NULL)
                  {
                    X_THREAD_unlock( reqmtsda ) ;
                    return FALSE ;
                  }
               L_TRACE_MSG_PrintF(DEFCON_1,
                            "receive_ANY_sync inserted in reqli[%i] = %i",
                            chn,
                            reqli->nreqli) ;
               X_THREAD_signalReady( reqmtsda ) ;
               X_THREAD_unlock( reqmtsda ) ;
             }
        }
        X_THREAD_unlock( &(preceive->mtsda) ) ;

        /*
         *  sleep till snoopy read all
         */
        X_THREAD_lock( &(receive->mtsda) ) ;
        X_THREAD_waitReady( &(receive->mtsda) ) ;
        X_THREAD_unlock( &(receive->mtsda) ) ;

        /*
         *  Trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "receive_ANY_sync end (from %i, tagX=%i tagY=%i)",
                       receive->from,
                       receive->tagX,
                       receive->tagY) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

