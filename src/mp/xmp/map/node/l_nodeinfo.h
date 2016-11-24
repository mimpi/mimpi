

#ifndef L_NODEINFO_H
#define L_NODEINFO_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_dtd.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node_server/l_nsi.h"
      #include "mp/xmp/map/node/l_nodes/l_nodei.h"
      #include "mp/xmp/map/node/l_nodes/l_reqman/l_reqli.h"
 
 
   /* ... Types / Tipos ........................................*/
 
      typedef
      struct
      {
 
         /**
          *  subnet
          */
         t_sb             sb ;
         T_INT            nodeid ;
         T_INT            nnodes ;
         T_BOOL           shutdown ;

         /**
          *  link tables
          */
         T_INT            node2sock[MAX_SOCKS] ;
         T_INT            sock2node[MAX_SOCKS] ;
         t_mtsda          linked[MAX_SOCKS] ;

         /**
          *  request lists
          */
         t_reqli          recvli[MAX_SOCKS] ;
         t_reqli          sendli[MAX_SOCKS] ;
         t_mtsda          recvmtsda[MAX_SOCKS] ;
         t_mtsda          sendmtsda[MAX_SOCKS] ;

         /**
          *  header pool
          */
         t_nodeHeader     inHeader[MAX_SOCKS] ;
         t_nodeHeader     outHeader[MAX_SOCKS] ;
         T_BOOL           isinHeader[MAX_SOCKS] ;

      } t_nodeInfo ;
 
 
   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  't_nodeInfo' information is respresented
       *  as string.
       *
       *     @params node info to inspect
       *     @return node information as string
       *
       */
      T_CHAR *L_NODEINFO_nodeinfoToString
      (
        IN    t_nodeInfo *nodeinfo
      ) ;

 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODEINFO_H */

