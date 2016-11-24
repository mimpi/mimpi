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
      #define G_LIST_SYNC_LOW       "MPI_GATHER_LIST_SYNC_LOW"
      #define G_LIST_SYNC_HIGH      "MPI_GATHER_LIST_SYNC_HIGH"
      #define G_LIST_ASYNC_LOW      "MPI_GATHER_LIST_ASYNC_LOW"
      #define G_LIST_ASYNC_HIGH     "MPI_GATHER_LIST_ASYNC_HIGH"
      #define G_LIST_JOIN_LOW       "MPI_GATHER_LIST_JOIN_LOW"
      #define G_LIST_JOIN_HIGH      "MPI_GATHER_LIST_JOIN_HIGH"
      #define G_LIST_JOINLESS_LOW   "MPI_GATHER_LIST_JOINLESS_LOW"
      #define G_LIST_JOINLESS_HIGH  "MPI_GATHER_LIST_JOINLESS_HIGH"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_MPI_GATHER_LIST_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  mpi_gather_list_sync
         */
        params->mpi_gather_list_sync_low   = 0 ;
        senv = getenv(G_LIST_SYNC_LOW) ;
        if (senv != NULL)
            params->mpi_gather_list_sync_low  = atoi(senv) ;

        params->mpi_gather_list_sync_high  = 8*1024 ;
        senv = getenv(G_LIST_SYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_gather_list_sync_high = atoi(senv) ;

        /*
         *  mpi_gather_list_async
         */
        params->mpi_gather_list_async_low  = 0 ;
        senv = getenv(G_LIST_ASYNC_LOW) ;
        if (senv != NULL)
            params->mpi_gather_list_async_low  = atoi(senv) ;

        params->mpi_gather_list_async_high = 0 ;
        senv = getenv(G_LIST_ASYNC_HIGH) ;
        if (senv != NULL)
            params->mpi_gather_list_async_high = atoi(senv) ;

        /*
         *  mpi_gather_list_join
         */
        params->mpi_gather_list_join_low  = 8*1024 ;
        senv = getenv(G_LIST_JOIN_LOW) ;
        if (senv != NULL)
            params->mpi_gather_list_join_low  = atoi(senv) ;

        params->mpi_gather_list_join_high = 128*1024*1024 ;
        senv = getenv(G_LIST_JOIN_HIGH) ;
        if (senv != NULL)
            params->mpi_gather_list_join_high = atoi(senv) ;

        /*
         *  mpi_gather_list_disjoin
         */
        params->mpi_gather_list_disjoin_low  = 0 ;
        senv = getenv(G_LIST_JOINLESS_LOW) ;
        if (senv != NULL)
            params->mpi_gather_list_disjoin_low  = atoi(senv) ;

        params->mpi_gather_list_disjoin_high = 0 ;
        senv = getenv(G_LIST_JOINLESS_HIGH) ;
        if (senv != NULL)
            params->mpi_gather_list_disjoin_high = atoi(senv) ;

        /*
         *  return ok  
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_MPI_GATHER_put
      (
        OUT    t_params_mpi     *params
      )
      {
        T_BOOL    ok ;

        /*
         *  load by diagram type
         */
        ok = L_PARAMS_MPI_GATHER_LIST_put(params) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

