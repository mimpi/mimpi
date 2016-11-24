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



   /* ... Include / Inclusiones ....................................... */

      #include "mp/mpi/params_mpi.h"


   /* ... Glob. Var / Var. Global ..................................... */

      t_params_mpi  PARAMS_MPI_param ;


   /* ... Functions / Funciones ....................................... */

      T_BOOL   PARAMS_MPI_put 
      ( 
        IN     int            argc,
        IN     char         **argv 
      )
      {
        T_BOOL     ok ;

        /*
         *  put each componets
         */
        ok = L_PARAMS_MPI_BCAST_put(&(PARAMS_MPI_param)) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_MPI_GATHER_put(&(PARAMS_MPI_param)) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_MPI_SCATTER_put(&(PARAMS_MPI_param)) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_MPI_REDUCE_put(&(PARAMS_MPI_param)) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_PARAMS_L_FILTER_REQUEST_put(&(PARAMS_MPI_param)) ;
        FALSE_RET_FALSE(ok) ;
 
        /*
         *  return ok
         */
        return TRUE ;
      }

      t_params_mpi  *PARAMS_MPI_getParams 
      ( 
        void 
      )
      {
        return &(PARAMS_MPI_param) ;
      }


  /* .................................................................... */

