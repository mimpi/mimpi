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
 *  prove x_file.c
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_file/x_file.h"


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
                 *  const values
                 */
                printf("\tdefault\n") ;
                printf("\t- NULL_DEVICE_PATH(%s)\n",    NULL_DEVICE_PATH) ;
                printf("\n") ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


