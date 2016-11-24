

 #ifndef V_DTD_H
 #define V_DTD_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Functions / Funciones ......................................... */

      /**  
       *
       *  Begin a DTD definition into '*dtd'.
       *
       *     @params dtd string
       *     @params dtd name
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *V_DTD_begin
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj
      ) ;

      /**  
       *
       *  End a DTD definition into '*dtd'.
       *
       *     @params dtd string
       *     @params dtd name
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *V_DTD_end
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj
      ) ;

      /**  
       *
       *  Add a DTD delimiter.
       *
       *     @params dtd string
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *V_DTD_addln
      ( 
        INOUT  T_CHAR   **dtd
      ) ;

      /**  
       *
       *  Add a sub-DTD definition into '*dtd'.
       *
       *     @params dtd string
       *     @params dtd name
       *     @params dtd value format
       *     @params dtd value params
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *V_DTD_vlAddDTD
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj,
        IN     T_CHAR    *dtd_value,
        IN     va_list    varg
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "base/l_string/v_dtd.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

