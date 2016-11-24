

 #ifndef L_SB_M
 #define L_SB_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macro ................................................ */

      /**
       **  read
       **/

     #define L_SB_read(sb,sock,buff,count)  \
             L_SB_SOCK_read((sb)->sock_set[(sock)],(buff),(count)) 

     #define L_SB_readAvailable(sb,sock,buff,count)  \
             L_SB_SOCK_readAvailable((sb)->sock_set[(sock)],(buff),(count)) 

     #define L_SB_lockRead(sb,sock) \
             L_SB_SOCK_lockRead( (t_sb_sock *)&((sb)->sock_set[(sock)]) ) 

     #define L_SB_unlockRead(sb,sock) \
             L_SB_SOCK_unlockRead( (t_sb_sock *)&((sb)->sock_set[(sock)]) ) 


      /**
       **  write
       **/

     #define L_SB_lockWrite(sb,sock) \
             L_SB_SOCK_lockWrite( (t_sb_sock *)&((sb)->sock_set[(sock)]) ) 

     #define L_SB_unlockWrite(sb,sock) \
             L_SB_SOCK_unlockWrite( (t_sb_sock *)&((sb)->sock_set[(sock)]) ) 

     #define L_SB_write(sb,sock,buff,count)  \
             L_SB_SOCK_write((sb)->sock_set[(sock)],(buff),(count))


      /**
       **  field
       **/

     #define L_SB_getFd(sb,sock) \
             L_SB_SOCK_getFd( ((sock) == -1) ? NULL : ((sb)->sock_set[(sock)]) )

     #define L_SB_getFdAddress(sb,sock) \
             L_SB_SOCK_getFdAddress( ((sock) == -1) ? NULL : ((sb)->sock_set[(sock)]) )


      /**
       **  collective
       **/

     #define L_SB_alive(sb,sock) \
             L_SB_SOCK_alive( ((sock) == -1) ? NULL : ((sb)->sock_set[(sock)]) )


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif


 #endif 

