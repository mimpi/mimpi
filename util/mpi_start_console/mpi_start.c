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
     #include "base/l_string/x_string.h"
     #include "l_mpi_start.h"
     #include "c_startver.h"


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
                "  mpi_start\n"
                " -----------\n"
                "\n"
                "   %s\n"
                "\n",
                MPISTART_CONSOLE_VER ) ;

        printf( "\n"
                "   Press ANY key to continue ...\n"
                "   Presione cualquier tecla para continuar...\n"
                "\n"
                ) ;
        fgetc(stdin) ;

        /*
         *  do work
         */
        ok = L_MPI_START_assist() ;
        FALSE_RET_TRUE(ok) ;

        /*
         *  return ok
         */
        return FALSE ;
     }


  /* ..........................................................*/

