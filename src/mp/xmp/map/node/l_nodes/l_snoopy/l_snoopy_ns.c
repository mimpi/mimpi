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

      #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_ns.h"


   /* ... Functions / Funciones ....................................... */

      void  L_SNOOPY_NS_perror_snoopy 
      ( 
        INOUT  t_nodeInfo  *local_node_info,
        IN     T_CHAR      *snoopyName,
        IN     T_INT        mynodeid,
        INOUT  int          chn,
        INOUT  int          ret 
      )
      {
        if (ret < 0)
           {
             if ( (local_node_info->shutdown) != TRUE )
                   L_TRACE_MSG_PrintF(DEFCON_1,
                                 "%s[node=%i,chn=%i] error in read.",
                                 snoopyName,
                                 mynodeid,
                                 chn) ;
           }
        if (ret == 0)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                       "%s[node=%i,chn=%i] found EOF...",
                       snoopyName,
                       mynodeid,
                       chn) ;
           }
      }


      void     L_SNOOPY_NS_do_ns_snoopy     
      ( 
        INOUT  int         chn,
        INOUT  t_nodeInfo *local_node_info 
      )
      {
        T_INT         mynodeid ;   /* nodeid of mine */
        T_INT         ret ;
        t_nsHeader    nsHeader ;   

        /*
         *  get node's references
         */
        mynodeid = local_node_info->nodeid ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"snoopy_ns_trace take control") ;

        /*
         *  begin server ...
         */
        L_SNOOPY_NS_TRACE_setChannel(local_node_info,chn) ;
        while ( (local_node_info->shutdown) != TRUE )
        {

           /*
            *  trace
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
                          "nsSnoopy[node=%i,chn=%i] go read nsHeader...", 
                          mynodeid,
                          chn) ;

           /*
            *  read header
            */
           ret = L_NSI_read( &(local_node_info->sb),
                              chn,
                             &nsHeader ) ;
           if ( (ret < 0) || (ret == 0) )
              {
                L_SNOOPY_NS_perror_snoopy(local_node_info,
                                          "nsSnoopy",
                                          mynodeid,
                                          chn,
                                          ret) ;
                break ;
              }

           /*
            *  trace
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
                          "nsSnoopy[node=%i,chn=%i] (code=%i)",
                          mynodeid, 
                          chn,
                          (nsHeader.n2nH).code) ;

           /*
            *  dispatch
            */
           switch ((nsHeader.n2nH).code)
           {
             case NS_DUMP :
                  L_SNOOPY_NS_DUMP_dumpNodeInfo(chn,local_node_info) ;
                  break ;
             case NS_TRACE_ON :
                  L_TRACE_MSG_setPrinter(L_SNOOPY_NS_TRACE_trace) ;
                  L_STACK_MSG_setPrinter(L_SNOOPY_NS_TRACE_trace) ;
                  L_CONDITION_MSG_setPrinter(L_SNOOPY_NS_TRACE_trace) ;
                  break ;
             case NS_TRACE_OFF :
                  L_TRACE_MSG_setPrinter(NULL) ;
                  L_STACK_MSG_setPrinter(NULL) ;
                  L_CONDITION_MSG_setPrinter(NULL) ;
                  break ;
             default : 
                  break ;
           }

        } /* while(...) */

        /*
         *  set default value
         */
        L_DEBUG_MSG_PrintMsg = (T_INT (*)(const T_CHAR *, va_list)) NULL ;
      }

      void     L_SNOOPY_NS_nsSnoopy      
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
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"nsSnoopy started...") ;

        /*
         *  signal ready
         */
        X_THREAD_lock( &(snoopy_info->boot) ) ;
        X_THREAD_signalReady( &(snoopy_info->boot) ) ;
        X_THREAD_unlock( &(snoopy_info->boot) ) ;

        /*
         *  begin ...
         */
        L_SNOOPY_NS_do_ns_snoopy(chn,local_node_info) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"nsSnoopy finished...") ;
      }


  /* ......................................................... */

