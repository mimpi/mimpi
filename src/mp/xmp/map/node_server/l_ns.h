

#ifndef L_NS_H
#define L_NS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/base/l_sb.h"
     #include "mp/xmp/map/node_server/c_nsver.h"
     #include "mp/xmp/map/node_server/l_nsi.h"
     #include "mp/xmp/map/node_server/l_nsinfo.h"
     #include "mp/xmp/map/node_server/l_ns/l_nodeli.h"
     #include "mp/xmp/map/node_server/l_ns/l_node.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow.h"
     #include "mp/xmp/map/node_server/l_ns/l_ns_params.h"


  /* ... Functions / Funciones ............................... */

      T_BOOL   L_NS_init      
      ( 
        IN      int        argc,
        IN      char      *argv[],
        INOUT   t_nsInfo  *nsinfo 
      ) ;

      T_BOOL   L_NS_server    
      ( 
        INOUT   t_nsInfo  *nsinfo 
      ) ;

      T_BOOL   L_NS_finalize  
      ( 
        INOUT   t_nsInfo  *nsinfo 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NS_H */

