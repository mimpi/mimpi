/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2003)
 * <fgarcia,acaldero@arcos.inf.uc3m.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/mpi/mpi_get_count.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Get_count 
      ( 
        IN     MPI_Status   *status, 
        IN     MPI_Datatype  datatype, 
        INOUT  int          *count 
      )
      {
        int   ret ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Get_count,%p,%p,%p",
                              status,
                              datatype,
                              count) ;
        #endif
 
        /*
         *  some checks...
         */
	if (status == NULL)
            goto LABEL_MPI_PACK_ERROR ;

        /*
	 * See mpi_wait.c:65/105
         */
	ret = status->count; 
	if (count != NULL)
            (*count) = ret;
        goto LABEL_MPI_PACK_OK ;

        /*
         *  Return
         */
        LABEL_MPI_PACK_OK :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop("MPI_Get_count,%p,%p,%p",
                             status,
                             datatype,
                             count) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_PACK_ERROR :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop("MPI_Get_count,%p,%p,%p",
                             status,
                             datatype,
                             count) ;
           #endif

           return (MPI_UNDEFINED) ;
      }


   /* ................................................................. */

