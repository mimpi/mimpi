

#ifndef MPI_STATUS_H
#define MPI_STATUS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"


   /* ... Types / Tipos ............................................... */

      typedef
      struct
      {
        int count ;
        int MPI_SOURCE ;
        int MPI_TAG ;
        int MPI_ERROR ;
      } MPI_Status ;


   /* ................................................................. */

 
 #ifdef  __cplusplus
    }
 #endif
 
#endif  /* MPI_STATUS_H */


