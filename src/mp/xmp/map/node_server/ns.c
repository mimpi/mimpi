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


/*
 *
 *  NodeServer
 *
 */


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/map/node_server/l_ns.h"


  /* ... Functions / Funciones ................................*/

     int  main 
     ( 
       int argc,  char *argv[] 
     )
     {
        t_nsInfo  nsinfo ;
        T_BOOL    ok ;

        setbuf(stdout, NULL);
        printf( "\n"
                "\n"
                "  NodeServer\n"
                " ------------\n"
                "\n"
                "   %s\n"
                "\n",
                NS_VER ) ;


        printf("NS init  ...\n");
        ok = L_NS_init(argc,argv,&nsinfo) ;
        FALSE_RET_TRUE(ok) ;

        printf("NS start ...\n");
        ok = L_NS_server( &nsinfo ) ;
        FALSE_RET_TRUE(ok) ;

        printf("NS finalize.\n");
        ok = L_NS_finalize(&nsinfo) ;
        FALSE_RET_TRUE(ok) ;

        return FALSE ;
     }


  /* ..........................................................*/

