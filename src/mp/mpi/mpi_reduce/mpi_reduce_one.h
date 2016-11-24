

#ifndef MPI_REDUCE_ONE_H
#define MPI_REDUCE_ONE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm_rank.h"
     #include "mp/mpi/mpi_comm_size.h"
     #include "mp/mpi/mpi_reduce/mpi_reduce_op.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_REDUCE_ONE_sync_function  
      ( 
        INOUT  void         *sendbuf,
        INOUT  void         *recvbuf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           op,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_REDUCE_ONE_H */


