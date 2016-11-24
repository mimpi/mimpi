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

      #include "mp/xmp/map/node/l_nodegrp.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODEGRP_isMember
      (
        INOUT    t_nodegrp      nodeli,
        IN       T_INT          who
      )
      {
         /*
          *  check params
          */
         NULL__SET_ERROR__RET_FALSE(nodeli) ;

         /*
          *  is in list ?
          */
         if ( (nodeli)[who] < 0 )
               return FALSE ;

         /*
          *  Return ok
          */
        return TRUE ;
      }

      T_BOOL   L_NODEGRP_addMember
      (
        INOUT    t_nodegrp      nodeli,
        IN       T_INT          who
      )
      {
         /*
          *  check params
          */
         NULL__SET_ERROR__RET_FALSE(nodeli) ;

         /*
          *  setup translation
          */
         (nodeli)[who] = who ;

         /*
          *  Return ok
          */
         return TRUE ;
      }

      T_BOOL   L_NODEGRP_removeMember
      (
        INOUT    t_nodegrp      nodeli,
        IN       T_INT          who
      )
      {
         /*
          *  check params
          */
         NULL__SET_ERROR__RET_FALSE(nodeli) ;

         /*
          *  setup translation
          */
         (nodeli)[who] = -1 ;

         /*
          *  Return ok
          */
         return TRUE ;
      }


   /* ................................................................. */

