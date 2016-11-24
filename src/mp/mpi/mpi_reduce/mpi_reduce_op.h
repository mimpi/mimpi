

#ifndef MPI_REDUCE_OP_H
#define MPI_REDUCE_OP_H

 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"


   /* ... Const. / Constantes ......................................... */

      #define  MPI_MAX    10
      #define  MPI_MIN    20
      #define  MPI_SUM    30
      #define  MPI_PROD   40
      #define  MPI_LAND   50
      #define  MPI_BAND   60
      #define  MPI_LOR    70
      #define  MPI_BOR    80
      #define  MPI_LXOR   90
      #define  MPI_NOP   100


   /* ... Functions / Funciones ....................................... */

      T_BOOL MPI_REDUCE_OP_ApplyReduce   
      ( 
        IN     int           op,
        IN     MPI_Datatype  datatype,
        IN     int           count,
        INOUT  void         *op1res,
        INOUT  void         *op2 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_REDUCE_OP_H */


