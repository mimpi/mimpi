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

      #include "mp/mpi/mpi_recv.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Recv 
      ( 
        INOUT  void         *buf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           source, 
        IN     int           tag,
        IN     MPI_Comm      comm,
        INOUT  MPI_Status   *status
      )
      {
        int           ret ;
        MPI_Request   mpi_req ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Recv,%p,%i,%i,%i,%i,%p",
                              buf,
                              count,
                              datatype,
                              source,
                              tag,
                              comm) ;
        #endif
 

        /*
         *  receive information
         */
        if (source != MPI_ANY_SOURCE)
           {
             int   from ;

             from = MPI_COMM_translate_rank(comm,source) ;
             if (from < 0)
                 goto LABEL_MPI_RECV_ERROR ;

             ret = MPI_REQUEST_init(&mpi_req,
                                    FALSE,
                                    REQ_RECEIVE_X_SYNC,
                                    comm,
                                    tag,
                                    NR_SENDRECV,
                                    FILTER_DEFAULT,
                                    buf,
                                    datatype,
                                    count,
                                    from,
                                    NODE_node_id()) ;
             if (MPI_ERR == ret)
                 goto LABEL_MPI_RECV_ERROR ;
           }
        else /* (source == MPI_ANY_SOURCE) */
           {
             ret = MPI_REQUEST_init(&mpi_req,
                                    FALSE,
                                    REQ_RECEIVE_ANY_SYNC,
                                    comm,
                                    tag,
                                    NR_SENDRECV,
                                    FILTER_DEFAULT,
                                    buf,
                                    datatype,
                                    count,
                                    ANY_NODE,
                                    NODE_node_id()) ;
             if (MPI_ERR == ret)
                 goto LABEL_MPI_RECV_ERROR ;
           }

        ret = MPI_Start(&mpi_req) ; 
        if (MPI_ERR == ret)
            goto LABEL_MPI_RECV_ERROR ;

        ret = MPI_Wait(&mpi_req,status) ; 
        if (MPI_ERR == ret)
            goto LABEL_MPI_RECV_ERROR ;
        else
            goto LABEL_MPI_RECV_OK ;


        /*
         *  Return
         */
        LABEL_MPI_RECV_OK :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop ("MPI_Recv,%p,%i,%i,%i,%i,%p",
                                 buf,
                                 count,
                                 datatype,
                                 source,
                                 tag,
                                 comm) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_RECV_ERROR :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop ("MPI_Recv,%p,%i,%i,%i,%i,%p",
                                 buf,
                                 count,
                                 datatype,
                                 source,
                                 tag,
                                 comm) ;
           #endif

           return (MPI_ERR) ;
      }


   /* ................................................................. */


