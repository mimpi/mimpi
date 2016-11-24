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

      #include "l_mpi_exec.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_MPI_EXEC_main 
      ( 
        void 
      )
      {
         T_CHAR  *pch ;

         /* 
          *  get service id 
          */
         pch = getenv("REQUEST") ;
         if (pch == NULL)
            {
              fprintf( stderr,
                       "You forgot \"request=...\"\n" ) ;
              return FALSE ;
            }

         /* 
          *  do service 
          */ 
         if ( X_STRING_Equal(pch,"sh_xmp") == TRUE )
            {
              return L_SH_XMP_main() ;
            }
         if ( X_STRING_Equal(pch,"rsh_xmp") == TRUE )
            {
              return L_RSH_XMP_main() ;
            }
         if ( X_STRING_Equal(pch,"poe_mpich") == TRUE )
            {
              return L_POE_MPICH_main() ;
            }
         if ( X_STRING_Equal(pch,"poe_xmp") == TRUE )
            {
              return L_POE_XMP_main() ;
            }
         if ( X_STRING_Equal(pch,"poe_nmpi") == TRUE )
            {
              return L_POE_NMPI_main() ;
            }
         if ( X_STRING_Equal(pch,"mpirun_mpich") == TRUE )
            {
              return L_MPIRUN_MPICH_main() ;
            }
         if ( X_STRING_Equal(pch,"xmprun_xmp") == TRUE )
            {
              return L_XMPRUN_XMP_main() ;
            }

         /* 
          *  do UNKNOW service 
          */
         fprintf( stderr,
                  "I can undestand request=\"%s\"\n",
                  pch ) ;
         return FALSE ;
      }
 

  /* .................................................................... */


