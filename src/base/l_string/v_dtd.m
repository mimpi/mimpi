

 #ifndef V_DTD_M
 #define V_DTD_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/i_dtd_xml.h"
      #include "base/l_string/i_dtd_prolog.h"


   /* ... Inline / Macros ............................................... */

      #if defined(__DTD_XML__)

           #define V_DTD_begin(dtd,dtd_name,dtd_obj) \
                   I_DTD_XML_begin((dtd),(dtd_name),(dtd_obj))
     
           #define V_DTD_end(dtd,dtd_name,dtd_obj) \
                   I_DTD_XML_end((dtd),(dtd_name),(dtd_obj))
     
           #define V_DTD_addln(dtd) \
                   I_DTD_XML_addln((dtd))
     
           #define V_DTD_vlAddDTD(dtd,dtd_name,dtd_obj,dtd_value,varg) \
                   I_DTD_XML_vlAddDTD((dtd),(dtd_name),(dtd_obj),(dtd_value),(varg))

      #else

           #define V_DTD_begin(dtd,dtd_name,dtd_obj) \
                   I_DTD_PROLOG_begin((dtd),(dtd_name),(dtd_obj))
     
           #define V_DTD_end(dtd,dtd_name,dtd_obj) \
                   I_DTD_PROLOG_end((dtd),(dtd_name),(dtd_obj))
     
           #define V_DTD_addln(dtd) \
                   I_DTD_PROLOG_addln((dtd))
     
           #define V_DTD_vlAddDTD(dtd,dtd_name,dtd_obj,dtd_value,varg) \
                   I_DTD_PROLOG_vlAddDTD((dtd),(dtd_name),(dtd_obj),(dtd_value),(varg))

      #endif


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

