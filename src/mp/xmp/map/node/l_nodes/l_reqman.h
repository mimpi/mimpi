

#ifndef L_REQMAN_H
#define L_REQMAN_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "console/l_trace_msg.h"
      #include "mp/xmp/map/node/l_nodes/l_reqman/l_reqli.h"
      #include "mp/xmp/map/node/l_nodes/l_netman.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy.h"
      #include "mp/xmp/map/node/l_nodes/l_params_xmp.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  Set with default values.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_REQMAN_setup
      (
        OUT      t_nodeInfo    *node_info
      ) ;

      /**
       *
       *  Free resources.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_REQMAN_finalize
      (
        OUT      t_nodeInfo      *node_info
      ) ;

      /**
       *
       *  Get send access.
       *
       *     @params node context.
       *     @params node to send.
       *     @return TRUE if allright.
       *
       */
      t_mtsda *L_REQMAN_get_send_mtsda
      (
        INOUT    t_nodeInfo     *node_info,
	IN       int             chn
      ) ;

      /**
       *
       *  Get receive access.
       *
       *     @params node context.
       *     @params node where receive.
       *     @return TRUE if allright.
       *
       */
      t_mtsda *L_REQMAN_get_receive_mtsda
      (
        INOUT    t_nodeInfo     *node_info,
	IN       int             chn
      ) ;

      /**
       *
       *  Submit a job.
       *
       *     @params request list.
       *     @params request
       *     @params FALSE means use eslabon and TRUE
       *             means alloc a new eslabon to use.
       *             in both case, return eslabon used.
       *     @params eslabon to use if isMalloc is FALSE.
       *     @return TRUE if allright.
       *
       */
      t_reqRef *L_REQMAN_submit
      (
        INOUT   t_reqli         *reqli,
        INOUT   t_nodeReq       *request,
        IN      T_BOOL           isMalloc,
        IN      t_reqRef        *eslabon
      ) ;

      /**
       *
       *  Return a send request, waiting at queue.
       *
       *     @params request list
       *     @return a node request or NULL if not found
       *
       */
      t_nodeReq *L_REQMAN_get_send_req
      (
        INOUT   t_reqli         *reqli
      ) ;

      /**
       *
       *  Return a receive request, waiting at queue.
       *
       *     @params request list
       *     @params node header
       *     @return a node request or NULL if not found
       *
       */
      t_nodeReq *L_REQMAN_get_receive_req
      (
        INOUT   t_reqli         *reqli,
        IN      t_nodeHeader    *inHeader
      ) ;

      /**
       *
       *  Send data now, do NOT submit.
       *
       *     @params node context
       *     @params node id
       *     @params node sock
       *     @params request
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL   L_REQMAN_send_direct
      (
        INOUT    t_nodeInfo     *node_info,
        IN       T_INT           nodeid,
	IN       int             chn,
        INOUT    t_nodeReq      *send
      ) ;

      /**
       *
       *  Receive data now, do NOT submit.
       *
       *     @params node context
       *     @params node id
       *     @params node sock
       *     @params node header
       *     @params request
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL   L_REQMAN_receive_direct
      (
        INOUT    t_nodeInfo     *node_info,
        IN       T_INT           nodeid,
	IN       int             chn,
        INOUT    t_nodeHeader   *inHeader,
        INOUT    t_nodeReq      *receive
      ) ;

      /**
       *
       *  Check TAGs is equals.
       *
       *     @params request
       *     @params node header
       *     @return TRUE if equals
       *
       */
      T_BOOL   L_REQMAN_TAGEquals
      (
        IN       t_nodeReq      *request,
        IN       t_nodeHeader   *header
      ) ;

      /**
       *
       *  Search a request with same TAG than header TAG.
       *
       *     @params request list
       *     @params node header
       *     @return elto that match
       *
       */
      t_reqRef *L_REQMAN_searchTAG
      (
        IN    t_reqli       *reqli,
        IN    t_nodeHeader  *header
      ) ;
 
 
   /* ... Inline / Macros ......................................*/

      /*  mtsda  *
       * ------- */
      #define L_REQMAN_get_receive_mtsda(node_info,chn)  \
              (&(((node_info)->recvmtsda)[(chn)]))

      #define L_REQMAN_get_send_mtsda(node_info,chn)  \
              (&(((node_info)->sendmtsda)[(chn)]))


      /*  reqli  *
       * ------- */
      #define L_REQMAN_get_receive_reqli(node_info,chn)  \
              (&(((node_info)->recvli)[(chn)]))

      #define L_REQMAN_get_send_reqli(node_info,chn)  \
              (&(((node_info)->sendli)[(chn)]))


      /*  nodeHeader  *
       * ------------ */
      #define L_REQMAN_get_isinHeader(node_info,chn)  \
              (&(((node_info)->isinHeader)[(chn)]))

      #define L_REQMAN_get_inHeader(node_info,chn)  \
              (&(((node_info)->inHeader)[(chn)]))

      #define L_REQMAN_get_outHeader(node_info,chn)  \
              (&(((node_info)->outHeader)[(chn)]))


   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_REQMAN_H */

