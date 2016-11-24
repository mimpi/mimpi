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



  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "l_mpi_exec.h"
     #include "c_execver.h"


  /* ... Functions / Funciones ................................*/

     int  main 
     ( 
       int   argc,  
       char *argv[] 
     )
     {
        T_BOOL ok ;

        /*
         *  intro
         */
        setbuf(stdout, NULL);
        printf( "\n"
                "\n"
                "  mpi_exec\n"
                " ----------\n"
                "\n"
                "   %s\n"
                "\n",
                MPI_EXEC_VER ) ;

        /*
         *  do work
         */
        ok = L_MPI_EXEC_main() ;
        FALSE_RET_TRUE(ok) ;

        /*
         *  return ok
         */
        return FALSE ;
     }


  /* ..........................................................*/

