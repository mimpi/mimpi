

#ifndef MPI_BCAST_LIST_H
#define MPI_BCAST_LIST_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm_rank.h"
     #include "mp/mpi/mpi_comm_size.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_BCAST_LIST
      (
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm,
        IN     int           bcast_exec
      ) ;

      int MPI_BCAST_LIST_join_thread   
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int MPI_BCAST_LIST_disjoin_thread   
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int MPI_BCAST_LIST_function   
      ( 
        INOUT  void         *buf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "mp/mpi/mpi_bcast/mpi_bcast_list.m"


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_BCAST_LIST_H */


