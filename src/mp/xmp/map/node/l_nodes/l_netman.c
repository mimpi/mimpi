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

      #include "mp/xmp/map/node/l_nodes/l_netman.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NETMAN_setup
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        t_params_xmp *XMP_params ;
        T_BOOL        ok ;

        /*
         *  setup params values
         */
        (node_info->shutdown) = FALSE ;
        XMP_params            = PARAMS_XMP_getParams() ;
        (node_info->nodeid)   = XMP_params->nodeid ;
        (node_info->nnodes)   = XMP_params->nnodes ;

        /*
         *  setup id manager
         */
        ok = L_NETLNK_setup(node_info) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NETMAN_linkAll
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        int      i ;
        T_BOOL   ok ;

        /*
         *  link all with all 
         */
        for (i=0; i < node_info->nnodes; i++)
            {
                if ((node_info->nodeid) < i)
                   {
                     ok = L_NETLNK_linkIncoming(node_info) ;
                     FALSE_RET_FALSE(ok) ;
                   }
                if ((node_info->nodeid) > i)
                   {
                     ok = L_NETLNK_linkOutgoing(node_info,i) ;
                     FALSE_RET_FALSE(ok) ;
                   }
            }

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NETMAN_linkTo
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          to
      )
      {
        T_BOOL   ok ;

        /*
         *  Link and sync
         */
        X_THREAD_lock( &((node_info->linked)[to]) ) ;
        if ( ((node_info->linked)[to]).ready == FALSE )
           {
             if ( (node_info->nnodes) > to)
                {
                  if ( (node_info->nodeid) > to )
                     {
                        ok = L_NETLNK_linkOutgoing(node_info,to) ;
                     }
                  else 
                     {
                        X_THREAD_waitReady( &((node_info->linked)[to]) ) ;
                        ok = TRUE ;
                     }
                }
             else 
                {
                  ok = FALSE ;
                }
           }
        else
           {
             ok = TRUE ;
           }
        X_THREAD_unlock( &((node_info->linked)[to]) ) ;

        /*
         *  Return 'ok'.
         */
        return ok ;
      }

      T_BOOL   L_NETMAN_finalize
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        T_BOOL    ok ;
 
        /*
         *  finalize net link
         */
        ok = L_NETLNK_finalize(node_info) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  Return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

