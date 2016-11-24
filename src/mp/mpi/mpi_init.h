

#ifndef MPI_INIT_H
#define MPI_INIT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/params_mpi.h"
     #include "mp/mpi/mpi_comm.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Init MPI instance.
       *
       * @param p_argc a pointer to argc's main argument.
       * @param p_argv a pointer to argv's main argument.
       *
       * @see MPI_Finalice()
       * @see MPI_Initialized()
       *
       * @return MPI_SUCCESS if all right.
       */

      int MPI_Init 
      ( 
        int      *p_argc,
        char   ***p_argv 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_INIT_H */


