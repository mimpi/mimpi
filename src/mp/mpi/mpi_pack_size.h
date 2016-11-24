

#ifndef MPI_PACK_SIZE_H
#define MPI_PACK_SIZE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/l_datatype.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Get pack size needed.
       *
       * @param  incount
       * @param  datatype
       * @param  comm 
       * @param  size
       *
       * @see MPI_Recv()
       * @see MPI_Send()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Pack_size
      ( 
        IN     int incount, 
	IN     MPI_Datatype datatype, 
	IN     MPI_Comm comm,
	INOUT  int *size 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_PACK_SIZE_H */


