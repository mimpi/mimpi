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

      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_recv.h"


   /* ... Functions / Funciones ....................................... */

      void  L_SNOOPY_RECV_perror_snoopy 
      ( 
        INOUT  t_nodeInfo  *local_node_info,
        IN     T_CHAR      *snoopyName,
        IN     T_INT        mynodeid,
        INOUT  int          chn,
        INOUT  int          ret 
      )
      {
        if (ret < 0)
           {
             if ( (local_node_info->shutdown) != TRUE )
                   L_TRACE_MSG_PrintF(DEFCON_1,
                                 "%s[node=%i,chn=%i] error in read.", 
                                 snoopyName,
                                 mynodeid,
                                 chn) ;
           }
        if (ret == 0)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                       "%s[node=%i,chn=%i] found EOF...", 
                       snoopyName,
                       mynodeid,
                       chn) ;
           }
      }

      t_nodeReq  *L_SNOOPY_RECV_getRecvReq 
      ( 
        IN     t_reqli       *reqli,
        IN     t_nodeHeader  *inHeader,
        IN     T_INT          nodeid,
        INOUT  int            chn,
        INOUT  t_mtsda       *reqmtsda,
        IN     T_BOOL        *validHeader 
      )
      {
        t_nodeReq   *RealReceive ;

        /* 
         *  obtiene la primera peticion
         */
        do
        {
          /*
           *  search request
           */
          RealReceive = L_REQMAN_get_receive_req( reqli, inHeader ) ;
          if (RealReceive == NULL)
             {
               /*
                *  trace
                */
               L_TRACE_MSG_PrintF(DEFCON_1,
                              "recvSnoopy[node=%i,chn=%i] go sleep",
                              nodeid, 
                              chn) ;

               /*
                *  wait
                */
               X_THREAD_setNotReady( reqmtsda ) ;
               X_THREAD_waitReady( reqmtsda ) ;
               if (X_THREAD_isDestroy(reqmtsda) == TRUE)
                  {
                    return NULL ;
                  }

               /*
                *  wake up and check header
                */
               if ( (*validHeader) == FALSE ) 
                  {
                    /*
                     *  trace
                     */
                    L_TRACE_MSG_PrintF(DEFCON_1,
                        "recvSnoopy[node=%i,chn=%i] Wake up without header",
                         nodeid, 
                         chn) ;

                    /* 
                     *  re-read header 
                     */
                    return NULL ;
                  }
               else 
                  {
                    /*
                     *  trace
                     */
                    L_TRACE_MSG_PrintF(DEFCON_1,
                        "recvSnoopy[node=%i,chn=%i] Wake up, try search",
                         nodeid, 
                         chn) ;
                  }
             }
 
        } while (RealReceive == NULL) ;
   
        /*
         *  well request
         */
        return RealReceive ;
      }

      void  L_SNOOPY_RECV_do_recv_snoopy 
      ( 
        INOUT  int         chn,
        INOUT  t_nodeInfo *local_node_info 
      )
      {
        int             ret ;
        t_nodeReq      *RealReceive ;
        t_reqli        *reqli ;       /* ptr to my reqli */
        t_nodeHeader   *inHeader ;    /* ptr to my header */
        T_BOOL         *isinHeader ;  /* ptr to my isheader */
        T_INT           nodeid ;      /* my nodeid */
        t_mtsda        *reqmtsda ;   /* ptr to my mtsda */

        /*
         *  get node's references
         */
        reqmtsda   = L_REQMAN_get_receive_mtsda(local_node_info,chn) ;
        reqli      = L_REQMAN_get_receive_reqli(local_node_info,chn) ;
        inHeader   = L_REQMAN_get_inHeader  (local_node_info,chn) ;
        isinHeader = L_REQMAN_get_isinHeader(local_node_info,chn) ;
        nodeid     = L_NETMAN_getNode(local_node_info,chn) ;

        /*
         *  begin server ...
         */
        while ( (local_node_info->shutdown) != TRUE )
        {

           /*
            *  trace
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
                          "recvSnoopy[node=%i,chn=%i] go read Header...", 
                          nodeid,
                          chn) ;

           /*
            *  read header
            */
           ret = L_NODEHEADER_readHeader( &(local_node_info->sb),
                                          chn,
                                          inHeader ) ;
           if ( (ret < 0) || (ret == 0) )
              {
                L_SNOOPY_RECV_perror_snoopy(local_node_info,
                                          "recvSnoopy",
                                          nodeid,
                                          chn,
                                          ret) ;
                break ;
              }

           /*
            *  trace
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
             "recvSnoopy[node=%i,chn=%i] (id=%i, tagX=%i, tagY=%i, size=%i)",
                          nodeid, 
                          chn,
                          (inHeader->id),
                          (inHeader->tagX),
                          (inHeader->tagY),
                          (inHeader->size)) ;

           /*
            *  dispatch
            */
           switch ( inHeader->id )
           {

             case NH_DATA :
                  /*
                   *  get first available request
                   */
                  X_THREAD_lock( reqmtsda ) ;
                  (*isinHeader) = TRUE ;
                  RealReceive = L_SNOOPY_RECV_getRecvReq(reqli,
                                                         inHeader,
                                                         nodeid,
                                                         chn,
                                                         reqmtsda,
                                                         isinHeader) ;
                  if ( (*isinHeader) == FALSE )
                     {
                       X_THREAD_unlock( reqmtsda ) ;
                       continue ;
                     }
                  (*isinHeader) = FALSE ;
       
                  /*
                   *  end snoopy
                   */
                  if (X_THREAD_isDestroy(reqmtsda) == TRUE)
                     {
                       break ;
                     }

                  /*
                   *  read data 
                   */
                  X_THREAD_lock( &(RealReceive->mtsda) ) ;
                  L_REQMAN_receive_direct( local_node_info,
                                           nodeid,
                                           chn,
                                           inHeader,
                                           RealReceive ) ;
  
                  /*
                   *  signal ready
                   */
                  X_THREAD_signalReady( &(RealReceive->mtsda) ) ;
                  X_THREAD_unlock( &(RealReceive->mtsda) ) ;
  
                  /*
                   *  unlock list
                   */
                  X_THREAD_unlock( reqmtsda ) ;
                  break ;

               default : ;

           } /* switch(...) */

        } /* while(...) */
      }

      void  L_SNOOPY_RECV_recvSnoopy  
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
                       "recvSnoopy started... [node=%i,chn=%i]", 
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
        L_SNOOPY_RECV_do_recv_snoopy(chn,local_node_info) ;

        /*
         *  Trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "recvSnoopy finished... [node=%i,chn=%i]", 
                       (local_node_info->sock2node)[chn],
                       chn) ;
      }


  /* ......................................................... */

