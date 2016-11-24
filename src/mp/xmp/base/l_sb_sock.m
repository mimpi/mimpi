

 #ifndef L_SB_SOCK_M
 #define L_SB_SOCK_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macro ................................................ */

      /**
       **  read
       **/

      #define L_SB_SOCK_read(sbs,buff,count)  \
              X_SOCKET_read((sbs)->fd,(buff),(count)) 
 
      #define L_SB_SOCK_readAvailable(sbs,buff,count)  \
              X_SOCKET_readAvailable((sbs)->fd,(buff),(count)) 
 
      #define L_SB_SOCK_lockRead(sbs) \
              X_THREAD_lock( &((sbs)->read_mutex) ) 
 
      #define L_SB_SOCK_unlockRead(sbs) \
              X_THREAD_unlock( &((sbs)->read_mutex) ) 
 

      /**
       **  write
       **/

      #define L_SB_SOCK_lockWrite(sbs) \
              X_THREAD_lock( &((sbs)->write_mutex) ) 
 
      #define L_SB_SOCK_unlockWrite(sbs) \
              X_THREAD_unlock( &((sbs)->write_mutex) ) 
 
      #define L_SB_SOCK_write(sbs,buff,count)  \
              X_SOCKET_write((sbs)->fd,(buff),(count)) 


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif


 #endif 

