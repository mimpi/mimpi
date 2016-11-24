

#ifndef MPI_GROUP_H
#define MPI_GROUP_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_society.h"


   /* ... Types / Tipos ............................................... */

      typedef
      t_society   MPI_Group ;


   /* ... Functions / Funciones ....................................... */

      T_BOOL  MPI_GROUP_belong     
      ( 
        int        member,
        long       nMembers,
        long      *ranks 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_GROUP_H */


