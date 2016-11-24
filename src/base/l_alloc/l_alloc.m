

 #ifndef L_ALLOC_M
 #define L_ALLOC_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define L_ALLOC_Malloc(size)                  \
              malloc((size))

      #define L_ALLOC_Free(ptr)                     \
              {                                     \
                free((*(ptr))) ;                    \
                (*(ptr)) = NULL ;                   \
              }

      #define L_ALLOC_Realloc(block,size)           \
              realloc((block),(size))

      #define L_ALLOC_MemSet(dest,value,count)      \
              memset((dest),(value),(count))

#if ( defined(__AIX__) )
      #define L_ALLOC_MemMove(dest,src,count)       \
                    bcopy((src),(dest),(count))
#else
      #define L_ALLOC_MemMove(dest,src,count)       \
                    memmove((dest),(src),(count))
#endif

      #define L_ALLOC_ChkPtr(ptr)                   \
              (ptr)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

