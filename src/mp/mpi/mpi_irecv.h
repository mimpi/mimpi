

#ifndef MPI_IRECV_H
#define MPI_IRECV_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_society.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_request.h"
     #include "mp/mpi/mpi_start.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Receive data asynchronous.
       *
       * @param  buffer
       * @param  count
       * @param  datatype
       * @param  source
       * @param  tag
       * @param  comm
       * @param  request
       *
       * @see MPI_Send()
       * @see MPI_SendRecv()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Irecv 
      ( 
        INOUT  void         *buffer, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           source, 
        IN     int           tag,
        IN     MPI_Comm      comm, 
        INOUT  MPI_Request  *request
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_IRECV_H */


