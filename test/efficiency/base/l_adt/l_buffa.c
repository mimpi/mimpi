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
 *  prove l_buffa (buffering ahead)
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_adt/l_buffa.h"
        #include "base/l_time/x_time.h"


        #define     MAX_NTEST         100


	int test_l_buffa_catonebyte
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
                 *  buffer
                 */
                T_CHAR   *b ;
                T_U_INT   cb ;
                T_BOOL    ok ;


		/*
                 *  setup
                 */
                b = NULL ;
                cb = 0 ;
		ok = L_BUFFA_CatOneByteToCache(&b,&cb,'a') ;

		/*
                 *  L_DSTACK_Push
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      ok = L_BUFFA_CatOneByteToCache(&b,&cb,'a') ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_1byte=%e\n",
                        outdiff / MAX_NTEST) ;

		/*
                 *  setup
                 */
 		free(b) ;

		/*
		 *  end
                 */
		return 1 ;
	}

	int test_l_buffa_catnbyte
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
                 *  buffer
                 */
                T_INT     l ;
                T_CHAR   *b ;
                T_U_INT   cb ;
                T_BOOL    ok ;


		/*
                 *  setup
                 */
                b = NULL ;
                cb = 0 ;
		ok = L_BUFFA_CatOneByteToCache(&b,&cb,'a') ;
		l = strlen("bc") ;

		/*
                 *  L_DSTACK_Push
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      ok = L_BUFFA_CatNBytesToCache(&b,&cb,"bc",l) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_nbyte=%e\n",
                        outdiff / MAX_NTEST) ;

		/*
                 *  setup
                 */
 		free(b) ;

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
                int     ret ;


		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  test
                 */
	        ret = test_l_buffa_catonebyte(argc,argv) ;
	        ret = test_l_buffa_catnbyte(argc,argv) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


