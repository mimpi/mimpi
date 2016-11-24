

 #ifndef MPI_BCAST_LIST_M
 #define MPI_BCAST_LIST_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define MPI_BCAST_LIST_join_thread(b,c,dt,root,comm)  \
              MPI_BCAST_LIST((b),(c),(dt),(root),(comm),MR_JOIN_THREAD)

      #define MPI_BCAST_LIST_disjoin_thread(b,c,dt,root,comm)  \
              MPI_BCAST_LIST((b),(c),(dt),(root),(comm),MR_JOINLESS_THREAD)

      #define MPI_BCAST_LIST_sync_function(b,c,dt,root,comm)  \
              MPI_BCAST_LIST((b),(c),(dt),(root),(comm),MR_SYNC_FUNCTION)

      #define MPI_BCAST_LIST_async_function(b,c,dt,root,comm)  \
              MPI_BCAST_LIST((b),(c),(dt),(root),(comm),MR_ASYNC_FUNCTION)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

