

 #ifndef L_STRING_H
 #define L_STRING_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/l_alloc.h"


   /* ... Functions / Funciones ......................................... */

      /**  
       *
       *  Return string length.
       *  (if ('str'==NULL) --> ret 0L) 
       *
       *     @params string
       *     @return string length
       *
       */
      T_U_LONG  L_STRING_StrLen       
      ( 
        IN  T_CHAR  *str 
      ) ;

      /**  
       *
       *  Return a pointer to first occurrence of
       *  'ch' char in 'str' string 
       *
       *     @params string
       *     @params caracter
       *     @return pointer to position or NULL
       *
       */
      T_CHAR   *L_STRING_StrChr       
      ( 
        IN     T_CHAR  *str,
        IN     T_CHAR   ch 
      ) ;

      /**  
       *
       *  Like 'strcmp' but also check NULL params 
       *
       *     @params string 1
       *     @params string 2
       *     @return like strcmp
       *
       */
      T_INT     L_STRING_StrCmp       
      ( 
        IN  T_CHAR  *str1,
        IN  T_CHAR  *str2 
      ) ;

      /**  
       *
       *  Like 'strdup' and also with NULL 'str' 
       *  return NULL. 
       *
       *     @params string
       *     @return pointer to a dup.
       *
       */
      T_CHAR   *L_STRING_StrDup       
      ( 
        IN  T_CHAR  *str 
      ) ;


  /* .................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

