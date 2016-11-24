

#ifndef MPI_RECV_H
#define MPI_RECV_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_society.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_status.h"
     #include "mp/mpi/mpi_request.h"
     #include "mp/mpi/mpi_start.h"
     #include "mp/mpi/mpi_wait.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Receive data.
       *
       * @param  buf
       * @param  count
       * @param  datatype
       * @param  source
       * @param  tag
       * @param  comm
       * @param  status
       *
       * @see MPI_Send()
       * @see MPI_SendRecv()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Recv 
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           source,
        IN     int           tag,
        IN     MPI_Comm      comm,
        IN     MPI_Status   *status 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_RECV_H */


