

 #ifndef I_PROCESS_POSIX_H
 #define I_PROCESS_POSIX_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_string/x_dtd.h"


 #if defined(HAVE_UNISTD_H)

  /* ... Types / Tipos ........................................*/

      typedef
      pid_t  t_posix_pid ;


  /* ... Const / Constantes ...................................*/

      #define  c_POSIX_PID        sizeof(t_posix_pid)


  /* ... Functions / Funciones ................................*/

      T_CHAR   *I_PROCESS_POSIX_pidToString 
      ( 
        IN   t_posix_pid    *pid
      ) ;

      void      I_PROCESS_POSIX_sleep
      (
        IN   long            msec
      ) ;

      t_posix_pid   I_PROCESS_POSIX_getpid
      (
        void
      ) ;


  /* ... Inline / Macros ...................................... */

      #include "base/l_process/i_process_posix.m"


  /* .......................................................... */

 #endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_PROCESS_POSIX_H */

