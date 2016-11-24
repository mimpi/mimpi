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

      #include "base/l_string/i_dtd_prolog.h"


   /* ... Functions / Funciones ......................................... */

      T_CHAR  *I_DTD_PROLOG_begin
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj
      )
      {
        /*
         *  open
         */
        X_STRING_Add2StrToStr(dtd,dtd_name,"(") ;
        NULL_RET_NULL((*dtd)) ;
 
        /*
         *  return 'dtd'
         */
        return (*dtd) ;
      }
 
      T_CHAR  *I_DTD_PROLOG_end
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj
      )
      {
        /*
         *  close
         */
        X_STRING_AddStrToStr(dtd,")") ;
        NULL_RET_NULL((*dtd)) ;
 
        /*
         *  return 'dtd'
         */
        return (*dtd) ;
      }
 
      T_CHAR  *I_DTD_PROLOG_addln
      ( 
        INOUT  T_CHAR   **dtd
      )
      {
        /*
         *  add a dtd backspace
         */
        X_STRING_AddStrToStr(dtd,",") ;
 
        /*
         *  return 'dtd'
         */
        return (*dtd) ;
      }
 
      T_CHAR  *I_DTD_PROLOG_vlAddDTD
      ( 
        INOUT  T_CHAR   **dtd,
        IN     T_CHAR    *dtd_name,
        IN     T_CHAR    *dtd_obj,
        IN     T_CHAR    *dtd_value,
        IN     va_list    varg
      )
      {
        T_CHAR  *pstr ;
 
        /*
         *  get dtd value
         */
        pstr = X_STRING_Dvsprintf(dtd_value,varg) ;
        NULL_RET_NULL(pstr) ;
 
        /*
         *  add value
         */
        X_STRING_Add2StrToStr(dtd,dtd_name,"(") ;
        X_STRING_Add2StrToStr(dtd,pstr,")") ;
        X_ALLOC_Free((void **)&(pstr)) ;
        NULL_RET_NULL((*dtd)) ;
 
        /*
         *  return 'dtd'
         */
        return (*dtd) ;
      }


/* ...................................................................... */

