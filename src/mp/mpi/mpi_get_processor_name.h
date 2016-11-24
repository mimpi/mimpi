

#ifndef MPI_GET_PROCESSOR_NAME_H
#define MPI_GET_PROCESSOR_NAME_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_comm.h"


   /* ... Const. / Constantes ......................................... */

      #define MPI_MAX_PROCESSOR_NAME 256


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Places in name the current processor name.
       *
       * @param name
       * @param result_len
       *
       * @see MPI_Init()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Get_processor_name 
      ( 
        INOUT  char *name,
        INOUT  int  *result_len 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_GET_PROCESSOR_NAME_H */


