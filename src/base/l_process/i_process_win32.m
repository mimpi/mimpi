

 #ifndef I_PROCESS_WIN32_M
 #define I_PROCESS_WIN32_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ............................... */

      #include "base/l_basic/c_basic.h"


  /* ... Inline / Macros ...................................... */

#if defined(HAVE_WINDOWS_H)

     #define  I_PROCESS_WIN32_getpid()               \
              _getpid()

     #define  I_PROCESS_WIN32_sleep(m)               \
              Sleep(1000 * (m))

#endif

  /* .......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_PROCESS_WIN32_M */

