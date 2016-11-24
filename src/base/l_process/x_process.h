

 #ifndef X_PROCESS_H
 #define X_PROCESS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_process/v_process.h"


  /* ... Functions / Funciones ................................*/

      T_PID     X_PROCESS_getpid
      ( 
        void
      ) ;

      void      X_PROCESS_sleep
      ( 
        IN    long   msec
      ) ;

      T_CHAR   *X_PROCESS_pidToString 
      ( 
        IN  T_PID     *pid
      ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_process/x_process.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* X_PROCESS_H */

