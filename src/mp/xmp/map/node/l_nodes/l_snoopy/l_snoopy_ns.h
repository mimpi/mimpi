

#ifndef L_SNOOPY_NS_H
#define L_SNOOPY_NS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_debug/l_debug.h"
      #include "console/l_stack_msg.h"
      #include "console/l_condition_msg.h"
      #include "mp/xmp/map/node/l_nodes/l_reqman.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopyinfo.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_ns/l_snoopy_ns_dump.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_ns/l_snoopy_ns_trace.h"
 
 
   /* ... Functions / Funciones ................................*/
 
       void  L_SNOOPY_NS_nsSnoopy
       (
         INOUT  t_snoopy_info  *snoopy_info
       ) ;
 
 
   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SNOOPY_NS_H */

