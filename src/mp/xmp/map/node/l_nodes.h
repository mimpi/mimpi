

#ifndef L_NODES_H
#define L_NODES_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "mp/xmp/map/node/l_nodes/l_nodecmd.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  Setup 'node_info' information using
       *  'argc' and 'argv'
       *
       *     @params node_info to setup
       *     @params argc's main
       *     @params argv's main
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODES_init
       (
         OUT      t_nodeInfo      *node_info,
         IN       int             *argc,
         IN       char          ***argv
       ) ;

      /**
       *
       *  Close, shutdown, free descriptor, etc.
       *
       *     @params node_info to end
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODES_finalize
       (
         OUT      t_nodeInfo      *node_info
       ) ;

      /**
       *
       *  Do a node request 'request' 
       *  ( send_X, receive_X, receive_ANY, ... )
       *  'nodeli' represents a node group in wich request
       *  operates.
       *
       *     @params node_info to use
       *     @params node subgroup to use
       *     @params request to do
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODES_request
       (
         INOUT    t_nodeInfo     *node_info,
         IN       T_INT          *nodeli,
         INOUT    t_nodeReq      *request
       ) ;

      /**
       *
       *  Get how many nodes are present.
       *
       *     @params node_info to use
       *     @return number of nodes
       *
       */
       T_INT    L_NODES_getNNodes
       (
         INOUT    t_nodeInfo     *node_info
       ) ;

      /**
       *
       *  Get Identification for current node.
       *
       *     @params node_info to use
       *     @return node identification
       *
       */
       T_INT    L_NODES_getId
       (
         INOUT    t_nodeInfo     *node_info
       ) ;

      /**
       *
       *  Get a Identification node list
       *
       *     @params node_info to use
       *     @return identification node list
       *
       */
       T_INT   *L_NODES_getIdList
       (
         INOUT    t_nodeInfo     *node_info
       ) ;

 
   /* ... Inline / Macros ......................................*/
 
      /*  Information  *
       * ------------- */
      #define L_NODES_getId(node_info)  \
              ((node_info)->nodeid)

      #define L_NODES_getNNodes(node_info)  \
              ((node_info)->nnodes)

 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODES_H */

