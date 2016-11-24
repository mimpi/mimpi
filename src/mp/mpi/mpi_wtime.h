

#ifndef MPI_WTIME_H
#define MPI_WTIME_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "base/l_time/x_time.h"


   /* ... Functions / Funciones ....................................... */

      double  MPI_Wtime 
      (
        void
      ) ;


   /* ... Inline / Macros ............................................. */

      #define  MPI_Wtime() \
               ( (double) X_TIME_GetTime_MSasSG() )


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_WTIME_H */


