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

      #include "mp/mpi/mpi_request.h"


   /* ... Functions / Funciones ....................................... */

      int     MPI_REQUEST_init
      ( 
        INOUT     MPI_Request  *MPI_req,
        IN        T_BOOL        ok,
        IN        T_INT         reqid,
        IN        MPI_Comm      comm,
        IN        int           tx,
        IN        int           ty,
        IN        int           filter,
        IN        char         *data_buff,
        IN        MPI_Datatype  data_type,
        IN        int           data_size,
        IN        int           from,
        IN        int           to
      )
      {
        /*
         *  initialize mpi request
         */
        MPI_req->ok        = ok ;
        MPI_req->reqid     = reqid ;
        MPI_req->comm      = comm ;
        MPI_req->tx        = tx ;
        MPI_req->ty        = ty ;
        MPI_req->filter    = filter ;
        MPI_req->data_buff = data_buff ;
        MPI_req->data_type = data_type ;
        MPI_req->data_size = data_size ;
        MPI_req->from      = from ;
        MPI_req->to        = to ;

        /*
         *  Return
         */
        return MPI_SUCCESS ;
      }


   /* ................................................................. */


