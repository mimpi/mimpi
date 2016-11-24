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

      #include "mp/mpi/mpi_comm_size.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Comm_size           
      ( 
        IN    MPI_Comm    comm,
        OUT   int        *size 
      ) 
      {
        /*
         *  console info
         */
        L_STACK_MSG_PopPush("COMM_SIZE,%p",
                            comm) ;

        /*
         *  get size
         */
        (*size) = L_SOCIETY_getNMembers(comm) ;

        /*
         *  return
         */
        if ( (*size) < 0 )
             return (MPI_ERR) ;
        else
             return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


