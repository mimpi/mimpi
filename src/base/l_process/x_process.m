

 #ifndef X_PROCESS_M
 #define X_PROCESS_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */


      /*  Process  *
       * --------- */
      #define X_PROCESS_pidToString(pid)       \
              V_PROCESS_pidToString((pid))

      #define X_PROCESS_sleep(m)               \
              V_PROCESS_sleep((m))

      #define X_PROCESS_getpid()               \
              V_PROCESS_getpid()


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

