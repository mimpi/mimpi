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
 *  prove x_dtd.c 
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_alloc/x_alloc.h"
        #include "base/l_string/x_string.h"
	#include "base/l_string/x_dtd.h"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		T_CHAR  *ret ;
		T_CHAR  *dtd ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  setup
                 */
                dtd = NULL ;

		/*
                 * X_DTD_begin
                 */
		_DO_( ret = X_DTD_begin(&dtd,"my_type","my_obj") ) ;
                if (ret == NULL)
                    printf("ERROR\n") ;

		/*
                 * X_DTD_put
                 */
		_DO_( ret = X_DTD_put(&dtd,"<x_dtd></x_dtd>") ) ;
                if (ret == NULL)
                    printf("ERROR\n") ;

		/*
                 * X_DTD_addln
                 */
		_DO_( ret = X_DTD_addln(&dtd) ) ;
                if (ret == NULL)
                    printf("ERROR\n") ;

		/*
                 * X_DTD_BeginPutEnd
                 */
		_DO_( ret = X_DTD_vBeginPutEnd(&dtd,"bool","my_obj","TRUE") ) ;
                if (ret == NULL)
                    printf("ERROR\n") ;

		/*
                 * X_DTD_end
                 */
		_DO_( ret = X_DTD_end(&dtd,"my_type","my_obj") ) ;
                if (ret == NULL)
                    printf("ERROR\n") ;

		/*
                 *  cleanup
                 */
                printf("\n"
                       "final dtd is:\n"
                       "%s\n"
                       "\n",dtd) ;
                free(dtd) ;

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


