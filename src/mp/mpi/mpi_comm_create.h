

#ifndef MPI_COMM_CREATE_H
#define MPI_COMM_CREATE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ....................................... */

      #include "console/l_stack_msg.h"
      #include "mp/mpi/c_base.h"
      #include "mp/mpi/mpi_group.h"
      #include "mp/mpi/mpi_comm.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Comm_create        
      ( 
        IN    MPI_Comm    comm,
        IN    MPI_Group   group,
        OUT   MPI_Comm   *newcomm 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_COMM_CREATE_H */


