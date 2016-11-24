

#ifndef MPI_GET_COUNT_H
#define MPI_GET_COUNT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_status.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Get number of items transfer.
       *
       * @param  status
       * @param  datatype
       * @param  count
       *
       * @see MPI_Recv()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Get_count 
      ( 
        IN     MPI_Status   *status,
	IN     MPI_Datatype  datatype,
	INOUT  int          *count
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_GET_COUNT_H */

