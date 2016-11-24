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
 *  prove l_debug.c 
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_debug/l_debug.h"
	#include "base/l_time/x_time.h"


        #define     MAX_NTEST         100


	int test_l_debug_write
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
                 *  L_DEBUG_MSG_Write
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
                      L_DEBUG_MSG_Write(__LINE__,__FILE__,0,TRUE,
                                        "h w\r") ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_write=%e                 \n",
                        outdiff / MAX_NTEST) ;

		/*
		 *  end
                 */
		return 1 ;
	}

	int test_l_debug_printf
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
                 *  L_DEBUG_MSG_Write
                 */
                X_TIME_GetTime(&t1) ;
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
                      L_DEBUG_MSG_PrintF(__LINE__,__FILE__,0,TRUE,
                                         "%s %i\r","a",33) ;
                    }
                X_TIME_GetTime(&t2) ;
                outdiff = X_TIME_DiffTime(t2,t1) ;
                printf("avg_printf=%e                 \n",
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
                 *  setup values
                 */
                L_DEBUG_MSG_PrintMsg = NULL ;

		/*
                 *  L_DEBUG_MSG_Write
                 */
	        ret = test_l_debug_write(argc,argv) ;
	        ret = test_l_debug_printf(argc,argv) ;

                /*
                 *  setup values
                 */
                L_DEBUG_MSG_PrintMsg = vprintf ;

		/*
                 *  L_DEBUG_MSG_Write
                 */
	        ret = test_l_debug_write(argc,argv) ;
	        ret = test_l_debug_printf(argc,argv) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


