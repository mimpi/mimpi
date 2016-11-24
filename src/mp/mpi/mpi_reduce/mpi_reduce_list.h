

#ifndef MPI_REDUCE_LIST_H
#define MPI_REDUCE_LIST_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm_rank.h"
     #include "mp/mpi/mpi_comm_size.h"
     #include "mp/mpi/mpi_reduce/mpi_reduce_op.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_REDUCE_LIST
      (
        INOUT  void         *sendbuf,
        INOUT  void         *recvbuf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           op,
        IN     int           root,
        IN     MPI_Comm      comm,
        IN     int           reduce_exec
      ) ;

      int MPI_REDUCE_LIST_join_thread
      ( 
        INOUT  void         *sendbuf,
        INOUT  void         *recvbuf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           op,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int MPI_REDUCE_LIST_disjoin_thread
      ( 
        INOUT  void         *sendbuf,
        INOUT  void         *recvbuf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           op,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int MPI_REDUCE_LIST_function 
      ( 
        INOUT  void         *sendbuf,
        INOUT  void         *recvbuf,
        IN     int           count,
        IN     MPI_Datatype  datatype,
        IN     int           op,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "mp/mpi/mpi_reduce/mpi_reduce_list.m"


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_REDUCE_LIST_H */


