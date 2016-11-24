

 #ifndef X_SOCKET_M
 #define X_SOCKET_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
 

   /* ... Inline / Macros ............................................... */

     /**
	  **  init and finalize
	  **/
     #define  X_SOCKET_init()                                     \
              V_SOCKET_init()

     #define  X_SOCKET_finalize()                                 \
              V_SOCKET_finalize()


      /**
   	   **  read and write
  	   **/
     #define  X_SOCKET_readAvailable(socket,buffer,size)          \
              V_SOCKET_read((socket),(buffer),(size))

     #define  X_SOCKET_writeAvailable(socket,buffer,size)         \
              V_SOCKET_write((socket),(buffer),(size))


     /**
	  **  read
	  **/
     #define  X_SOCKET_MAC_writeRead(socket,buffer,size)          \
              (                                                   \
                (X_SOCKET_write((socket),(buffer),(size)) < 0) ?  \
                (-1)                                              \
                :                                                 \
                (X_SOCKET_read((socket),(buffer),(size)))         \
              )


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

