

#ifndef L_NETID_H
#define L_NETID_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodeinfo.h"
      #include "mp/xmp/map/node/l_nodes/params_xmp.h"
 
 
   /* ... Const / Constantes ...................................*/

      /**
       *  node and sock identification
       */
      #define NID_NULL    -2
      #define NID_ERROR   -1


   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  Set with default values.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETID_init
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
      T_BOOL   L_NETID_finalize
      (
        OUT      t_nodeInfo    *node_info
      ) ;

      /**
       *
       *  Set pair (who,fd).
       *
       *     @params node context.
       *     @params who as node id
       *     @params fd as sock id
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETID_set
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          who,
        IN       T_INT          fd
      ) ;

      /**
       *
       *  Return socket from 'who'.
       *
       *     @params node context.
       *     @params who as node id
       *     @return socket asociado
       *
       */
      T_INT    L_NETID_getSock
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          who
      ) ;

      /**
       *
       *  Return node from 'fd'.
       *
       *     @params node context.
       *     @params fd as sock id
       *     @return socket asociado
       *
       */
      T_INT    L_NETID_getNode
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          fd
      ) ;

      /**
       *
       *  'who' identification is respresented
       *  as string.
       *
       *     @params node id
       *     @return elto information as string.
       *
       */
      T_CHAR  *L_NETID_NodeToString
      (
        IN       T_INT          who
      ) ;
 
 
   /* ... Inline / Macros ......................................*/

      #define L_NETID_getSock(node_info,who) \
              ((node_info->node2sock)[who])

      #define L_NETID_getNode(node_info,fd) \
              ((node_info->sock2node)[fd])

      #define L_NETID_NodeToString(who) \
              X_STRING_Dsprintf("%d",who)


   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NETID_H */

