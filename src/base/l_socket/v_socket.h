

 #ifndef V_SOCKET_H
 #define V_SOCKET_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_socket/i_socket_win32.h"
      #include "base/l_socket/i_socket_posix.h"


  /* ... Types / Tipos ........................................*/

      #if defined(HAVE_WINDOWS_H)
           #define  T_SOCKET         t_win32_socket
           #define  T_SOCKADDR_IN    t_win32_sockaddr_in

      #else
           #define  T_SOCKET         t_posix_socket
           #define  T_SOCKADDR_IN    t_posix_sockaddr_in
      #endif


  /* ... Const / Constantes ...................................*/

      #define  c_SOCKET         (sizeof(T_SOCKET))
      #define  c_SOCKADDR_IN    (sizeof(T_SOCKADDR_IN))

      #if defined(HAVE_WINDOWS_H)
           #define  NULL_SOCKET          0
      #else
           #define  NULL_SOCKET         -1
      #endif


  /* ... Functions / Funciones ................................*/

      /**
   	   **  setup
  	   **/
      T_BOOL     V_SOCKET_init 
      ( 
        void
      ) ;

      T_BOOL     V_SOCKET_finalize
      ( 
        void
      ) ;

      /**
   	   **  read and write
  	   **/
      T_INT      V_SOCKET_read             
      ( 
        INOUT    T_SOCKET   socket,
        OUT      T_CHAR    *buffer,
        IN       T_INT      size 
      ) ;

      T_INT      V_SOCKET_write            
      ( 
        INOUT    T_SOCKET   socket,
        OUT      T_CHAR    *buffer,
        IN       T_INT      size 
      ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_socket/v_socket.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* V_SOCKET_H */

