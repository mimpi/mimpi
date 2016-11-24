

 #ifndef L_TIME_M
 #define L_TIME_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */

      #define L_TIME_DiffTime_MS(fin,ini)         \
              ((fin) - (ini))


      #define L_TIME_DiffTime_HS(fin,ini)         \
              ((fin) - (ini))


      #define L_TIME_GetTime_SG()                 \
              time(NULL)

      #define L_TIME_DiffTime_SG(fin,ini)         \
              difftime((fin),(ini))


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

