/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_string/x_dtd.h"


   /* ... Functions / Funciones ......................................... */

      T_CHAR  *X_DTD_put
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_children
      )
      {
        /*
         *  add a dtd
         */
        X_STRING_AddStrToStr(dtd,dtd_children) ;
        NULL_RET_NULL((*dtd)) ;
 
        /*
         *  return 'dtd'
         */
        return (*dtd) ;
      }

      T_CHAR  *X_DTD_vBeginPutEnd
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj,
        IN     T_CHAR    *dtd_value,
        ...
      )
      {
        T_CHAR  *pstr ;
        va_list  varg ;
 
        /*
         *  get dtd value
         */
        va_start(varg,dtd_value) ;
        pstr = X_DTD_vlBeginPutEnd(dtd,
                                   dtd_name,
                                   dtd_obj,
                                   dtd_value,
                                   varg) ;
        va_end(varg) ;
        NULL_RET_NULL(pstr) ;
 
        /*
         *  return 'dtd'
         */
        return (*dtd) ;
      }


/* ...................................................................... */

