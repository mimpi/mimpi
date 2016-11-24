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

      #include "mp/mpi/mpi_pack.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Pack 
      ( 
        IN     void         *inbuf, 
        IN     int           incount, 
        IN     MPI_Datatype  datatype, 
        INOUT  void         *outbuf, 
        IN     int           outsize, 
        INOUT  int          *position, 
        IN     MPI_Comm      comm
      )
      {
        int   ret ;
        T_INT data_byte_size, available_byte_size ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Pack,%p,%i,%p,%p,%i,%p,%p",
                              inbuf,
                              incount,
                              datatype,
                              outbuf,
                              outsize,
                              position,
                              comm) ;
        #endif
 
        /*
         *  translate to bytes...
         */
        data_byte_size = incount * L_DATATYPE_size(datatype) ;
        available_byte_size = outsize - (*position) ;

        /*
         *  try to copy information...
         */
        if (available_byte_size < data_byte_size)
            goto LABEL_MPI_PACK_ERROR ;

	X_ALLOC_MemMove(outbuf+(*position),inbuf,data_byte_size);
        (*position) = (*position) + data_byte_size ;
        goto LABEL_MPI_PACK_OK ;

        /*
         *  Return
         */
        LABEL_MPI_PACK_OK :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop("MPI_Pack,%p,%i,%p,%p,%i,%p,%p",
                              inbuf,
                              incount,
                              datatype,
                              outbuf,
                              outsize,
                              position,
                              comm) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_PACK_ERROR :

           #if defined(__DEBUG__)
             L_STACK_MSG_Pop("MPI_Pack,%p,%i,%p,%p,%i,%p,%p",
                              inbuf,
                              incount,
                              datatype,
                              outbuf,
                              outsize,
                              position,
                              comm) ;
           #endif

           return (MPI_ERR) ;
      }


   /* ................................................................. */

