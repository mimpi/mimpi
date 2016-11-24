

#ifndef L_NSINFO_H
#define L_NSINFO_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/base/l_sb.h"
     #include "mp/xmp/map/node_server/l_ns/l_nodeli.h"


  /* ... Type / Tipos .........................................*/

     typedef
     struct
     {
        t_sb          sb ;
        t_nodeli      nodeli ;
        T_BOOL        shutdown ;
     } t_nsInfo ;


  /* ... Const / Constantes ...................................*/

     #define c_NSINFO              (sizeof(t_nsInfo))


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NSINFO_H */

