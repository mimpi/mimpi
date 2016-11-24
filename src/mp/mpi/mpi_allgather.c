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

      #include "mp/mpi/mpi_allgather.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Allgather  
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

        /*
         *  console  
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Allgather,%p,%p,%i,%p,%i,%i,%p",
                             sendbuf,
                             recvbuf,
                             count,
                             datatype,
                             op,
                             comm) ;
        #endif

        /*
	 *  default
	 */
        ret = MPI_ALLGATHER_GB(sendbuf,
                               sendcount,
                               senddatatype,
                               recvbuf,
                               recvcount,
                               recvdatatype,
                               comm) ;

        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Allgather,%p,%p,%i,%p,%i,%i,%p",
                            sendbuf,
                            recvbuf,
                            count,
                            datatype,
                            op,
                            root,
                            comm) ;
        #endif

        return MPI_SUCCESS ;
      }


   /* ................................................................. */


