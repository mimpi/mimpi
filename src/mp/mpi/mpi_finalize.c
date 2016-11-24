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

      #include "mp/mpi/mpi_finalize.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Finalize 
      ( 
        void 
      )
      {
        T_BOOL ok ;

        /*
         *  console info
         */
        L_STACK_MSG_Push("MPI_finalize") ;
 
        /*
         *  check NODE_initialized
         */
        if (NODE_initialized() == FALSE)
           {
             L_STACK_MSG_Pop("MPI_finalize") ;
             return MPI_SUCCESS ;
           }

        /*
         *  finalize node
         */
        ok = NODE_finalize() ;
        MPI_COMM_finalize() ;

        /*
         *  Return
         */
        L_STACK_MSG_Pop("MPI_finalize") ;
        return ( (ok == TRUE) ? MPI_SUCCESS : MPI_ERR ) ;
      }


   /* ................................................................. */


