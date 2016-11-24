

#ifndef L_SNOOPY_NS_TRACE_H
#define L_SNOOPY_NS_TRACE_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopyinfo.h"
 
 
   /* ... Functions / Funciones ................................*/
 
      void  L_SNOOPY_NS_TRACE_setChannel
      (
        IN     t_nodeInfo   *nlocal_node_info,
        IN     int           nchn
      ) ;
 
      int   L_SNOOPY_NS_TRACE_trace         
      ( 
        IN     const char   *format,
        IN     va_list       ap
      ) ;
 
 
   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SNOOPY_NS_TRACE_H */

