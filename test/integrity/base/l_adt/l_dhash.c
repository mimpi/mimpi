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


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		t_dhash   *h ;
		T_U_LONG   n ;
		T_POINTER *outptr ;
		T_BOOL     ok ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  L_DHASH_Creat
                 */
		_DO_( h = L_DHASH_Creat() ) ;
                if (h == NULL)
                    printf("ERROR\n") ;

		/*
                 *  L_DHASH_NumberKV
                 */
		_DO_( n = L_DHASH_NumberKV(h) ) ;
                if (n != 0L)
                    printf("ERROR\n") ;

		/*
                 *  L_DHASH_InsertKV
                 */
		_DO_( ok = L_DHASH_InsertKV(h,"this",(T_POINTER)h) ) ;
                if (ok != TRUE)
                    printf("ERROR\n") ;

		/*
                 *  L_DHASH_NumberKV
                 */
		_DO_( n = L_DHASH_NumberKV(h) ) ;
                if (n != 1L)
                    printf("ERROR\n") ;

		/*
                 *  L_DHASH_ValueOf
                 */
		_DO_( outptr = L_DHASH_ValueOf(h,"this",TRUE) ) ;
                if (outptr == NULL)
                    printf("ERROR\n") ;

		/*
                 *  L_DHASH_ValueOf
                 */
		_DO_( outptr = L_DHASH_ValueOf(h,"that",TRUE) ) ;
                if (outptr != NULL)
                    printf("ERROR\n") ;

		/*
                 *  L_DHASH_Destroy
                 */
 		_DO_( ok = L_DHASH_Destroy(&h) ) ;
                if (ok != TRUE)
                    printf("ERROR\n") ;

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


