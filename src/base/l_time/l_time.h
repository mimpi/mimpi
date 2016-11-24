

 #ifndef L_TIME_H
 #define L_TIME_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Types / Tipos ................................................. */

      #define  T_TIME_MS       double
      #define  T_TIME_HS       double
      #define  T_TIME_SG       time_t

      #define  T_ACCTIME       double


   /* ... Const / Constantes ............................................ */

      #define  c_TIME_MS          sizeof(T_TIME_MS)
      #define  c_TIME_SG          sizeof(T_TIME_SG)
      #define  c_TIME_HS          sizeof(T_TIME_HS)
      #define  c_ACCTIME          sizeof(T_ACCTIME)

      #define  ACCTIME_MAX        MAXDOUBLE
      #define  ACCTIME_MIN        ((double)0)


   /* ... Functions / Funciones ......................................... */

      /**
       **  miliseconds
       **/

      /**
       *
       *  Return current instant as miliseconds 
       *
       *     @params nothing
       *     @return current time
       *
       */
      T_TIME_MS     L_TIME_GetTime_MS       
      ( 
        void 
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
      T_ACCTIME     L_TIME_DiffTime_MS      
      ( 
        IN  T_TIME_MS   fin, 
        IN  T_TIME_MS   ini 
      ) ;

      /**  
       *
       *  Return current instant as seconds BUT 
       *  with milisecond resolution 
       *
       *     @params nothing
       *     @return current time
       *
       */
      T_DOUBLE      L_TIME_GetTime_MSasSG   
      ( 
        void 
      ) ;


      /**
       **  houndred seconds
       **/

      /**  
       *
       *  Return current instant as houndred of seconds 
       *
       *     @params nothing
       *     @return current time
       *
       */
      T_TIME_HS     L_TIME_GetTime_HS       
      ( 
        void 
      ) ;

      /**  
       *
       *  Return seconds between 'ini' and 'fin' 
       *
       *     @params end instant
       *     @params begin instant
       *     @return time between
       *
       */
      T_ACCTIME     L_TIME_DiffTime_HS      
      ( 
        IN  T_TIME_HS      fin,
        IN  T_TIME_HS      ini 
      ) ;

      /**
       **  seconds
       **/

      /**  
       *
       *  Return current instant as seconds 
       *
       *     @params nothing
       *     @return current time
       *
       */
      T_TIME_SG    *L_TIME_GetTime_SG       
      ( 
        void 
      ) ;

      /**  
       *
       *  Return seconds between 'ini' and 'fin' 
       *
       *     @params end instant
       *     @params begin instant
       *     @return time between
       *
       */
      T_ACCTIME     L_TIME_DiffTime_SG      
      ( 
        IN  T_TIME_SG  *fin,
        IN  T_TIME_SG  *ini 
      ) ;

      /**
       **  miscellaneous
       **/

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
      T_CHAR       *L_TIME_CurrCTime        
      ( 
        void 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "base/l_time/l_time.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

