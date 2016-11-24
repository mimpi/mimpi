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

      #include "base/l_debug/l_debug.h"


   /* ... Functions / Funciones ......................................... */

      T_BOOL L_DEBUG_assert               
      ( 
        IN     T_BOOL      condition, 
        IN     T_U_INT     line,
        IN     T_CHAR     *name,
        IN     T_INT       type,
        IN     int         xerrno,
        IN     T_CHAR     *fto, 
        ... 
      )
      {
        va_list  vl ;

        va_start(vl,fto) ;
        if (condition == TRUE)
           {
             errno = xerrno ;
             L_DEBUG_MSG_VPrintF(line,name,type,TRUE,fto,vl) ;
           }
        va_end(vl) ;
        return condition ;
      }


   /* ................................................................... */

