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

      #include "mp/mpi/mpi_comm_create.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Comm_create         
      ( 
        IN    MPI_Comm    comm,
        IN    MPI_Group   group,
        OUT   MPI_Comm   *newcomm 
      )
      {
        long j, np ;

        /*
         *  console info
         */
        L_STACK_MSG_PopPush("COMM_CREATE,%p,%p",
                            comm,group) ;

        /*
         *  count members
         */
        np = 0 ;
        for (j=0; j < MAX_SOCKS; j++)
            {
              if (L_SOCIETY_getMemberInfo(group,j) < 0)
                  continue ;
              else
                  np ++ ;
            }

        /*
         *  set default info
         */
        (*newcomm) = group ;
        L_SOCIETY_setNMembers(group,np) ;

        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


