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

      #include "mp/mpi/l_multi_request/l_mr_async.h"


   /* ... Functions / Funciones ....................................... */

      /* ----------------------------------------------------------- *
       *                       request vector                        *
       * ----------------------------------------------------------- */

      t_req_param   *L_MR_ASYNC_addReq
      ( 
        t_req_param   *param 
      )
      {
         t_req_param *q_new ;

         /*
          *  check vector
          */
         if (param->q_size <= param->q_i)
            {
              /*
               *  request new size
               */
              q_new = X_ALLOC_Realloc
                      (
                        param->q,
                        (param->q_size + Q_ADD_SIZE) * c_REQ_PARAM
                      ) ;
              NULL_RET_NULL(q_new) ;

              /*
               *  update
               */
              param->q       = q_new ;
              param->q_size += Q_ADD_SIZE ;
            }

         /*
          *  get reference
          */
         q_new = &(param->q[param->q_i]) ;
         (param->q_i)++ ;

         /*
          *  copy request
          */
         X_ALLOC_MemMove(
                          q_new,
                          param,
                          c_REQ_PARAM
                        ) ;

         /*
          *  return request reference
          */
         return q_new ;
      }


      /* ----------------------------------------------------------- *
       *                      requests inteface                      *
       * ----------------------------------------------------------- */

      T_BOOL  L_MR_ASYNC_init      
      ( 
        t_req_param   *param 
      )
      {
         /*
          *  check params  
          */
         NULL_RET_FALSE(param) ;

         /*
          *  default values
          */
         param->q = X_ALLOC_Malloc(Q_INITIAL_SIZE * c_REQ_PARAM) ;
         NULL_RET_FALSE(param->q) ;
         param->q_i    = 0 ;
         param->q_size = Q_INITIAL_SIZE ;

         /*
          *  return ok
          */
         return TRUE ;
      }
 
      T_BOOL  L_MR_ASYNC_finalize 
      ( 
        t_req_param   *param 
      )
      {
         T_INT   i ;
         T_BOOL  ok, rok ;
         t_req_param   *p_new ;

         /*
          *  check params  
          */
         NULL_RET_TRUE(param) ;

         /*
          *  wait all
          */
         rok = TRUE ;
         for (i=0; i<param->q_i; i++)
         {
           p_new = &(param->q[i]) ;

           L_FILTER_REQUEST_wait( &ok, 
                                  &(p_new->req),
                                  &(p_new->filter) ) ;
           if (ok == FALSE)
               rok = FALSE ;
         }

         /*
          *  free
          */
         X_ALLOC_Free((void **) &(param->q)) ;
         param->q      = NULL ;
         param->q_size = 0 ;
         param->q_i    = 0 ;

         /*
          *  return 'rok'
          */
         return rok ;
      }

      T_BOOL  L_MR_ASYNC_send      
      ( 
        t_req_param   *param 
      )
      {
         T_BOOL       ok ;
         t_req_param *p_new ;

         /*
          *  add request
          */
         p_new = L_MR_ASYNC_addReq(param) ; 
         NULL_RET_FALSE(p_new) ;

         /*
          *  do request
          */
         L_FILTER_REQUEST_pack_and_send
         (
           &ok,
           &(p_new->req),
            (param->nodeli),
            REQ_SEND_X_ASYNC,
            (0),
            (param->tagY),
            (param->filter),
            (param->req).data_buff,
            (param->req).data_size,
            (NODE_node_id()),
            (param->req).to
         ) ;

         /*
          *  return 'ok'
          */
         return ok ;
      }

      T_BOOL  L_MR_ASYNC_recv
      ( 
        t_req_param  *param 
      )
      {
         T_BOOL       ok ;
         t_req_param *p_new ;

         /*
          *  add request
          */
         p_new = L_MR_ASYNC_addReq(param) ; 
         NULL_RET_FALSE(p_new) ;

         /*
          *  do request
          */
         L_FILTER_REQUEST_recv_and_unpack
         (
           &ok,
           &(p_new->req),
            (param->nodeli),
            REQ_RECEIVE_X_ASYNC,
            (0),
            (param->tagY),
            (param->filter),
            ((param->req).data_buff),
            ((param->req).data_size),
            ((param->req).from),
            (NODE_node_id())
         ) ;

         /*
          *  return 'ok'
          */
         return ok ;
      }


   /* ................................................................. */

