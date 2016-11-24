

#ifndef MPI_PACK_H
#define MPI_PACK_H

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
       * Pack data.
       *
       * @param  inbuf
       * @param  incount
       * @param  datatype
       * @param  outbuf
       * @param  outsize
       * @param  position
       * @param  comm 
       *
       * @see MPI_Recv()
       * @see MPI_Send()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Pack 
      ( 
        IN     void         *inbuf, 
        IN     int           incount, 
        IN     MPI_Datatype  datatype, 
        INOUT  void         *outbuf, 
        IN     int           outsize, 
        INOUT  int          *position, 
        IN     MPI_Comm      comm
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_PACK_H */


