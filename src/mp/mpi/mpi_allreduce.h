

#ifndef MPI_ALLREDUCE_H
#define MPI_ALLREDUCE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/params_mpi.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/mpi_reduce.h"
     #include "mp/mpi/mpi_bcast.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Accumulates partial results and merges all
       * ussing a reduction operation. Then, broadcast
       * final results to all process
       *
       * @param sendbuf
       * @param recvbuf
       * @param count
       * @param datatype
       * @param op
       * @param comm 
       *
       * @see MPI_Bcast()
       * @see MPI_Reduce()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Allreduce  
      ( 
        INOUT  void         *sendbuf,
        INOUT  void         *recvbuf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           op,
        IN     MPI_Comm      comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_ALLREDUCE_H */


