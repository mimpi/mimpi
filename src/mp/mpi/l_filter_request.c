/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/mpi/l_filter_request.h"


   /* ... Constants / Constantes ...................................... */

      #define _NO_COMPRESSION_               256
      #define _BEST_SPEED_               32*1024
      #define _BEST_COMPRESSION_    32*1024*1024

      #define _TOO_SMALL_                   1024


   /* ... Functions / Funciones ....................................... */

      T_BOOL  L_FILTER_REQUEST_pack
      ( 
        IN       void       *data_buff,
        IN       long        data_size,
        INOUT    void      **cdata_buff,
        INOUT    long       *cdata_size,
        INOUT    int        *filter
      )
      {
        int     ret ;
        t_params_mpi *xP ;
        int           clevel ;

        /*
         *  1.- compression level
         */
        xP     = PARAMS_MPI_getParams() ;
        clevel = xP->l_filter_request_clevel ;
        if (data_size < _TOO_SMALL_)
            clevel = ZL_NO_COMPRESSION ;

        /*
         *  2.- compression 
         */
        if (clevel == ZL_NO_COMPRESSION)
            (*filter) &= !(FILTER_COMPRESS) ;

        /*
         *  3.- compress
         */
        (*cdata_size) = 0L ;
        (*cdata_buff) = NULL ;
        if ((*filter) & FILTER_COMPRESS)
           {
             ret = X_ZL_compress_to( data_buff,
                                     data_size,
                                     cdata_buff,
                                     cdata_size,
                                     clevel ) ;
             if (ret < 0)
                 return FALSE ;
           }

        /*
         *  4.- return 'ok'
         */
        return TRUE ;
      }

      T_BOOL  L_FILTER_REQUEST_unpack
      ( 
        IN       long        cdata_size,
        IN       char       *data_buff,
        IN       long        data_size,
        INOUT    int        *filter
      )
      {
        int       ret ;
        t_params_mpi *xP ;
        int           clevel ;
        /* cdata_size: amount data readed */
        /* cdata_buff: compress buffer */
        char     *cdata_buff ;

        /*
         *  1.- compression level
         */
        xP     = PARAMS_MPI_getParams() ;
        clevel = xP->l_filter_request_clevel ;
        if (data_size < _TOO_SMALL_)
            clevel = ZL_NO_COMPRESSION ;

        /*
         *  2.- compression 
         */
        if (clevel == ZL_NO_COMPRESSION)
            (*filter) &= !(FILTER_COMPRESS) ;

        /*
         *  3.- check uncompress
         */
        if ((*filter) & FILTER_COMPRESS)
           {
              /*
               *  3.a.1.- malloc buffer
               */
              cdata_buff = X_ALLOC_MemDup(data_buff,cdata_size) ;
              NULL_RET_FALSE(cdata_buff) ;
      
              /*
               *  3.a.2.- uncompress
               */
              ret = X_ZL_uncompress_into(  cdata_buff,
                                           cdata_size,
                                           data_buff,
                                          &data_size ) ;
              if (ret < 0)
                  return FALSE ;
      
              /*
               *  3.a.3.- free
               */
              X_ALLOC_Free(&(cdata_buff)) ;
           }

        /*
         *  3.- return ok
         */
        return TRUE ;
      }


      /**
       **
       **  pack AND send.
       **
       **/
      T_BOOL  L_FILTER_REQUEST_pack_and_send
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       T_INT       reqid,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       long        data_size,
        IN       int         from,
        IN       int         to
      )
      {
        void   *cdata_buff ;
        long    cdata_size ;

        /*
         *  1.- pack
         */
        (*ok) = L_FILTER_REQUEST_pack(data_buff,
                                      data_size,
                                      &cdata_buff,
                                      &cdata_size,
                                      &filter) ; 
        FALSE_RET_FALSE((*ok)) ;

        /*
         *  2.- send
         */
        if (FILTER_NULL == filter)
           {
             NODE_request( ok,
                           request, nodeli, reqid,
                           tx, ty, 
                           data_buff, data_size,
                           from, to ) ;
           }
        else 
           {
             NODE_request( ok,
                           request, nodeli, reqid,
                           tx, ty, 
                           cdata_buff, cdata_size,
                           from, to ) ;

             X_ALLOC_Free(&(cdata_buff)) ;
           }

        /*
         *  3.- return '(*ok)'
         */
        return (*ok) ;
      }

      /**
       **
       **  recv AND unpack.
       **
       **/
      T_BOOL  L_FILTER_REQUEST_recv_and_unpack
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       T_INT       reqid,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      )
      {
        T_BOOL  isAsync ;

        /*
         *  request to node instance
         */
        NODE_request( ok,
                      request, nodeli, reqid,
                      tx, ty, 
                      data_buff, data_size,
                      from, to ) ;

        /*
         *  unpack buffer
         */
        isAsync = (REQ_RECEIVE_X_ASYNC == request->requestId) ||
                  (REQ_RECEIVE_ANY_ASYNC == request->requestId) ;
        if (! isAsync)
           {
             (*ok) = L_FILTER_REQUEST_unpack(  request->ret_size,
                                               data_buff,
                                               data_size,
                                              &filter ) ; 
           }
 
        /*
         *  return '(*ok)'
         */
        return (*ok) ;
      }

      /**
       **
       **  wait send OR (wait recv AND unpack).
       **
       **/
      T_BOOL  L_FILTER_REQUEST_wait
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        INOUT    int        *filter
      )
      {
         T_BOOL  isReqRecv, isCompress ;

         /*
          *  request to node instance
          */
         NODE_wait(ok,request) ;
         FALSE_RET_FALSE((*ok)) ;

         /*
          *  unpack buffer
          */
         isReqRecv  = (REQ_RECEIVE_X_SYNC == request->requestId) ||
                      (REQ_RECEIVE_X_ASYNC == request->requestId) ||
                      (REQ_RECEIVE_ANY_SYNC == request->requestId) ||
                      (REQ_RECEIVE_ANY_ASYNC == request->requestId) ;
         isCompress = ((*filter) & FILTER_COMPRESS) ;

         if ( isReqRecv && isCompress )
            {
              (*ok) = L_FILTER_REQUEST_unpack( request->ret_size,
                                               request->data_buff,
                                               request->data_size,
                                               filter ) ; 
              FALSE_RET_FALSE((*ok)) ;
            }
 
         /*
          *  return ok
          */
         return TRUE ;
      }


   /* ................................................................. */


