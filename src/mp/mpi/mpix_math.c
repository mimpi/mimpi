/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/mpi/mpix_math.h"


   /* ... Functions / Funciones ....................................... */

      int MPIX_MATH_pow_x_2
      ( 
        IN    int  x 
      )
      {
        int i, c ;

        c = 1 ;
        for (i=0; i<x; i++)
             c = 2 * c ;
        return c ;
      }

      int MPIX_MATH_log_x_2_ge
      (
        int n
      )
      {
        int ln2p, i ;

        ln2p = 1 ;
        for (i=0; i <= n; i++)
        {
          if (ln2p >= n)
              return i ;
          ln2p = ln2p << 1 ;
        }

        return i ;
      }

      int MPIX_MATH_log_x_2_le
      (
        int n
      )
      {
        int ln2p, i ;

        ln2p = 1 ;
        for (i=0; i <= n; i++)
        {
          if (ln2p > n)
              return i - 1 ;
          ln2p = ln2p << 1 ;
        }

        return i ;
      }


   /* ................................................................. */


