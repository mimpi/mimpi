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
      #define R_LIST_SYNC_LOW       "MPI_REDUCE_LIST_SYNC_LOW"
      #define R_LIST_SYNC_HIGH      "MPI_REDUCE_LIST_SYNC_HIGH"
      #define R_LIST_ASYNC_LOW      "MPI_REDUCE_LIST_ASYNC_LOW"
      #define R_LIST_ASYNC_HIGH     "MPI_REDUCE_LIST_ASYNC_HIGH"
      #define R_LIST_JOIN_LOW       "MPI_REDUCE_LIST_JOIN_LOW"
      #define R_LIST_JOIN_HIGH      "MPI_REDUCE_LIST_JOIN_HIGH"
      #define R_LIST_JOINLESS_LOW   "MPI_REDUCE_LIST_JOINLESS_LOW"
      #define R_LIST_JOINLESS_HIGH  "MPI_REDUCE_LIST_JOINLESS_HIGH"

      #define R_ONE_SYNC_LOW        "MPI_REDUCE_ONE_SYNC_LOW"
      #define R_ONE_SYNC_HIGH       "MPI_REDUCE_ONE_SYNC_HIGH"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_MPI_REDUCE_LIST_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_reduce_list_sync
         */
        params->mpi_reduce_list_sync_low   = 0 ;
        senv = getenv(R_LIST_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_reduce_list_sync_low  = atoi(senv) ;

        params->mpi_reduce_list_sync_high  = 8*1024 ;
        senv = getenv(R_LIST_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_reduce_list_sync_high = atoi(senv) ;

        /*
         *  mpi_reduce_list_async
         */
        params->mpi_reduce_list_async_low  = 0 ;
        senv = getenv(R_LIST_ASYNC_LOW) ;
        if (senv != NULL)
            params->mpi_reduce_list_async_low  = atoi(senv) ;

        params->mpi_reduce_list_async_high = 0 ;
        senv = getenv(R_LIST_ASYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_reduce_list_async_high = atoi(senv) ;

        /*
         *  mpi_reduce_list_join
         */
        params->mpi_reduce_list_join_low  = 0 ;
        senv = getenv(R_LIST_JOIN_LOW) ;
        if (senv != NULL)
            params->mpi_reduce_list_join_low  = atoi(senv) ;

        params->mpi_reduce_list_join_high = 128*1024*1024 ;
        senv = getenv(R_LIST_JOIN_HIGH) ;
        if (senv != NULL)
            params->mpi_reduce_list_join_high = atoi(senv) ;

        /*
         *  mpi_reduce_list_disjoin
         */
        params->mpi_reduce_list_disjoin_low  = 0 ;
        senv = getenv(R_LIST_JOINLESS_LOW) ;
        if (senv != NULL)
            params->mpi_reduce_list_disjoin_low  = atoi(senv) ;

        params->mpi_reduce_list_disjoin_high = 0 ;
        senv = getenv(R_LIST_JOINLESS_HIGH) ;
        if (senv != NULL)
            params->mpi_reduce_list_disjoin_high = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_REDUCE_ONE_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_reduce_one_sync
         */
        params->mpi_reduce_one_sync_low         = 8*1024 ;
        senv = getenv(R_ONE_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_reduce_one_sync_low     = atoi(senv) ;

        params->mpi_reduce_one_sync_high        = 64*1024 ;
        senv = getenv(R_ONE_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_reduce_one_sync_high    = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_REDUCE_put
      (
        OUT    t_params_mpi     *params
      )
      {
        T_BOOL    ok ;

        /*
         *  load by diagram type
         */
        ok = L_PARAMS_MPI_REDUCE_LIST_put(params) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_MPI_REDUCE_ONE_put(params) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

