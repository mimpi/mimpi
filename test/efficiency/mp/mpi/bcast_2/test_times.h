

#ifndef TEST_TIMES_H
#define TEST_TIMES_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include <stdlib.h>
     #include <stdio.h>
     #include "mpi.h"


  /* ... Functions / Funciones ................................*/

      double TEST_TIMES_getBarrierTime
      (
        /* IN    */   int n_test
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* TEST_TIMES_H */

