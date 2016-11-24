

 #ifndef I_DTD_PROLOG_H
 #define I_DTD_PROLOG_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"


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
      T_CHAR  *I_DTD_PROLOG_begin
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
      T_CHAR  *I_DTD_PROLOG_end
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
      T_CHAR  *I_DTD_PROLOG_addln
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
      T_CHAR  *I_DTD_PROLOG_vlAddDTD
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj,
        IN     T_CHAR    *dtd_value,
        IN     va_list    varg
      ) ;


  /* .................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

