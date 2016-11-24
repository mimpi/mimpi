

 #ifndef MPI_SCATTER_LIST_M
 #define MPI_SCATTER_LIST_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define MPI_SCATTER_LIST_join_thread(sb,sc,sdt,rb,rc,rdt,root,comm)  \
              MPI_SCATTER_LIST((sb),(sc),(sdt),(rb),(rc),(rdt),(root),(comm),MR_JOIN_THREAD)

      #define MPI_SCATTER_LIST_disjoin_thread(sb,sc,sdt,rb,rc,rdt,root,comm)  \
              MPI_SCATTER_LIST((sb),(sc),(sdt),(rb),(rc),(rdt),(root),(comm),MR_JOINLESS_THREAD)

      #define MPI_SCATTER_LIST_sync_function(sb,sc,sdt,rb,rc,rdt,root,comm)  \
              MPI_SCATTER_LIST((sb),(sc),(sdt),(rb),(rc),(rdt),(root),(comm),MR_SYNC_FUNCTION)

      #define MPI_SCATTER_LIST_async_function(sb,sc,sdt,rb,rc,rdt,root,comm)  \
              MPI_SCATTER_LIST((sb),(sc),(sdt),(rb),(rc),(rdt),(root),(comm),MR_ASYNC_FUNCTION)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

