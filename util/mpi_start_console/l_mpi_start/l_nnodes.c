/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "l_nnodes.h"


   /* ... Funciones ................................................... */

      T_CHAR  *L_NNODES_chose ( void )
      {
         static  T_CHAR sz_respose[4*1024] ;

         /* ... ask ... */
         fprintf
         ( 
           stdout,
           "\n"
           "\n"
           "   How many nodes program will use ?\n"
           " ? Cuantos nodos se compone el programa ?\n"
           "\n"
           "\n"
         ) ;

         /* ... read response ... */
         fprintf(stdout,"- ") ;
         fscanf(stdin,"%s",sz_respose) ;

         /* ... return value ... */
         return sz_respose ;
      }
 

  /* .................................................................... */


