

#ifndef MPI_SCATTER_LIST_H
#define MPI_SCATTER_LIST_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm_rank.h"
     #include "mp/mpi/mpi_comm_size.h"


   /* ... Functions / Funciones ....................................... */

      int   MPI_SCATTER_LIST
      (
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           root,
        IN     MPI_Comm      comm,
        IN     int           scatter_exec
      ) ;

      int   MPI_SCATTER_LIST_join_thread  
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int   MPI_SCATTER_LIST_disjoin_thread  
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;

      int   MPI_SCATTER_LIST_function  
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           root,
        IN     MPI_Comm      comm 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "mp/mpi/mpi_scatter/mpi_scatter_list.m"


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_SCATTER_LIST_H */


