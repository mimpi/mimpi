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
 *  prove c_basic definitios
 *
 */

	#include "base/l_basic/c_basic.h"


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
                 *  data type sizes
                 */
		printf("\tchar\n") ;
		printf("\t- T_CHAR(%i)\n",    c_CHAR) ;
		printf("\n") ;

		printf("\tscalar\n") ;
                printf("\t- T_SHORT(%i)\n",   c_SHORT ) ;
                printf("\t- T_U_SHORT(%i)\n", c_U_SHORT ) ;
                printf("\t- T_INT(%i)\n",     c_INT ) ;
                printf("\t- T_U_INT(%i)\n",   c_U_INT ) ;
                printf("\t- T_LONG(%i)\n",    c_LONG ) ;
                printf("\t- T_U_LONG(%i)\n",  c_U_LONG ) ;
		printf("\n") ;

		printf("\tfloat\n") ;
                printf("\t- T_FLOAT(%i)\n",   c_FLOAT ) ;
                printf("\t- T_DOUBLE(%i)\n",  c_DOUBLE ) ;
		printf("\n") ;

		printf("\tbival\n") ;
                printf("\t- T_BOOL(%i)\n",    c_BOOL ) ;
                printf("\t- T_FLAG(%i)\n",    c_FLAG ) ;
		printf("\n") ;

		printf("\tstatus\n") ;
                printf("\t- T_STATUS(%i)\n",  c_STATUS ) ;
		printf("\n") ;

		printf("\tmemo\n") ;
                printf("\t- T_BYTE(%i)\n",    c_BYTE ) ;
                printf("\t- T_WORD(%i)\n",    c_WORD ) ;
                printf("\t- T_POINTER(%i)\n", c_POINTER ) ;
		printf("\n") ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


