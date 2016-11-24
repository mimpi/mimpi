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

      #include "mp/mpi/mpi_start.h"


   /* ... Functions / Funciones ....................................... */

      int     MPI_Start
      ( 
        INOUT     MPI_Request  *mpi_req
      )
      {
        T_INT   data_byte_size ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Start,%p",
                              mpi_req) ;
        #endif

        /*
         *  start
         */
        data_byte_size = mpi_req->data_size 
                         * L_DATATYPE_size(mpi_req->data_type) ;

        switch (mpi_req->reqid)
        {
          case REQ_SEND_X_SYNC :
          case REQ_SEND_X_ASYNC :

               L_FILTER_REQUEST_pack_and_send
               (
                 &(mpi_req->ok),
                 &(mpi_req->n_req),
                 MPI_COMM_commNodeLi(mpi_req->comm),
                 mpi_req->reqid,
                 mpi_req->tx,
                 mpi_req->ty,
                 mpi_req->filter,
                 mpi_req->data_buff,
                 data_byte_size,
                 mpi_req->from,
                 mpi_req->to
               ) ;

               break ;

          case REQ_RECEIVE_X_SYNC :
          case REQ_RECEIVE_ANY_SYNC :

               L_FILTER_REQUEST_recv_and_unpack
               (
                 &(mpi_req->ok),
                 &(mpi_req->n_req),
                 MPI_COMM_commNodeLi(mpi_req->comm),
                 mpi_req->reqid,
                 mpi_req->tx,
                 mpi_req->ty,
                 mpi_req->filter,
                 mpi_req->data_buff,
                 data_byte_size,
                 mpi_req->from,
                 mpi_req->to
               ) ;

               break ;

          case REQ_RECEIVE_X_ASYNC :
          case REQ_RECEIVE_ANY_ASYNC :

               L_FILTER_REQUEST_recv_and_unpack
               (
                 &(mpi_req->ok),
                 &(mpi_req->n_req),
                 MPI_COMM_commNodeLi(mpi_req->comm),
                 mpi_req->reqid,
                 mpi_req->tx,
                 mpi_req->ty,
                 mpi_req->filter,
                 mpi_req->data_buff,
                 data_byte_size,
                 mpi_req->from,
                 mpi_req->to
               ) ;

               break ;

          default :
               break ;
        }

        /*
         *  Return
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Start,%p",
                             mpi_req) ;
        #endif

        return ( (mpi_req->ok == TRUE) ? MPI_SUCCESS : MPI_ERR ) ;
      }


   /* ................................................................. */


