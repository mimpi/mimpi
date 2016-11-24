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

      #include "mp/mpi/mpi_comm_group.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Comm_group         
      ( 
        IN    MPI_Comm    comm,
        OUT   MPI_Group  *group 
      )
      {
        /*
         *  console info
         */
        L_STACK_MSG_PopPush("COMM_GROUP,%p",
                            comm) ;

        /*
         *  set current group
         */
        (*group) = comm ;

        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


