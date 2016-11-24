

#ifndef MPI_REDUCE_H
#define MPI_REDUCE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/params_mpi.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/mpi_reduce/mpi_reduce_list.h"
     #include "mp/mpi/mpi_reduce/mpi_reduce_one.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Accumulates partial results and merges all
       * ussing a reduction operation.
       *
       * @param sendbuf
       * @param recvbuf
       * @param count
       * @param datatype
       * @param op
       * @param root
       * @param comm 
       *
       * @see MPI_Gather()
       * @see MPI_Scatter()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Reduce  
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

#endif  /* MPI_REDUCE_H */


