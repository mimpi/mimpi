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

       #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_ns/l_snoopy_ns_dump.h"


   /* ... Functions / Funciones ....................................... */

      void  L_SNOOPY_NS_DUMP_dumpNodeInfo  
      ( 
        INOUT  int           chn,
        INOUT  t_nodeInfo   *local_node_info 
      )
      {
        T_CHAR  *ret ;
        T_CHAR  *pstr, *pstr1 ;

        /* 
         *  nodeinfo as string
         */
        ret   = NULL ;
        pstr  = NULL ;
        pstr1 = NULL ;

            ret = X_DTD_begin(&pstr,"nodeinfo","local_node_info") ;
        if (ret != NULL)
            pstr1 = L_NODEINFO_nodeinfoToString(local_node_info) ;
        if (pstr1 != NULL)
           {
             ret = X_DTD_put(&pstr,pstr1) ;
             X_ALLOC_Free((void **)&(pstr1)) ;
           }
        if (ret != NULL)
            ret  = X_DTD_end(&pstr,"nodeinfo","local_node_info") ;

        /* 
         *  if string available, send it
         */
        if (pstr != NULL)
           {
             L_SB_lockWrite( &(local_node_info->sb), chn ) ;

             /* 
              *  send data
              */
             L_NSI_writeDump( &(local_node_info->sb),
                              chn,
                              local_node_info->nodeid,
                              "%s",pstr ) ;

             /* 
              *  zero data means end nodeDump 
              */
             L_NSI_writeDump( &(local_node_info->sb),
                              chn,
                              local_node_info->nodeid,
                              "%s","" ) ;

             L_SB_unlockWrite( &(local_node_info->sb), chn ) ;

             X_ALLOC_Free((void **)&(pstr)) ;
           }
      }

      void  L_SNOOPY_NS_DUMP_do_dump_snoopy  
      ( 
        INOUT  int           chn,
        INOUT  t_nodeInfo   *local_node_info 
      )
      {
        while ( (local_node_info->shutdown) != TRUE )
        {
           /*
            *  send information
            */
           L_TRACE_MSG_PrintF(DEFCON_1,
                              "nsSnoopy[node=%i,chn=%i] dump...", 
                              local_node_info->nodeid,
                              chn) ;
           L_SNOOPY_NS_DUMP_dumpNodeInfo(chn,local_node_info) ;

           /*
            *  wait 30 seconds
            */
           X_PROCESS_sleep(30) ;
        }
      }


  /* ......................................................... */

