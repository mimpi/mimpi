/* ....................................................................
 *
 * Copyright Felix Garcia (1997-2000)
 * <fgarcia@laurel.datsi.fi.upm.es>
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "test_times.h"


   /* ... Funciones ................................................... */

      double TEST_TIMES_getBarrierTime
      (
        /* IN    */   int n_test
      )
      {
	double start_time ;
	double barrier_time ;
	int    j ;

        /*
         *  test barrier
         */
        start_time = MPI_Wtime() ;
        for(j = 0; j < n_test; j++)
        {
          MPI_Barrier(MPI_COMM_WORLD) ;
        }
        barrier_time = (MPI_Wtime() - start_time) ;

        /*
         *  return barrier_time
         */
        return barrier_time ;
      }


  /* .................................................................... */

