/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


/*
 *
 *  prove l_dstack
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_adt/l_dstack.h"
	#include "base/l_time/x_time.h"


        #define     MAX_NTEST         100


	int test_l_dstack_push
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                /*
                 *  time
                 */
                T_DOUBLE    t1 ;
                T_DOUBLE    t2 ;
		T_ACCTIME   outdiff ;
		T_INT       ntest ;

                /*
                 *  stack
                 */
		t_pointerDStack  s ;
		t_pointerDStack  outs ;


		/*
                 *  setup
                 */
		s = L_DSTACK_CreatEmpty() ;

		/*
                 *  L_DSTACK_Push
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      outs = L_DSTACK_Push(&s,(T_POINTER)&s) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_push=%e\n",
                        outdiff / MAX_NTEST) ;

		/*
                 *  setup
                 */
 		L_DSTACK_Empty(&s) ;

		/*
		 *  end
                 */
		return 1 ;
	}

	int test_l_dstack_pop
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                /*
                 *  time
                 */
                T_DOUBLE    t1 ;
                T_DOUBLE    t2 ;
		T_ACCTIME   outdiff ;
		T_INT       ntest ;

                /*
                 *  stack
                 */
		t_pointerDStack  s ;
		t_pointerDStack  outs ;
		T_POINTER       *outptr ;


		/*
                 *  setup
                 */
		s = L_DSTACK_CreatEmpty() ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      outs = L_DSTACK_Push(&s,(T_POINTER)&s) ;
                    }

		/*
                 *  L_DSTACK_Pop
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      outptr = L_DSTACK_Pop(&s) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_pop=%e\n",
                        outdiff / MAX_NTEST) ;

		/*
                 *  setup
                 */
 		L_DSTACK_Empty(&s) ;

		/*
		 *  end
                 */
		return 1 ;
	}


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		int              ret ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;


		/*
                 *  test
                 */
                ret = test_l_dstack_push(argc,argv) ;
                ret = test_l_dstack_pop(argc,argv) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


