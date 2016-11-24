

 #ifndef L_BUFFA_M
 #define L_BUFFA_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
 

   /* ... Inline / Macros ............................................... */

      T_BOOL  L_BUFFA_F_CatOneByteToCache   ( INOUT  T_CHAR   **b, 
   		          		      INOUT  T_U_INT   *cb,
   					      IN     T_CHAR     ch ) ;

      #define L_BUFFA_CatOneByteToCache(b,cb,ch)          \
              (                                           \
                ( ((*cb) % c_BUFFSIZE) == 0 ) ?           \
                  (L_BUFFA_F_CatOneByteToCache(b,cb,ch))  \
                  :                                       \
                  (((*b)[(*cb)++]=ch),TRUE)               \
              )


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

