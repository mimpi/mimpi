

#ifndef MPI_BCAST_TREE_H
#define MPI_BCAST_TREE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpix_math.h"
     #include "mp/mpi/mpi_comm_rank.h"
     #include "mp/mpi/mpi_comm_size.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_BCAST_TREE
      (
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm,
        IN     int           bcast_exec
      ) ;

      int MPI_BCAST_TREE_join_thread
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int MPI_BCAST_TREE_disjoin_thread
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int MPI_BCAST_TREE_function
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "mp/mpi/mpi_bcast/mpi_bcast_tree.m"


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_BCAST_TREE_H */


