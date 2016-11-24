

#ifndef L_NS_PARAMS_H
#define L_NS_PARAMS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/map/node_server/l_ns/l_ns_params/l_ns_params_sb.h"
     #include "mp/xmp/map/node_server/l_nsinfo.h"
     #include "mp/xmp/map/node_server/l_ns/l_ns_params/l_params_ns.h"


  /* ... Functions / Funciones ................................*/

      T_BOOL   L_NS_PARAMS_init      
      ( 
        IN     int            argc,
        IN     char         **argv 
      ) ;

      t_params_ns   *L_PARAMS_NS_getParams 
      ( 
        void 
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif /* L_NS_PARAMS_H */

