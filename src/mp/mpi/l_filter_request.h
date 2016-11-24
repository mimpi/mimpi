

#ifndef L_FILTER_REQUEST_H
#define L_FILTER_REQUEST_H

 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 
 
  /* ... Includes / Inclusiones ....................................... */

     #include "base/l_basic/c_basic.h"
     #include "base/l_zlib/x_zl.h"
     #include "mp/mpi/params_mpi.h"
     #include "mp/mpi/node.h"


   /* ... Types / Tipos ............................................... */

      typedef int t_filter ;


   /* ... Const / Constantes .......................................... */

      #define c_FILTER   sizeof(t_filter)

      #define FILTER_NULL      0
      #define FILTER_COMPRESS  1

      #define FILTER_DEFAULT   (FILTER_COMPRESS | FILTER_NULL)


   /* ... Functions / Funciones ....................................... */

      /**
       *
       *  Send request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_send_x_sync
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /**
       *
       *  Receive request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_receive_x_sync
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /**
       *
       *  Receive request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_receive_any_sync
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /**
       *
       *  Send request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_send_x_async
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /**
       *
       *  Receive request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_receive_x_async
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /**
       *
       *  Receive request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_receive_any_async
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       int         tx,
        IN       int         ty,
        IN       int         filter,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /**
       *
       *  Wait request
       *
       *  @params request information
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_wait
      ( 
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        INOUT    int        *filter
      ) ;


      /**
       *
       *  Pack data with filters that belongs 
       *  to 'filter'.
       *
       *  @params data_buff  buffer 
       *  @params data_size  buffer size
       *  @params cdata_buff buffer reference
       *  @params cdata_size buffer size reference
       *  @params filter     filter to use
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_pack
      ( 
        IN       void       *data_buff,
        IN       long        data_size,
        INOUT    void      **cdata_buff,
        INOUT    long       *cdata_size,
        INOUT    int        *filter
      ) ;
      
      /**
       *
       *  Unpack data with filters that belongs 
       *  to 'filter'.
       *
       *  @params request    information
       *  @params cdata_buff buffer reference
       *  @params cdata_size buffer size reference
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_FILTER_REQUEST_unpack
      ( 
        IN       long        cdata_size,
        IN       char       *data_buff,
        IN       long        data_size,
        INOUT    int        *filter
      ) ;

      /**
       *
       *  Pack data with filters that belongs 
       *  to 'filter' and send it.
       *
       *  @params ok         result from service
       *  @params request    information
       *  @params nodeli     node list
       *  @params reqid      request identification
       *  @params tx         tag X
       *  @params ty         tag Y
       *  @params filter     filter
       *  @params data_buff  buffer 
       *  @params data_size  buffer size 
       *  @params from       from node
       *  @params to         to node
       *  @return TRUE if all right
       *
       */
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
      ) ;
      
      /**
       *
       *  Receive and unpack data with filters that 
       *  belongs to 'filter'.
       *
       *  @params ok         result from service
       *  @params request    information
       *  @params nodeli     node list
       *  @params reqid      request identification
       *  @params tx         tag X
       *  @params ty         tag Y
       *  @params filter     filter
       *  @params data_buff  buffer 
       *  @params data_size  buffer size 
       *  @params from       from node
       *  @params to         to node
       *  @return TRUE if all right
       *
       */
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
      ) ;
      

   /* ... Inline / Macros ............................................... */

      #include "mp/mpi/l_filter_request.m"


   /* ................................................................. */

 
 #ifdef  __cplusplus
    }
 #endif
 

#endif  /* L_FILTER_REQUEST_H */


