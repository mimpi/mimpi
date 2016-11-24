

#ifndef L_NODE_H
#define L_NODE_H

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
     #include "mp/xmp/map/node_server/l_ns/l_node/l_do_creat.h"
     #include "mp/xmp/map/node_server/l_ns/l_node/l_do_default.h"
     #include "mp/xmp/map/node_server/l_ns/l_node/l_do_disc.h"
     #include "mp/xmp/map/node_server/l_ns/l_node/l_do_match.h"
     #include "mp/xmp/map/node_server/l_ns/l_node/l_do_open.h"
     #include "mp/xmp/map/node_server/l_ns/l_node/l_do_unlink.h"
     #include "mp/xmp/map/node_server/l_ns/l_node/l_go_debug.h"


  /* ... Functions / Funciones ................................*/

      T_BOOL   L_NODE_do_services    
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd,
        INOUT   int          *dsd 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODE_H */

