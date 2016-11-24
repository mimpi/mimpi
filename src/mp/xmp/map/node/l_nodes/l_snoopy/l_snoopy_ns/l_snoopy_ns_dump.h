

#ifndef L_SNOOPY_NS_DUMP_H
#define L_SNOOPY_NS_DUMP_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_dtd.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopyinfo.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      void  L_SNOOPY_NS_DUMP_dumpNodeInfo  
      ( 
        INOUT  int           chn,
        INOUT  t_nodeInfo   *local_node_info 
      ) ;
 
      void  L_SNOOPY_NS_DUMP_do_dump_snoopy  
      ( 
        INOUT  int           chn,
        INOUT  t_nodeInfo   *local_node_info 
      ) ;
 
 
   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SNOOPY_NS_DUMP_H */

