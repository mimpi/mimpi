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

      #include "base/l_time/l_time.h"
      #include "base/l_time/l_time_win32.c"
      #include "base/l_time/l_time_posix.c"
      #include "base/l_time/l_time_msdos.c"


   /* ... Functions / Funciones ......................................... */

      T_CHAR  *L_TIME_CurrCTime  
      ( 
        void 
      )
      { 
        time_t tnow ;
        T_CHAR *pcr, *tstr ;

        tnow = time(NULL) ;
	    tstr = (T_CHAR *)ctime(&tnow) ;
        pcr  = strrchr(tstr,'\n') ;
        *pcr = '\0' ;
        return tstr ; 
      }


   /* ................................................................... */

