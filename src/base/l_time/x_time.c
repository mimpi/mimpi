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



   /* ... Includes / Inclusiones ...................................... */

      #include "base/l_time/x_time.h"


   /* ... Functions / Funciones ....................................... */

      T_DOUBLE   X_TIME_detect_tick      
      ( 
        IN   T_INT cnt_max 
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
        t1 = X_TIME_GetTime_MSasSG() ;
        do
        {
          t2 = X_TIME_GetTime_MSasSG() ;
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

      T_DOUBLE   X_TIME_Get_tick      
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
             tickval = X_TIME_detect_tick(1) ;
             for (icnt=0; icnt<10; icnt++) 
                 {
                   tv = X_TIME_detect_tick(1000) ;
                   if (tv < tickval)
                       tickval = tv ;
                 }
           }

        /*
         *  return tickval
         */
        return tickval ;
      }


   /* ................................................................. */


