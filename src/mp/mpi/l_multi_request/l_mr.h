

#ifndef L_MR_H
#define L_MR_H

 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 
 
  /* ... Includes / Inclusiones ....................................... */

     #include "base/l_basic/c_basic.h"
     #include "mp/mpi/l_filter_request.h"


   /* ... Types / Tipos ............................................... */

      typedef
      struct req_param t_req_param ;

      struct req_param
      {

         /*
          *  req
          */
         T_INT             howLaunch ;
         t_nodeReq         req  ;
         T_INT            *nodeli ;
         int               tagY ;
         int               filter ;

         /*
          *  threads
          */
         t_mtsda           boot ;
         t_mtsda           crash ;
         T_LONG            counter ;

         /*
          *  async
          */
         t_req_param      *q ;
         T_INT             q_i ;
         T_INT             q_size ;

      } ;


   /* ... Const. / Constantes ......................................... */

      /*
       *  datatype size
       */
      #define  c_REQ_PARAM     (sizeof(t_req_param))

      /*
       *  howLaunch  
       */
      #define  MR_JOIN_THREAD        100
      #define  MR_JOINLESS_THREAD    200
      #define  MR_SYNC_FUNCTION      300
      #define  MR_ASYNC_FUNCTION     400


   /* ................................................................. */

 
 #ifdef  __cplusplus
    }
 #endif
 

#endif  /* L_MR_H */


