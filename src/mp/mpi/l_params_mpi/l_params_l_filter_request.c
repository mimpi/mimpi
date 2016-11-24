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
      #include "mp/mpi/l_filter_request.h"


   /* ... Const / Constantes .......................................... */

      /*
       *  env. keys 
       */
      #define L_FILTER_REQ_Z        "COMPRESSION"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_L_FILTER_REQUEST_put
      ( 
        OUT    t_params_mpi     *params
      )
      {
        T_CHAR   *senv ;

        /*
         *  clevel
         */
        params->l_filter_request_clevel       = ZL_NO_COMPRESSION ;
        senv = getenv(L_FILTER_REQ_Z) ;
        if (senv != NULL)
           {
             if (X_STRING_Equal(senv,"BEST_SPEED") == TRUE)
                 params->l_filter_request_clevel = ZL_BEST_SPEED ;
             if (X_STRING_Equal(senv,"BEST_COMPRESS") == TRUE)
                 params->l_filter_request_clevel = ZL_BEST_COMPRESSION ;
           }

        /*
         *  return ok  
         */
        return TRUE ;
      }


   /* ................................................................. */

