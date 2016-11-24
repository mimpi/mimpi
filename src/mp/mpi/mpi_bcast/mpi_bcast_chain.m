

 #ifndef MPI_BCAST_CHAIN_M
 #define MPI_BCAST_CHAIN_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define MPI_BCAST_CHAIN_sync_function(b,c,dt,root,comm)  \
              MPI_BCAST_CHAIN((b),(c),(dt),(root),(comm),MR_SYNC_FUNCTION)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

