

 #ifndef L_VERBOSE_MSG_H
 #define L_VERBOSE_MSG_H

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
      void   L_VERBOSE_MSG_setPrinter 
      ( 
        IN    T_INT (*printer) (const T_CHAR *, va_list) 
      ) ;

      /**
       *
       *  Print a string with "format" and variable
       *  argument list, using PrintMsg.
       *
       */
      void   L_VERBOSE_MSG_VPrintF    
      ( 
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      ) ;

      /**
       *
       *  Print a string with "format", using PrintMsg.
       *
       */
      void   L_VERBOSE_MSG_PrintF     
      ( 
        IN    T_CHAR  *fto, 
        ... 
      ) ;


   /* ................................................................... */

 #ifdef  __cplusplus
    }
 #endif


 #endif

