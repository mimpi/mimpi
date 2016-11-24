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


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		t_pointerDStack  s ;
		t_pointerDStack  outs ;
		T_POINTER       *outptr ;
		T_BOOL           ok ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  L_DSTACK_CreatEmpty
                 */
		_DO_( s = L_DSTACK_CreatEmpty() ) ;
                if (s != NULL)
                    printf("ERROR\n") ;

		/*
                 *  L_DSTACK_IsEmpty
                 */
		_DO_( ok = L_DSTACK_IsEmpty(s) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DSTACK_Push
                 */
		_DO_( outs = L_DSTACK_Push(&s,(T_POINTER)&s) ) ;
                if (outs == NULL)
                    printf("ERROR\n") ;

		/*
                 *  L_DSTACK_IsEmpty
                 */
		_DO_( ok = L_DSTACK_IsEmpty(s) ) ;
                if (ok != FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DSTACK_Pop
                 */
		_DO_( outptr = L_DSTACK_Pop(&s) ) ;
                if (outptr == NULL)
                    printf("ERROR\n") ;

		/*
                 *  L_DSTACK_IsEmpty
                 */
		_DO_( ok = L_DSTACK_IsEmpty(s) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DSTACK_Empty
                 */
 		_DO_( L_DSTACK_Empty(&s) ) ;

		/*
                 *  L_DSTACK_IsEmpty
                 */
		_DO_( ok = L_DSTACK_IsEmpty(s) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


