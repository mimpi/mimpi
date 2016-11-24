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

      #include "mp/mpi/mpi_wait.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Wait
      (
        INOUT  MPI_Request  *mpi_req,
        INOUT  MPI_Status   *status
      )
      {
        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Wait,%p,%p",
                              mpi_req,
                              status) ;
        #endif
 
        /*
         *  check error and update status
         */
        if (mpi_req->ok == FALSE)
           {
             status->MPI_SOURCE = 0 ;
             status->MPI_TAG    = 0 ;
             status->MPI_ERROR  = -1 ;
             status->count      = 0 ;
             goto LABEL_MPI_WAIT_ERROR ;
           }

        /*
         *  wait for request end
         */
        L_FILTER_REQUEST_wait ( &(mpi_req->ok),
                                &(mpi_req->n_req),
                                &(mpi_req->filter) ) ;
        if (mpi_req->ok == FALSE)
            goto LABEL_MPI_WAIT_ERROR ;


        /*
         *  update status
         */
        status->MPI_TAG    = (mpi_req->n_req).tagX ;
        status->MPI_ERROR  = ( ((mpi_req->n_req).ret_size < 0) ? 
                               MPI_ERR : MPI_SUCCESS) ;
        status->count      = (mpi_req->n_req).ret_size 
                               / L_DATATYPE_size(mpi_req->data_type) ;
        mpi_req->from      = (mpi_req->n_req).from ;
        status->MPI_SOURCE = MPI_COMM_translate_nodeid(mpi_req->comm,
                                                     mpi_req->from) ;

        if (mpi_req->ok == FALSE)
            goto LABEL_MPI_WAIT_ERROR ;
        else
            goto LABEL_MPI_WAIT_OK ;


        /*
         *  Return
         */
        LABEL_MPI_WAIT_OK :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_Wait,%p,%p",
                                mpi_req,
                                status) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_WAIT_ERROR :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_Wait,%p,%p",
                                mpi_req,
                                status) ;
           #endif

           return (MPI_ERR) ;
      }


   /* ................................................................. */


