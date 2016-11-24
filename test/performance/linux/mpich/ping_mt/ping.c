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


#define	N_THREADS		16
#define PRUEBAS 		10
#define PRUEBAS_THREADS		10


struct thr{
	int	lenbuf;
	int 	tag;
	double 	used_time;
};

void transfiere(struct thr *t);
void nulo(void *);
int             max_len;
int             me, nproc;
char           *buf;


int main(int argc, char *argv[])
{
	int             ret;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
	double          start_time;
        double          used_time;
        double          avg_time;
        double          us_rate;
        int             lenbuf;
	MPI_Status      status;
        FILE           *fparam ;
	int 		i;
	int 		k;
	int 		j;
	struct thr	t[N_THREADS+1];
	pthread_attr_t 	attr;
        pthread_t 	thid[N_THREADS+1];
	double		crear_threads[N_THREADS+1];



	setbuf(stdout, NULL);
        fparam = fopen
                 (
                   "/home/proyectos/mpi/src/MiMPI/test_II/mpich_linux/ping/ping.in",
                   "rt"
                 ) ;
        if (fparam == NULL)
        {
                printf("ERROR: can not open ping.in, sorry.\n");
		exit(1);
        }
        ret = fscanf(fparam,"max_len=%i",&max_len) ;
        fclose(fparam) ;
        if (ret != 1)
        {
                printf("ERROR: can not read a valid 'max_len' value from ping.in, sorry.\n");
		exit(1);
        }
        if ( (max_len <= 1) || (max_len >= 8*1024*1024) )
        {
                printf("ERROR: max_len = %i\n",max_len);
                printf("ERROR: (max_len <= 0) || (max_len >= 4*1024*1024)\n");
                exit(1) ;
        }


	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("Can't init\n");
		exit(1);
	}

	MPI_Comm_rank(MPI_COMM_WORLD,&me);
	MPI_Get_processor_name(processor_name,&namelen);
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);

#if (0)
	printf("Process %d; total %d is alive on %s\n",me,nproc,processor_name);
#endif


	MPI_Barrier(MPI_COMM_WORLD) ;

        buf = (char *) malloc((unsigned) max_len);
        if (buf == NULL)
        {
                perror("Error en malloc");
                exit(1);
        }

#if (1)
	printf("PING LISTO \n");
	if (me == 0)
	{
	  ret=MPI_Send(buf,12,MPI_CHAR,1,1, MPI_COMM_WORLD);
	}
	else
	{
	  ret=MPI_Recv(buf,12,MPI_CHAR,0,1, MPI_COMM_WORLD, &status);
	  printf("count = %d\n", status.count);
	}
#endif

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


	/* tiempo en crear y esperar por N threads */


if (me == 0)
{
	i = 1;
        while(i <= N_THREADS)
	{
		start_time = MPI_Wtime();
		for(j = 0; j < PRUEBAS_THREADS; j ++)
		{
			for (k = 0; k < i; k++)
                		pthread_create(&thid[k], &attr, 
					(void *(*)(void *))nulo, NULL);

			for (k = 0; k < i; k++)
                                pthread_join(thid[k], NULL);
		}

		crear_threads[i]=((MPI_Wtime() - start_time)) / PRUEBAS_THREADS;
		printf("Tiempo para %d threads = %f\n", i, crear_threads[i]);

		  i *= 2;

	}
}


	i = 1;
	while(i <= N_THREADS)
	{

		if (me == 0)
			printf("N_THREADS = %d \n\n", i);
		MPI_Barrier(MPI_COMM_WORLD) ;

		lenbuf = 1;
		while (lenbuf <= max_len)
        	{

			start_time = MPI_Wtime();
	
/*
			transfiere(&t[i]);
*/

			for (k = 0; k < i; k++)
			{
				t[k].lenbuf = lenbuf;
				t[k].tag = k;
				pthread_create(&thid[k], &attr,  
					(void *(*)(void *))transfiere, &t[k]);
			}


			for (k = 0; k < i; k++)
				pthread_join(thid[k], NULL);


			used_time = (MPI_Wtime() - start_time);
	
        		avg_time =  used_time / (float)  PRUEBAS;
			avg_time = avg_time - crear_threads[i];

			if (avg_time > 0)    /* rate is megabytes per second */
                   		us_rate = (double)((nproc * lenbuf * (i))/
					(avg_time*(double)1000000));
       			else
       				us_rate = 0.0;


			if (me == 0)
       				printf("len_bytes=%e avg_time_sec=%e rate_Mbytes_sec=%e\n", (double)lenbuf, (double)avg_time/(2.0*i), (double)us_rate);
	
			lenbuf *= 2;
		}

		i *= 2;

	}



#if (0)
	if (me != 0)
	    printf("\nclock resolution in seconds: %10.8f\n", MPI_Wtick());
#endif

	MPI_Finalize();
        free(buf);
	exit(0);

}


void nulo (void *p)
{
	pthread_exit(0);
}

		
void transfiere(struct thr *t)
{
	MPI_Status      status;
	int j;

	
	if (me == 0)
	{
		for(j = 0; j < PRUEBAS; j++)
               	{
			MPI_Recv(buf,t->lenbuf,MPI_CHAR,1,t->tag,
					MPI_COMM_WORLD, &status);

			MPI_Send(buf,t->lenbuf,MPI_CHAR,1,t->tag,
					MPI_COMM_WORLD);
		}
	}
	else
	{
		for(j = 0; j < PRUEBAS; j++)
                {
			MPI_Send(buf,t->lenbuf,MPI_CHAR,0,t->tag,
                                        MPI_COMM_WORLD);

			MPI_Recv(buf,t->lenbuf,MPI_CHAR,0,t->tag,
                                                MPI_COMM_WORLD, &status);
                }

        }

	pthread_exit(0);

}

		
	
	
	
	
	
	
