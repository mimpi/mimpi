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

      #include "mp/mpi/mpi_reduce.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Reduce  
      ( 
        INOUT  void         *sendbuf, 
        INOUT  void         *recvbuf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           op, 
        IN     int           root, 
        IN     MPI_Comm      comm 
      )
      {
        int   ret ;
        t_params_mpi *xP ;

        /*
         *  console  
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                             sendbuf,
                             recvbuf,
                             count,
                             datatype,
                             op,
                             root,
                             comm) ;
        #endif

        /*
         *  get configuration
         */
        xP = PARAMS_MPI_getParams() ;

        /*
         *  use list diagram ...
         */
        if ( 
             (count >= xP->mpi_reduce_list_sync_low) 
                    &&
             (count <  xP->mpi_reduce_list_sync_high) 
           )
           {
             ret = MPI_REDUCE_LIST_sync_function(sendbuf,
                                               recvbuf,
                                               count,
                                               datatype,
                                               op,
                                               root,
                                               comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                                 sendbuf,
                                 recvbuf,
                                 count,
                                 datatype,
                                 op,
                                 root,
                                 comm) ;
             #endif

             return ret ;
           }
        if (
             (count >= xP->mpi_reduce_list_async_low) 
                    &&
             (count <  xP->mpi_reduce_list_async_high) 
           )
           {
             ret = MPI_REDUCE_LIST_async_function(sendbuf,
                                                recvbuf,
                                                count,
                                                datatype,
                                                op,
                                                root,
                                                comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                                 sendbuf,
                                 recvbuf,
                                 count,
                                 datatype,
                                 op,
                                 root,
                                 comm) ;
             #endif

             return ret ;
           }
        if (
             (count >= xP->mpi_reduce_list_join_low) 
                    &&
             (count <  xP->mpi_reduce_list_join_high) 
           )
           {
             ret = MPI_REDUCE_LIST_join_thread(sendbuf,
                                             recvbuf,
                                             count,
                                             datatype,
                                             op,
                                             root,
                                             comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                                 sendbuf,
                                 recvbuf,
                                 count,
                                 datatype,
                                 op,
                                 root,
                                 comm) ;
             #endif

             return ret ;
           }
        if (
             (count >= xP->mpi_reduce_list_disjoin_low) 
                    &&
             (count <  xP->mpi_reduce_list_disjoin_high) 
           )
           {
             ret = MPI_REDUCE_LIST_disjoin_thread(sendbuf,
                                                recvbuf,
                                                count,
                                                datatype,
                                                op,
                                                root,
                                                comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                                 sendbuf,
                                 recvbuf,
                                 count,
                                 datatype,
                                 op,
                                 root,
                                 comm) ;
             #endif

             return ret ;
           }

        /*
         *  use no diagram ...
         */
        if ( 
             (count >= xP->mpi_reduce_one_sync_low) 
                    && 
             (count <  xP->mpi_reduce_one_sync_high) 
           )
           {
             ret = MPI_REDUCE_ONE_sync_function(sendbuf,
                                              recvbuf,
                                              count,
                                              datatype,
                                              op,
                                              root,
                                              comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                                 sendbuf,
                                 recvbuf,
                                 count,
                                 datatype,
                                 op,
                                 root,
                                 comm) ;
             #endif

             return ret ;
           }

        /*
         *  ... default diagram
         */
        ret = MPI_REDUCE_LIST_join_thread(sendbuf,
                                        recvbuf,
                                        count,
                                        datatype,
                                        op,
                                        root,
                                        comm) ;

        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Reduce,%p,%p,%i,%p,%i,%i,%p",
                            sendbuf,
                            recvbuf,
                            count,
                            datatype,
                            op,
                            root,
                            comm) ;
        #endif

        return ret ;
      }


   /* ................................................................. */


