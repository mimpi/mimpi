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

      #include "mp/xmp/map/node/l_nodes/l_netman/l_netid.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NETID_init
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        int       i ;
        T_INT     nodeid ;
        T_INT     nnodes ;
        t_params_xmp *XMP_params ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /* 
         *  get params 
         */
        XMP_params = PARAMS_XMP_getParams() ;
        (node_info->nodeid) = XMP_params->nodeid ;
        (node_info->nnodes) = XMP_params->nnodes ;

        /* 
         *  setup translation tables
         */
        nodeid  = XMP_params->nodeid ;
        nnodes  = XMP_params->nnodes ;
        for (i=0; i < MAX_SOCKS; i++)
            {
              if (
                   ( i != (node_info->nodeid) )
                              &&
                   ( i <  (node_info->nnodes) )
                 )
                 {
                   (node_info->node2sock)[i]   = NID_NULL ;
                   (node_info->sock2node)[i]   = NID_NULL ;
                 }
              else
                 {
                   (node_info->node2sock)[i]   = NID_ERROR ;
                   (node_info->sock2node)[i]   = NID_ERROR ;
                 }
            }

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NETID_set
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          who,
        IN       T_INT          fd
      )
      {
         /*
          *  check params
          */
         NULL__SET_ERROR__RET_FALSE(node_info) ;

         /*
          *  setup translation
          */
         (node_info->node2sock)[who] = fd ;
         (node_info->sock2node)[fd]  = who ;

         /*
          *  Return ok
          */
        return TRUE ;
      }

      T_BOOL   L_NETID_finalize
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        T_INT i ;

        /*
         *  reset translation table
         */
        for (i=0; i < MAX_SOCKS; i++)
            {
              (node_info->node2sock)[i] = NID_ERROR ;
              (node_info->sock2node)[i] = NID_ERROR ;
            }

        /*
         *  Return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

