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

      #include "l_runner.h"


   /* ... Funciones ................................................... */

      T_CHAR  *L_RUNNER_chose ( void )
      {
         T_INT id ;
         static  T_CHAR sz_respose[4*1024] ;

         /* ... ask ... */
         fprintf
         ( 
           stdout,
           "\n"
           "\n"
           " Select \"runner\" you want to use :\n"
           " Elije que \"impulsor\" quieres usar :\n"
           "\n"
           "\n"
           "     1.- mpirun/sp2\n"
           "     2.- poe/sp2\n"
           "     3.- mpirun/*\n"
           "     4.- shell-script/*\n"
           "     5.- xmp_run/*\n"
           "\n"
           "\n"
         ) ;

         /* ... read response ... */
         fprintf(stdout,"- ") ;
         id = -1 ;
         fscanf(stdin,"%i",&id) ;

         /* ... return value ... */
         switch (id)
         {
           case 1 :
                sprintf(sz_respose,"poe_mpich") ;
                break ;
           case 2 :
                sprintf(sz_respose,"poe_xmp") ;
                break ;
           case 3 :
                sprintf(sz_respose,"mpirun_mpich") ;
                break ;
           case 4 :
                sprintf(sz_respose,"sh_xmp") ;
                break ;
           case 5 :
                sprintf(sz_respose,"xmprun_xmp") ;
                break ;
           default :
                sz_respose[0] = '\0' ;
         }
         return sz_respose ;
      }
 

  /* .................................................................... */


