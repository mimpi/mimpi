

#ifndef MPI_ISEND_H
#define MPI_ISEND_H

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
       * Send data asynchronously.
       *
       * @param  buf
       * @param  count
       * @param  datatype
       * @param  dest
       * @param  tag
       * @param  comm 
       *
       * @see MPI_Wait()
       * @see MPI_Irecv()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Isend 
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           dest,
        IN     int           tag,
        IN     MPI_Comm      comm,
        INOUT  MPI_Request  *req
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_ISEND_H */


