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

      #include "mp/mpi/mpi_barrier.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Barrier    
      ( 
        IN     MPI_Comm      comm 
      )
      {
        int ret ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_BARRIER,%p",
                              comm) ;
        #endif

        /*
         *  default
         */
        ret = MPI_BARRIER_48H_Barrier(comm) ;

        /*
         *  Return
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_BARRIER,%p",
                             comm) ;
        #endif

        return ret ;
      }


   /* ................................................................. */

