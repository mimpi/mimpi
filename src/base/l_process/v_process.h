

 #ifndef V_PROCESS_H
 #define V_PROCESS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_process/i_process_win32.h"
      #include "base/l_process/i_process_posix.h"


  /* ... Types / Tipos ........................................*/

      #if defined(HAVE_WINDOWS_H)
           #define  T_PID   t_win32_pid
      #else
           #define  T_PID   t_posix_pid
      #endif


  /* ... Const / Constantes ...................................*/

     #define  c_PID   sizeof(T_PID)


  /* ... Functions / Funciones ................................*/

      T_PID     V_PROCESS_getpid
      ( 
        void
      ) ;

	  void      V_PROCESS_sleep
      ( 
        IN    long   msec
      ) ;

      T_CHAR   *V_PROCESS_pidToString 
      ( 
 	    IN  T_PID     *pid
      ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_process/v_process.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* V_PROCESS_H */

