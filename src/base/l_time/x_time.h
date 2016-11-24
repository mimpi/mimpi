

 #ifndef X_TIME_H
 #define X_TIME_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_time/l_time.h"


   /* ... Types / Tipos ................................................. */

      #define  T_TIME       T_TIME_MS 


   /* ... Const / Constantes ............................................ */

      #define  c_TIME            sizeof(T_TIME)


   /* ... Functions / Funciones ......................................... */

      /**
       *
       *  If 'ins' is no NULL, put in current time. 
       *
       *     @params nothing
       *     @return current time
       *
       */
      void       X_TIME_GetTime          
      ( 
        IN  T_TIME  *ins 
      ) ;

      /** 
       *
       *  Return miliseq. between 'ini' and 'fin' 
       *
       *     @params end instant
       *     @params begin instant
       *     @return time between
       *
       */
      T_ACCTIME  X_TIME_DiffTime         
      ( 
        IN  T_TIME  *fin, 
        IN  T_TIME  *ini 
      ) ;

      /**  
       *
       *  Return a string with day, month, year, hour,
       *  minutes and seconds at instant where is called
       *  Return a NO malloc string. 
       *
       *     @params nothing
       *     @return current time
       *
       */
      T_CHAR    *X_TIME_CurrCTime        
      ( 
        void 
      ) ;


      /**
       **  MiMPI use :
       **/

      /**  
       *
       *  Return current seconds but with 
       *  milisec. resolution 
       *
       *     @params nothing
       *     @return current time
       *
       */
      T_DOUBLE   X_TIME_GetTime_MSasSG   
      ( 
        void 
      ) ;

      /**  
       *
       *  Return miliseq. between two measures 
       *
       *     @params nothing
       *     @return tick
       *
       */
      T_DOUBLE   X_TIME_Get_tick         
      ( 
        void 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "base/l_time/x_time.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

