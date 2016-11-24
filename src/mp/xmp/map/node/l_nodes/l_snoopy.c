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

      #include "mp/xmp/map/node/l_nodes/l_snoopy.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_SNOOPY_createDaemonX  
      ( 
        IN    t_nodeInfo          *node_info,
        IN    T_INT                ch,
        IN    t_thcode             xSnoopy,
        OUT   T_THREAD            *thid 
      )
      {
        T_BOOL  ok ;
        t_snoopy_info  snoopy_info ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  setup node boot params
         */
        X_THREAD_init( &(snoopy_info.boot) ) ;
        snoopy_info.node_info  = node_info ;
        snoopy_info.chn        = ch ;

        /*
         *  new thread
         */
        ok = X_THREAD_createDetached( thid, xSnoopy, &snoopy_info ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  wait thread begin execution
         */
        X_THREAD_lock( &(snoopy_info.boot) ) ;
        X_THREAD_waitReady( &(snoopy_info.boot) ) ;
        X_THREAD_unlock( &(snoopy_info.boot) ) ;
	X_THREAD_destroy( &(snoopy_info.boot) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_SNOOPY_createComunicationDaemons 
      ( 
        IN    t_nodeInfo  *node_info,
        IN    T_INT        ch 
      )
      {
        T_THREAD       thid ;
        T_BOOL         ok ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin create comunication daemons") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  new threads
         */
        if (
             ( ch != (node_info->sb).ns )
                    &&
             ( ch != (node_info->sb).my )
                    &&
             ( L_SB_alive(&(node_info->sb),ch) == TRUE )
           )
           {
             ok = L_SNOOPY_createDaemonX
                  (
                     node_info,
                     ch,
                     (t_thcode)L_SNOOPY_RECV_recvSnoopy,
                     &thid
                  ) ;
             FALSE_RET_FALSE(ok) ;

             ok = L_SNOOPY_createDaemonX
                  (
                     node_info,
                     ch,
                     (t_thcode)L_SNOOPY_SEND_sendSnoopy,
                     &thid
                  ) ;
             FALSE_RET_FALSE(ok) ;
           }

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"exit create comunication daemons") ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_SNOOPY_createControlDaemons 
      ( 
        IN    t_nodeInfo  *node_info
      ) 
      {
        T_THREAD    thid ;
        T_BOOL      ok ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin create control daemons") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  new threads
         */
        ok = L_SNOOPY_createDaemonX
             (
               node_info,
               (node_info->sb).ns,
               (t_thcode)L_SNOOPY_NS_nsSnoopy,
               &thid
             ) ;
        FALSE_RET_FALSE(ok) ;

        ok = L_SNOOPY_createDaemonX
             (
               node_info,
               (node_info->sb).my,
               (t_thcode)L_SNOOPY_ACCEPT_acceptSnoopy,
               &thid
             ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"exit create control daemons") ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_SNOOPY_createAllDaemons
      ( 
        IN    t_nodeInfo  *node_info
      ) 
      {
        int         ch ;
        T_BOOL      ok ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin create all daemons") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  new comunication threads
         */
        for (ch=0; ch < MAX_SOCKS; ch++)
        {
          ok = L_SNOOPY_createComunicationDaemons(node_info,ch) ;
          FALSE_RET_FALSE(ok) ;
        }

        /*
         *  new control threads
         */
        ok = L_SNOOPY_createControlDaemons(node_info) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"exit create all daemons") ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

