

 #ifndef L_STACK_MSG_H
 #define L_STACK_MSG_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_debug/l_debug_msg.h"
      #include "base/l_string/x_string.h"


   /* ... Functions / Funciones ......................................... */
      
      /**
       *
       *  Set 'printer' dispacher. 
       *
       */
      void   L_STACK_MSG_setPrinter 
      ( 
        IN    T_INT (*printer) (const T_CHAR *, va_list) 
      ) ;

      /**
       *
       *  Push a string with "format", using PrintMsg.
       *
       */
      void   L_STACK_MSG_Push
      ( 
        IN    T_CHAR  *fto, 
        ... 
      ) ;

      /**
       *
       *  Pop a string with "format", using PrintMsg.
       *
       */
      void   L_STACK_MSG_Pop
      ( 
        IN    T_CHAR  *fto, 
        ... 
      ) ;

      /**
       *
       *  Pop last string and push a new string 
       *  with "format", using PrintMsg.
       *
       */
      void   L_STACK_MSG_PopPush
      ( 
        IN    T_CHAR  *fto, 
        ... 
      ) ;


   /* ................................................................... */

 #ifdef  __cplusplus
    }
 #endif


 #endif

