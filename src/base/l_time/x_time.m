

 #ifndef X_TIME_M
 #define X_TIME_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define  X_TIME_GetTime_MSasSG()                  \
               L_TIME_GetTime_MSasSG()

      #define  X_TIME_GetTime(t)                        \
               (*(t)) = L_TIME_GetTime_MS()

      #define  X_TIME_DiffTime(fin,ini)                 \
               L_TIME_DiffTime_MS((fin),(ini))

      #define  X_TIME_CurrCTime()                       \
               L_TIME_CurrCTime()


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

