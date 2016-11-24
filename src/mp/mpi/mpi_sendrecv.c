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

      #include "mp/mpi/mpi_sendrecv.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Sendrecv
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        IN     int           dest,
        IN     int           sendtag,

        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     int           source,
        IN     int           recvtag,

        IN     MPI_Comm      comm,
        IN     MPI_Status   *status
      )
      {
        int   oks, okr ;

        /*
         *  Send information
         */
        oks = MPI_Send
        (
          sendbuf,
          sendcount,
          senddatatype,
          dest,
          sendtag,
          comm
        ) ;

        /*
         *  Receive information
         */
        okr = MPI_Recv
        (
          recvbuf,
          recvcount,
          recvdatatype,
          dest,
          recvtag,
          comm,
          status
        ) ;

        /*
         *  Return
         */
        return ( (oks == MPI_ERR) ? MPI_ERR : okr ) ;
      }


   /* ................................................................. */


