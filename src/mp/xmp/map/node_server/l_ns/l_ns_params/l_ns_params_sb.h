

#ifndef L_NS_PARAMS_SB_H
#define L_NS_PARAMS_SB_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "base/l_alloc/x_alloc.h"
     #include "console/l_trace_msg.h"
     #include "mp/xmp/map/node_server/l_ns/l_ns_params/l_params_ns.h"


  /* ... Functions / Funciones ................................*/

      T_BOOL  L_NS_PARAMS_SB_put      
      ( 
        IN     int           argc,
        IN     char        **argv,
        OUT    t_params_ns  *paramli 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NS_PARAMS_SB_H */

