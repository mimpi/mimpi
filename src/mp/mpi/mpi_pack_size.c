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

      #include "mp/mpi/mpi_pack_size.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Pack_size
      (
	IN     int              incount,
	IN     MPI_Datatype     datatype,
	IN     MPI_Comm         comm,
	INOUT  int             *size
      )
      {
        int   ret ;
        T_INT data_byte_size, available_byte_size ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Pack_size,%i,%p,%p,%p",
                              incount,
                              datatype,
                              comm,
                              size) ;
        #endif
 
        /*
         *  translate to bytes...
         */
        data_byte_size = incount * L_DATATYPE_size(datatype) ;

        /*
         *  try to copy information...
         */
        if (NULL == size)
            goto LABEL_MPI_PACK_SIZE_ERROR ;

        (*size) = data_byte_size ;
        goto LABEL_MPI_PACK_SIZE_OK ;

        /*
         *  Return
         */
        LABEL_MPI_PACK_SIZE_OK :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop("MPI_Pack_size,%i,%p,%p,%p",
                              incount,
                              datatype,
                              comm,
                              size) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_PACK_SIZE_ERROR :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop("MPI_Pack_size,%i,%p,%p,%p",
                              incount,
                              datatype,
                              comm,
                              size) ;
           #endif

           return (MPI_ERR) ;
      }


   /* ................................................................. */

