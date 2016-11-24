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
	#include "base/l_alloc/x_alloc.h"
	#include "base/l_string/x_string.h"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		T_BOOL   ok ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 * X_STRING_Match
                 */
		_DO_( ok = X_STRING_Match("a.b.c.exe","*.exe",FALSE) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 * X_STRING_Match
                 */
		_DO_( ok = X_STRING_Match("aaabaaa","*b*",FALSE) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 * X_STRING_Match
                 */
		_DO_( ok = X_STRING_Match("aaaaabc","**b?",FALSE) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 * X_STRING_Match
                 */
		_DO_( ok = X_STRING_Match("b123aaacb123b","b???*b???b",FALSE) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


