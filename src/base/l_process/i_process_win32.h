

 #ifndef I_PROCESS_WIN32_H
 #define I_PROCESS_WIN32_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_string/x_dtd.h"


 #if defined(HAVE_WINDOWS_H)

  /* ... Types / Tipos ........................................*/

     typedef
     int  t_win32_pid ;


  /* ... Const / Constantes ...................................*/

     #define  c_WIN32_PID        sizeof(t_win32_pid)


  /* ... Functions / Funciones ................................*/

      T_CHAR   *I_PROCESS_WIN32_pidToString 
      ( 
        IN  t_win32_pid     *pid
      ) ;

      void      I_PROCESS_WIN32_sleep
      (
        IN   long            msec
      ) ;

      t_win32_pid   I_PROCESS_WIN32_getpid
      (
        void
      ) ;


  /* ... Inline / Macros ......................................*/

	 #include "base/l_process/i_process_win32.m"


  /* ..........................................................*/

 #endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_PROCESS_WIN32_H */

