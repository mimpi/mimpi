

#ifndef L_MR_THREAD_H
#define L_MR_THREAD_H

 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 
 
  /* ... Includes / Inclusiones ....................................... */

     #include "base/l_basic/c_basic.h"
     #include "mp/mpi/l_multi_request/l_mr.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       *  Init componets.
       *
       *  @param  request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_MR_THREAD_init      
      ( 
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
      T_BOOL  L_MR_THREAD_send      
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
      T_BOOL  L_MR_THREAD_recv      
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
      T_BOOL  L_MR_THREAD_finalize  
      ( 
        t_req_param   *param 
      ) ;


   /* ................................................................. */

 
 #ifdef  __cplusplus
    }
 #endif
 

#endif  /* L_MR_THREAD_H */


