

#ifndef PARAMS_MPI_H
#define PARAMS_MPI_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/mpi/node.h"
     #include "mp/mpi/l_params_mpi.h"


  /* ... Functions / Funciones ................................*/

     T_BOOL             PARAMS_MPI_put 
     ( 
        IN     int            argc,
        IN     char         **argv 
     ) ;

     t_params_mpi      *PARAMS_MPI_getParams 
     ( 
       void 
     ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    extern "C" {
 #endif
 
#endif

