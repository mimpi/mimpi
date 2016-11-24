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

      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_send.h"


   /* ... Functions / Funciones ....................................... */

      void  L_SNOOPY_SEND_do_send_snoopy 
      ( 
        INOUT  int         chn,
        INOUT  t_nodeInfo *local_node_info 
      )
      {
        t_nodeReq      *psend ;
        t_reqli        *reqli ;      /* ptr to my reqli */
        t_nodeHeader   *outHeader ;  /* ptr to my header */
        T_INT           nodeid ;     /* my nodeid */
        t_mtsda        *reqmtsda ;   /* ptr to my mtsda */

        /*
         *  get node's references
         */
        reqmtsda  = L_REQMAN_get_send_mtsda(local_node_info,chn) ;
        reqli     = L_REQMAN_get_send_reqli(local_node_info,chn) ;
        outHeader = L_REQMAN_get_outHeader (local_node_info,chn) ;
        nodeid    = L_NETMAN_getNode(local_node_info,chn) ;

        /*
         *  lock reqli
         */
        X_THREAD_lock( reqmtsda ) ;

        /*
         *  begin server ...
         */
        while ( (local_node_info->shutdown) != TRUE )
        {

           /*
            *  get first request
            */
           do
           {
             psend = L_REQMAN_get_send_req( reqli ) ;
             if (psend == NULL)
                {
                  /*
                   *  trace
                   */
                  L_TRACE_MSG_PrintF(DEFCON_1,
                                 "sendSnoopy[node=%i,chn=%i] go sleep",
                                 nodeid, 
                                 chn) ;

                  /*
                   *  go sleep
                   */
                  X_THREAD_setNotReady( reqmtsda ) ;
                  X_THREAD_waitReady( reqmtsda ) ;
                  if (X_THREAD_isDestroy(reqmtsda) == TRUE)
                     {
                       return ;   /* check */
                     }

                  /*
                   *  trace
                   */
                  L_TRACE_MSG_PrintF(DEFCON_1,
                                 "sendSnoopy[node=%i,chn=%i] WakeUp !!!",
                                 nodeid, 
                                 chn) ;
                }

           } while (psend == NULL) ;

           /*
            *  trace
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
                          "sendSnoopy[node=%i,chn=%i] see %i sendRequests",
                          nodeid, 
                          chn,
                          reqli->nreqli) ;

           /*
            *  write data
            */
           L_NODEI_writeSendReq( &(local_node_info->sb), 
                                 chn,
                                 outHeader,
                                 psend ) ;

           /*
            *  wake up
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
                            "sendSnoopy[node=%i,chn=%i] signal ready...",
                            nodeid, 
                            chn) ;
           X_THREAD_lock( &(psend->mtsda) ) ;
           X_THREAD_signalReady( &(psend->mtsda) ) ;
           X_THREAD_unlock( &(psend->mtsda) ) ;
        }
      }

      void  L_SNOOPY_SEND_sendSnoopy   
      ( 
        INOUT  t_snoopy_info  *snoopy_info 
      )
      {
        int          chn ;
        t_nodeInfo  *local_node_info;

        /*
         *  copy params
         */
        chn             = (snoopy_info->chn) ;
        local_node_info = (snoopy_info->node_info) ;

        /*
         *  Trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "sendSnoopy started... [node=%i,chn=%i]",
                       (local_node_info->sock2node)[chn],
                       chn) ;

        /*
         *  signal ready
         */
        X_THREAD_lock( &(snoopy_info->boot) ) ;
        X_THREAD_signalReady( &(snoopy_info->boot) ) ;
        X_THREAD_unlock( &(snoopy_info->boot) ) ;

        /*
         *  begin ...
         */
        L_SNOOPY_SEND_do_send_snoopy(chn,local_node_info) ;

        /*
         *  Trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "sendSnoopy finished... [node=%i,chn=%i]",
                       (local_node_info->sock2node)[chn],
                       chn) ;
      }


  /* ......................................................... */

