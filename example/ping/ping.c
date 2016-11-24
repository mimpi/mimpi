/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@hinojo.datsi.fi.upm.es>
 * <fgarcia@hinojo.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"


      int
      main
      (
        int   argc,
        char *argv[]
      )
      {
	int             ret;
	char           *buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
        int             max_pingpong, buf_len ;
        int             i;
	int             me, nproc;
	MPI_Status      status;


	/*
	 *  init
	 */
	setbuf(stdout, NULL) ;
	if (argc != 2)
        {
                printf
		(
		  "\n"
		  "Usage: ping <max_pingpong> \n"
		  "\n"
		) ;
		exit(1) ;
        }

	/*
	 *  max_pingpong
	 */
	buf_len    = 1024 ;
	max_pingpong = atoi(argv[1]) ;
        if ( (max_pingpong <= 0) || (max_pingpong >= 1*1024*1024) )
        {
                printf("ERROR: max_pingpong = %i\n",max_pingpong) ;
                printf("ERROR: (max_pingpong <= 0) || (max_pingpong >= 1*1024*1024)\n") ;
                exit(1) ;
        }

	/*
	 *  MPI_Init
	 */
	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("ERROR: Can't init\n") ;
		exit(1) ;
	}

	/*
	 *  get info
	 */
	MPI_Barrier(MPI_COMM_WORLD) ;
	MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
	MPI_Get_processor_name(processor_name,&namelen) ;
	MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;
	printf("INFO: Process %d; total %d is alive on %s\n",
		me,nproc,processor_name) ;
	printf("INFO: Process %d see clock resolution: %10.8f\n", 
		me,MPI_Wtick()) ;

	/*
	 *  alloc buffer
	 */
        buf = (char *) malloc((unsigned) buf_len) ;
        if (buf == NULL)
        {
                perror("ERROR: Error at malloc") ;
                exit(1) ;
        }

	/*
	 *  ping pong
	 */
	MPI_Barrier(MPI_COMM_WORLD) ;
	for (i=0; i<max_pingpong; i++)
	{
	  if (me == 0)
	     {
   	       printf("ping ... ") ;
	       ret=MPI_Send(buf,buf_len,MPI_CHAR,1,1, 
			       MPI_COMM_WORLD) ;
	     }
	  else
	     {
	       ret=MPI_Recv(buf,buf_len,MPI_CHAR,0,1, 
			       MPI_COMM_WORLD, &status) ;
   	       printf("... pong\n") ;
	     }
	}

	/*
	 *  end
	 */
	MPI_Finalize() ;
        free(buf) ;
	exit(0) ;
     }



