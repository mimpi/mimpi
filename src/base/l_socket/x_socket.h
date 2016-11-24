

#ifndef X_SOCKET_H
#define X_SOCKET_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "base/l_debug/l_debug.h"
     #include "base/l_alloc/x_alloc.h"
     #include "base/l_socket/v_socket.h"


  /* ... Functions / Funciones ................................*/

      /** 
       **  Address Management
       **/

      /** 
       *
       *  Return 'localhost' address as sockaddr_in. 
       *
       */
      T_BOOL   X_SOCKET_local2address    
      ( 
        OUT   T_SOCKADDR_IN       *sa,
        IN    T_INT                port 
      ) ;

      /** 
       *
       *  Return logical name ('hostName','port') as sockaddr_in. 
       *
       */
      T_BOOL   X_SOCKET_ln2address       
      ( 
        OUT   T_SOCKADDR_IN       *sa,
        IN    T_CHAR              *hostName,
        IN    T_INT                port 
      ) ;

      /** 
       *
       *  Return (getenv('hostName'),getenv('port')) as sockaddr_in. 
       *
       */
      T_BOOL   X_SOCKET_env2address      
      ( 
        OUT   T_SOCKADDR_IN       *sa,
        IN    T_CHAR              *hostName,
        IN    T_CHAR              *port 
      ) ;

      /** 
       *
       *  Return 'sd' address as sockaddr_in.
       *
       */
      T_BOOL   X_SOCKET_getSockAddr      
      ( 
        IN    T_SOCKADDR_IN       *sa,
        OUT   T_SOCKET            *sd 
      ) ;


      /***  
       ***  Socket Connection Oriented
       ***/

      /**  
       **  socket live
       **/

      /** 
       *
       *  creat socket + bind with 'sa' 
       *
       */
      T_BOOL   X_SOCKET_beeper          
      ( 
        OUT    T_SOCKET            *sd,
        IN     T_SOCKADDR_IN       *sa 
      ) ;

      /** 
       *
       *  connect to 'sa' address 
       *
       */
      T_BOOL   X_SOCKET_connect         
      ( 
        OUT    T_SOCKET            *sd,
        IN     T_SOCKADDR_IN       *sa 
      ) ;

      /** 
       *
       *  from a 'beeper' sock, accept one conection ('sd') 
       *
       */
      T_BOOL   X_SOCKET_accept          
      ( 
        OUT    T_SOCKET            *sd,
        OUT    T_SOCKADDR_IN       *sa,
        IN     T_SOCKET             beeper 
      ) ;

      /** 
       *
       *  shutdown + close 
       *
       */
      T_BOOL   X_SOCKET_unplug          
      ( 
        INOUT  T_SOCKET             sd 
      ) ;

      /** 
       *
       *  like 'X_SOCKET_beeper' but use 'sa' for bind 
       *
       */
      T_BOOL   X_SOCKET_socketBindTo    
      ( 
        OUT    T_SOCKET            *sd,
        IN     T_SOCKADDR_IN       *sa 
      ) ;


      /**  
       **  data movement
       **/

      /** 
       *
       *  like 'X_SOCKET_fullRead' but do that 
       *  in several steps. 
       *
       */
      T_INT    X_SOCKET_read             
      ( 
        INOUT    T_SOCKET   socket,
        OUT      T_CHAR    *buffer,
        IN       T_INT      size 
      ) ;

      /**
       *
       */
      T_INT    X_SOCKET_write            
      ( 
        INOUT    T_SOCKET   socket,
        IN       T_CHAR    *buffer,
        IN       T_INT      size 
      ) ;

      /**
       *
       */
      T_INT    X_SOCKET_writeRead        
      ( 
        INOUT    T_SOCKET   socket,
        INOUT    T_CHAR    *buffer,
        INOUT    T_INT      size 
      ) ;

      /**
       *
       */
      T_INT    X_SOCKET_fullRead         
      ( 
        INOUT    T_SOCKET   socket,
        INOUT    T_CHAR    *buffer,
        INOUT    T_INT      size 
      ) ;



      /***  
       ***  Socket NOT Connection Oriented
       ***/


      /**  
       **  socket live
       **/

      /**
       *
       */
      T_BOOL   X_SOCKET_creatSocket      
      ( 
        INOUT  T_SOCKET   *sockout 
      ) ;

      /**
       *
       */
      T_BOOL   X_SOCKET_close            
      ( 
        INOUT  int      socket 
      ) ;


      /**  
       **  data movement
       **/

      /**
       *
       */
      T_BOOL   X_SOCKET_sendMsg          
      ( 
        INOUT  T_SOCKET            sockdest,
        IN     void               *msg,
        IN     T_INT               msgLen,
        IN     T_SOCKADDR_IN      *raddr 
      ) ;

      /**
       *
       *  Fill first 'msgLen' characters that are reading, 
       *  from socket 'sockorig'. In 'raddr' we will found
       *  origin's address. Remember that if there are more
       *  bytes to read, these will be delete.
       *
       */
      T_BOOL   X_SOCKET_recvMsg          
      ( 
        INOUT  T_SOCKET            sockorig,
        IN     void               *msg,
        IN     T_INT               msgLen,
        IN     T_SOCKADDR_IN      *raddr 
      ) ;


  /* ... Inline / Macros ...................................... */

      #include "base/l_socket/x_socket.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* X_SOCKET_H */

