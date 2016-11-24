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
 *  prove l_dhash
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_adt/l_dhash.h"
        #include "base/l_time/x_time.h"


        #define     MAX_NTEST         100


	int test_l_dhash_insert
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
                 *  dhash
                 */
		t_dhash   *h ;
		T_BOOL     ok ;


		/*
                 *  setup
                 */
		h = L_DHASH_Creat() ;

		/*
                 *  L_DSTACK_Push
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      ok = L_DHASH_InsertKV(h,"this",(T_POINTER)h) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_insert=%e\n",
                        outdiff / MAX_NTEST) ;

		/*
                 *  setup
                 */
 		ok = L_DHASH_Destroy(&h) ;

		/*
		 *  end
                 */
		return 1 ;
	}

	int test_l_dhash_valueof
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
                 *  dhash
                 */
		t_dhash   *h ;
		T_POINTER *outptr ;
		T_BOOL     ok ;


		/*
                 *  setup
                 */
		h = L_DHASH_Creat() ;
		ok = L_DHASH_InsertKV(h,"this",(T_POINTER)h) ;

		/*
                 *  L_DSTACK_Push
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      outptr = L_DHASH_ValueOf(h,"this",TRUE) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_valueof=%e\n",
                        outdiff / MAX_NTEST) ;

		/*
                 *  setup
                 */
 		ok = L_DHASH_Destroy(&h) ;

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
		int       ret ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;


		/*
                 *  test
                 */
		ret = test_l_dhash_insert(argc,argv) ;
		ret = test_l_dhash_valueof(argc,argv) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


