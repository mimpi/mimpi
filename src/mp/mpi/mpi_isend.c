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

      #include "mp/mpi/mpi_isend.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Isend 
      ( 
        INOUT  void         *buf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           dest, 
        IN     int           tag,
        IN     MPI_Comm      comm,
        INOUT  MPI_Request  *mpi_req
      )
      {
        int   to ;
        int   ret ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Isend,%p,%i,%i,%i,%i,%p,%p",
                              buf,
                              count,
                              datatype,
                              dest,
                              tag,
                              comm,
                              mpi_req) ;
        #endif
 
        /*
         *  get some information
         */
        to = MPI_COMM_translate_rank(comm,dest) ;
        if (to < 0)
            goto LABEL_MPI_ISEND_ERROR ;


        /*
         *  send request
         */
        ret = MPI_REQUEST_init(mpi_req,
                               FALSE,
                               REQ_SEND_X_ASYNC,
                               comm,
                               tag,
                               NR_SENDRECV,
                               FILTER_DEFAULT,
                               buf,
                               datatype,
                               count,
                               NODE_node_id(),
                               to) ;
        if (MPI_ERR == ret)
            goto LABEL_MPI_ISEND_ERROR ;

        ret = MPI_Start(mpi_req) ;
        if (MPI_ERR == ret)
            goto LABEL_MPI_ISEND_ERROR ;
        else
            goto LABEL_MPI_ISEND_OK ;


        /*
         *  Return
         */
        LABEL_MPI_ISEND_OK :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop ("MPI_Isend,%p,%i,%i,%i,%i,%p,%p",
                                 buf,
                                 count,
                                 datatype,
                                 source,
                                 tag,
                                 comm,
                                 mpi_req) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_ISEND_ERROR :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop ("MPI_Isend,%p,%i,%i,%i,%i,%p,%p",
                                 buf,
                                 count,
                                 datatype,
                                 source,
                                 tag,
                                 comm,
                                 mpi_req) ;
           #endif

           return (MPI_ERR) ;
      }


   /* ................................................................. */


