/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_string/l_string.h"


   /* ... Funtions / Funciones .......................................... */

      T_U_LONG  L_STRING_StrLen       
      ( 
        IN  T_CHAR  *str 
      )
      {
        if (str == NULL)
            return 0L ;

        return (T_U_LONG)strlen(str) ;
      }

      T_CHAR   *L_STRING_StrChr       
      ( 
        IN     T_CHAR  *str,
        IN     T_CHAR   ch 
      )
      {
        T_U_INT  lenstr ;
        T_CHAR  *pch ;

        lenstr = L_STRING_StrLen(str) ;
        pch    = memchr(str,ch,lenstr) ;

        return pch ;
      }

      T_INT     L_STRING_StrCmp       
      ( 
        IN  T_CHAR  *str1,
        IN  T_CHAR  *str2 
      )
      {
        if ( (str1 == str2) )
              return  0 ;
        if ( (str1 == NULL) && (str2 != NULL) )
              return  1 ;
        if ( (str1 != NULL) && (str2 == NULL) )
              return -1 ;

        return strcmp(str1,str2) ;
      }

      T_CHAR   *L_STRING_StrDup       
      ( 
        IN  T_CHAR  *str 
      )
      {
        T_CHAR  *pch ;

        NULL_RET_NULL(str) ;
        pch = (T_CHAR *)strdup(str) ;

        return pch ;
      }


   /* ................................................................... */


