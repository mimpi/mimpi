

#ifndef L_SNOOPY_RECV_H
#define L_SNOOPY_RECV_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_debug/l_debug.h"
      #include "mp/xmp/map/node/l_nodes/l_netman.h"
      #include "mp/xmp/map/node/l_nodes/l_reqman.h"
      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopyinfo.h"
 
 
   /* ... Functions / Funciones ................................*/
 
       void  L_SNOOPY_RECV_recvSnoopy
       (
         INOUT  t_snoopy_info  *snoopy_info
       ) ;
 
 
   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SNOOPY_RECV_H */

