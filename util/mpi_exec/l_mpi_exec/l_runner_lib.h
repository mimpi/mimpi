

#ifndef L_RUNNER_LIB_H
#define L_RUNNER_LIB_H


  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "l_mpi_exec/l_runner_lib.h"


  /* ... Functions / Funciones ............................... */

      T_CHAR  *L_RUNNER_LIB_getValue
      ( 
        IN      T_CHAR    *value 
      ) ;

      T_BOOL   L_RUNNER_LIB_execRunner
      ( 
        IN      T_CHAR    *runnerOutput,
        IN      T_CHAR    *runnerError,
        IN      T_CHAR    *runnerName 
      ) ;

  /* ......................................................... */


#endif  /* L_RUNNER_LIB_H */

