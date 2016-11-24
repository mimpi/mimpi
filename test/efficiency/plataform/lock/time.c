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



   /* ... Functions / Funciones ......................................... */


 #if (defined(HAVE_GETTIMEOFDAY))

      double   TIME_time_1
      ( 
        void 
      )
      {
        struct timeval tp ;

        gettimeofday(&tp,NULL) ;
        return ((double) tp.tv_sec + .000001 * (double) tp.tv_usec) ;
      }

 #endif

 #if (defined(HAVE_WINDOWS_H))

      int             TIME_isInitTimer = FALSE ;
      LARGE_INTEGER   TIME_startTime ;
      LARGE_INTEGER   TIME_TicksPerSecond = {0,0} ; 
      double          TIME_TicksPerMicrosecond = 0 ;


      double     TIME_time_2
      ( 
        void 
      )
      {
        LARGE_INTEGER  stopTime ;
        LARGE_INTEGER  diffTime ; 
        double         diffms ;
                         
        if (TIME_isInitTimer == FALSE)
           {
             QueryPerformanceFrequency(&TIME_TicksPerSecond);
             TIME_TicksPerMicrosecond = (float) (TIME_TicksPerSecond.LowPart/ 1E6);
             QueryPerformanceCounter(&TIME_startTime);
             TIME_isInitTimer = TRUE ;
           }

        QueryPerformanceCounter(&stopTime) ;
        diffTime.QuadPart = ( stopTime.QuadPart - TIME_startTime.QuadPart) ;
        diffms = diffTime.LowPart / TIME_TicksPerMicrosecond ;
        if (diffTime.HighPart != 0)
            diffms += ldexp(diffTime.HighPart,32)/TIME_TicksPerMicrosecond ;

        return (diffms / 1000000) ;
      }

      double   TIME_time_3
      ( 
        void 
      )
      {
        SYSTEMTIME   st ;
	    double       us ;

        GetSystemTime(&st) ;
        us = (double) ((st.wHour)              * 60) ;
        us = (double) ((us + st.wMinute)       * 60) ;
        us = (double) ((us + st.wSecond)       * 1) ;
        us = (double) ((us + st.wMilliseconds) * 0.001) ;

        return us ;
      }

 #endif

      /*
       *  get time (MS as Seconds)
       */
      #define   TIME_time   TIME_time_1


      /*
       *  some helpfull functions...
       */
      double   TIME_detect_tick      
      ( 
        int cnt_max 
      )
      {
        double tickval ;
        double t1, t2 ;
        int    cnt ;

        /*
         *  default values
         */
        tickval = 1.0e6 ;
        cnt = cnt_max ;

        /*
         *  try get min. diff. time
         */
        t1 = TIME_time() ;
        do
        {
          t2 = TIME_time() ;
          cnt-- ;
        } while (
                  (cnt != 0) 
                      && 
                  (t2 <= t1) 
                )  ;

        /*
         *  default values
         */
        if (
             (cnt != 0) 
                 && 
             (t2 - t1 < tickval)
           )
           {
             tickval = t2 - t1 ;
           }

        /*
         *  return
         */
        return tickval ;
      }

      double   TIME_get_tick      
      ( 
        void 
      )
      {
        static double tickval = -1.0 ;
        double tv ;
        int    icnt ;

        /*
         *  if first time, detect tick value
         */
        if (tickval < 0.0) 
           {
             tickval = TIME_detect_tick(1) ;
             for (icnt=0; icnt<10; icnt++) 
                 {
                   tv = TIME_detect_tick(1000) ;
                   if (tv < tickval)
                       tickval = tv ;
                 }
           }

        /*
         *  return tickval
         */
        return tickval ;
      }

      char  *TIME_ctime
      (
        void
      )
      {
        time_t  tnow ;
        char   *pcr, *tstr ;

        tnow = time(NULL) ;
        tstr = (char *)ctime(&tnow) ;
        pcr  = strrchr(tstr,'\n') ;
        *pcr = '\0' ;
        return tstr ;
      }


   /* ................................................................... */

