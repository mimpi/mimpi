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


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                T_CHAR   *b ;
                T_U_INT   cb ;
                T_BOOL    ok ;


		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

                /*
                 *  setup values
                 */
                b = NULL ;

		/*
                 *  L_BUFFA_CatOneByteToCache
                 */
		_DO_( ok = L_BUFFA_CatOneByteToCache(&b,&cb,'a') ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_BUFFA_CatNBytesToCache
                 */
		_DO_( ok = L_BUFFA_CatNBytesToCache(&b,&cb,"bc",strlen("bc")) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_BUFFA_AjustCache
                 */
		_DO_( ok = L_BUFFA_AjustCache(&b,cb) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


