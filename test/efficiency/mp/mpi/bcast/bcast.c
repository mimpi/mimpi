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
#include "mpi.h"

#define PRUEBAS 		100


int main(int argc, char *argv[])
{
	int             ret;
	char           *buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
	double          start_time;
        double          used_time;
        double          avg_time;
        double          barrier_time;
        double          us_rate;
        int             max_len, lenbuf;
        int             j;
	int             me, nproc;
        FILE           *fparam ;


        /*
         *  begining ...
         */

	setbuf(stdout, NULL) ;

        /*
         *  max_len  ...
         */
/*
	if (argc != 2)
        {
                printf("Use: bcast <max_len> \n") ;
		exit(1) ;
        }
	max_len =atoi(argv[1]) ;
*/
/*
#if defined(__LINUX__)
        fparam = fopen("bcast.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("bcast.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("/u/fperez/XMP/MiMPI/test/mp/mpi/performance/bcast/bcast.in","rt") ;
#endif
        if (fparam == NULL)
        {
                printf("ERROR: can not open bcast.in, sorry.\n") ;
		exit(1) ;
        }
        ret = fscanf(fparam,"max_len=%i",&max_len) ;
        fclose(fparam) ;
        if (ret != 1)
        {
                printf("ERROR: can not read a valid 'max_len' value from bcast.in, sorry.\n") ;
		exit(1) ;
        }
*/
	max_len = 1024 * 1024;

        if ( (max_len <= 0) || (max_len >= 8*1024*1024) )
        {
                printf("ERROR: (max_len <= 0) || (max_len >= 8*1024*1024)\n") ;
                exit(1) ;
        }

        /*
         *  MPI init  ...
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

#if (0)
	printf("Process %d; total %d is alive on %s\n",me,nproc,processor_name) ;
#endif


        buf = (char *) malloc((unsigned) max_len) ;
        if (buf == NULL)
        {
                perror("Error en malloc") ;
                exit(1) ;
        }
	memset(buf,'x',max_len) ;

	printf("barrier\n") ;
	 MPI_Barrier(MPI_COMM_WORLD) ;

        /* ... Barrier ... */
	start_time = MPI_Wtime() ;
	for(j = 0; j < 10; j++)
        {
	  MPI_Barrier(MPI_COMM_WORLD) ;
        }
	barrier_time = (MPI_Wtime() - start_time) ;
	barrier_time = barrier_time / 2000.0;

	if (me == 0)
        	printf(">>>>>>>>> BARRERA1  =%e\n",  barrier_time);

	/*barrier_time = 0;*/

        /* ... test ... */
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
			used_time = (MPI_Wtime() - start_time) ;

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

		if (me == 0)
		{
				char c;
				read(0, &c, 1);
		}

#if (0)
	if (me == 0)
	    printf("\nclock resolution in seconds: %10.8f\n", MPI_Wtick()) ;
#endif

	MPI_Finalize() ;
        free(buf) ;
	exit(0) ;

}

		
	
	
	
	
