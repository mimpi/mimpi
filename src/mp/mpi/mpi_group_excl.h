

#ifndef MPI_GROUP_EXCL_H
#define MPI_GROUP_EXCL_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_society.h"
     #include "mp/mpi/mpi_group.h"


   /* ... Functions / Funciones ....................................... */

      int     MPI_Group_excl       
      ( 
        MPI_Group  group,
        long       nMembers,
        long      *ranks,
        MPI_Group *newgroup 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_GROUP_EXCL_H */


