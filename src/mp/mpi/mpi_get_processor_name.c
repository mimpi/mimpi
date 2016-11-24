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

      #include "mp/mpi/mpi_get_processor_name.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Get_processor_name 
      ( 
        char *name, 
        int  *result_len 
      )
      {
        /*
         *  console info
         */
        L_STACK_MSG_Push("MPI_Get_processor_name") ;

        /*
         *  get host name
         */
        gethostname(name, MPI_MAX_PROCESSOR_NAME) ;
        (*result_len) = strlen(name) ;

        /*
         *  return ok
         */
        L_STACK_MSG_Pop("MPI_Get_processor_name") ;
        return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


