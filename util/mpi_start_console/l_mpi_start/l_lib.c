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

      #include "l_lib.h"


   /* ... Funciones ................................................... */

      T_CHAR  *L_LIB_chose ( void )
      {
         T_INT id ;
         static  T_CHAR sz_respose[4*1024] ;

         /* ... ask ... */
         fprintf
         ( 
           stdout,
           "\n"
           "\n"
           " Select what library you want to link with :\n"
           " Elije que biblioteca quieres usar :\n"
           "\n"
           "\n"
           "     1.- mpich\n"
           "     2.- mpl/mpi nativo de SP2\n"
           "     3.- MiMPI/xmp\n"
           "\n"
           "\n"
         ) ;

         /* ... read response ... */
         id = -1 ;
         fprintf(stdout,"- ") ;
         fscanf(stdin,"%i",&id) ;

         /* ... return value ... */
         switch (id)
         {
           case 1 :
                sprintf(sz_respose,"mpich") ;
                break ;
           case 2 :
                sprintf(sz_respose,"mpl") ;
                break ;
           case 3 :
                sprintf(sz_respose,"mimpi") ;
                break ;
           default :
                sz_respose[0] = '\0' ;
         }
         return sz_respose ;
      }
 

  /* .................................................................... */


