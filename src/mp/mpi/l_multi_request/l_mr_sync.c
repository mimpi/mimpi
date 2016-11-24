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

      #include "mp/mpi/l_multi_request/l_mr_sync.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL  L_MR_SYNC_init      
      ( 
        t_req_param   *param 
      )
      {
         /*
          *  check params  
          */
         NULL_RET_FALSE(param) ;

         /*
          *  return ok
          */
         return TRUE ;
      }
 
      T_BOOL  L_MR_SYNC_finalize 
      ( 
        t_req_param   *param 
      )
      {
         /*
          *  check params  
          */
         NULL_RET_TRUE(param) ;

         /*
          *  return 'ok'
          */
         return TRUE ;
      }

      T_BOOL  L_MR_SYNC_send      
      ( 
        t_req_param   *send_param 
      )
      {
         T_BOOL     ok ;

         /*
          *  function
          */
         L_FILTER_REQUEST_pack_and_send
         (
            &ok,
            &(send_param->req),
             (send_param->nodeli),
             REQ_SEND_X_SYNC,
             (0),
             (send_param->tagY),
             (send_param->filter),
             (send_param->req).data_buff,
             (send_param->req).data_size,
             (NODE_node_id()),
             (send_param->req).to
         ) ;

         /*
          *  return 'ok'
          */
         return ok ;
      }

      T_BOOL  L_MR_SYNC_recv
      ( 
        t_req_param  *recv_param 
      )
      {
         T_BOOL     ok ;

         /*
          *  function
          */
         L_FILTER_REQUEST_recv_and_unpack
         (
            &ok,
            &(recv_param->req),
             (recv_param->nodeli),
             REQ_RECEIVE_X_SYNC,
             (0),
             (recv_param->tagY),
             (recv_param->filter),
             ((recv_param->req).data_buff),
             ((recv_param->req).data_size),
             ((recv_param->req).from),
             (NODE_node_id())
         ) ;

        /*
         *  return 'ok'
         */
        return ok ;
      }


   /* ................................................................. */


