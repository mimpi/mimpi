/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "mpi.h"

#define PRUEBAS 		20


int main(int argc, char *argv[])
{

	int             ret;
	char           *send_buf;
	char           *recv_buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
	double          start_time;
	double          stop_time;
        double          used_time;
        double          avg_time;
        double          barrier_time;
        double          us_rate;
        int             max_len, lenbuf;
        int             j;
	int             me, nproc;
        FILE           *fparam ;


        /*
         *  welcome
         */
	setbuf(stdout, NULL) ;

        /*
         *  get values
         */
/*
	if (argc != 2)
        {
                printf("Use: gather <max_len> \n") ;
		exit(1) ;
        }
	max_len =atoi(argv[1]) ;
*/
/*
#if defined(__LINUX__)
        fparam = fopen("gather.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("gather.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("gather.in","rt") ;
#endif

        if (fparam == NULL)
        {
          printf("ERROR: can not open gather.in, sorry.\n") ;
          exit(1) ;
        }
        ret = fscanf(fparam,"max_len=%i",&max_len) ;
        fclose(fparam) ;
        if (ret != 1)
        {
          printf("ERROR: can not read 'max_len' from gather.in, sorry.\n") ;
	  exit(1) ;
        }
        if ( (max_len <= 0) || (max_len >= 8*1024*1024) )
        {
                printf("ERROR: (max_len <= 0) || (max_len >= 8*1024*1024)\n") ;
                exit(1) ;
        }
*/
        max_len = 1024 * 1024;


        /*
         *  init MPI
         */
	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("Can't init\n") ;
		exit(1) ;
	}

	MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
	MPI_Get_processor_name(processor_name,&namelen) ;
	MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;

	MPI_Barrier(MPI_COMM_WORLD) ;

#if (0)
	printf("Process %d; total %d is alive on %s\n",me,nproc,processor_name) ;
#endif


        /*
         *  buffers
         */
        send_buf = (char *) malloc((unsigned) max_len) ;
        if (send_buf == NULL)
        {
                perror("Error en malloc") ;
                exit(1) ;
        }
	memset(send_buf,'x',max_len) ;

        recv_buf = (char *) malloc((unsigned) max_len * nproc) ;
        if (recv_buf == NULL)
        {
                perror("Error en malloc") ;
                exit(1) ;
        }
	memset(recv_buf,'x',max_len * nproc) ;


        /*
         *  barrier time
         */
	start_time = MPI_Wtime() ;
	for(j = 0; j < 2000; j++)
        {
	  MPI_Barrier(MPI_COMM_WORLD) ;
        }
        barrier_time = (MPI_Wtime() - start_time);
        barrier_time = barrier_time / (float) 2000.0;

	if (me == 0)
        	printf(">>>>>>>>> BARRERA1  =%e\n",  barrier_time);


        /*
         *  test
         */
	barrier_time = 0 ;
        for (lenbuf = 1; (lenbuf <= max_len); lenbuf *= 2)
        {
	        MPI_Barrier(MPI_COMM_WORLD) ;

		if (me != 0)
		{
			for(j = 0; j < PRUEBAS; j++)
                	{

				MPI_Gather(send_buf,lenbuf,MPI_CHAR,
				           recv_buf,lenbuf,MPI_CHAR,
                                           0,MPI_COMM_WORLD) ;
	                        MPI_Barrier(MPI_COMM_WORLD) ;
			}
		}
		else
		{
		        avg_time = 0.0;
			start_time = MPI_Wtime() ;
			for(j = 0; j < PRUEBAS; j++)
                        {

				MPI_Gather(send_buf,lenbuf,MPI_CHAR,
				           recv_buf,lenbuf,MPI_CHAR,
                                           0,MPI_COMM_WORLD) ;
	                        MPI_Barrier(MPI_COMM_WORLD) ;

			}
			stop_time = MPI_Wtime() ;
			used_time = (stop_time - start_time) ;

                	avg_time =  used_time  / (float)  PRUEBAS;
                	avg_time =  avg_time - barrier_time ;

			if (avg_time > 0)    /* rate is megabytes per second */
                        	us_rate = (double)((nproc * lenbuf)/
					(avg_time*(double)1000000)) ;
                	else
                        	us_rate = 0.0;

                	printf("len_bytes=%e avg_time_sec=%e rate_Mbytes_sec=%e\n", 
			        (double)lenbuf, (double)avg_time, (double)us_rate) ;
                }

        }

#if (0)
	if (me == 0)
	    printf("\nclock resolution in seconds: %10.8f\n", MPI_Wtick()) ;
#endif

	MPI_Finalize() ;
        free(send_buf) ;
        free(recv_buf) ;
	exit(0) ;

}



