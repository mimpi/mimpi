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
      #define S_LIST_SYNC_LOW       "MPI_SCATTER_LIST_SYNC_LOW"
      #define S_LIST_SYNC_HIGH      "MPI_SCATTER_LIST_SYNC_HIGH"
      #define S_LIST_ASYNC_LOW      "MPI_SCATTER_LIST_ASYNC_LOW"
      #define S_LIST_ASYNC_HIGH     "MPI_SCATTER_LIST_ASYNC_HIGH"
      #define S_LIST_JOIN_LOW       "MPI_SCATTER_LIST_JOIN_LOW"
      #define S_LIST_JOIN_HIGH      "MPI_SCATTER_LIST_JOIN_HIGH"
      #define S_LIST_JOINLESS_LOW   "MPI_SCATTER_LIST_JOINLESS_LOW"
      #define S_LIST_JOINLESS_HIGH  "MPI_SCATTER_LIST_JOINLESS_HIGH"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_MPI_SCATTER_LIST_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_scatter_list_sync
         */
        params->mpi_scatter_list_sync_low   = 0 ;
        senv = getenv(S_LIST_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_scatter_list_sync_low  = atoi(senv) ;

        params->mpi_scatter_list_sync_high  = 8*1024 ;
        senv = getenv(S_LIST_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_scatter_list_sync_high = atoi(senv) ;

        /*
         *  mpi_scatter_list_async
         */
        params->mpi_scatter_list_async_low  = 0 ;
        senv = getenv(S_LIST_ASYNC_LOW) ;
        if (senv != NULL)
            params->mpi_scatter_list_async_low  = atoi(senv) ;

        params->mpi_scatter_list_async_high = 0 ;
        senv = getenv(S_LIST_ASYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_scatter_list_async_high = atoi(senv) ;

        /*
         *  mpi_scatter_list_join
         */
        params->mpi_scatter_list_join_low  = 0 ;
        senv = getenv(S_LIST_JOIN_LOW) ;
        if (senv != NULL)
            params->mpi_scatter_list_join_low  = atoi(senv) ;

        params->mpi_scatter_list_join_high = 128*1024*1024 ;
        senv = getenv(S_LIST_JOIN_HIGH) ;
        if (senv != NULL)
            params->mpi_scatter_list_join_high = atoi(senv) ;

        /*
         *  mpi_scatter_list_disjoin
         */
        params->mpi_scatter_list_disjoin_low  = 0 ;
        senv = getenv(S_LIST_JOINLESS_LOW) ;
        if (senv != NULL)
            params->mpi_scatter_list_disjoin_low  = atoi(senv) ;

        params->mpi_scatter_list_disjoin_high = 0 ;
        senv = getenv(S_LIST_JOINLESS_HIGH) ;
        if (senv != NULL)
            params->mpi_scatter_list_disjoin_high = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_SCATTER_put
      (
        OUT    t_params_mpi     *params
      )
      {
        T_BOOL    ok ;

        /*
         *  load by diagram type
         */
        ok = L_PARAMS_MPI_SCATTER_LIST_put(params) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

