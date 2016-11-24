

#ifndef L_SNOOPY_H
#define L_SNOOPY_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodeinfo.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopyinfo.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_send.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_recv.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_ns.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_accept.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  Creat send/receive daemons that is needed
       *  in order move data across rest of nodes.
       *
       *     @params node context
       *     @params node within node context
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_SNOOPY_createComunicationDaemons
       (
         IN    t_nodeInfo  *node_info,
         IN    T_INT        ch
       ) ;
 
      /**
       *
       *  Creat control daemons that this node need.
       *
       *     @params node context
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL   L_SNOOPY_createControlDaemons
       (
         IN    t_nodeInfo  *node_info
       ) ;
 
      /**
       *
       *  Creat all daemons ( control and send/receive )
       *  for current node.
       *
       *     @params node context
       *     @return TRUE if no problem is found.
       *
       */
       T_BOOL    L_SNOOPY_createAllDaemons
       (
         IN    t_nodeInfo  *node_info
       ) ;
 
 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SNOOPY_H */

