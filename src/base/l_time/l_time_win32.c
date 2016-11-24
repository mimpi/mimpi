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


 #if (defined(HAVE_WINDOWS_H))

      T_BOOL        L_TIME_isInitTimer = FALSE ;
      LARGE_INTEGER L_TIME_startTime ;
      LARGE_INTEGER L_TIME_TicksPerSecond = {0,0} ; 
      T_DOUBLE      L_TIME_TicksPerMicrosecond = 0 ;


      T_TIME_MS     L_TIME_GetTime_MS
      ( 
        void 
      )
      {
        LARGE_INTEGER  stopTime ;
        LARGE_INTEGER  diffTime ; 
        T_DOUBLE       diffms ;
                         
        if (L_TIME_isInitTimer == FALSE)
           {
             QueryPerformanceFrequency(&L_TIME_TicksPerSecond);
             L_TIME_TicksPerMicrosecond = (float) (L_TIME_TicksPerSecond.LowPart/ 1E6);
             QueryPerformanceCounter(&L_TIME_startTime);
             L_TIME_isInitTimer = TRUE ;
           }

        QueryPerformanceCounter(&stopTime) ;
        diffTime.QuadPart = ( stopTime.QuadPart - L_TIME_startTime.QuadPart) ;
        diffms = diffTime.LowPart / L_TIME_TicksPerMicrosecond ;
        if (diffTime.HighPart != 0)
            diffms += ldexp(diffTime.HighPart,32)/L_TIME_TicksPerMicrosecond ;

        return diffms ;
      }

      T_TIME_HS     L_TIME_GetTime_HS
      ( 
        void 
      )
      {
        return (T_DOUBLE)(L_TIME_GetTime_MS() / 10000) ;
      }

      T_DOUBLE   L_TIME_GetTime_MSasSG
      ( 
        void 
      )
      {
        return (T_DOUBLE)(L_TIME_GetTime_MS() / 1000000) ;
      }


	  /*
	   *  second try
	   */
      T_TIME_MS     L_TIME_GetTime_MS2
      ( 
        void 
      )
      {
        SYSTEMTIME   st ;
        T_DOUBLE     us ;

        GetSystemTime(&st) ;
        us = (T_DOUBLE) ((st.wHour)              * 60) ;
        us = (T_DOUBLE) ((us + st.wMinute)       * 60) ;
        us = (T_DOUBLE) ((us + st.wSecond)       * 1000) ;
        us = (T_DOUBLE) ((us + st.wMilliseconds) * 1000) ;

        return us ;
      }

      T_TIME_HS     L_TIME_GetTime_HS2
      ( 
        void 
      )
      {
        SYSTEMTIME   st ;
        T_DOUBLE     us ;

        GetSystemTime(&st) ;
        us = (T_DOUBLE) ((st.wHour)              * 60) ;
        us = (T_DOUBLE) ((us + st.wMinute)       * 60) ;
        us = (T_DOUBLE) ((us + st.wSecond)       * 100) ;
        us = (T_DOUBLE) ((us + st.wMilliseconds) * 0.1) ;

        return us ;
      }

      T_DOUBLE   L_TIME_GetTime_MSasSG2
      ( 
        void 
      )
      {
        SYSTEMTIME   st ;
	    T_DOUBLE     us ;

        GetSystemTime(&st) ;
        us = (T_DOUBLE) ((st.wHour)              * 60) ;
        us = (T_DOUBLE) ((us + st.wMinute)       * 60) ;
        us = (T_DOUBLE) ((us + st.wSecond)       * 1) ;
        us = (T_DOUBLE) ((us + st.wMilliseconds) * 0.001) ;

        return us ;
      }

 #endif


   /* ................................................................... */

