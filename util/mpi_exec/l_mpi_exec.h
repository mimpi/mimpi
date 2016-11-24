

#ifndef L_MPI_EXEC_H
#define L_MPI_EXEC_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "base/l_string/x_string.h"
     #include "l_mpi_exec/l_sh_xmp.h"
     #include "l_mpi_exec/l_rsh_xmp.h"
     #include "l_mpi_exec/l_poe_nmpi.h"
     #include "l_mpi_exec/l_poe_mpich.h"
     #include "l_mpi_exec/l_poe_xmp.h"
     #include "l_mpi_exec/l_mpirun_mpich.h"
     #include "l_mpi_exec/l_xmprun_xmp.h"


  /* ... Functions / Funciones ............................... */

      T_BOOL   L_MPI_EXEC_main ( void ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
          }
 #endif

#endif  /* L_MPI_EXEC_H */

