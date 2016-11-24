

#ifndef L_SB_ALIVES_H
#define L_SB_ALIVES_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "console/l_trace_msg.h"
     #include "mp/xmp/base/l_sb.h"


  /* ... Functions / Funciones ............................... */

      /**
       *
       *  Count how many sockets are open at 'sb' and
       *  return it.
       *
       *  @params scroll bar
       *  @return how many sock are open
       *
       */
      T_INT   L_SB_alives   
      ( 
        INOUT  t_sb    *sb 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SB_ALIVES_H */

