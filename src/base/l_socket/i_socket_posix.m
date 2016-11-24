

 #ifndef I_SOCKET_POSIX_M
 #define I_SOCKET_POSIX_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ............................... */

      #include "base/l_basic/c_basic.h"


  /* ... Inline / Macros ...................................... */

#if defined(HAVE_UNISTD_H)

     /**
      **  init and finalize
      **/
     #define  I_SOCKET_POSIX_init()

     #define  I_SOCKET_POSIX_finalize()


     /**
      **  read and write
      **/
     #define  I_SOCKET_POSIX_read(s,b,lb)            \
              read((s),(b),(lb))

     #define  I_SOCKET_POSIX_write(s,b,lb)           \
              write((s),(b),(lb))


#endif


  /* .......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_SOCKET_POSIX_M */

