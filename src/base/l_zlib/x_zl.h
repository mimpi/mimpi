

#ifndef X_ZL_H
#define X_ZL_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "base/l_zlib/v_zl.h"


  /* ... Functions / Funciones ................................*/

      /** 
       *
       *  Compress buffer 'source' into a mallocated
       *  buffer '*dest' and put at '*destLen' final size.
       *
       */
      T_STATUS  X_ZL_compress_to
      ( 
        IN       void   *source,
        IN       long    sourceLen,
        OUT      void  **dest,
        OUT      long   *destLen,
        IN       int     level
      ) ;

      /** 
       *
       *  Compress buffer 'source' into a user
       *  buffer '*dest' and put at '*destLen' final size.
       *
       */
      T_STATUS  X_ZL_compress_into
      ( 
        IN       void   *source,
        IN       long    sourceLen,
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       int     level
      ) ;

      /** 
       *
       *  Uncompress buffer 'source' into a user
       *  buffer '*dest' and put at '*destLen' final size.
       *
       */
      T_STATUS  X_ZL_uncompress_into
      ( 
        IN       void   *source,
        IN       long    sourceLen,
        OUT      void   *dest,
        OUT      long   *destLen
      ) ;

      /** 
       *
       *  A change to init internal data.
       *
       */
      T_STATUS  X_ZL_init
      (
        void
      ) ;

      /** 
       *
       *  A change to finalize internal data.
       *
       */
      T_STATUS  X_ZL_finalize
      (
        void
      ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_zlib/x_zl.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* X_ZL_H */

