

#ifndef MPI_BARRIER_H
#define MPI_BARRIER_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_barrier/mpi_barrier_48h.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       *  Barrier.
       *
       *  @param  comm  communicator
       *
       *  @return MPI_STATUS
       *
       */

      int MPI_Barrier 
      ( 
        MPI_Comm comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_BARRIER_H */


