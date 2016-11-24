

#ifndef MPI_WAIT_H
#define MPI_WAIT_H

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


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Wait untill request end.
       *
       * @param  mpi_req
       * @param  status
       *
       * @see MPI_Isend()
       * @see MPI_Iwait()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Wait
      ( 
        INOUT  MPI_Request  *mpi_req,
        INOUT  MPI_Status   *status
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_WAIT_H */


