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

      #include "mp/mpi/mpi_unpack.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Unpack 
      (
        IN     void         *inbuf, 
        IN     int           insize, 
        INOUT  int          *position, 
        INOUT  void         *outbuf, 
        IN     int           outcount, 
        IN     MPI_Datatype  datatype, 
        IN     MPI_Comm      comm
      )
      {
        int   ret ;
        T_INT data_byte_size, available_byte_size ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Unpack,%p,%i,%p,%p,%i,%p,%p",
                              inbuf,
                              insize,
                              position,
                              outbuf,
                              outcount,
                              datatype,
                              comm) ;
        #endif
 
        /*
         *  translate to bytes...
         */
        data_byte_size = outcount * L_DATATYPE_size(datatype) ;
        available_byte_size = insize - (*position) ;

        /*
         *  try to copy information...
         */
        if (available_byte_size < data_byte_size)
            goto LABEL_MPI_PACK_ERROR ;

	X_ALLOC_MemMove(outbuf,inbuf+(*position),data_byte_size);
        (*position) = (*position) + data_byte_size ;
        goto LABEL_MPI_PACK_OK ;

        /*
         *  Return
         */
        LABEL_MPI_PACK_OK :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop ("MPI_Unpack,%p,%i,%p,%p,%i,%p,%p",
                              inbuf,
                              insize,
                              position,
                              outbuf,
                              outcount,
                              datatype,
                              comm) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_PACK_ERROR :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop ("MPI_Unpack,%p,%i,%p,%p,%i,%p,%p",
                              inbuf,
                              insize,
                              position,
                              outbuf,
                              outcount,
                              datatype,
                              comm) ;
           #endif

           return (MPI_ERR) ;
      }


   /* ................................................................. */


