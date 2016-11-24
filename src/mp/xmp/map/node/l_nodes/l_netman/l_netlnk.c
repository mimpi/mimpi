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

      #include "mp/xmp/map/node/l_nodes/l_netman/l_netlnk.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NETLNK_setup
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        int     i, ret, code, nsfd, myfd ;
        T_BOOL  ok ;
        T_CHAR   *host ;
        T_INT     port ;
        T_CHAR   *name ;
        t_params_xmp *XMP_params ;

        /*
         *  setup link flag
         */
        for (i=0; i < MAX_SOCKS; i++)
            {
              X_THREAD_init(&((node_info->linked)[i])) ;
            }

        /*
         *  setup id manager
         */
        ok = L_NETID_init(node_info) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  setup scrollbar
         */
        ok = L_SB_init( &(node_info->sb) ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  setup basic conections
         */
        XMP_params = PARAMS_XMP_getParams() ;
        host = XMP_params->host ;
        port = XMP_params->port ;
        ok = L_SB_connectToNs
             ( 
               &(node_info->sb), 
               &nsfd,
                host,
                port 
             ) ;
        FALSE_RET_FALSE(ok) ;
        ok = L_SB_creatMy
             ( 
               &(node_info->sb), 
               &myfd 
             ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  try to register myself
         */
        name = L_NETID_NodeToString(node_info->nodeid) ;
        ret  = L_NSI_writeInsert
               (
                 &(node_info->sb),
                  (node_info->sb).ns, 
                  name, 
                  L_SB_getFdAddress(&(node_info->sb),myfd),
                 &code 
               ) ;
        X_ALLOC_Free((void **)&(name)) ;
        if (ret < 0)
            return FALSE ;

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NETLNK_linkIncoming
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        T_BOOL  ok ;
        T_INT   who, fd ;

        /*
         *  receive connection
         */
        ok = L_NODEI_recvConnect( &(node_info->sb),
                                  &fd,
                                  &who ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  set translation
         */
        ok = L_NETID_set(node_info,who,fd) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  signal link
         */
        X_THREAD_signalReady(&((node_info->linked)[who])) ;

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NETLNK_linkOutgoing
      (
        OUT      t_nodeInfo    *node_info,
        IN       T_INT          who
      )
      {
        T_BOOL   ok ;
        int      code, ret, fd ;
        struct   sockaddr_in sa ;
        T_CHAR  *name ;

        /*
         *  ask who's address
         */
        name = L_NETID_NodeToString(who) ;
        NULL_RET_FALSE(name) ;
        ret  = L_NSI_writeOpen( &(node_info->sb),
                                 (node_info->sb).ns,
                                 (name),
                                &(sa),
                                &(code) ) ; 
        X_ALLOC_Free((void **)&(name)) ;
        if (ret < 0)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: fail at response from NS") ;
             return FALSE ;
           }
        if (code < 0)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: Can't open %d",
                                 who) ;
             return FALSE ;
           }

        /*
         *  connect to who
         */
        ok = L_NODEI_sendConnect( &(node_info->sb), 
                                  &(node_info->nodeid), 
                                  &sa,
                                  &fd ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  set translation
         */
        ok = L_NETID_set(node_info,who,fd) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  signal link
         */
        X_THREAD_signalReady(&((node_info->linked)[who])) ;

        /*
         *  Return ok
         */
        return TRUE ;
      }

      T_BOOL   L_NETLNK_finalize
      (
        OUT      t_nodeInfo    *node_info
      )
      {
        int       i, code ;
        T_BOOL    ok ;
 
        /*
         *  disconnect from ns 
         */
        ok = L_NSI_writeDisconnect( &(node_info->sb),
                                     (node_info->sb).ns,
                                    &code ) ;
        FALSE_RET_FALSE(ok) ;
 
        /*
         *  disconnect scrollbar
         */
        ok = L_SB_finalize( &(node_info->sb) ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  reset translation tables
         */
        ok = L_NETID_finalize( node_info ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  reset flag
         */
        for (i=0; i < MAX_SOCKS; i++)
            {
              X_THREAD_destroy(&((node_info->linked)[i])) ;
            }

        /*
         *  Return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

