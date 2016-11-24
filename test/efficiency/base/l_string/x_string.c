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
 *  prove x_string.c 
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_string/x_string.h"
	#include "base/l_time/x_time.h"


        #define     MAX_NTEST         100


	int test_x_string_match
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                T_TIME      t1 ;
                T_TIME      t2 ;
		T_ACCTIME   outdiff ;
		T_INT       ntest ;


		/*
                 *  X_STRING_Match
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      X_STRING_Match("a.b.c.exe","*.exe",FALSE) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_match=%e\n",
                        outdiff / MAX_NTEST) ;

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
                 * X_STRING_Match
                 */
	        ret = test_x_string_match(argc,argv) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


