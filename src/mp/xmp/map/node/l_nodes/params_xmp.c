/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusiones ....................................... */

      #include "mp/xmp/map/node/l_nodes/params_xmp.h"


   /* ... Glob. Var / Var. Global ..................................... */

      t_params_xmp  PARAMS_XMP_param ;


   /* ... Functions / Funciones ....................................... */

      T_BOOL         PARAMS_XMP_put
      (
         IN     int             argc,
         IN     char          **argv,
         IN     char          **envv
      )
      {
        T_BOOL     ok ;

        /*
         *  put sb 
         */
        ok = L_PARAMS_XMP_SB_put( argc, argv, envv, &(PARAMS_XMP_param) ) ;
        FALSE_RET_FALSE(ok) ;
 
        /*
         *  put nodes 
         */
        ok = L_PARAMS_XMP_NODES_put( &(PARAMS_XMP_param) ) ;
        FALSE_RET_FALSE(ok) ;
 
        /*
         *  allways true
         */
        return TRUE ;
      }

      t_params_xmp  *PARAMS_XMP_getParams
      (
        void
      )
      {
        /*
         *  return current params
         */
        return &(PARAMS_XMP_param) ;
      }


  /* .................................................................... */

