

#ifndef MPI_UNPACK_H
#define MPI_UNPACK_H

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
       * Unpack data.
       *
       * @param  inbuf
       * @param  insize
       * @param  position
       * @param  outbuf
       * @param  outcount
       * @param  datatype
       * @param  comm 
       *
       * @see MPI_Recv()
       * @see MPI_Send()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Unpack 
      ( 
        IN     void         *inbuf, 
        IN     int           insize, 
        INOUT  int          *position, 
        INOUT  void         *outbuf, 
        IN     int           outcount, 
        IN     MPI_Datatype  datatype, 
        IN     MPI_Comm      comm
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_UNPACK_H */


