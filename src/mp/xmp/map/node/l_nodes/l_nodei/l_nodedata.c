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



   /* ... Include / Inclusiones ....................................... */

      #include "mp/xmp/map/node/l_nodes/l_nodei/l_nodedata.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODEDATA_skipData   
      ( 
        INOUT    t_sb          *sb,
        INOUT    int            sock,
        IN       T_INT          size 
      )
      {
        T_INT   i, nchuck, rchuck ;
        T_CHAR  chuck[4] ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin L_NODEDATA_skipData") ;

        /*
         *  read 4 bytes packets
         */
        nchuck = (size) / 4 ;
        rchuck = (size) % 4 ;
        for (i=0; i<nchuck; i++)
             L_SB_read(sb,sock,chuck,4) ;
        if  (rchuck != 0)
             L_SB_read(sb,sock,chuck,rchuck) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"ok L_NODEDATA_skipData") ;

        /*
         *  return ok
         */
        return TRUE ;
      }


  /* .................................................................... */

