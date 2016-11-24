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



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/xmp/map/node/l_nodes/l_nodecmd.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODECMD_finalize
      (
        OUT      t_nodeInfo      *node_info
      )
      {
        T_BOOL   ok ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"go finalize node") ;

        /*
         *  flag go down ...
         */
        (node_info->shutdown) = TRUE ;

        /*
         *  finalize per node resources
         */
        ok = L_REQMAN_finalize( node_info ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  finalize subnet
         */
        ok = L_NETMAN_finalize( node_info ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"ok when finalize nodec") ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

