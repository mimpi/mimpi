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
                 *  setup values
                 */
                L_DEBUG_MSG_PrintMsg = vprintf ;

		/*
                 *  L_DEBUG_MSG_Write
                 */
		L_DEBUG_MSG_Write(__LINE__,__FILE__,0,TRUE,
                                  "h w\n") ;

		/*
                 *  L_DEBUG_MSG_PrintF
                 */
		L_DEBUG_MSG_PrintF(__LINE__,__FILE__,0,TRUE,
                                   "%s %i\n","a",33) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


