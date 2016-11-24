

#ifndef MPI_COMM_H
#define MPI_COMM_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ....................................... */

      #include "console/l_stack_msg.h"
      #include "mp/mpi/c_base.h"
      #include "mp/mpi/l_society.h"
      #include "mp/mpi/mpi_group.h"


   /* ... Const. / Constantes ......................................... */
 
      #define MPI_COMM_WORLD   SOCIETY_WORLD
      #define MPI_MAX_COMM     MAX_SOCIETIES


   /* ... Types / Tipos ............................................... */

      typedef
      t_society   MPI_Comm ;

 
   /* ... Functions / Funciones ....................................... */

      int MPI_COMM_init               
      ( 
        void 
      ) ;

      int MPI_COMM_finalize           
      ( 
        void 
      ) ;

      int MPI_COMM_insert             
      ( 
        IN    MPI_Comm    comm,
        IN    int         rank 
      ) ;

      int MPI_COMM_commSize           
      ( 
        IN    MPI_Comm    comm 
      ) ;

      int MPI_COMM_translate_nodeid   
      ( 
        IN    MPI_Comm    comm,
        IN    int         node_id 
      ) ;

      int MPI_COMM_translate_rank     
      ( 
        IN    MPI_Comm    comm,
        IN    int         rank 
      ) ;

      int MPI_COMM_back_rank          
      ( 
        IN    MPI_Comm    comm,
        IN    int         rank 
      ) ;

      int MPI_COMM_next_rank          
      ( 
        IN    MPI_Comm    comm,
        IN    int         rank 
      ) ;


   /* ... Inline / Macros ............................................. */

      #define  MPI_COMM_commSize(comm) \
               L_SOCIETY_getNMembers(comm)

      #define  MPI_COMM_commNodeLi(comm) \
               L_SOCIETY_getNodeLi(comm)

      #define  MPI_COMM_translate_nodeid(comm,node_id)  \
               L_SOCIETY_getMember(comm,node_id)

      #define  MPI_COMM_translate_rank(comm,rank) \
               L_SOCIETY_getMemberInfo(comm,rank)


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPI_COMM_H */


