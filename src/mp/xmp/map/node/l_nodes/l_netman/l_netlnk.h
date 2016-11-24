

#ifndef L_NETLNK_H
#define L_NETLNK_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "mp/xmp/map/node/l_nodeinfo.h"
      #include "mp/xmp/map/node/l_nodes/params_xmp.h"
      #include "mp/xmp/map/node/l_nodes/l_netman/l_netid.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      /**
       *
       *  Set default values.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETLNK_setup     
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
      T_BOOL   L_NETLNK_finalize  
      (  
        OUT      t_nodeInfo    *node_info  
      ) ;

      /**
       *
       *  Wait to a incoming conection request.
       *
       *     @params node context.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETLNK_linkIncoming
      (
        OUT      t_nodeInfo    *node_info
      ) ;

      /**
       *
       *  Wait to a outgoing conection request.
       *
       *     @params node context.
       *     @params destination identification
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NETLNK_linkOutgoing
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          who
      ) ;

 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NETLNK_H */

