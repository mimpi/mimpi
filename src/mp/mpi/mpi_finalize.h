

#ifndef MPI_FINALIZE_H
#define MPI_FINALIZE_H

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
       * Finalize MPI instance.
       *
       * @see MPI_Finalice()
       * @see MPI_Initialized()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Finalize 
      ( 
        void 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_FINALIZE_H */


