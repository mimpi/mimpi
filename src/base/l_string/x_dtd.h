

 #ifndef X_DTD_H
 #define X_DTD_H

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
       *  DTD father uses 'begin' to describe children.
       *
       *     @params dtd string
       *     @params dtd name
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *X_DTD_begin
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj
      ) ;

      /**  
       *
       *  Add a sub-DTD 'dtd_children' into '*dtd'.
       *  DTD father uses 'put' to attach a children's description.
       *
       *     @params dtd string
       *     @params dtd children
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *X_DTD_put
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_children
      ) ;
      /**  
       *
       *  End a DTD definition into '*dtd'.
       *  DTD father uses 'end' to describe children.
       *
       *     @params dtd string
       *     @params dtd name
       *     @return pointer dtd updated
       *
       */
      T_CHAR  *X_DTD_end
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
      T_CHAR  *X_DTD_addln
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
      T_CHAR  *X_DTD_vBeginPutEnd
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj,
        IN     T_CHAR    *dtd_value,
        ...
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
      T_CHAR  *X_DTD_vlBeginPutEnd
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj,
        IN     T_CHAR    *dtd_value,
        IN     va_list   *varg
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "base/l_string/x_dtd.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

