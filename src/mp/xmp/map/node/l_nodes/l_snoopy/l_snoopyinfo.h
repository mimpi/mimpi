

#ifndef L_SNOOPYINFO_H
#define L_SNOOPYINFO_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_thread/x_thread.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodeinfo.h"
      #include "mp/xmp/map/node/l_nodes/l_nodei.h"
      #include "mp/xmp/map/node_server/l_nsi.h"
 
 
   /* ... Types / Tipos ........................................*/
 
      typedef
      struct
      {
 
         /*
          *  work space
          */
         int           chn ;        /* my sock's descriptor */
         t_nodeInfo   *node_info ;
 
         /*
          *  start/stop
          */
         t_mtsda       boot ;
         T_BOOL       *shutdown ;   /* commond shutdown */
 
      } t_snoopy_info ;
 
 
   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SNOOPYINFO_H */

