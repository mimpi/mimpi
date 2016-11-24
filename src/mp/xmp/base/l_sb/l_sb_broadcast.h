

#ifndef L_SB_BROADCAST_H
#define L_SB_BROADCAST_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "console/l_trace_msg.h"
     #include "mp/xmp/base/l_sb.h"


  /* ... Functions / Funciones ............................... */

      /*
       *
       *  Broadcast 'count' bytes at 'buff' buffer,
       *  if any is 'NULL' then has no efect 
       *
       *  @param scroll bar where to send
       *  @param data to send
       *  @return total bytes writed
       *
       */
      T_INT   L_SB_broadcast   
      ( 
        IN     t_sb    *sb,
        IN     T_CHAR  *buff,
        IN     T_INT    count 
      ) ;


  /* ......................................................... */

 
 #ifdef  __cplusplus
    }
 #endif
 
#endif /* L_SB_BROADCAST_H */

