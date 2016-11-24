

#ifndef MPI_SENDRECV_H
#define MPI_SENDRECV_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_send.h"
     #include "mp/mpi/mpi_recv.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Send and inmediatly wait for a reply.
       *
       * @ param sendbuf
       * @ param sendcount
       * @ param senddatatype
       * @ param dest
       * @ param sendtag
       * 
       * @ param recvbuf
       * @ param recvcount
       * @ param recvdatatype
       * @ param source
       * @ param recvtag
       * 
       * @ param comm
       * @ param status 
       *
       * @see MPI_Send()
       * @see MPI_Recv()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Sendrecv
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        IN     int           dest,
        IN     int           sendtag,

        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           source,
        IN     int           recvtag,

        IN     MPI_Comm      comm,
        IN     MPI_Status   *status 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_SENDRECV_H */


