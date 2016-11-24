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

      #include "mp/xmp/map/node_server/l_ns/l_ns_params.h"


   /* ... Glob. Var / Var. Global ..................................... */

      t_params_ns   L_PARAMS_NS_param ;


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NS_PARAMS_init      
      ( 
        IN     int            argc,
        IN     char         **argv 
      )
      {
        T_BOOL     ok ;

        ok = L_NS_PARAMS_SB_put( argc, argv, &(L_PARAMS_NS_param) ) ;
        FALSE_RET_FALSE(ok) ;
 
        return TRUE ;
      }

      t_params_ns   *L_PARAMS_NS_getParams 
      ( 
        void 
      )
      {
        return &(L_PARAMS_NS_param) ;
      }


  /* .................................................................... */

