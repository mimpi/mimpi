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



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/xmp/base/l_sb/l_sb_broadcast.h"


   /* ... Functions / Funciones ....................................... */

      T_INT   L_SB_broadcast   
      ( 
        IN     t_sb    *sb,
        IN     T_CHAR  *buff,
        IN     T_INT    count 
      )
      {
        T_INT  ret, i ;
        t_sb_sock *socki ;

        /*
         *  send to all members
         */
        ret = 0 ;
        for (i=0; i<sb->last; i++)
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
                   ret = ret + L_SB_write(sb,i,buff,count) ;
                 }

            }

        /*
         *  return 'ret'
         */
        return ret ;
      }


  /* .................................................................... */

