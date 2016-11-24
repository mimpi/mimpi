

#ifndef L_PARAMS_NS_H
#define L_PARAMS_NS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"


  /* ... Types / Tipos ........................................*/

     typedef
     struct
     {

       /*
        * - l_sb
        */

       T_INT          nodeid ;
       T_INT          nnodes ;
       char          *host ;
       int            port ;

     } t_params_ns ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif /* L_PARAMS_NS_H */

