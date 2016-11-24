

#ifndef L_SB_H
#define L_SB_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones .............................. */

     #include "base/l_basic/c_basic.h"
     #include "console/l_trace_msg.h"
     #include "mp/xmp/base/l_sb_sock.h"


  /* ... Const / Constantes .................................. */

     #define  MAX_SOCKS   64
     #define  c_SB        sizeof(t_sb)


  /* ... Types / Tipos ....................................... */

     typedef 
     struct
     {
       int          my ;
       int          ns ;
       t_sb_sock   *sock_set [MAX_SOCKS] ;
       int          last ;
     } t_sb ;


  /* ... Functions / Funciones ............................... */

      /**
       **  init/finalize  
       **/

      /**
       *
       *  Setup with default values.
       *
       *  @params scroll bar
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_init      
      ( 
        INOUT  t_sb    *sb 
      ) ;

      /**
       *
       *  Finalize components and itself.
       *
       *  @params scroll bar
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_finalize  
      ( 
        INOUT  t_sb    *sb 
      ) ;


      /**
       **  my/ns  
       **/

      /**
       *
       *  Creat a new sock, in wich receive conection
       *  request (as a beeper to movile).
       *
       *  @params scroll bar
       *  @params my sock
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_creatMy   
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *my 
      ) ;

      /**
       *
       *  Creat a new sock, in wich receive conection
       *  request (as a beeper to movile).
       *  This is only used by scroll bar controler
       *
       *  @params scroll bar
       *  @params my sock
       *  @params host name
       *  @params port number
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_creatMy_2 
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *ns,
        INOUT  T_CHAR  *ns_host,
        INOUT  int      ns_port 
      ) ;

      /**
       *
       *  Conect to scroll bar controler and add this
       *  new socket into scroll bar.
       *
       *  @params scroll bar
       *  @params socket with scroll bar controler
       *  @params host name
       *  @params port number
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_connectToNs 
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *ns,
        INOUT  T_CHAR  *ns_host,
        INOUT  int      ns_port 
      ) ;


      /**
       **  nodes  
       **/

      /**
       *
       *  Conect with other scroll bar member, and add this
       *  new socket into scroll bar.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @params sock address
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_connectTo 
      ( 
        INOUT  t_sb           *sb,
        INOUT  int            *sock,
        INOUT  T_SOCKADDR_IN  *fdaddr 
      ) ;

      /**
       *
       *  Conect with other scroll bar member, and add this
       *  new socket into scroll bar.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_accept    
      ( 
        INOUT  t_sb    *sb,
        OUT    int     *sock 
      ) ;

      /**
       *
       *  Close conect with other scroll bar member, and remove
       *  its socket from scroll bar.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_unplug    
      ( 
        IN     t_sb    *sb,
        INOUT  int      sock 
      ) ;


      /**
       **  info nodes  
       **/

      /**
       *
       *  Return 'sock' socket descriptor.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return socket descriptor
       *
       */
      T_SOCKET            L_SB_getFd        
      ( 
        INOUT  t_sb       *sb,
        IN     int         sock 
      ) ;

      /**
       *
       *  Return 'sock' socket address.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return socket address
       *
       */
      T_SOCKADDR_IN      *L_SB_getFdAddress 
      ( 
        INOUT  t_sb       *sb,
        IN     int         sock 
      ) ;

      /**
       *
       *  Check if 'sock' is alives.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return check if alives
       *
       */
      T_INT                 L_SB_alive        
      ( 
        INOUT  t_sb       *sb,
        IN     int         sock 
      ) ;


      /**
       **  read  
       **/

      /**
       *
       *  Get a lock access in order to use it 
       *  to warranty that reads are multi-thread safe
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return nothing
       *
       */
      void    L_SB_lockRead       
      ( 
        INOUT  t_sb    *sb,
        IN     int      sock 
      ) ;

      /**
       *
       *  Get back a lock access in order to use it 
       *  to warranty that reads are multi-thread safe
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return nothing
       *
       */
      void    L_SB_unlockRead     
      ( 
        INOUT  t_sb    *sb,
        IN     int      sock 
      ) ;

      /**
       *
       *  Receive a piece of data from a member at
       *  scroll bar.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @params data to receive
       *  @params how many bytes receive
       *  @return how many bytes was received
       *
       */
      T_INT   L_SB_read           
      ( 
        IN     t_sb    *sb,
        INOUT  int      sock,
        OUT    T_CHAR  *buff,
        IN     T_INT    count 
      ) ;

      /**
       *
       *  Receive a piece of data to a member from
       *  scroll bar.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return TRUE if all right
       *
       */
      T_INT   L_SB_readAvailable  
      ( 
        IN     t_sb    *sb,
        INOUT  int      sock,
        OUT    T_CHAR  *buff,
        IN     T_INT    count 
      ) ;


      /**
       **  write  
       **/

      /**
       *
       *  Get a lock access in order to use it 
       *  to warranty that writes are multi-thread safe
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return nothing
       *
       */
      void    L_SB_lockWrite   
      ( 
        INOUT  t_sb    *sb,
        IN     int      sock 
      ) ;

      /**
       *
       *  Get back a lock access in order to use it 
       *  to warranty that writes are multi-thread safe
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return nothing
       *
       */
      void    L_SB_unlockWrite 
      ( 
        INOUT  t_sb    *sb,
        IN     int      sock 
      ) ;

      /**
       *
       *  Send a piece of data to a member from
       *  scroll bar.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @params data to send
       *  @params how many bytes send
       *  @return how many bytes was sended
       *
       */
      T_INT   L_SB_write       
      ( 
        IN     t_sb    *sb,
        INOUT  int      sock,
        IN     T_CHAR  *buff,
        IN     T_INT    count 
      ) ;


      /**
       **  collective  
       **/

      /**
       *
       *  Count how many members are alives.
       *
       *  @params scroll bar
       *  @return how may are alives
       *
       */
      T_INT   L_SB_alives            
      ( 
        INOUT  t_sb    *sb 
      ) ;

      /**
       *
       *  Wait to any event at scroll bar members.
       *
       *  @params scroll bar
       *  @params socket with other member
       *  @return TRUE if all right
       *
       */
      T_BOOL  L_SB_select            
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *sock 
      ) ;

      /**
       *
       *  Send a piece of data to all member from
       *  scroll bar.
       *
       *  @params scroll bar
       *  @params data to send
       *  @params how many bytes send each member
       *  @return total bytes sends.
       *
       */
      T_INT   L_SB_broadcast         
      ( 
        IN     t_sb    *sb,
        IN     T_CHAR  *buff,
        IN     T_INT    count 
      ) ;


  /* ... Inline / Macros ..................................... */

      #include "mp/xmp/base/l_sb.m"


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif

