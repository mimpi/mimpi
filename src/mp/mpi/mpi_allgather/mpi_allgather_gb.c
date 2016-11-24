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

      #include "mp/mpi/mpi_allgather/mpi_allgather_gb.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_ALLGATHER_GB
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     MPI_Comm      comm
      )
      {
        int   ret ;
        int   comm_size ;

        /*
         *  console  
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_ALLGATHER_GB,%p,%p,%i,%p,%i,%i,%p",
                             sendbuf,
                             recvbuf,
                             count,
                             datatype,
                             op,
                             comm) ;
        #endif

        /*
         *  Gather to 0 ...
         */
        ret = MPI_Gather(sendbuf,
                         sendcount,
                         senddatatype,
                         recvbuf,
                         recvcount,
                         recvdatatype,
                         0,
                         comm) ;

        if (MPI_ERR == ret)
            goto LABEL_MPI_ALLGATHER_GB_ERROR ;

        /*
         *  ... and Broadcast.
         */
        MPI_Comm_size(comm, &comm_size);

        ret = MPI_Bcast(recvbuf,
                        recvcount * comm_size,
                        recvdatatype,
                        0,
                        comm) ;

        if (MPI_ERR == ret)
            goto LABEL_MPI_ALLGATHER_GB_ERROR ;
        else
            goto LABEL_MPI_ALLGATHER_GB_OK ;


        /*
         *  Return
         */
        LABEL_MPI_ALLGATHER_GB_OK :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_ALLGATHER_GB,%p,%p,%i,%p,%i,%i,%p",
                               sendbuf,
                               recvbuf,
                               count,
                               datatype,
                               op,
                               root,
                               comm) ;
           #endif

           return MPI_SUCCESS ;

        LABEL_MPI_ALLGATHER_GB_ERROR :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_ALLGATHER_GB,%p,%p,%i,%p,%i,%i,%p",
                               sendbuf,
                               recvbuf,
                               count,
                               datatype,
                               op,
                               root,
                               comm) ;
           #endif

           return MPI_ERR ;
      }


   /* ................................................................. */


