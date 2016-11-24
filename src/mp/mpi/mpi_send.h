

#ifndef MPI_SEND_H
#define MPI_SEND_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_request.h"
     #include "mp/mpi/mpi_start.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Send data.
       *
       * @param  buf
       * @param  count
       * @param  datatype
       * @param  dest
       * @param  tag
       * @param  comm 
       *
       * @see MPI_Recv()
       * @see MPI_SendRecv()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Send 
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           dest,
        IN     int           tag,
        IN     MPI_Comm      comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_SEND_H */


