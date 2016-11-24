

#ifndef MPI_BCAST_H
#define MPI_BCAST_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/params_mpi.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_bcast/mpi_bcast_list.h"
     #include "mp/mpi/mpi_bcast/mpi_bcast_chain.h"
     #include "mp/mpi/mpi_bcast/mpi_bcast_tree.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       *  Broadcast.
       *
       *  @param  buf data reference
       *  @param  count how many
       *  @param  datatype datatype
       *  @param  root root id
       *  @param  comm communicator
       *
       *  @return MPI_STATUS
       *
       */

      int MPI_Bcast        
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_BCAST_H */


