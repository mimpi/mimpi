

#ifndef MPI_ALLGATHER_H
#define MPI_ALLGATHER_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_allgather/mpi_allgather_gb.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Logical meanning is equal to MPI_Gather + MPI_Bcast.
       *
       * @param sendBuf
       * @param sendCount
       * @param sendDataType
       * @param recvBuf
       * @param recvCount
       * @param recvDataType
       * @param comm 
       *
       * @see MPI_Bcast()
       * @see MPI_Gather()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Allgather  
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     MPI_Comm      comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_ALLGATHER_H */


