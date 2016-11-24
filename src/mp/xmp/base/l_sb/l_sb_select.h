

#ifndef L_SB_SELECT_H
#define L_SB_SELECT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/base/l_sb.h"


  /* ... Functions / Funciones ............................... */

      /**
       *
       *  wait to any event at any sock inside 'sb'.
       *  'fd' point to sock where event ocurrs.
       *
       *  @params scroll bar
       *  @params sock where event ocurrs
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_select            
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *fd 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SB_SELECT_H */

