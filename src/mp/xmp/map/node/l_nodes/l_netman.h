

#ifndef L_NETMAN_H
#define L_NETMAN_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodeinfo.h"
      #include "mp/xmp/map/node/l_nodes/params_xmp.h"
      #include "mp/xmp/map/node/l_nodes/l_netman/l_netid.h"
      #include "mp/xmp/map/node/l_nodes/l_netman/l_netlnk.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  Set default values.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETMAN_setup     
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
      T_BOOL   L_NETMAN_finalize  
      (  
        OUT      t_nodeInfo    *node_info  
      ) ;

      /**
       *
       *  Make a conection 'all to all'.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETMAN_linkAll   
      (  
        OUT      t_nodeInfo    *node_info  
      ) ;

      /**
       *
       *  Make a conection.
       *  Return FALSE if can NOT make connection to node 'to'.
       *
       *     @params node context.
       *     @params destination identification
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETMAN_linkTo
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          to
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
      T_INT    L_NETMAN_getSock
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          who
      ) ;

      /**
       *
       *  Return node from 'fd'
       *
       *     @params node context.
       *     @params fd as sock id
       *     @return socket asociado
       *
       */
      T_INT    L_NETMAN_getNode
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          fd
      ) ;

      /**
       *
       *  indentification is respresented
       *  as string.
       *
       *     @params node id
       *     @return elto information as string.
       *
       */
      T_CHAR  *L_NETMAN_NodeToString
      (
        IN       T_INT          who
      ) ;
 
 
   /* ... Inline / Macros ......................................*/

      #define L_NETMAN_getSock(node_info,who) \
              L_NETID_getSock(node_info,who)

      #define L_NETMAN_getNode(node_info,fd) \
              L_NETID_getNode(node_info,fd)

      #define L_NETMAN_NodeToString(who) \
              L_NETID_NodeToString(who)


   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NETMAN_H */

