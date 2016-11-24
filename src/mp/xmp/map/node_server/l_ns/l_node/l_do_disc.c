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

      #include "mp/xmp/map/node_server/l_ns/l_node/l_do_disc.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_DO_DISC_disc        
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd 
      )
      {
        int    ret ;

        L_NODELI_delete( &(nsinfo->nodeli),
                          (mess->n2nH).name ) ;
        (mess->n2nH).ret_code = 1 ;
        ret = L_NSI_write(&(nsinfo->sb),ssd,mess) ;
        if (ret < 0)
           {
             printf("Error at L_NSI_write\n") ;
           }
        L_SB_unplug(&(nsinfo->sb),ssd) ;
        if (L_SB_alives(&(nsinfo->sb)) == 0)
           {
             printf("NS Alone at Home !!\n") ;
             (nsinfo->shutdown) = TRUE ;
           }
        if (ret < 0)
           {
             return FALSE ;
           }

        return TRUE ;
      }


  /* .................................................................... */


