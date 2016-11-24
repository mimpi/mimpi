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
 *  prove x_time.c
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_time/x_time.h"


        #define     MAX_NTEST         100


	int test_x_time_get_time_ms_as_sg
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                T_DOUBLE    t1 ;
                T_DOUBLE    t2 ;
                T_DOUBLE    t11 ;
                T_DOUBLE    t22 ;
		T_ACCTIME   outdiff ;
		T_INT       ntest ;


		/*
                 *  X_TIME_GetTime_MSasSG
                 */
		t1 = X_TIME_GetTime_MSasSG() ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
		      t11 = X_TIME_GetTime_MSasSG() ;
		      t22 = X_TIME_GetTime_MSasSG() ;
                    }
		t2 = X_TIME_GetTime_MSasSG() ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_gettime_msassg=%e\n",
                        outdiff / (2*MAX_NTEST)) ;

		/*
		 *  end
                 */
		return 1 ;
	}

	int test_x_time_get_time 
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		T_TIME      t1 ;
		T_TIME      t2 ;
		T_TIME      t11 ;
		T_TIME      t22 ;
		T_ACCTIME   outdiff ;
		T_INT       ntest ;


		/*
                 *  X_TIME_GetTime
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
                      X_TIME_GetTime(&t11) ;
                      X_TIME_GetTime(&t22) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_gettime=%e\n",
                        outdiff / (2*MAX_NTEST)) ;

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
		int         ret ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  X_TIME_CurrCTime
                 */
                printf("current time: %s\n", 
                       X_TIME_CurrCTime());

		/*
                 *  X_TIME_Get_tick
                 */
                printf("clock resolution in seconds: %10.8f\n", 
                       X_TIME_Get_tick());

		/*
                 *  X_TIME_GetTime
                 */
	        ret = test_x_time_get_time(argc,argv) ;

		/*
                 *  X_TIME_GetTime_MSasSG
                 */
	        ret = test_x_time_get_time_ms_as_sg(argc,argv) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


