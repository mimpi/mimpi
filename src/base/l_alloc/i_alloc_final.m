

 #ifndef I_ALLOC_FINAL_M
 #define I_ALLOC_FINAL_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/i_alloc_final.h"


   /* ... Inline / Macros ............................................... */

      #define I_ALLOC_FINAL_Malloc(size)                  \
              L_ALLOC_Malloc(size)

      #define I_ALLOC_FINAL_Free(ptr)                     \
              L_ALLOC_Free(ptr)

      #define I_ALLOC_FINAL_Realloc(block,size)           \
              L_ALLOC_Realloc(block,size)

      #define I_ALLOC_FINAL_MemMove(dest,src,count)       \
              L_ALLOC_MemMove(dest,src,count)

      #define I_ALLOC_FINAL_MemSet(dest,value,count)      \
              L_ALLOC_MemSet(dest,value,count)

      #define I_ALLOC_FINAL_MemDup(ptr,count)             \
              I_ALLOC_MemDup(ptr,count)

      #define I_ALLOC_FINAL_AllocAndSet(count,value)      \
              I_ALLOC_AllocAndSet(count,value)

      #define I_ALLOC_FINAL_Available()                   \
              I_ALLOC_Available()

      #define I_ALLOC_FINAL_ChkPtr(ptr)                   \
              L_ALLOC_ChkPtr(ptr)


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

