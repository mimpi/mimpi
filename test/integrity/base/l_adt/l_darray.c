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
 *  prove l_darray
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_adt/l_darray.h"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                t_pointerDArray  t ;
                T_U_LONG         n ;
                T_U_LONG         outn ;
                char             ptr_1 ;
                char             ptr_2 ;
                char             ptr_3 ;
                void            *outptr ;
                T_BOOL           ok ;


		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  setup values
                 */
                t = NULL ;
                n = 0L ;

		/*
                 *  L_DARRAY_InsEndDarray
                 */
		_DO_( ok = L_DARRAY_InsEndDarray(&t,&n,&ptr_1) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_InsEndDarray
                 */
		_DO_( ok = L_DARRAY_InsEndDarray(&t,&n,&ptr_2) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_InsEndDarray
                 */
		_DO_( ok = L_DARRAY_InsEndDarray(&t,&n,&ptr_3) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_DelEndDarray
                 */
		_DO_( ok = L_DARRAY_DelEndDarray(&t,&n,&outptr) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;
                if (outptr != &ptr_3)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_DelBeginDarray
                 */
		_DO_( ok = L_DARRAY_DelBeginDarray(&t,&n,&outptr) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;
                if (outptr != &ptr_1)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_GetNDarray
                 */
		_DO_( outn = L_DARRAY_GetNDarray(t) ) ;
                if (outn != n)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_DelEltoDarray
                 */
		_DO_( ok = L_DARRAY_DelEltoDarray(&t,&ptr_1) ) ;
                if (ok == TRUE)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_DelEltoDarray
                 */
		_DO_( ok = L_DARRAY_DelEltoDarray(&t,&ptr_2) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;

		/*
                 *  L_DARRAY_GetNDarray
                 */
		_DO_( outn = L_DARRAY_GetNDarray(t) ) ;
                if (outn != 0)
                    printf("ERROR\n") ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


