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

      #include "mp/xmp/map/node/l_nodes/l_params_xmp.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_XMP_NODES_put 
      (
        OUT    t_params_xmp  *params
      )
      {
        T_CHAR *penv ;

        /*
         *  setup node
         */
        params->DYNAMIC_LINK       = 0 ;
        penv = getenv("XMP_LINK_D") ;
        if ( penv == NULL )
                   params->DYNAMIC_LINK = 0 ;
              else params->DYNAMIC_LINK = 1 ;

        params->MAX_RECV_THROUGH   = LONG_MAX ;
        penv = getenv("XMP_RECV_THROUGH_MAX") ;
        if ( penv == NULL )
                   params->MAX_RECV_THROUGH = LONG_MAX ;
              else params->MAX_RECV_THROUGH = atoi(penv) ;

        params->MAX_SEND_THROUGH   = LONG_MAX ;
        penv = getenv("XMP_SEND_THROUGH_MAX") ;
        if ( penv == NULL )
                   params->MAX_SEND_THROUGH = LONG_MAX ;
              else params->MAX_SEND_THROUGH = atoi(penv) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


  /* .................................................................... */

