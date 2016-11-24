/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Inclusiones / Includes ...................................... */

      #include "mp/xmp/base/l_sb/l_sb_alives.h"


   /* ... Functions / Funciones ....................................... */

      T_INT   L_SB_alives 
      ( 
        INOUT  t_sb    *sb 
      )
      {
        T_INT       nfd, i ;
        t_sb_sock  *socki ;

        /*
         *  check params
         */
        TRUE__SET_ERROR__RET_LONG( (sb == NULL), 0 ) ;

        /*
         *  count alives
         */
        nfd = 0 ;
        for (i = 0; i < sb->last; i++)
            {
              socki = sb->sock_set[i] ;
              if (
                   ( L_SB_SOCK_alive(socki) == TRUE )
                          &&
                   ( i != sb->ns )
                          &&
                   ( i != sb->my )
                 )
                 {
                   nfd++ ;
                 }
            }

        /*
         *  return
         */
        return nfd ;
      }


  /* .................................................................... */

