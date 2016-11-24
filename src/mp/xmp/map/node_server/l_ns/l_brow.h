

#ifndef L_BROW_H
#define L_BROW_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_authors.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_bctes.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_dump_all.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_root.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_trace_all.h"
     #include "mp/xmp/map/node_server/l_ns/l_brow/l_unknow.h"


  /* ... Functions / Funciones ................................*/

      T_BOOL   L_BROW_do_services  
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      ) ;

      T_BOOL   L_BROW_is_services  
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_BROW_H */

