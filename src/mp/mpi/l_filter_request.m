

 #ifndef L_FILTER_REQUEST_M
 #define L_FILTER_REQUEST_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define L_FILTER_REQUEST_send_x_sync(ok,request,nodeli,tx,ty,filter,databuff,data_size,from,to) \
              L_FILTER_REQUEST_pack_and_send(ok,request,nodeli,REQ_SEND_X_SYNC,tx,ty,filter,data_buff,data_size,from,to)

      #define L_FILTER_REQUEST_send_x_async(ok,request,nodeli,tx,ty,filter,databuff,data_size,from,to) \
              L_FILTER_REQUEST_pack_and_send(ok,request,nodeli,REQ_SEND_X_ASYNC,tx,ty,filter,data_buff,data_size,from,to)

      #define L_FILTER_REQUEST_receive_x_sync(ok,request,nodeli,tx,ty,filter,databuff,data_size,from,to) \
              L_FILTER_REQUEST_recv_and_unpack(ok,request,nodeli,REQ_RECEIVE_X_SYNC,tx,ty,filter,data_buff,data_size,from,to)

      #define L_FILTER_REQUEST_receive_any_sync(ok,request,nodeli,tx,ty,filter,databuff,data_size,from,to) \
              L_FILTER_REQUEST_recv_and_unpack(ok,request,nodeli,REQ_RECEIVE_ANY_SYNC,tx,ty,filter,data_buff,data_size,from,to)

      #define L_FILTER_REQUEST_receive_x_async(ok,request,nodeli,tx,ty,filter,databuff,data_size,from,to) \
              L_FILTER_REQUEST_recv_and_unpack(ok,request,nodeli,REQ_RECEIVE_X_ASYNC,tx,ty,filter,data_buff,data_size,from,to)

      #define L_FILTER_REQUEST_receive_any_async(ok,request,nodeli,tx,ty,filter,databuff,data_size,from,to) \
              L_FILTER_REQUEST_recv_and_unpack(ok,request,nodeli,REQ_RECEIVE_ANY_ASYNC,tx,ty,filter,data_buff,data_size,from,to)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

