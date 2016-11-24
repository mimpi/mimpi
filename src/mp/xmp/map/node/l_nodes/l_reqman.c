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

      #include "mp/xmp/map/node/l_nodes/l_reqman.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_REQMAN_setup
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        int     i ;
        T_BOOL  ok ;

        /*
         *  setup link flag
         */
        for (i=0; i < MAX_SOCKS; i++)
            {
              /*
               *  inHeader
               */
              L_NODEHEADER_nodeheaderInit( &((node_info->inHeader)[i]) ) ;
              (node_info->isinHeader)[i] = FALSE ;

              /*
               *  outHeader
               */
              L_NODEHEADER_nodeheaderInit( &((node_info->inHeader)[i]) ) ;

              /*
               *  sendli
               */
              ok = L_REQLI_init( &((node_info->sendli)[i]) ) ;
              FALSE_RET_FALSE(ok) ;

              /*
               *  req mtsda
               */
              X_THREAD_init( &((node_info->sendmtsda)[i]) ) ;

              /*
               *  recvli
               */
              ok = L_REQLI_init( &((node_info->recvli)[i]) ) ;
              FALSE_RET_FALSE(ok) ;

              /*
               *  req mtsda
               */
              X_THREAD_init(&((node_info->recvmtsda)[i])) ;
            }

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_REQMAN_finalize
      (
        OUT      t_nodeInfo      *node_info
      )
      {
        int       i ;
        T_BOOL    ok ;
        t_reqli  *reqli ;
        t_mtsda  *reqmtsda ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"go finalize reqman") ;

        /*
         *  finalize per node resources
         */
        for (i=0; i < MAX_SOCKS; i++)
            {
              /*
               *  recv list
               */
              reqli    = &((node_info->recvli)[i]) ;
              reqmtsda = &((node_info->recvmtsda)[i]) ;

              /*
               *  finalize list
               */
              X_THREAD_lock( reqmtsda ) ;
              ok = L_REQLI_finalize( reqli ) ;
              X_THREAD_unlock( reqmtsda ) ;
              FALSE_RET_FALSE(ok) ;

              /*
               *  finalize mtsda
               */
              X_THREAD_destroy( reqmtsda ) ;

              /*
               *  recv list
               */
              reqli    = &((node_info->sendli)[i]) ;
              reqmtsda = &((node_info->sendmtsda)[i]) ;

              /*
               *  finalize list
               */
              X_THREAD_lock( reqmtsda ) ;
              ok = L_REQLI_finalize( reqli ) ;
              X_THREAD_unlock( reqmtsda ) ;
              FALSE_RET_FALSE(ok) ;

              /*
               *  finalize mtsda
               */
              X_THREAD_destroy( reqmtsda ) ;
            }

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"ok when finalize reqman") ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_REQMAN_TAGEquals
      (
        IN       t_nodeReq      *request,
        IN       t_nodeHeader   *header
      )
      {
        /* 
	 *  test ...
         */
        if (
             (
               (request->tagX == ANY_TAG)
                              ||
               (request->tagX == header->tagX)
             )
                         &&
             (
               (request->tagY == ANY_TAG)
                              ||
               (request->tagY == header->tagY)
             )
           )
           {
             /* 
     	      *  ... return equals
              */
             return TRUE ;
           }

        /* 
	 *  ... return not equals
         */
        return FALSE ;
      }

      t_reqRef *L_REQMAN_searchTAG
      (
        IN    t_reqli       *reqli,
        IN    t_nodeHeader  *header
      )
      {
        t_reqRef  *eltoAux ;

        /* 
         *  check params
         */
        NULL__SET_ERROR__RET_NULL(reqli) ;

        /* 
         *  search elto
         */
        for (
              eltoAux = L_REQLI_first(reqli) ;
              (eltoAux != NULL) ;
              eltoAux = L_REQLI_next(eltoAux)
            )
        {
          if (L_REQMAN_TAGEquals((eltoAux->req),header) == TRUE)
             {
               return eltoAux ;
             }
        }

        /* 
         *  return 'not found'
         */
        return NULL ;
      }

      t_reqRef *L_REQMAN_submit
      (
        INOUT   t_reqli         *reqli,
        INOUT   t_nodeReq       *request,
        IN      T_BOOL           isMalloc,
        IN      t_reqRef        *eslabon
      )
      {
        t_reqRef *peslabon ;
        T_BOOL    ok ;

        /*
         *  insert in list
         */
         if (isMalloc == FALSE)
            {
              eslabon->req      = request ;
              eslabon->isMalloc = FALSE ;
              ok = L_REQLI_insert( reqli, eslabon ) ;
              FALSE_RET_NULL(ok) ;
              peslabon = eslabon ;
            }
         else 
            {
              ok = L_REQLI_allocReqAndInsert( reqli, &peslabon ) ;
              FALSE_RET_NULL(ok) ;
              peslabon->req      = request ;
              peslabon->isMalloc = TRUE ;
            }

        /*
         *  return peslabon
         */
        return peslabon ;
      }

      T_BOOL   L_REQMAN_send_direct
      (
        INOUT    t_nodeInfo     *node_info,
        IN       T_INT           nodeid,
	IN       int             chn,
        INOUT    t_nodeReq      *send
      )
      {
        T_BOOL         ok ;
        t_nodeHeader  *outHeader ;

        /* 
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                            "to %i send_direct %i bytes",
                            nodeid,
                            send->data_size) ;

        /* 
         *  hand on !
         */
        outHeader = &((node_info->outHeader)[chn]) ;

        /* 
         *  write data
         */
        ok = L_NODEI_writeSendReq( &(node_info->sb),
                                   chn,
                                   outHeader,
                                   send ) ;
        (send->code)     = (ok == TRUE) ? 1 : -1 ; 
        (send->isServed) = TRUE ; 

	/*
         *  trace 
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"send_direct ok") ;

        /* 
	 *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_REQMAN_receive_direct
      (
        INOUT    t_nodeInfo     *node_info,
        IN       T_INT           nodeid,
	IN       int             chn,
        INOUT    t_nodeHeader   *inHeader,
        INOUT    t_nodeReq      *receive
      )
      {
        T_BOOL   ok ;
        T_INT    dataToRead, dataToSkip ;

        /* 
         *  hand on !
         */
        dataToRead = MIN( (receive->data_size),
                           inHeader->size ) ;
        dataToSkip = (inHeader->size) - (receive->data_size) ;

        /* 
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                            "from %i receive_direct %i bytes",
                            nodeid,
                            dataToRead) ;

        /* 
         *  process data
         */
	ok = TRUE ;
	if (dataToRead <= NH_IDATA)
	   { 
              /*
               *  read data from header
               */
	      X_ALLOC_MemMove((receive)->data_buff,
			      (inHeader)->idata,
			      dataToRead) ;
	   }
	else
	   {
              /*
               *  read data from header ...
               */
	      X_ALLOC_MemMove((receive)->data_buff,
			      (inHeader)->idata,
			      NH_IDATA) ;

             /* 
              *  and read data.
              */
             ok = L_NODEDATA_readData( &(node_info->sb),
                                       chn,
                                       (receive->data_buff+NH_IDATA),
                                       dataToRead-NH_IDATA ) ;

             /* 
              *  skip data
              */
             if ( dataToSkip != 0 )
		{
                    L_TRACE_MSG_PrintF(DEFCON_1,
                                       "from %i receive_direct skip %i bytes",
                                       nodeid,
                                       dataToSkip) ;
                    ok = L_NODEDATA_skipData( &(node_info->sb),
                                              chn,
                                              dataToSkip ) ;
                    (receive->code) = -1 ;
		}
	 }

 	/*
         *  set results 
         */
        (receive->ret_size) = dataToRead ;
        (receive->code)     = (ok == TRUE) ? 1 : -1 ; 
        (receive->ch)       = chn ;
        (receive->isServed) = TRUE ;
        (receive->tagX)     = (inHeader->tagX) ;
        (receive->tagY)     = (inHeader->tagY) ;
        (receive->from)     = nodeid ;

 	/*
         *  trace 
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"receive_direct end") ;

        /* 
	 *  return ok
         */
        return TRUE ;
      }

      t_nodeReq *L_REQMAN_get_send_req
      (
        INOUT   t_reqli         *reqli
      )
      {
        t_reqRef       *peslabon ;
        t_nodeReq      *psend ;
        t_nodeReq      *RealSend ;

        /* 
	 *  get first
         */
        peslabon = L_REQLI_first( reqli ) ;
        NULL_RET_NULL(peslabon) ;

        /*
         *  unlink
         */
        psend = peslabon->req ;
        RealSend = psend->reqptr ;
        L_REQLI_delete( reqli, peslabon ) ;

        /* 
	 *  return RealSend
         */
        return RealSend ;
      }

      t_nodeReq *L_REQMAN_get_receive_req
      (
        INOUT   t_reqli         *reqli,
        IN      t_nodeHeader    *inHeader
      )
      {
        t_reqRef       *peslabon ;
        t_nodeReq      *preceive ;
        t_nodeReq      *RealReceive ;

        do
        {

          /* 
  	   *  search a valid receive
           */
          peslabon = L_REQMAN_searchTAG( reqli, inHeader ) ;
          NULL_RET_NULL(peslabon) ;
  
          /*
           *  but was served
           */
          preceive    = peslabon->req ;
          RealReceive = preceive->reqptr ;
          X_THREAD_lock( &(preceive->mtsda) ) ;
          if ((preceive->isServed) == TRUE)
             {
               L_TRACE_MSG_PrintF(DEFCON_1,
                              "get_receive_req skip receive...") ;
  
               /* ... eraser ... */
               if (preceive->nlinks > 1)
                  {
                    L_REQLI_delete( reqli, peslabon ) ;
                    X_THREAD_unlock( &(preceive->mtsda) ) ;
                  }
               else { /* ... i am the last to delete */
                      X_THREAD_unlock( &(preceive->mtsda) ) ;
                      L_REQLI_delete( reqli, peslabon ) ;
                    }
  
               peslabon = NULL ;
             }
          else
             {
               L_TRACE_MSG_PrintF(DEFCON_1,
                              "recvSnoopy[node=%i,chn=%i] mark as served...") ;
  
               (preceive->isServed) = TRUE ;
  
               /* ... eraser ... */
               if (preceive->nlinks > 1)
                  {
                    L_REQLI_delete( reqli, peslabon ) ;
                    X_THREAD_unlock( &(preceive->mtsda) ) ;
                  }
               else { /* ... i am the last to delete */
                      X_THREAD_unlock( &(preceive->mtsda) ) ;
                      L_REQLI_delete( reqli, peslabon ) ;
                    }
             }

        } while (peslabon == NULL) ;


        /* 
	 *  return RealReceive
         */
        return RealReceive ;
      }


   /* ................................................................. */

