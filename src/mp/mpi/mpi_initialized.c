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

      #include "mp/mpi/mpi_initialized.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Initialized
      ( 
        int      *flag 
      )
      {
        T_BOOL ok ;

        /*
         *  console info
         */
        L_STACK_MSG_Push("MPI_Initialized") ;
 
        /*
         *  is initialized ?
         */
        ok = NODE_initialized() ;
        (*flag) = ok ;

        /*
         *  Return
         */
        L_STACK_MSG_Pop("MPI_Initialized") ;
        return MPI_SUCCESS ;
      }


   /* ................................................................. */


