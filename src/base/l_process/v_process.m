

 #ifndef V_PROCESS_M
 #define V_PROCESS_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #if defined(HAVE_WINDOWS_H)

           #define V_PROCESS_getpid()               \
                   I_PROCESS_WIN32_getpid()

           #define V_PROCESS_sleep(m)               \
                   I_PROCESS_WIN32_sleep(m)

           #define V_PROCESS_pidToString(pid)       \
                   I_PROCESS_WIN32_pidToString((pid))

      #else

           #define V_PROCESS_getpid()               \
                   I_PROCESS_POSIX_getpid()

           #define V_PROCESS_sleep(m)               \
                   I_PROCESS_POSIX_sleep((m))

           #define V_PROCESS_pidToString(pid)       \
                   I_PROCESS_POSIX_pidToString((pid))

      #endif


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

