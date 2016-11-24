 
 
 #ifndef L_SB_SOCK_H
 #define L_SB_SOCK_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 
 
   /* ... Includes / Inclusiones .............................. */
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_socket/x_socket.h"
      #include "base/l_thread/x_thread.h"
      #include "base/l_process/x_process.h"
      #include "console/l_trace_msg.h"
 
 
   /* ... Types / Tipos ....................................... */
 
      typedef 
      struct
      {
        t_mtsda         read_mutex ;
        t_mtsda         write_mutex ;
        T_SOCKET        fd ;
        T_SOCKADDR_IN   fdaddr ;
      } t_sb_sock ;
 
 
   /* ... Const / Constantes .................................. */
 
      #define  c_SB_SOCK      sizeof(t_sb_sock)
 
 
   /* ... Functions / Funciones ............................... */

      /**
       **  creat/destroy  
       **/

      /**
       *
       *  Alloc memory and setup with default values.
       *
       *  @params nothing
       *  @return a pointer to sb_sock
       *
       */
      t_sb_sock      *L_SB_SOCK_Creat 
      ( 
        void 
      ) ;

      /**
       *
       *  Finalize components and free itself.
       *
       *  @params a pointer to sb_sock by reference
       *  @return TRUE if all right
       *
       */
      T_BOOL          L_SB_SOCK_Destroy  
      ( 
        INOUT  t_sb_sock  **sbs 
      ) ;


      /**
       **  setup  
       **/

      /**
       *
       *  Creat a new sock, in wich receive conection
       *  request (as a beeper to movile).
       *
       *  @params sock address
       *  @params sock
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_SOCK_beeper
      ( 
        IN     T_SOCKADDR_IN       *sa,
        INOUT  t_sb_sock          **sbs 
      ) ;

      /**
       *
       *  Conect with other sock, and return this
       *  new socket into a param.
       *
       *  @params sock
       *  @params sock by reference
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_SOCK_accept    
      ( 
        INOUT  t_sb_sock           *sbs,
        OUT    t_sb_sock          **sret 
      ) ;

      /**
       *
       *  Conect with other sock, and return this
       *  new socket into a param.
       *
       *  @params sock address
       *  @params sock by reference
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_SOCK_connect   
      ( 
        INOUT  T_SOCKADDR_IN       *fdaddr,
        OUT    t_sb_sock          **sret 
      ) ;


      /**
       **  field  
       **/

      /**
       *
       *  Return 'sock' socket descriptor.
       *
       *  @params socket
       *  @return socket descriptor
       *
       */
      T_SOCKET              L_SB_SOCK_getFd        
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;

      /**
       *
       *  Return 'sock' socket address.
       *
       *  @params socket
       *  @return socket address
       *
       */
      T_SOCKADDR_IN        *L_SB_SOCK_getFdAddress 
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;

      /**
       *
       *  Check if 'sock' is alives.
       *
       *  @params socket
       *  @return check if alives
       *
       */
      T_BOOL                L_SB_SOCK_alive        
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;


      /**
       **  read  
       **/

      /**
       *
       *  Get a lock access in order to use it
       *  to warranty that reads are multi-thread safe
       *
       *  @params socket
       *  @return nothing
       *
       */
      void    L_SB_SOCK_lockRead       
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;

      /**
       *
       *  Get back a lock access in order to use it
       *  to warranty that reads are multi-thread safe
       *
       *  @params socket
       *  @return nothing
       *
       */
      void    L_SB_SOCK_unlockRead     
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;

      /**
       *
       *  Receive a piece of data from a socket.
       *
       *  @params socket
       *  @params data to receive
       *  @params how many bytes receive
       *  @return how many bytes was received
       *
       */
      T_INT   L_SB_SOCK_read           
      ( 
        IN     t_sb_sock    *sbs,
        OUT    T_CHAR       *buff,
        IN     T_INT         count 
      ) ;

      /**
       *
       *  Receive a piece of data from a socket.
       *
       *  @params socket
       *  @params data to receive
       *  @params how many bytes receive
       *  @return how many bytes was received
       *
       */
      T_INT   L_SB_SOCK_readAvailable  
      ( 
        IN     t_sb_sock    *sbs,
        OUT    T_CHAR       *buff,
        IN     T_INT         count 
      ) ;


      /**
       **  write  
       **/

      /**
       *
       *  Get back a lock access in order to use it
       *  to warranty that writes are multi-thread safe
       *
       *  @params socket
       *  @return nothing
       *
       */
      void    L_SB_SOCK_lockWrite   
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;

      /**
       *
       *  Get back a lock access in order to use it
       *  to warranty that writes are multi-thread safe
       *
       *  @params socket
       *  @return nothing
       *
       */
      void    L_SB_SOCK_unlockWrite 
      ( 
        INOUT  t_sb_sock    *sbs 
      ) ;

      /**
       *
       *  Send a piece of data to a socket.
       *
       *  @params socket
       *  @params data to receive
       *  @params how many bytes receive
       *  @return how many bytes was received
       *
       */
      T_INT   L_SB_SOCK_write       
      ( 
        IN     t_sb_sock    *sbs,
        IN     T_CHAR       *buff,
        IN     T_INT         count 
      ) ;


   /* ... Inline / Macros ..................................... */

      #include "mp/xmp/base/l_sb_sock.m"


   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif

