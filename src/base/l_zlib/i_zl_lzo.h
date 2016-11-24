

#ifndef I_ZL_LZO_H
#define I_ZL_LZO_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "base/l_debug/l_debug.h"
     #include "base/l_alloc/x_alloc.h"
     #include "base/l_zlib/l_zl.h"


  /* ... Functions / Funciones ............................... */

      T_STATUS  I_ZL_LZO_compress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen,
        IN       int     level
      ) ;

      T_STATUS  I_ZL_LZO_uncompress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen
      ) ;

      T_STATUS  I_ZL_LZO_init
      (
        void
      ) ;

      T_STATUS  I_ZL_LZO_finalize
      (
        void
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_ZL_LZO_H */

