

 #ifndef L_DEFCON_H
 #define L_DEFCON_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_process/x_process.h"


   /* ... Consts / Constantes ........................................... */

/*
      #define  DEFCON_1 __LINE__,__FILE__,X_PROCESS_getpid(),0
      #define  DEFCON_2 __LINE__,__FILE__,X_PROCESS_getpid(),0
      #define  DEFCON_3 __LINE__,__FILE__,X_PROCESS_getpid(),1
      #define  DEFCON_4 __LINE__,__FILE__,X_PROCESS_getpid(),1
      #define  DEFCON_5 __LINE__,__FILE__,X_PROCESS_getpid(),2
      #define  DEFCON_6 __LINE__,__FILE__,X_PROCESS_getpid(),2
*/

      #define  DEFCON_1 __LINE__,__FILE__,(0),0
      #define  DEFCON_2 __LINE__,__FILE__,(0),0
      #define  DEFCON_3 __LINE__,__FILE__,(0),1
      #define  DEFCON_4 __LINE__,__FILE__,(0),1
      #define  DEFCON_5 __LINE__,__FILE__,(0),2
      #define  DEFCON_6 __LINE__,__FILE__,(0),2


   /* ................................................................... */

 #ifdef  __cplusplus
    }
 #endif


 #endif

