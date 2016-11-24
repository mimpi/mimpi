

#ifndef L_NODECMD_H
#define L_NODECMD_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "base/l_thread/x_thread.h"
      #include "console/l_trace_msg.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodegrp.h"
      #include "mp/xmp/map/node/l_nodes/l_reqman.h"
      #include "mp/xmp/map/node/l_nodes/l_netman.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy.h"
      #include "mp/xmp/map/node/l_nodes/params_xmp.h"
 
 
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
       T_BOOL   L_NODECMD_init
       (
         OUT      t_nodeInfo      *node_info,
         IN       int             *argc,
         IN       char          ***argv
       ) ;

      /**
       *
       *  Close, shutdown, free descriptors, etc.
       *
       *     @params node_info to end
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_finalize
       (
         OUT      t_nodeInfo      *node_info
       ) ;

      /**
       *
       *  Send request.
       *
       *     @params node_info to use
       *     @params request to do
       *     @params node subgroup to use
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_send_X_sync
       (
         INOUT    t_nodeInfo     *node_info,
         INOUT    t_nodeReq      *send,
         INOUT    T_INT          *node2sock
       ) ;

      /**
       *
       *  Send request but in a asyncronous way.
       *
       *     @params node_info to use
       *     @params request to do
       *     @params node subgroup to use
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_send_X_async
       (
         INOUT    t_nodeInfo     *node_info,
         INOUT    t_nodeReq      *send,
         INOUT    T_INT          *node2sock
       ) ;

      /**
       *
       *  Receive request.
       *
       *     @params node_info to use
       *     @params request to do
       *     @params node subgroup to use
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_receive_X_sync
       (
         INOUT    t_nodeInfo     *node_info,
         INOUT    t_nodeReq      *receive,
         INOUT    T_INT          *node2sock
       ) ;

      /**
       *
       *  Receive request but in a asyncronous way.
       *
       *     @params node_info to use
       *     @params request to do
       *     @params node subgroup to use
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_receive_X_async
       (
         INOUT    t_nodeInfo     *node_info,
         INOUT    t_nodeReq      *receive,
         INOUT    T_INT          *node2sock
       ) ;

      /**
       *
       *  Receive request from ANY.
       *
       *     @params node_info to use
       *     @params request to do
       *     @params node subgroup to use
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_receive_ANY_sync
       (
         INOUT    t_nodeInfo     *node_info,
         INOUT    t_nodeReq      *receive,
         INOUT    T_INT          *node2sock
       ) ;

      /**
       *
       *  Receive request from ANY, but in a asyncronous way.
       *
       *     @params node_info to use
       *     @params request to do
       *     @params node subgroup to use
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_receive_ANY_async
       (
         INOUT    t_nodeInfo     *node_info,
         INOUT    t_nodeReq      *receive,
         INOUT    T_INT          *node2sock
       ) ;

      /**
       *
       *  Wait untill a asyncronous request end.
       *
       *     @params request to wait
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_NODECMD_wait
       (
         INOUT    t_nodeReq      *preq
       ) ;

      /**
       *
       *  Return values that configures this library.
       *
       *     @params nothing
       *     @return params table
       *
       */
       t_params_xmp  *L_NODECMD_getParams
       (
         void
       ) ;

 
   /* ... Inline / Macros ......................................*/
 
      #define L_NODECMD_getParams \
              PARAMS_XMP_getParams 
 
 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODECMD_H */

