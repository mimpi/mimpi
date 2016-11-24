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
 *  prove l_trace_msg.c
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "console/l_trace_msg.h"


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
                 *  null printer
                 */
                L_TRACE_MSG_setPrinter(NULL) ;
		L_TRACE_MSG_PrintF(DEFCON_1,
                                   "%s %i : null printer","test",1) ;

		/*
                 *  simple printer
                 */
                L_TRACE_MSG_setPrinter(vprintf) ;
		L_TRACE_MSG_PrintF(DEFCON_1,
                                   "%s %i : simple printer","test",2) ;


		/*
                 */
                printf("\n") ;
		printf("end\n") ;
		return 1 ;
	}


