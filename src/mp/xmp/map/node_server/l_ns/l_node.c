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

      #include "mp/xmp/map/node_server/l_ns/l_node.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_NODE_print_service_status  
      ( 
        INOUT  t_nsHeader  *mess 
      )
      {
         switch ((mess->n2nH).code)
         {
           case NS_FINALIZE:
                   printf( "NS do_finalize(") ;
                   break;
           case NS_MATCH:
                   printf( "NS do_match(") ;
                   break;
           case NS_CREAT:
                   printf( "NS do_creat(") ;
                   break;
           case NS_OPEN:
                   printf( "NS do_open(") ;
                   break;
           case NS_UNLINK:
                   printf( "NS do_unlink(") ; /* hide from others */
                   break;
           case NS_DISC:
                   printf( "NS do_disc(") ; /* full disconnect */
                   break;
           case NS_DUMP:
                   printf( "NS do_dump(") ;
                   break;
           case NS_TRACE:
                   /* frecuenly ...  
                      printf( "NS do_trace(") ;
                   */
                   return TRUE ;
                   break;
           default:
                   printf( "NS do_unknow(") ;
                   break;
         }

         if ((mess->n2nH).code < 0)
                  printf(")=%x\n", (mess->n2nH).code) ;
             else printf(")=%d\n", (mess->n2nH).code) ;

         return TRUE ;
      }

      T_BOOL   L_NODE_do_services    
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int           ssd,
        INOUT   int          *dsd 
      )
      {
         T_BOOL ok ;
 
         switch ((mess->n2nH).code)
         {
           case NS_FINALIZE:
                (nsinfo->shutdown) = TRUE ;
                ok = TRUE ;
                break;
           case NS_MATCH :
                ok = L_DO_MATCH_match(nsinfo,mess,ssd) ;
                break ;
           case NS_CREAT :
                ok = L_DO_CREAT_creat(nsinfo,mess,ssd) ;
                break ;
           case NS_OPEN:
                ok = L_DO_OPEN_open(nsinfo,mess,ssd) ;
                break ;
           case NS_UNLINK:
                ok = L_DO_UNLINK_unlink(nsinfo,mess,ssd) ;
                break ;
           case NS_DISC:
                ok = L_DO_DISC_disc(nsinfo,mess,ssd) ;
                break ;
           case NS_DUMP:
                ok = L_GO_DEBUG_dump(nsinfo,mess,ssd,dsd) ;
                break ;
           case NS_TRACE:
                ok = L_GO_DEBUG_trace(nsinfo,mess,ssd,dsd) ;
                break ;
           default:
                ok = L_DO_DEFAULT_default(nsinfo,mess,ssd) ;
                break ;
         }
 
 #if defined(__DEBUG_MPI__)
         L_NODE_print_service_status(mess) ;
 #endif
 
         return ok ;
      }


  /* .................................................................... */


