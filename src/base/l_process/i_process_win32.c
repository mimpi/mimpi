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

      #include "base/l_process/i_process_win32.h"


   /* ... Functions / Funciones ......................................... */


#if defined(HAVE_WINDOWS_H)

      T_CHAR    *I_PROCESS_WIN32_pidToString 
      ( 
        IN  t_win32_pid     *pid
      )
      {
        T_CHAR  *pstr ;
        T_CHAR  *ret ;

       /*
        *  build pid value.
        */
        if (pid != 0)
           {
             /* ... set to null ... */
             pstr = NULL ;
     
             /* ... add pid ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"_PROCESS_INFORMATION","pid",
                                       "%li",pid) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
           }

       /*
        *  return dtd
        */
        return pstr ;
      }

#endif


   /* ................................................................... */

