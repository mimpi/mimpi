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

      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_accept.h"


   /* ... Functions / Funciones ....................................... */

      void  L_SNOOPY_ACCEPT_do_accept_snoopy 
      ( 
        INOUT  int         chn,
        INOUT  t_nodeInfo *local_node_info 
      )
      {
        T_BOOL  ok ;

        /*
         *  go accept conections ...
         */
        while ( (local_node_info->shutdown) != TRUE )
        {

          ok = L_NETLNK_linkIncoming( local_node_info ) ;
          if (ok == FALSE)
             {
               L_TRACE_MSG_PrintF(DEFCON_1,
                              "acceptSnoopy had a nightmare...") ;
               continue ;
             }

        }
      }

      void  L_SNOOPY_ACCEPT_acceptSnoopy   
      ( 
        INOUT  t_snoopy_info  *snoopy_info 
      )
      {
        int          chn ;
        t_nodeInfo  *local_node_info;

        /*
         *  copy params
         */
        chn             = (snoopy_info->chn) ;
        local_node_info = (snoopy_info->node_info) ;

        /*
         *  Trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "acceptSnoopy started... [node=%i,chn=%i]",
                       (local_node_info->sock2node)[chn],
                       chn) ;

        /*
         *  signal ready
         */
        X_THREAD_lock( &(snoopy_info->boot) ) ;
        X_THREAD_signalReady( &(snoopy_info->boot) ) ;
        X_THREAD_unlock( &(snoopy_info->boot) ) ;

        /*
         *  begin ...
         */
        L_SNOOPY_ACCEPT_do_accept_snoopy(chn,local_node_info) ;

        /*
         *  Trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,
                       "acceptSnoopy finished... [node=%i,chn=%i]",
                       (local_node_info->sock2node)[chn],
                       chn) ;
      }


  /* ......................................................... */

