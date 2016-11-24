

 #ifndef L_TRACE_MSG_H
 #define L_TRACE_MSG_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_debug/l_debug_msg.h"
      #include "base/l_string/x_string.h"
      #include "base/l_process/x_process.h"
      #include "console/l_defcon.h"


   /* ... Functions / Funciones ......................................... */
      
      /**
       *
       *  Set 'printer' dispacher. 
       *
       */
      void   L_TRACE_MSG_setPrinter 
      ( 
        IN    T_INT (*printer)
        (const T_CHAR *, va_list) 
      ) ;

      /**
       *
       *  Escribe un mensaje, usando formato y lista
       *  de argumentos variables. 
       *
       */
      void   L_TRACE_MSG_VPrintF    
      ( 
        IN    T_U_INT  line,
        IN    T_CHAR  *name,
        IN    T_PID    pid,
        IN    T_INT    type,
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      ) ;

      /**
       *
       *  Escribe una tira CON FORMATO usando PrintMsg. 
       *
       */
      void   L_TRACE_MSG_PrintF     
      ( 
        IN    T_U_INT  line,
	    IN    T_CHAR  *name,
        IN    T_PID    pid,
	    IN    T_INT    type,
	    IN    T_CHAR  *fto, 
        ... 
      ) ;


   /* ................................................................... */

 #ifdef  __cplusplus
    }
 #endif


 #endif

