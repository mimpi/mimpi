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

      #include "mp/mpi/l_params_mpi.h"


   /* ... Const / Constantes .......................................... */

      /*
       *  env. keys 
       */
      #define B_LIST_ASYNC_LOW       "MPI_BCAST_LIST_ASYNC_LOW"
      #define B_LIST_ASYNC_HIGH      "MPI_BCAST_LIST_ASYNC_HIGH"
      #define B_LIST_SYNC_LOW        "MPI_BCAST_LIST_SYNC_LOW"
      #define B_LIST_SYNC_HIGH       "MPI_BCAST_LIST_SYNC_HIGH"
      #define B_LIST_JOINLESS_LOW    "MPI_BCAST_LIST_JOINLESS_LOW"
      #define B_LIST_JOINLESS_HIGH   "MPI_BCAST_LIST_JOINLESS_HIGH"
      #define B_LIST_JOIN_LOW        "MPI_BCAST_LIST_JOIN_LOW"
      #define B_LIST_JOIN_HIGH       "MPI_BCAST_LIST_JOIN_HIGH"

      #define B_TREE_ASYNC_LOW       "MPI_BCAST_TREE_ASYNC_LOW"
      #define B_TREE_ASYNC_HIGH      "MPI_BCAST_TREE_ASYNC_HIGH"
      #define B_TREE_SYNC_LOW        "MPI_BCAST_TREE_SYNC_LOW"
      #define B_TREE_SYNC_HIGH       "MPI_BCAST_TREE_SYNC_HIGH"
      #define B_TREE_JOINLESS_LOW    "MPI_BCAST_TREE_JOINLESS_LOW"
      #define B_TREE_JOINLESS_HIGH   "MPI_BCAST_TREE_JOINLESS_HIGH"
      #define B_TREE_JOIN_LOW        "MPI_BCAST_TREE_JOIN_LOW"
      #define B_TREE_JOIN_HIGH       "MPI_BCAST_TREE_JOIN_HIGH"

      #define B_CHAIN_SYNC_LOW        "MPI_BCAST_CHAIN_SYNC_LOW"
      #define B_CHAIN_SYNC_HIGH       "MPI_BCAST_CHAIN_SYNC_HIGH"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_MPI_BCAST_LIST_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_bcast_async
         */
        params->mpi_bcast_list_async_low      = 0 ;
        senv = getenv(B_LIST_ASYNC_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_list_async_low  = atoi(senv) ;

        params->mpi_bcast_list_async_high     = 0 ;
        senv = getenv(B_LIST_ASYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_list_async_high = atoi(senv) ;

        /*
         *  mpi_bcast_sync
         */
        params->mpi_bcast_list_sync_low      = 0 ;
        senv = getenv(B_LIST_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_list_sync_low  = atoi(senv) ;

        params->mpi_bcast_list_sync_high     = 32*1024 ;
        senv = getenv(B_LIST_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_list_sync_high = atoi(senv) ;

        /*
         *  mpi_bcast_joinless
         */
        params->mpi_bcast_list_disjoin_low      = 0 ;
        senv = getenv(B_LIST_JOINLESS_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_list_disjoin_low  = atoi(senv) ;

        params->mpi_bcast_list_disjoin_high     = 0 ;
        senv = getenv(B_LIST_JOINLESS_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_list_disjoin_high = atoi(senv) ;

        /*
         *  mpi_bcast_join
         */
        params->mpi_bcast_list_join_low      = 32*1024 ;
        senv = getenv(B_LIST_JOIN_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_list_join_low  = atoi(senv) ;

        params->mpi_bcast_list_join_high     = 128*1024*1024 ;
        senv = getenv(B_LIST_JOIN_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_list_join_high = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_BCAST_TREE_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_bcast_async
         */
        params->mpi_bcast_tree_async_low      = 0 ;
        senv = getenv(B_TREE_ASYNC_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_tree_async_low  = atoi(senv) ;

        params->mpi_bcast_tree_async_high     = 0 ;
        senv = getenv(B_TREE_ASYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_tree_async_high = atoi(senv) ;

        /*
         *  mpi_bcast_sync
         */
        params->mpi_bcast_tree_sync_low      = 0 ;
        senv = getenv(B_TREE_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_tree_sync_low  = atoi(senv) ;

        params->mpi_bcast_tree_sync_high     = 4*1024 ;
        senv = getenv(B_TREE_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_tree_sync_high = atoi(senv) ;

        /*
         *  mpi_bcast_joinless
         */
        params->mpi_bcast_tree_disjoin_low      = 0 ;
        senv = getenv(B_TREE_JOINLESS_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_tree_disjoin_low  = atoi(senv) ;

        params->mpi_bcast_tree_disjoin_high     = 0 ;
        senv = getenv(B_TREE_JOINLESS_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_tree_disjoin_high = atoi(senv) ;

        /*
         *  mpi_bcast_join
         */
        params->mpi_bcast_tree_join_low      = 4*1024 ;
        senv = getenv(B_TREE_JOIN_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_tree_join_low  = atoi(senv) ;

        params->mpi_bcast_tree_join_high     = 128*1024*1024 ;
        senv = getenv(B_TREE_JOIN_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_tree_join_high = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_BCAST_CHAIN_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_bcast_sync
         */
        params->mpi_bcast_chain_sync_low      = 0 ;
        senv = getenv(B_CHAIN_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_bcast_chain_sync_low  = atoi(senv) ;

        params->mpi_bcast_chain_sync_high     = 4*1024 ;
        senv = getenv(B_CHAIN_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_bcast_chain_sync_high = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_BCAST_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_BOOL    ok ;

        /*
         *  load by diagram type
         */
        ok = L_PARAMS_MPI_BCAST_LIST_put(params) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_MPI_BCAST_TREE_put(params) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_MPI_BCAST_CHAIN_put(params) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }


   /* ................................................................. */

