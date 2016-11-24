

#ifndef MPI_INITIALIZED_H
#define MPI_INITIALIZED_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_comm.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Check if MPI instance was ready.
       *
       * @param flag an boolean INOUT argument.
       *
       * @see MPI_Finalice()
       * @see MPI_Init()
       *
       * @return MPI_SUCCESS if was used MPI_Init before.
       */

      int MPI_Initialized 
      ( 
        int      *flag
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_INITIALIZED_H */


