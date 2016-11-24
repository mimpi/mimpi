

#ifndef MPI_START_H
#define MPI_START_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/node.h"
     #include "mp/mpi/l_filter_request.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/mpi_request.h"


   /* ... Functions / Funciones ....................................... */

      int     MPI_Start
      (
        INOUT     MPI_Request  *mpi_req
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_START_H */


