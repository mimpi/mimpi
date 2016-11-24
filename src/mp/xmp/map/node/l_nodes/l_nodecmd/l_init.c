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

      T_BOOL   L_NODECMD_init
      (
        OUT      t_nodeInfo      *node_info,
        IN       int             *argc,
        IN       char          ***argv
      )
      {
        T_BOOL        ok ;
        T_LONG        isDynamic ;
        t_params_xmp *XMP_params ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"init nodec") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  init app. params
         */
        ok = PARAMS_XMP_put((*argc),(*argv),NULL) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  setup params
         */
        XMP_params = PARAMS_XMP_getParams() ;
        (node_info->shutdown)  = FALSE ;
        (node_info->nodeid)    = XMP_params->nodeid ;
        (node_info->nnodes)    = XMP_params->nnodes ;
        isDynamic = (T_BOOL)XMP_params->DYNAMIC_LINK ;

        /*
         *  setup per node resources
         */
        ok = L_REQMAN_setup(node_info) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  setup subnet
         */
        ok = L_NETMAN_setup(node_info) ;
        FALSE_RET_FALSE(ok) ;
        if (isDynamic == 0L)
           {
             ok = L_NETMAN_linkAll(node_info) ;
             FALSE_RET_FALSE(ok) ;
             ok = L_SNOOPY_createAllDaemons(node_info) ;
           }
        else
           {
             ok = L_SNOOPY_createControlDaemons(node_info) ;
           }
        FALSE_RET_FALSE(ok) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"ok init nodec") ;

        /*
         *  return ok
         */
        return ok ;
      }


   /* ................................................................. */

