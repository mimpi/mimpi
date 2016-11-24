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


   /* ... Functions / Funciones ......................................... */

 #if defined(__MSDOS__)

      T_TIME_MS     L_TIME_GetTime_MS       
      ( 
        void 
      )
      {
        struct time      instant ;
	T_DOUBLE         us ;

	gettime(&instant) ;
        us = (instant.ti_sec) * 1000000
             + 
             (instant.ti_hund) * 10 ;

        return us ;
      }

      T_TIME_HS     L_TIME_GetTime_HS       
      ( 
        void 
      )
      {
        struct time      instant ;
	T_DOUBLE         hs ;

	gettime(&instant) ;
        hs = (instant.ti_sec) * 100
             + 
             (instant.ti_hund) ;

        return hs ;
      }

      T_DOUBLE   L_TIME_Get_time_MSasSG    
      ( 
        void 
      )
      {
        struct time   instant ;

	gettime(&instant) ;
        return ((double)instant.ti_sec) + 0.01 ((double)instant.ti_hund) ;
      }

 #endif


   /* ................................................................... */

