

#ifndef L_MULTI_REQUEST_H
#define L_MULTI_REQUEST_H

 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 
 
  /* ... Includes / Inclusiones ....................................... */

     #include "base/l_basic/c_basic.h"
     #include "mp/mpi/l_multi_request/l_mr.h"
     #include "mp/mpi/l_multi_request/l_mr_thread.h"
     #include "mp/mpi/l_multi_request/l_mr_sync.h"
     #include "mp/mpi/l_multi_request/l_mr_async.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       *  Init componets.
       *
       *  @param  how do request
       *  @param  request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_MULTI_REQUEST_init      
      ( 
        T_INT          howLaunch,
        t_req_param   *param 
      ) ;

      /**
       *
       *  Send request
       *
       *  @param  request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_MULTI_REQUEST_send      
      ( 
        t_req_param   *param 
      ) ;

      /**
       *
       *  Receive request
       *
       *  @param  request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_MULTI_REQUEST_recv      
      ( 
        t_req_param   *param 
      ) ;

      /**
       *
       *  Finalize componets.
       *
       *  @param  request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_MULTI_REQUEST_finalize  
      ( 
        t_req_param   *param 
      ) ;


   /* ................................................................. */

 
 #ifdef  __cplusplus
    }
 #endif
 

#endif  /* L_MULTI_REQUEST_H */


