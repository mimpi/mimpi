

#ifndef L_ZL_H
#define L_ZL_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"


  /* ... Constants / Constantes .............................. */

     /*
      *  Status
      */
     #define ZL_OK              STATUS_OK
     #define ZL_ERRNO           (-1)
     #define ZL_STREAM_ERROR    (-2)
     #define ZL_DATA_ERROR      (-3)
     #define ZL_MEM_ERROR       (-4)
     #define ZL_BUF_ERROR       (-5)
     #define ZL_VERSION_ERROR   (-6)
     
     /*
      *  Compression levels
      */
     #define ZL_NO_COMPRESSION          0
     #define ZL_BEST_SPEED              1
     #define ZL_BEST_COMPRESSION        9
     #define ZL_DEFAULT_COMPRESSION  (-1)


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_ZL_H */

