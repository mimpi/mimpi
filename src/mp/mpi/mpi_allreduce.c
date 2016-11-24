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

      #include "mp/mpi/mpi_allreduce.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Allreduce  
      ( 
        INOUT  void         *sendbuf, 
        INOUT  void         *recvbuf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           op, 
        IN     MPI_Comm      comm 
      )
      {
        int   ret ;

        /*
         *  console  
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Allreduce,%p,%p,%i,%p,%i,%i,%p",
                             sendbuf,
                             recvbuf,
                             count,
                             datatype,
                             op,
                             comm) ;
        #endif

        /*
         *  Reduce to 0 ...
         */
        ret = MPI_Reduce(sendbuf,
                         recvbuf,
                         count,
                         datatype,
                         op,
                         0,
                         comm) ;

        if (MPI_ERR == ret)
           {
             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Allreduce,%p,%p,%i,%p,%i,%i,%p",
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

        /*
         *  ... and Broadcast.
         */
        ret = MPI_Bcast(recvbuf,
                        count,
                        datatype,
                        0,
                        comm) ;

        if (MPI_ERR == ret)
           {
             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Allreduce,%p,%p,%i,%p,%i,%i,%p",
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


        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Allreduce,%p,%p,%i,%p,%i,%i,%p",
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


