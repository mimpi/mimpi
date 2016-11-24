

 #ifndef I_SOCKET_WIN32_H
 #define I_SOCKET_WIN32_H

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
      SOCKET               t_win32_socket ;

      typedef
      struct sockaddr_in   t_win32_sockaddr_in ;


  /* ... Const / Constantes ...................................*/

      #define  c_WIN32_SOCKET        (sizeof(t_win32_socket))
      #define  c_WIN32_SOCKADDR_IN   (sizeof(t_win32_sockaddr_in))

      #define  SSIZE_MAX    (1024*1024)
	           /*
				* TODO: SSIZE_MAX = getsockopt(...SO_MAX_MSG_SIZE...)
				*/


  /* ... Functions / Funciones ................................*/

      /**
       **  setup
       **/
      T_BOOL     I_SOCKET_WIN32_init 
      ( 
        void
      ) ;

      T_BOOL     I_SOCKET_WIN32_finalize
      ( 
        void
      ) ;

      /**
       **  read and write
       **/
      T_INT      I_SOCKET_WIN32_read
      (
        INOUT    t_win32_socket   socket,
        OUT      T_CHAR          *buffer,
        IN       T_INT            size
      ) ;

      T_INT      I_SOCKET_WIN32_write
      (
        INOUT    t_win32_socket   socket,
        OUT      T_CHAR          *buffer,
        IN       T_INT            size
      ) ;


  /* ... Inline / Macros ......................................*/

     #include "base/l_socket/i_socket_win32.m"


  /* ..........................................................*/

 #endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_SOCKET_WIN32_H */

