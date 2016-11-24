

#ifndef MPI_WTICK_H
#define MPI_WTICK_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "base/l_time/x_time.h"


   /* ... Functions / Funciones ....................................... */

      double  MPI_Wtick 
      ( 
        void 
      ) ;


   /* ... Inline / Macros ............................................. */

      #define  MPI_Wtick() \
               ( (double) X_TIME_Get_tick() )


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_WTICK_H */


