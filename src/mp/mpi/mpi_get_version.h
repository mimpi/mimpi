

#ifndef MPI_GET_VERSION_H
#define MPI_GET_VERSION_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/mpi_comm.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Return current MPI interface.
       *
       * @param version
       * @param subversion
       *
       * @see MPI_Init()
       *
       * @return MPI_SUCCESS if was used MPI_Init before.
       */

      int MPI_Get_version 
      ( 
        INOUT     int   *version,
        INOUT     int   *subversion
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_GET_VERSION_H */


