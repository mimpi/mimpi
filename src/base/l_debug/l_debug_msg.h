

 #ifndef L_DEBUG_MSG_H
 #define L_DEBUG_MSG_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Consts / Constantes ........................................... */

      #define  DBG_INFO     __LINE__,__FILE__,0
      #define  DBG_WARNING  __LINE__,__FILE__,1
      #define  DBG_ERROR    __LINE__,__FILE__,2
 

   /* ... Globla var. / Variables glob. ................................. */

      extern T_INT  (*L_DEBUG_MSG_PrintMsg)(const T_CHAR *, va_list) ;


   /* ... Functions / Funciones ......................................... */
      
      /* 
       *  Like 'perror'. 
       */
      void   L_DEBUG_MSG_perror   
      ( 
        IN    T_U_INT  line,
        IN    T_CHAR  *name,
	IN    T_INT    type,
	IN    T_BOOL   printwhere,
	IN    T_CHAR  *msg 
      ) ;

      /* 
       *  Write a debug string using L_DEBUG_MSG_PrintMsg,
       *  if this var. is NOT null. 
       */
      void   L_DEBUG_MSG_Write    
      ( 
        IN    T_U_INT  line,
        IN    T_CHAR  *name,
        IN    T_INT    type,
        IN    T_BOOL   printwhere,
        IN    T_CHAR  *msg 
      ) ;

      /* 
       *  'vprintf' like interface.
       */
      void   L_DEBUG_MSG_VPrintF  
      ( 
        IN    T_U_INT  line,
        IN    T_CHAR  *name,
        IN    T_INT    type,
        IN    T_BOOL   printwhere,
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      ) ;

      /* 
       *  'printf' like interface.
       */
      void   L_DEBUG_MSG_PrintF   
      ( 
        IN    T_U_INT  line,
	IN    T_CHAR  *name,
	IN    T_INT    type,
	IN    T_BOOL   printwhere,
	IN    T_CHAR  *fto, ... 
      ) ;


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif


 #endif

