

#ifndef NODE_H
#define NODE_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 
 
  /* ... Includes / Inclusiones ....................................... */

     #include "base/l_basic/c_basic.h"
     #include "base/l_alloc/x_alloc.h"
     #include "mp/xmp.h"


   /* ... Glob. var / Var. globales ................................... */

      extern t_nodeInfo   NODE_info ;
      extern T_BOOL       NODE_active ;


   /* ... Const. / Constantes ......................................... */

      #define  NR_SENDRECV   10
      #define  NR_BARRIER    20
      #define  NR_BCAST      30
      #define  NR_REDUCE     40
      #define  NR_SCATTER    50
      #define  NR_GATHER     60
      #define  NR_ALLTOALL   70


   /* ... Functions / Funciones ....................................... */

      int NODE_init
      ( 
        IN    int     *argc,
        IN    char  ***argv 
      ) ;

      int NODE_finalize
      ( 
        void 
      ) ;

      int NODE_initialized
      ( 
        void 
      ) ;

      int NODE_n_nodes
      ( 
        void 
      ) ;

      int NODE_node_id
      ( 
        void 
      ) ;

      void NODE_request
      (
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *nodereq,
        IN       T_INT      *nodeli,
        IN       T_INT       reqid,
        IN       int         tx,
        IN       int         ty,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      void NODE_wait
      (
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request
      ) ;


  /* ... Inline / Macros .............................................. */

     #define  NODE_initialized()                      \
              (NODE_active)

     #define  NODE_n_nodes()                          \
              L_NODES_getNNodes(&NODE_info)

     #define  NODE_node_id()                          \
              L_NODES_getId(&NODE_info)


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* NODE_H */


