

 #ifndef V_SOCKET_M
 #define V_SOCKET_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_socket/v_socket.h"


   /* ... Inline / Macros ............................................... */

      #if defined(HAVE_WINDOWS_H)

          /**
       	   **  init and finalize
     	   **/
          #define  V_SOCKET_init()                         \
                   I_SOCKET_WIN32_init()

          #define  V_SOCKET_finalize()                     \
                   I_SOCKET_WIN32_finalize()


          /**
       	   **  read and write
     	   **/
          #define  V_SOCKET_read(s,b,lb)                   \
		           recv((s),(b),(lb),0)   

          #define  V_SOCKET_write(s,b,lb)                  \
                   send((s),(b),(lb),0)   

      #else

          /**
       	   **  init and finalize
     	   **/
          #define  V_SOCKET_init()                         \
                   I_SOCKET_POSIX_init()

          #define  V_SOCKET_finalize()                     \
                   I_SOCKET_POSIX_finalize()


          /**
       	   **  read and write
     	   **/
          #define  V_SOCKET_read(s,b,lb)                   \
                   I_SOCKET_POSIX_read((s),(b),(lb))

          #define  V_SOCKET_write(s,b,lb)                  \
                   I_SOCKET_POSIX_write((s),(b),(lb))

      #endif


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

