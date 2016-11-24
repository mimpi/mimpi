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


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		T_INT       i ;
		T_TIME      t1 ;
		T_TIME      t2 ;
		T_ACCTIME   outdiff ;
		T_CHAR     *outpch ;
		T_DOUBLE    outtime ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  X_TIME_GetTime
                 */
		_DO_( X_TIME_GetTime(&t1) ) ;
                _DO_( sleep(1) ) ;
		_DO_( X_TIME_GetTime(&t2) ) ;

		/*
                 *  X_TIME_DiffTime
                 */
		_DO_( outdiff = X_TIME_DiffTime(t2,t1) ) ;
                if (outdiff < 1)
                    printf("ERROR\n") ;

		/*
                 *  X_TIME_GetTime && X_TIME_DiffTime
                 */
                printf("\tX_TIME_GetTime(&t1)\n") ;
                printf("\tX_TIME_GetTime(&t2)\n") ;
                printf("\tX_TIME_DiffTime(t2,t1)\n") ;
		for (i=0; i< 1000000; i++)
		    {
    		      X_TIME_GetTime(&t1) ;
		      X_TIME_GetTime(&t2) ;
		      outdiff = X_TIME_DiffTime(t2,t1) ;
                      if (outdiff < 0)
                          printf("ERROR\n") ;
		      outdiff = X_TIME_DiffTime(t2,t1) ;
                      if (outdiff == 0)
                          printf("WARNING\n") ;
		    }

		/*
                 *  X_TIME_CurrCTime
                 */
		_DO_( outpch = X_TIME_CurrCTime() ) ;
                if (outpch == NULL)
                    printf("ERROR\n") ;

		/*
                 *  X_TIME_GetTime_MSasSG
                 */
		_DO_( outtime = X_TIME_GetTime_MSasSG() ) ;
                if (outtime <= 0)
                    printf("ERROR\n") ;

		/*
                 *  X_TIME_Get_tick
                 */
		_DO_( outtime = X_TIME_Get_tick() ) ;
                if (outtime < 0)
                    printf("ERROR\n") ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


