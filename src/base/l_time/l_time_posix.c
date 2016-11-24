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

 #if (defined(__UNIX95__))

      T_TIME_MS     L_TIME_GetTime_MS       
      ( 
        void 
      )
      {
        struct timeval   instant ;
	T_DOUBLE         us ;

	gettimeofday(&instant,NULL) ;
        us = (T_DOUBLE)(instant.tv_sec) * 1000000
             + 
             (T_DOUBLE)(instant.tv_usec) ;

        return us ;
      }

      T_TIME_HS     L_TIME_GetTime_HS       
      ( 
        void 
      )
      {
        struct timeval   instant ;
	T_DOUBLE         us ;

	gettimeofday(&instant,NULL) ;
        us = (instant.tv_sec) * 100
             + 
             (instant.tv_usec) / 10000 ;

        return us ;
      }

      T_DOUBLE   L_TIME_GetTime_MSasSG    
      ( 
        void 
      )
      {
        struct timeval tp ;

        gettimeofday(&tp,NULL) ;
        return ((double) tp.tv_sec + .000001 * (double) tp.tv_usec) ;
      }

 #endif


   /* ................................................................... */

