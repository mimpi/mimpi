/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 * <fgarcia@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



    /*
     *
     *   test node interface
     *   -------------------
     *
     *   probe l_nodei.c
     *
     */

      #include "mp/xmp/map/node/l_nodes/l_nodei.h"


      T_BOOL test_nodei_protocol
      ( 
        IN       int      argc,
        IN       char    *argv[],
        IN       t_sb     sb,
        IN       int      myfd
      )
      {
	/*
        T_BOOL   ok ;
        int            sock ;
        t_nodeHeader   outHeader ;
        t_nodeReq      psend ;
	*/

        /* 
         *  check params
         */
	/*
        ok = L_NODEI_writeSendReq(&sb,sock,&outHeader,&psend) ;
        FALSE_RET_FALSE(ok) ;
	*/

        /* 
         *  return ok. 
         */
        return TRUE ;
      }

      int main
      ( 
        IN       int   argc,
        IN       char *argv[]
      )
      {
        T_BOOL   ok ;
        t_sb     sb ;
        int      myfd ;

        /*
         */
        printf("\n") ;
        printf("%s\n",argv[0]) ;
        printf("begin\n") ;

        /*
         *  setup scrollbar
         */
        _DO_( ok = L_SB_init( &(sb) ) ) ;
        if (ok == FALSE)
            printf("ERROR\n") ;

        /*
         *  setup basic conections
         */
        _DO_( ok = L_SB_creatMy ( &(sb), &myfd) ) ;
        if (ok == FALSE)
            printf("ERROR\n") ;

        /* 
         *  check nodei
         */
        _DO_( ok = test_nodei_protocol(argc,argv,sb,myfd) ) ;
        if (ok == FALSE)
            printf("ERROR\n") ;

        /*
         *  disconnect scrollbar
         */
        _DO_( ok = L_SB_finalize( &(sb) ) ) ;
        if (ok == FALSE)
            printf("ERROR\n") ;

        /* 
         *  return ok. 
         */
        printf("end\n") ;
        return FALSE ;
      }


   /* ................................................................. */

