

#ifndef L_PARAMS_MPI_H
#define L_PARAMS_MPI_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"


  /* ... Types / Tipos ........................................*/

     typedef
     struct
     {

        /*
         *  broadcast
         *  ---------
         */

        long mpi_bcast_list_sync_low ;
        long mpi_bcast_list_sync_high ;
        long mpi_bcast_list_async_low ;
        long mpi_bcast_list_async_high ;
        long mpi_bcast_list_join_low ;
        long mpi_bcast_list_join_high ;
        long mpi_bcast_list_disjoin_low ;
        long mpi_bcast_list_disjoin_high ;

        long mpi_bcast_tree_sync_low ;
        long mpi_bcast_tree_sync_high ;
        long mpi_bcast_tree_async_low ;
        long mpi_bcast_tree_async_high ;
        long mpi_bcast_tree_join_low ;
        long mpi_bcast_tree_join_high ;
        long mpi_bcast_tree_disjoin_low ;
        long mpi_bcast_tree_disjoin_high ;

        long mpi_bcast_chain_sync_low ;
        long mpi_bcast_chain_sync_high ;

        /*
         *  gather
         *  ------
         */

        long mpi_gather_list_sync_low ;
        long mpi_gather_list_sync_high ;
        long mpi_gather_list_async_low ;
        long mpi_gather_list_async_high ;
        long mpi_gather_list_join_low ;
        long mpi_gather_list_join_high ;
        long mpi_gather_list_disjoin_low ;
        long mpi_gather_list_disjoin_high ;

        /*
         *  scatter
         *  -------
         */

        long mpi_scatter_list_sync_low ;
        long mpi_scatter_list_sync_high ;
        long mpi_scatter_list_async_low ;
        long mpi_scatter_list_async_high ;
        long mpi_scatter_list_join_low ;
        long mpi_scatter_list_join_high ;
        long mpi_scatter_list_disjoin_low ;
        long mpi_scatter_list_disjoin_high ;

        /*
         *  reduce
         *  ------
         */

        long mpi_reduce_list_sync_low ;
        long mpi_reduce_list_sync_high ;
        long mpi_reduce_list_async_low ;
        long mpi_reduce_list_async_high ;
        long mpi_reduce_list_join_low ;
        long mpi_reduce_list_join_high ;
        long mpi_reduce_list_disjoin_low ;
        long mpi_reduce_list_disjoin_high ;

        long mpi_reduce_one_sync_low ;
        long mpi_reduce_one_sync_high ;

        /*
         *  l_filter_request
         *  ----------------
         */

        long l_filter_request_clevel ;

     } t_params_mpi ;


  /* ... Functions / Funciones ................................*/

     T_BOOL   L_PARAMS_MPI_BCAST_put
     (
       OUT    t_params_mpi     *params
     ) ;

     T_BOOL   L_PARAMS_MPI_GATHER_put
     (
       OUT    t_params_mpi     *params
     ) ;

     T_BOOL   L_PARAMS_MPI_SCATTER_put
     (
       OUT    t_params_mpi     *params
     ) ;

     T_BOOL   L_PARAMS_MPI_REDUCE_put
     (
       OUT    t_params_mpi     *params
     ) ;

     T_BOOL   L_PARAMS_L_FILTER_REQUEST_put
     (
       OUT    t_params_mpi     *params
     ) ;


  /* ..........................................................*/

 
 #ifdef  __cplusplus
    }
 #endif
 
#endif

