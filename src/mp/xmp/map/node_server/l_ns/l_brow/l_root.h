

#ifndef L_ROOT_H
#define L_ROOT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_bctes.h"


  /* ... Functions / Funciones ................................*/

      T_BOOL   L_ROOT_root             
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_ROOT_H */

