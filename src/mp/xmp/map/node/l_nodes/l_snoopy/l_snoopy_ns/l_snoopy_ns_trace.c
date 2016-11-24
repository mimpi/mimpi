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

       #include "mp/xmp/map/node/l_nodes/l_snoopy/l_snoopy_ns/l_snoopy_ns_trace.h"


   /* ... Glob Vars / Variables Globales .............................. */

      t_nodeInfo  *L_SNOOPY_NS_TRACE_local_node_info ;
      int          L_SNOOPY_NS_TRACE_chn ;


   /* ... Functions / Funciones ....................................... */

      void  L_SNOOPY_NS_TRACE_setChannel
      (
        IN     t_nodeInfo   *nlocal_node_info,
        IN     int           nchn
      )
      {
        L_SNOOPY_NS_TRACE_local_node_info = nlocal_node_info ;
        L_SNOOPY_NS_TRACE_chn             = nchn ;
      }
 
      int   L_SNOOPY_NS_TRACE_trace
      (
        IN     const char   *format,
        IN     va_list       ap
      )
      {
        T_CHAR   *pstr, *pstr1 ;
        T_INT     lpstr ;
 
        if ( (L_SNOOPY_NS_TRACE_local_node_info->shutdown) == TRUE )
             return 0 ;
 
        /*
         *  get info
         */
        pstr1 = X_STRING_Dvsprintf((T_CHAR *)format,ap) ;
        pstr  = X_STRING_Dsprintf("node_%i(%s)",
                                  L_SNOOPY_NS_TRACE_local_node_info->nodeid,
                                  pstr1) ;
        X_ALLOC_Free((void **)&(pstr1)) ;
        lpstr = X_STRING_StrLen(pstr) ;

        /*
         *  try send
         */
        if (pstr != NULL)
           {
             L_SB_lockWrite( &(L_SNOOPY_NS_TRACE_local_node_info->sb), 
                             L_SNOOPY_NS_TRACE_chn ) ;
             L_NSI_writeTrace( &(L_SNOOPY_NS_TRACE_local_node_info->sb),
                              L_SNOOPY_NS_TRACE_chn,
                              L_SNOOPY_NS_TRACE_local_node_info->nodeid,
                              pstr ) ;
             L_SB_unlockWrite( &(L_SNOOPY_NS_TRACE_local_node_info->sb), 
                               L_SNOOPY_NS_TRACE_chn ) ;
             X_ALLOC_Free((void **)&(pstr)) ;
           }

        /*
         *  return
         */
        return lpstr ;
      }


   /* ......................................................... */

