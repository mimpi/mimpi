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

      #include "mp/mpi/mpi_comm_rank.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Comm_rank           
      ( 
        IN    MPI_Comm    comm,
        OUT   int        *rank 
      )
      {
        /*
         *  console info
         */
        L_STACK_MSG_PopPush("COMM_RANK,%p",
                            comm) ;
        /*
         *  get rank
         */
        (*rank) = L_SOCIETY_getMember(comm,NODE_node_id()) ;

        /*
         *  return
         */
        if ( (*rank) == -1 )
             return (MPI_ERR);     
        else
             return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


