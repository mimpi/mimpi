

 #ifndef I_SOCKET_POSIX_H
 #define I_SOCKET_POSIX_H

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
      int t_posix_socket ;

      typedef
      struct sockaddr_in t_posix_sockaddr_in ;


  /* ... Const / Constantes ...................................*/

      #define  c_POSIX_SOCKET        (sizeof(t_posix_socket))
      #define  c_POSIX_SOCKADDR_IN   (sizeof(t_posix_sockaddr_in))


  /* ... Functions / Funciones ................................*/

      /**
       **  setup
       **/
      T_BOOL     I_SOCKET_POSIX_init
      (
        void
      ) ;

      T_BOOL     I_SOCKET_POSIX_finalize
      (
        void
      ) ;

      /**
       **  read and write
       **/
      T_INT      I_SOCKET_POSIX_read
      (
        INOUT    t_posix_socket   socket,
        OUT      T_CHAR          *buffer,
        IN       T_INT            size
      ) ;

      T_INT      I_SOCKET_POSIX_write
      (
        INOUT    t_posix_socket   socket,
        OUT      T_CHAR          *buffer,
        IN       T_INT            size
      ) ;


  /* ... Inline / Macros ......................................*/

     #include "base/l_socket/i_socket_posix.m"


  /* ..........................................................*/

 #endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_SOCKET_POSIX_H */

