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



   /* ... Includes .................................................... */

      #include "mp/xmp/map/node_server/l_ns.h"


   /* ... Funciones ................................................... */

      /*
       *  L_NS_init
       * -----------
       */
      T_BOOL   L_NS_init  
      ( 
        IN      int        argc,
        IN      char      *argv[],
        INOUT   t_nsInfo  *nsinfo 
      )
      {
        char    *ns_host ;
        int      ns_port ;
        int      nodeid, nnodes ;
        int      ns_fd ;
        t_params_ns *param ;
        T_BOOL   ok ;

        /*
         *  init param
         */
        ok = L_NS_PARAMS_init(argc,argv) ;
        FALSE_RET_FALSE(ok) ;
        param = L_PARAMS_NS_getParams() ;

        /*
         *  get param
         */
        nodeid  = param->nodeid ;
        nnodes  = param->nnodes ;
        ns_host = param->host ;
        ns_port = param->port ;

        /*
         *  init
         */
        ok = L_NODELI_init( &(nsinfo->nodeli) ) ;
        FALSE_RET_TRUE(ok) ;
        L_SB_init( &((*nsinfo).sb) ) ;
        ok = L_SB_creatMy_2( &((*nsinfo).sb), 
                             &ns_fd,
                             ns_host,
                             ns_port ) ;
        (nsinfo)->shutdown = FALSE ;

        /*
         *  return ok
         */
        return ok ;
      }

      /*
       *  L_NS_server
       * -------------
       */
      T_BOOL   L_NS_server  ( INOUT   t_nsInfo  *nsinfo )
      {
         int                 sock, ret, dumpSock ;
         t_nsHeader          mess ;
         T_BOOL              ok, isBrowser ;
 
         sock             = 0 ;
         dumpSock         = 0 ;
         while ( (nsinfo->shutdown) == FALSE )
         {
           ok  = L_SB_select( &(nsinfo->sb), 
                              &sock ) ;
           FALSE_RET_FALSE(ok) ;

           ret = L_NSI_readAvailable(&(nsinfo->sb),sock,&mess) ;
           if (sock == dumpSock)
              {
                if (ret == 0)
                   {
                     L_SB_unplug(&(nsinfo->sb),sock) ;
                     dumpSock = 0 ;
                   }
                continue ;
              }
           if (ret == 0)
              {
                L_SB_unplug(&(nsinfo->sb),sock) ;
                continue ;
              }
           if (ret < 0)
              {
                printf("Error at L_NSI_readAvailable\n") ;
                continue ;
              }
           isBrowser = L_BROW_is_services(nsinfo,&mess,&sock) ;
           if (isBrowser == TRUE)
              {
                dumpSock = sock ;
                ok = L_BROW_do_services(nsinfo,&mess,&dumpSock) ;
                if (ok == FALSE)
                    continue ;
              }
           else  /* (isBrowser == FALSE) */
              {
                ok = L_NODE_do_services(nsinfo,&mess,sock,&dumpSock) ;
                if (ok == FALSE)
                    continue ;
              }
         }
 
        /*
         *  return ok
         */
         return TRUE ;
      }
 
      /*
       *  L_NS_PARAMS_finalize
       * ----------------------
       */
      T_BOOL   L_NS_finalize  
      ( 
        INOUT   t_nsInfo  *nsinfo 
      )
      {
        /*
         *  return ok
         */
         return TRUE ;
      }
 

  /* .................................................................... */


