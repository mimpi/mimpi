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

      #include "mp/mpi/mpi_get_version.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Get_version
      ( 
        INOUT     int   *version,
        INOUT     int   *subversion
      )
      {
        /*
         *  console info
         */
        L_STACK_MSG_Push("MPI_Get_version") ;
 
        /*
         *  is initialized ?
         */
        (*version)    = MPI_VERSION ;
        (*subversion) = MPI_SUBVERSION ;

        /*
         *  Return
         */
        L_STACK_MSG_Pop("MPI_Get_version") ;
        return MPI_SUCCESS ;
      }


   /* ................................................................. */


