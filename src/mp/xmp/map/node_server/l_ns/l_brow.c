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

      #include "mp/xmp/map/node_server/l_ns/l_brow.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_BROW_do_services      
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      )
      {
        if ( X_STRING_Match((char *)mess,
                            "GET / *",FALSE) == TRUE )
             return L_ROOT_root(nsinfo,mess,dsd) ;

        if ( X_STRING_Match((char *)mess,
                            "GET */index.html *",FALSE) == TRUE )
             return L_ROOT_root(nsinfo,mess,dsd) ;

        if ( X_STRING_Match((char *)mess,
                            "GET */dump_all.html *",FALSE) == TRUE )
             return L_DUMP_ALL_dumpAll(nsinfo,mess,dsd) ;

        if ( X_STRING_Match((char *)mess,
                            "GET */trace_all.html *",FALSE) == TRUE )
             return L_TRACE_ALL_traceAll(nsinfo,mess,dsd) ;

        if ( X_STRING_Match((char *)mess,
                            "GET */authors.html *",FALSE) == TRUE )
             return L_AUTHORS_authors(nsinfo,mess,dsd) ;

        return L_UNKNOW_unknow(nsinfo,mess,dsd) ;
      }

      T_BOOL   L_BROW_is_services      
      ( 
        INOUT   t_nsInfo     *nsinfo,
        INOUT   t_nsHeader   *mess,
        IN      int          *dsd 
      )
      {
               T_INT    i ;
               T_CHAR  *http_methods[] = 
               {
                 "GET",
                 "HEAD",
                 "PUT",
                 "POST",
                 "OPTIONS",
                  NULL
               } ;

        for (i=0; http_methods[i] != NULL; i++)
            {
              if (
                   strncmp
                   (  
                     (char *)mess,
                     http_methods[i],
                     strlen(http_methods[i])
                   ) == 0
                 )
                 {
                   return TRUE ;
                 }
            }

        return FALSE ;
      }


  /* .................................................................... */


