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



        /**
         **  include files
         **/

	#include <stdlib.h>
	#include <stdio.h>

	#include "mpi.h"

	#include "test_params.h"
	#include "test_buffers.h"
	#include "test_times.h"
	#include "test_user.h"



        /**
         **  constants
         **/

	#define PRUEBAS 		100



        /**
         **  Main
         **/

int main(int argc, char *argv[])
{
	int             ret;
	char           *buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
	double          start_time;
	double          stop_time;
        double          used_time;
        double          avg_time;
        double          barrier_time;
        double          us_rate;
        int             max_len, min_len, lenbuf;
        int             j;
	int             me, nproc;


        /*
         *  welcome
         */
	setbuf(stdout, NULL) ;
        printf
        (
          "\t bcast\n"
          "\t-------\n"
          "\n"
        ) ;


        /*
         *  max_len  ...
         */
	max_len = 1024 * 1024;
        ret = TEST_PARAMS_getLimits("bcast.in",&max_len,&min_len) ;
	if (ret < 1)
            exit(1) ;


        /*
         *  MPI init  ...
         */
	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("Can't init\n") ;
		exit(1) ;
	}


        /*
         *  MPI info  ...
         */
	MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
	MPI_Get_processor_name(processor_name,&namelen) ;
	MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;
#if (0)
	printf("Process %d; total %d is alive on %s\n",me,nproc,processor_name) ;

	if (me == 0)
	    printf("\nclock resolution in seconds: %10.8f\n", MPI_Wtick()) ;
#endif


        /*
         *  try get buffers ...
         */
        ret = TEST_BUFFERS_getBuf(max_len,&buf) ;
	if (ret < 1)
            exit(1) ;


        /*
         *  barrier_time
         */
	printf("barrier\n") ;
        MPI_Barrier(MPI_COMM_WORLD) ;
        barrier_time = TEST_TIMES_getBarrierTime(PRUEBAS) ;
        if (me == 0)
            printf("BARRERA1=%e\n",  barrier_time);


        /*
         *  test
         */
	lenbuf = 1;
        while (lenbuf <= max_len)
        {
	        MPI_Barrier(MPI_COMM_WORLD) ;

		avg_time = 0.0;
		if (me != 0)
		{
			for(j = 0; j < PRUEBAS; j++)
                        {

				ret = MPI_Bcast(buf,lenbuf,MPI_CHAR,0,
				                MPI_COMM_WORLD) ;
				if (ret != MPI_SUCCESS)
						printf("ERROR EN BCAST \n");

	                    
			}
		}
		else
		{
			start_time = MPI_Wtime() ;
			for(j = 0; j < PRUEBAS; j++)
                        {

				ret = MPI_Bcast(buf,lenbuf,MPI_CHAR,0,
                                                MPI_COMM_WORLD) ;
    	                        if (ret != MPI_SUCCESS)
						printf("ERROR EN BCAST \n");


			}
			stop_time = MPI_Wtime() ;
			used_time = (stop_time - start_time) ;

                	avg_time =  used_time  / (float)  PRUEBAS;
				
			if (avg_time > 0)    /* rate is megabytes per second */
                        	us_rate = (double)((nproc * lenbuf)/
					(avg_time*(double)1000000)) ;
                	else
                        	us_rate = 0.0;

                	printf("len_bytes=%e avg_time_sec=%e rate_Mbytes_sec=%e\n", 
			        (double)lenbuf, (double)avg_time, (double)us_rate) ;
                }

                lenbuf *= 2;
        }


        /*
         *  get a key
         */
	if (me == 0)
 	    TEST_USER_getKey() ;


        /*
         *  finished
         */
	MPI_Finalize() ;
        free(buf) ;


        /*
         *  return ok
         */
	exit (0) ;

}


