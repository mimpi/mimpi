

 #ifndef I_PROCESS_POSIX_M
 #define I_PROCESS_POSIX_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ............................... */

      #include "base/l_basic/c_basic.h"


  /* ... Inline / Macros ...................................... */

#if defined(HAVE_UNISTD_H)

     #define  I_PROCESS_POSIX_getpid()               \
              getpid()

     #define  I_PROCESS_POSIX_sleep(m)               \
              sleep((m))

#endif

  /* .......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_PROCESS_POSIX_M */

