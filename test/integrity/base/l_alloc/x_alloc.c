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
 *  prove x_alloc.c and l_debug if __DEBUG_ALLOC__
 *  is defined (#define __DEBUG_ALLOC__)
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_alloc/x_alloc.h"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		void  *p ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  malloc
                 */
		_DO_( p = X_ALLOC_Malloc(3) ) ;
                if (p == NULL)
                    printf("ERROR\n") ;

		/*
                 *  realloc
                 */
		_DO_( p = X_ALLOC_Realloc(p,32) ) ;
                if (p == NULL)
                    printf("ERROR\n") ;

		/*
                 *  free
                 */
                printf("X_ALLOC_Free(&p)") ;
                X_ALLOC_Free(&p) ;
                if (p != NULL)
                    printf("ERROR\n") ;

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


