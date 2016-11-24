

 #ifndef X_DTD_M
 #define X_DTD_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/v_dtd.h"


   /* ... Inline / Macros ............................................... */

      #define X_DTD_begin(dtd,dtd_name,dtd_obj) \
              V_DTD_begin((dtd),(dtd_name),(dtd_obj))

      #define X_DTD_end(dtd,dtd_name,dtd_obj) \
              V_DTD_end((dtd),(dtd_name),(dtd_obj))

      #define X_DTD_addln(dtd) \
              V_DTD_addln((dtd))

      #define X_DTD_vlBeginPutEnd(dtd,dtd_name,dtd_obj,dtd_value,varg) \
              V_DTD_vlAddDTD((dtd),(dtd_name),(dtd_obj),(dtd_value),(varg))


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

