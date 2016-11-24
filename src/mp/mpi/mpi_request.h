

#ifndef MPI_REQUEST_H
#define MPI_REQUEST_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/node.h"
     #include "mp/mpi/l_filter_request.h"
     #include "mp/mpi/l_datatype.h"
     #include "mp/mpi/mpi_comm.h"


   /* ... Types / Tipos ............................................... */

      typedef
      struct 
      {

         t_nodeReq      n_req ;
         MPI_Comm       comm ;
         T_BOOL         ok ;
         T_INT          reqid ;
         int            tx ;
         int            ty ;
         int            filter ;
         char          *data_buff ;
         MPI_Datatype   data_type ;
         int            data_size ;
         int            from ;
         int            to ;

      } MPI_Request ;


   /* ... Functions / Funciones ....................................... */

      int     MPI_REQUEST_init
      ( 
        INOUT     MPI_Request  *MPI_req,
        IN        T_BOOL        ok,
        IN        T_INT         reqid,
        IN        MPI_Comm      comm,
        IN        int           tx,
        IN        int           ty,
        IN        int           filter,
        IN        char         *data_buff,
        IN        MPI_Datatype  data_type,
        IN        int           data_size,
        IN        int           from,
        IN        int           to
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_REQUEST_H */


