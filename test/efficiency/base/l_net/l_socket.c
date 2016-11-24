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
 *  prove x_socket.c 
 *
 */

	#include "base/l_basic/c_basic.h"


        #define MAX_DATA_MOVE "1048576"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
		pid_t   pid_1 ;
		pid_t   pid_2 ;
		int     status ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;


		/*
                 *  load server
                 */
                pid_1 = fork() ;
                switch(pid_1)
                {
                  case -1 :
                       perror("fork: ") ;
                       break ;
                  case 0 :
                       execlp("./server.exe",
                              "./server.exe",
                              MAX_DATA_MOVE,
                              NULL) ;
                       perror("execlp: ") ;
                       exit(-1) ;
                       break ;
                  default :
                       break ;
                }

		/*
                 *  load client
                 */
                pid_2 = fork() ;
                switch(pid_2)
                {
                  case -1 :
                       perror("fork: ") ;
                       break ;
                  case 0 :
                       sleep(1) ;
                       execlp("./client.exe",
                              "./client.exe",
                              MAX_DATA_MOVE,
                              NULL) ;
                       perror("execlp: ") ;
                       exit(-1) ;
                       break ;
                  default :
                       break ;
                }

		/*
                 *  load client
                 */
                wait(&status) ;
                wait(&status) ;


		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


