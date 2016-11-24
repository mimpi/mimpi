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

      #include "mp/mpi/mpi_group_excl.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Group_excl       
      ( 
        MPI_Group  group, 
        long       nMembers, 
        long      *ranks, 
        MPI_Group *newgroup 
      )
      {
        long   j, k ;

        /*
         *  init values  
         */
        k = 0L ;
        L_SOCIETY_last_society++;     

        /*
         *  insert values  
         */
        for (j = 0L; j < MAX_SOCKS; j++)
            {
              if (MPI_GROUP_belong(j,nMembers,ranks) == FALSE)
                 {
                   if (j < NODE_n_nodes())
                      {
                        L_SOCIETY_setMemberInfo(L_SOCIETY_last_society,k,j) ;
                        k ++ ;
                      }
                      else
                      {
                        break ;
                      }
                 }
            }
        
        /*
         *  set values
         */
        L_SOCIETY_setNMembers(L_SOCIETY_last_society,k) ;
        (*newgroup) = L_SOCIETY_last_society ;

        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


