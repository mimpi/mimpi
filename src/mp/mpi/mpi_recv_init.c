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

      #include "mp/mpi/mpi_recv_init.h"


   /* ... Functions / Funciones ....................................... */

      int     MPI_Recv_init
      ( 
        IN        char         *data_buff,
        IN        int           data_count,
        IN        MPI_Datatype  data_type,
        IN        int           from,
        IN        int           tag,
        IN        MPI_Comm      comm,
        INOUT     MPI_Request  *mpi_req
      )
      {
        int   ret ;

        ret = MPI_REQUEST_init(mpi_req,
                               FALSE,
                               REQ_RECEIVE_X_SYNC,
                               comm,
                               tag,
                               NR_SENDRECV,
                               FILTER_DEFAULT,
                               data_buff,
                               data_type,
                               data_count,
                               from,
                               NODE_node_id()) ;

        /*
         *  Return
         */
        return ret ;
      }


   /* ................................................................. */


