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

      #include "mp/xmp/map/node_server/l_ns/l_nodeli.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODELI_init           
      ( 
        INOUT    t_nodeli *nodeli 
      )
      {
        T_INT i ;

        NULL__SET_ERROR__RET_FALSE(nodeli) ;

        for (i=0; i<MAX_SOCKS; i++)
            {
              ((*nodeli)[i]).in_use = FALSE ;
            }

        return TRUE ;
      }

      T_INT    L_NODELI_whereIs        
      ( 
        INOUT    t_nodeli *nodeli,
        IN       T_CHAR   *name 
      )
      {
        T_INT i ;

        NULL__SET_ERROR__RET_FALSE(nodeli) ;
        NULL__SET_ERROR__RET_FALSE(name) ;

        for (i = 0; i <  MAX_SOCKS; i++)
            {
              if ((*nodeli)[i].in_use)
                 {
                   if (strcmp(name, (*nodeli)[i].name) == 0)
                       return i ;
                 }
            }

        return (-1) ;
      }

      T_BOOL   L_NODELI_search         
      ( 
        INOUT    t_nodeli *nodeli,
        IN       T_CHAR   *name 
      )
      {
        T_INT i ;

        NULL__SET_ERROR__RET_FALSE(nodeli) ;
        NULL__SET_ERROR__RET_FALSE(name) ;

        for (i = 0; i <  MAX_SOCKS; i++)
            {
              if ((*nodeli)[i].in_use)
                 {
                   if (strcmp(name, (*nodeli)[i].name) == 0)
                       return TRUE ;
                 }
            }

        return FALSE ;
      }

      T_BOOL   L_NODELI_enter          
      ( 
        INOUT    t_nodeli            *nodeli,
        IN       T_CHAR              *name,
        IN       struct sockaddr_in   from 
      )
      {
        T_INT  i ;
        T_BOOL ok ;

        NULL__SET_ERROR__RET_FALSE(nodeli) ;
        NULL__SET_ERROR__RET_FALSE(name) ;
        ok = L_NODELI_search(nodeli,name) ;
        TRUE_RET_FALSE(ok) ;

        for (i = 0; i <  MAX_SOCKS; i++)
            {
              if ((*nodeli)[i].in_use == FALSE)
                 {
                   strcpy((*nodeli)[i].name, name) ;
                   (*nodeli)[i].from = from ;
                   (*nodeli)[i].in_use = TRUE ;
                   return TRUE ;
                 }
            }
        return FALSE ;
      }

      T_BOOL   L_NODELI_delete         
      ( 
        INOUT    t_nodeli *nodeli,
        IN       T_CHAR   *name 
      )
      {
        T_INT  i ;

        NULL__SET_ERROR__RET_FALSE(nodeli) ;
        NULL__SET_ERROR__RET_FALSE(name) ;
        i = L_NODELI_whereIs(nodeli,name) ;
        if (i == -1)
           {
             return FALSE ;
           }
        (*nodeli)[i].in_use = FALSE;
        return TRUE ;
      }


  /* .................................................................... */

