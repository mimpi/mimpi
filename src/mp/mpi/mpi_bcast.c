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

      #include "mp/mpi/mpi_bcast.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Bcast        
      ( 
        INOUT  void         *buf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           root, 
        IN     MPI_Comm      comm 
      )
      {
        int   ret ;
        t_params_mpi *xP ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Broadcast,%p,%i,%i,%i,%p",
                              buf,
                              count,
                              datatype,
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
             (count >= xP->mpi_bcast_list_sync_low)
                   &&
             (count <  xP->mpi_bcast_list_sync_high) 
           )
           {
             ret = MPI_BCAST_LIST_sync_function(buf,
                                              count,
                                              datatype,
                                              root,
                                              comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if ( 
             (count >= xP->mpi_bcast_list_async_low)
                   &&
             (count <  xP->mpi_bcast_list_async_high) 
           )
           {
             ret = MPI_BCAST_LIST_async_function(buf,
                                               count,
                                               datatype,
                                               root,
                                               comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if ( 
             (count >= xP->mpi_bcast_list_join_low)  
                    && 
             (count <  xP->mpi_bcast_list_join_high) 
           )
           {
             ret = MPI_BCAST_LIST_join_thread(buf,
                                            count,
                                            datatype,
                                            root,
                                            comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if ( 
             (count >= xP->mpi_bcast_list_disjoin_low)  
                    && 
             (count <  xP->mpi_bcast_list_disjoin_high) 
           )
           {
             ret = MPI_BCAST_LIST_disjoin_thread(buf,
                                               count,
                                               datatype,
                                               root,
                                               comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }

        /* 
         *  tree diagram ...
         */
        if ( 
             (count >= xP->mpi_bcast_tree_sync_low)
                   &&
             (count <  xP->mpi_bcast_tree_sync_high) 
           )
           {
             ret = MPI_BCAST_TREE_sync_function(buf,
                                              count,
                                              datatype,
                                              root,
                                              comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if ( 
             (count >= xP->mpi_bcast_tree_async_low)
                   &&
             (count <  xP->mpi_bcast_tree_async_high) 
           )
           {
             ret = MPI_BCAST_TREE_async_function(buf,
                                               count,
                                               datatype,
                                               root,
                                               comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if ( 
             (count >= xP->mpi_bcast_tree_join_low)  
                    && 
             (count <  xP->mpi_bcast_tree_join_high) 
           )
           {
             ret = MPI_BCAST_TREE_join_thread(buf,
                                            count,
                                            datatype,
                                            root,
                                            comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }
        if ( 
             (count >= xP->mpi_bcast_tree_disjoin_low)  
                    && 
             (count <  xP->mpi_bcast_tree_disjoin_high) 
           )
           {
             ret = MPI_BCAST_TREE_disjoin_thread(buf,
                                               count,
                                               datatype,
                                               root,
                                               comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }

        /* 
         *  chain diagram ...
         */
        if ( 
             (count >= xP->mpi_bcast_chain_sync_low)  
                    && 
             (count <  xP->mpi_bcast_chain_sync_high) 
           )
           {
             ret = MPI_BCAST_CHAIN_sync_function(buf,
                                               count,
                                               datatype,
                                               root,
                                               comm) ;

             #if defined(__DEBUG__)
                 L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                                  buf,
                                  count,
                                  datatype,
                                  root,
                                  comm) ;
             #endif

             return ret ;
           }

        /*
         *  ... default diagram
         */
        ret = MPI_BCAST_LIST_join_thread(buf,
                                       count,
                                       datatype,
                                       root,
                                       comm) ;

        #if defined(__DEBUG__)
            L_STACK_MSG_Pop("MPI_Broadcast,%p,%i,%i,%i,%p",
                             buf,
                             count,
                             datatype,
                             root,
                             comm) ;
        #endif

        return ret ;
      }


   /* ................................................................. */

