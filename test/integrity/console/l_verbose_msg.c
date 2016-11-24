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
 *  prove l_verbose_msg.c
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "console/l_verbose_msg.h"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 *  simple printer
                 */
                L_VERBOSE_MSG_setPrinter(NULL) ;
		L_VERBOSE_MSG_PrintF("'%s' and '%i' are not equals",
                                     "a",33) ;

		/*
                 *  simple printer
                 */
                L_VERBOSE_MSG_setPrinter(vprintf) ;
		L_VERBOSE_MSG_PrintF("'%s' and '%i' are not equals",
                                     "a",33) ;


		/*
                 */
		printf("\n") ;
		printf("end\n") ;
		return 1 ;
	}


