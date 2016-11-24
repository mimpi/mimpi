

#ifndef MPI_GATHER_H
#define MPI_GATHER_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/params_mpi.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/mpi_gather/mpi_gather_list.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Receive fragments of data.
       *
       * @param  sendbuf
       * @param  sendcount
       * @param  senddatatype
       * @param  recvbuf
       * @param  recvcount
       * @param  recvdatatype
       * @param  root
       * @param  comm
       *
       * @see MPI_Scatter()
       *
       * @return MPI_SUCCESS if all right.
       */

      int   MPI_Gather      
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_GATHER_H */


