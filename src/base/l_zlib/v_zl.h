

 #ifndef V_ZL_H
 #define V_ZL_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Functions / Funciones ......................................... */

      T_STATUS  V_ZL_compress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen,
        IN       int     level
      ) ;

      T_STATUS  V_ZL_uncompress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen
      ) ;

      T_STATUS  V_ZL_init
      (
        void
      ) ;

      T_STATUS  V_ZL_finalize
      (
        void
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "base/l_zlib/v_zl.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

