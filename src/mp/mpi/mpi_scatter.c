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

      #include "mp/mpi/mpi_scatter.h"


   /* ... Functions / Funciones ....................................... */

      int   MPI_Scatter     
      ( 
        INOUT  void         *sendbuf, 
        IN     int           sendcount, 
        IN     MPI_Datatype  senddatatype, 
        INOUT  void         *recvbuf, 
        IN     int           recvcount, 
        IN     MPI_Datatype  recvdatatype, 
        IN     int           root, 
        IN     MPI_Comm      comm 
      )
      {
        int ret ;
        t_params_mpi *xP ;

        /*
         *  console  
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Scatter,%p,%i,%i,%p,%i,%i,%i,%p",
                              sendbuf,
                              sendcount,
                              senddatatype,
                              recvbuf,
                              recvcount,
                              recvdatatype,
                              root,
                              comm) ;
        #endif

        /*
         *  get configuration
         */
        xP = PARAMS_MPI_getParams() ;

        /*
         *  list diagram ...
         */
        if (
             (sendcount >= xP->mpi_scatter_list_sync_low)
                   &&
             (sendcount <  xP->mpi_scatter_list_sync_high)
           )
           {
             ret = MPI_SCATTER_LIST_sync_function(sendbuf,
                                                  sendcount,
                                                  senddatatype,
                                                  recvbuf,
                                                  recvcount,
                                                  recvdatatype,
                                                  root,
                                                  comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("SCATTER,%p,%i,%i,%p,%i,%i,%i,%p",
                                  sendbuf,
                                  sendcount,
                                  senddatatype,
                                  recvbuf,
                                  recvcount,
                                  recvdatatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if (
             (sendcount >= xP->mpi_scatter_list_async_low)
                   &&
             (sendcount <  xP->mpi_scatter_list_async_high)
           )
           {
             ret = MPI_SCATTER_LIST_async_function(sendbuf,
                                                   sendcount,
                                                   senddatatype,
                                                   recvbuf,
                                                   recvcount,
                                                   recvdatatype,
                                                   root,
                                                   comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("SCATTER,%p,%i,%i,%p,%i,%i,%i,%p",
                                  sendbuf,
                                  sendcount,
                                  senddatatype,
                                  recvbuf,
                                  recvcount,
                                  recvdatatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if (
             (sendcount >= xP->mpi_scatter_list_join_low)
                    &&
             (sendcount <  xP->mpi_scatter_list_join_high)
           )
           {
             ret = MPI_SCATTER_LIST_join_thread(sendbuf,
                                                sendcount,
                                                senddatatype,
                                                recvbuf,
                                                recvcount,
                                                recvdatatype,
                                                root,
                                                comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("SCATTER,%p,%i,%i,%p,%i,%i,%i,%p",
                                  sendbuf,
                                  sendcount,
                                  senddatatype,
                                  recvbuf,
                                  recvcount,
                                  recvdatatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if (
             (sendcount >= xP->mpi_scatter_list_disjoin_low)
                    &&
             (sendcount <  xP->mpi_scatter_list_disjoin_high)
           )
           {
             ret = MPI_SCATTER_LIST_disjoin_thread(sendbuf,
                                                   sendcount,
                                                   senddatatype,
                                                   recvbuf,
                                                   recvcount,
                                                   recvdatatype,
                                                   root,
                                                   comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("SCATTER,%p,%i,%i,%p,%i,%i,%i,%p",
                                  sendbuf,
                                  sendcount,
                                  senddatatype,
                                  recvbuf,
                                  recvcount,
                                  recvdatatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }

        /*
         *  ... default diagram
         */
        ret = MPI_SCATTER_LIST_join_thread(sendbuf,
                                         sendcount,
                                         senddatatype,
                                         recvbuf,
                                         recvcount,
                                         recvdatatype,
                                         root,
                                         comm) ;

        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Scatter,%p,%i,%i,%p,%i,%i,%i,%p",
                             sendbuf,
                             sendcount,
                             senddatatype,
                             recvbuf,
                             recvcount,
                             recvdatatype,
                             root,
                             comm) ;
        #endif

        return ret ;
      }

                
   /* ................................................................. */


