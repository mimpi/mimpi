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

      #include "mp/mpi/mpi_group.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL  MPI_GROUP_belong     
      ( 
        int        member, 
        long       nMembers, 
        long      *ranks 
      )
      {
        int j ;

        /*
         *  return true if found
         */
        for (j = 0; j < nMembers; j ++)
            {
              if (ranks[j] == member)
                  return TRUE ;
            }

        /*
         *  return error
         */
        return FALSE ;
      }


   /* ................................................................. */


