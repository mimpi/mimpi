

#ifndef MPI_XMP_H
#define MPI_XMP_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ...............................*/

     #include "mp/mpi/c_mapver.h"
     #include "mp/mpi/c_const.h"
     #include "mp/mpi/c_error.h"

     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_status.h"
     #include "mp/mpi/mpi_comm.h"
     #include "mp/mpi/mpi_group.h"

     #include "mp/mpi/mpi_barrier.h"
     #include "mp/mpi/mpi_bcast.h"
     #include "mp/mpi/mpi_finalize.h"
     #include "mp/mpi/mpi_gather.h"
     #include "mp/mpi/mpi_get_processor_name.h"
     #include "mp/mpi/mpi_init.h"
     #include "mp/mpi/mpi_initialized.h"
     #include "mp/mpi/mpi_recv.h"
     #include "mp/mpi/mpi_reduce.h"
     #include "mp/mpi/mpi_allreduce.h"
     #include "mp/mpi/mpi_scatter.h"
     #include "mp/mpi/mpi_send.h"
     #include "mp/mpi/mpi_sendrecv.h"
     #include "mp/mpi/mpi_wtick.h"
     #include "mp/mpi/mpi_wtime.h"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif /* MPI_XMP_H */

