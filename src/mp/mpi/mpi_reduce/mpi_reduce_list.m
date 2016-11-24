

 #ifndef MPI_REDUCE_LIST_M
 #define MPI_REDUCE_LIST_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define MPI_REDUCE_LIST_join_thread(sb,rb,c,dt,op,root,comm)  \
              MPI_REDUCE_LIST((sb),(rb),(c),(dt),(op),(root),(comm),MR_JOIN_THREAD)

      #define MPI_REDUCE_LIST_disjoin_thread(sb,rb,c,dt,op,root,comm)  \
              MPI_REDUCE_LIST((sb),(rb),(c),(dt),(op),(root),(comm),MR_JOINLESS_THREAD)

      #define MPI_REDUCE_LIST_sync_function(sb,rb,c,dt,op,root,comm)  \
              MPI_REDUCE_LIST((sb),(rb),(c),(dt),(op),(root),(comm),MR_SYNC_FUNCTION)

      #define MPI_REDUCE_LIST_async_function(sb,rb,c,dt,op,root,comm)  \
              MPI_REDUCE_LIST((sb),(rb),(c),(dt),(op),(root),(comm),MR_ASYNC_FUNCTION)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

