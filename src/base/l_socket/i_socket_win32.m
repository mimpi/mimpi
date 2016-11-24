

 #ifndef I_SOCKET_WIN32_M
 #define I_SOCKET_WIN32_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ............................... */

      #include "base/l_basic/c_basic.h"


  /* ... Inline / Macros ...................................... */

#if defined(HAVE_WINDOWS_H)


     /**
      **  read and write
      **/
     #define  I_SOCKET_WIN32_read(s,b,lb)            \
              recv((s),(b),(lb),0)

     #define  I_SOCKET_WIN32_write(s,b,lb)           \
              send((s),(b),(lb),0)


#endif

  /* .......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_SOCKET_WIN32_M */

