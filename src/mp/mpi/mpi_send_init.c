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

      #include "mp/mpi/mpi_send_init.h"


   /* ... Functions / Funciones ....................................... */

      int     MPI_Send_init
      ( 
        IN        char         *data_buff,
        IN        int           data_count,
        IN        MPI_Datatype  data_type,
        IN        int           to,
        IN        int           tag,
        IN        MPI_Comm      comm,
        INOUT     MPI_Request  *mpi_req
      )
      {
        int   ret ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Send_init,%p,%i,%i,%i,%i,%p,%p",
                              data_buff,
                              data_count,
                              data_type,
                              to,
                              tag,
                              comm,
                              mpi_req) ;
        #endif

        /*
         *  fill request
         */
        ret = MPI_REQUEST_init(mpi_req,
                               FALSE,
                               REQ_SEND_X_SYNC,
                               comm,
                               tag,
                               NR_SENDRECV,
                               FILTER_DEFAULT,
                               data_buff,
                               data_type,
                               data_count,
                               NODE_node_id(),
                               to) ;

        /*
         *  Return
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Send_init,%p,%i,%i,%i,%i,%p,%p",
                             data_buff,
                             data_count,
                             data_type,
                             to,
                             tag,
                             comm,
                             mpi_req) ;
        #endif

        return ret ;
      }


   /* ................................................................. */


