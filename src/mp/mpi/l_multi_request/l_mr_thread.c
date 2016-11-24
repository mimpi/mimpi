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

      #include "mp/mpi/l_multi_request/l_mr_thread.h"


   /* ... Functions / Funciones ....................................... */

      /* ----------------------------------------------------------- * 
       *                        threads zone                         *
       * ----------------------------------------------------------- */

      void *L_MR_THREAD_tSend 
      ( 
        void *param 
      )
      {
        T_BOOL        ok ;
        t_req_param   send_param ;

        /* 
         *  copy params and counter ++ 
         */
        X_THREAD_lock         ( &(((t_req_param *)param)->boot) ) ;
        X_ALLOC_MemMove( 
                         &send_param,
                         (t_req_param *)param,
                         c_REQ_PARAM 
                       ) ;
        X_THREAD_signalReady  ( &(((t_req_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_req_param *)param)->boot) ) ;


        /* 
         *  send request 
         */
        L_FILTER_REQUEST_pack_and_send
        (  
            &ok,
            &(send_param.req),
             send_param.nodeli,
             REQ_SEND_X_SYNC,
             0,
             send_param.tagY,
             send_param.filter,
             send_param.req.data_buff,
             send_param.req.data_size,
             NODE_node_id(),
             send_param.req.to
        ) ;


        /* 
         *  counter-- and signal 
         */
        if (send_param.howLaunch == MR_JOIN_THREAD)
           {
             X_THREAD_lock   ( &(((t_req_param *)param)->crash) ) ;
             ((t_req_param *)param)->counter -- ;
             if ( ((t_req_param *)param)->counter == 0)
                  X_THREAD_signalReady  ( &(((t_req_param *)param)->crash) ) ;
             X_THREAD_unlock ( &(((t_req_param *)param)->crash) ) ;
           }

        /*
         *  return 'ok'
         */
        return (void *)(long)(ok) ;
      }

      void *L_MR_THREAD_tRecv 
      ( 
        void *param 
      )
      {
        T_BOOL        ok ;
        t_req_param   recv_param ;

        /* 
         *  copy params and counter ++ 
         */
        X_THREAD_lock         ( &(((t_req_param *)param)->boot) ) ;
        X_ALLOC_MemMove( 
                         &recv_param,
                         (t_req_param *)param,
                         c_REQ_PARAM 
                       ) ;
        X_THREAD_signalReady  ( &(((t_req_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_req_param *)param)->boot) ) ;


        /* 
         *  receive request 
         */
        L_FILTER_REQUEST_recv_and_unpack
        (
          &ok,
          &(recv_param.req),
           recv_param.nodeli,
           REQ_RECEIVE_X_SYNC,
           0,
           recv_param.tagY,
           recv_param.filter,
           recv_param.req.data_buff,
           recv_param.req.data_size,
           recv_param.req.from,
           NODE_node_id()
        ) ;


        /* 
         *  counter-- and signal 
         */
        if (recv_param.howLaunch == MR_JOIN_THREAD)
           {
             X_THREAD_lock   ( &(((t_req_param *)param)->crash) ) ;
             ((t_req_param *)param)->counter -- ;
             if ( ((t_req_param *)param)->counter == 0)
                  X_THREAD_signalReady  ( &(((t_req_param *)param)->crash) ) ;
             X_THREAD_unlock ( &(((t_req_param *)param)->crash) ) ;
           }

        /*
         *  return 'ok'
         */
        return (void *)(long)(ok) ;
      }


      /* ----------------------------------------------------------- * 
       *                      requests inteface                      *
       * ----------------------------------------------------------- */

      T_BOOL  L_MR_THREAD_init      
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
         X_THREAD_init( &(param->boot) ) ;
         X_THREAD_init( &(param->crash) ) ;
         X_THREAD_setReady( &(param->boot) ) ;
         X_THREAD_setReady( &(param->crash) ) ;

         /*
          *  return ok
          */
         return TRUE ;
      }
 
      T_BOOL  L_MR_THREAD_finalize 
      ( 
        t_req_param   *param 
      )
      {
         /*
          *  check params  
          */
         NULL_RET_TRUE(param) ;

         /*
          *  if need join -> wait all request are finished
          */
         if (param->howLaunch == MR_JOIN_THREAD)
            {
              X_THREAD_lock      ( &(param->crash) ) ;
              X_THREAD_waitReady ( &(param->crash) ) ;
              X_THREAD_unlock    ( &(param->crash) ) ;
            }

         /*
          *  finalize boot and crash
          */
         X_THREAD_destroy   ( &(param->boot) ) ;
         X_THREAD_destroy   ( &(param->crash) ) ;

         /*
          *  return ok
          */
         return TRUE ;
      }

      T_BOOL  L_MR_THREAD_send      
      ( 
        t_req_param   *param 
      )
      {
         T_BOOL     ok ;
         T_THREAD   thid ;

         /*
          *  counter++  
          */
         X_THREAD_lock         ( &(param->crash) ) ;
         X_THREAD_setNotReady  ( &(param->crash) ) ;
         ((t_req_param *)param)->counter ++ ;
         X_THREAD_unlock       ( &(param->crash) ) ;
  
         /*
          *  thread++  
          */
         X_THREAD_setNotReady( &(param->boot) ) ;
         ok = X_THREAD_createDetached( &(thid),
                                        (t_thcode)L_MR_THREAD_tSend,
                                        (void *)param ) ;
         FALSE_RET_FALSE(ok) ;
         X_THREAD_lock       ( &(param->boot) ) ;
         X_THREAD_waitReady  ( &(param->boot) ) ;
         X_THREAD_unlock     ( &(param->boot) ) ;

         /*
          *  return 'ok'
          */
         return ok ;
      }

      T_BOOL  L_MR_THREAD_recv
      ( 
        t_req_param  *param 
      )
      {
         T_BOOL     ok ;
         T_THREAD   thid ;

         /*
          *  counter++
          */
         X_THREAD_lock         ( &(param->crash) ) ;
         X_THREAD_setNotReady  ( &(param->crash) ) ;
         ((t_req_param *)param)->counter ++ ;
         X_THREAD_unlock       ( &(param->crash) ) ;
 
         /*
          *  thread++
          */
         X_THREAD_setNotReady( &(param->boot) ) ;
         ok = X_THREAD_createDetached( &(thid),
                                        (t_thcode)L_MR_THREAD_tRecv,
                                        (void *)param ) ;
         FALSE_RET_FALSE(ok) ;
         X_THREAD_lock       ( &(param->boot) ) ;
         X_THREAD_waitReady  ( &(param->boot) ) ;
         X_THREAD_unlock     ( &(param->boot) ) ;

         /*
          *  return ok  
          */
         return ok ;
      }


   /* ................................................................. */


