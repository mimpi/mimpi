

 #ifndef X_STRING_M
 #define X_STRING_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macro ................................................ */

      #define X_STRING_StrLen(str)                   \
              L_STRING_StrLen((str))

      #define X_STRING_StrChr(str,ch)                \
              L_STRING_StrChr((str),(ch))            \

      #define X_STRING_StrCmp(str1,str2)             \
              L_STRING_StrCmp((str1),(str2))         \


 /* ...................................................................... */

 #ifdef  __cplusplus
    }
 #endif


 #endif 

