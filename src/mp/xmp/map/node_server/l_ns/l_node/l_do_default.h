

#ifndef L_DO_DEFAULT_H
#define L_DO_DEFAULT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/base/l_sb.h"
     #include "mp/xmp/map/node_server/c_nsver.h"
     #include "mp/xmp/map/node_server/l_nsi.h"
     #include "mp/xmp/map/node_server/l_nsinfo.h"
     #include "mp/xmp/map/node_server/l_ns/l_nodeli.h"


  /* ... Functions / Funciones ................................*/

      T_BOOL   L_DO_DEFAULT_default  
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DO_DEFAULT_H */

