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

      #include "mp/xmp/map/node_server/l_ns/l_node/l_do_creat.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_DO_CREAT_creat      
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd 
      )
      {
        T_BOOL ok ;
        int    ret ;

        ok = L_NODELI_enter( &(nsinfo->nodeli),
                             (mess->n2nH).name,
                             (mess->n2nH).sa ) ;
        if (ok == TRUE)
                 (mess->n2nH).ret_code = 1 ;
            else (mess->n2nH).ret_code = 0 ;
        ret = L_NSI_write(&(nsinfo->sb),ssd,mess) ;
        if (ret < 0)
           {
             printf("Error at L_NSI_write\n") ;
             return FALSE ;
           }

        return TRUE ;
      }


  /* .................................................................... */


