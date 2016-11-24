

 #ifndef L_BUFFA_H
 #define L_BUFFA_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"


   /* ... Consts / Constantes ........................................... */

      #define c_BUFFSIZE   (32*1024)


   /* ... Ahead Buffering ............................................... */
   
      /**
       *
       *  Will catenate 'ch' at end of '(*b)' buffer, and
       *  also will increment '(*cb)' in one.
       *
       *     @params buffer
       *     @params number of elements
       *     @params byte to add
       *     @return TRUE if allright
       *
       */
      T_BOOL  L_BUFFA_CatOneByteToCache   
      ( 
        INOUT  T_CHAR   **b, 
   	INOUT  T_U_INT   *cb,
   	IN     T_CHAR     ch 
      ) ;
   
      /**
       *
       *  Will catenate 'cs' first char of string 's' 
       *  at end of '(*b)' buffer, and also will 
       *  increment '(*cb)' in one.
       *
       *     @params buffer
       *     @params number of elements
       *     @params byte to add
       *     @params number of byte to add
       *     @return TRUE if allright
       *
       */
      T_BOOL  L_BUFFA_CatNBytesToCache    
      ( 
        INOUT  T_CHAR   **b,
   	INOUT  T_U_INT   *cb,
   	IN     T_CHAR    *s, 
        IN     T_U_INT    cs 
      ) ;
   
      /**
       *  Change buffer size to 'cb'.
       *
       *     @params buffer
       *     @params number of elements
       *     @return TRUE if allright
       *
       */
      T_BOOL  L_BUFFA_AjustCache          
      ( 
        INOUT  T_CHAR   **b,
        IN     T_U_INT    cb 
      ) ;
   

   /* ... Inline / Macros ............................................... */

      #include "base/l_adt/l_buffa.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

