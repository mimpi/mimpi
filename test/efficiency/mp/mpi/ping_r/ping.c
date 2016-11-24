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


/*
 * include
 */

#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>
#if defined(HAVE_WINDOWS_H)
    #include <windows.h>
#endif


/*
 * define
 */
#define	N_THREADS		16
#define PRUEBAS 		30
#define PRUEBAS_THREADS		40
#if defined(HAVE_WINDOWS_H)
#else
    #define DWORD   long
    #define WINAPI
#endif


/*
 * types
 */
struct thr{
	int	lenbuf;
	int 	tag;
	double 	used_time;
	char           *buf;
};


/*
 * global variable
 */
int             max_len;
int             me, nproc;
char           *buf;


/*
 * thread code
 */
DWORD WINAPI nulo (void *p)
{
#if defined(HAVE_WINDOWS_H)
	ExitThread(0);
#else
	return 0;
#endif
}

		
DWORD WINAPI transfiere(struct thr *t)
{
	MPI_Status      status;
	int j, ret;

	/*
	 * printf("Yo el %d con tag %d \n", me, t->tag);
	 */
	
	if (me == 0)
	{
		for(j = 0; j < PRUEBAS; j++)
        {
	
			ret = MPI_Recv(t->buf,t->lenbuf,MPI_CHAR,1,t->tag,
					       MPI_COMM_WORLD, &status);
            if (ret != MPI_SUCCESS)
               	perror("Error en MPI_Send");

		
			ret = MPI_Send(t->buf,t->lenbuf,MPI_CHAR,1,t->tag,
					       MPI_COMM_WORLD);
            if (ret != MPI_SUCCESS)
               	perror("Error en MPI_Recv");
		
		}
	}
	else
	{
		for(j = 0; j < PRUEBAS; j++)
        {

			ret = MPI_Send(t->buf,t->lenbuf,MPI_CHAR,0,t->tag,
                                         MPI_COMM_WORLD);
            if (ret != MPI_SUCCESS)
               	perror("Error en MPI_Send");


			ret = MPI_Recv(t->buf,t->lenbuf,MPI_CHAR,0,t->tag,
                                         MPI_COMM_WORLD, &status);
            if (ret != MPI_SUCCESS)
               	perror("Error en MPI_Recv");

        }

    }

#if defined(HAVE_WINDOWS_H)
	ExitThread(0);
#endif
}


/*
 * MAIN
 */
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
/*        FILE           *fparam ;*/
	int 		i;
	int 		k;
	int 		j;
	struct thr	t[N_THREADS+1];
	double		crear_threads[N_THREADS+1];
#if defined(HAVE_WINDOWS_H)
    HANDLE 	     thid[N_THREADS+1];
	DWORD        thinfo ;
#else
	pthread_attr_t   attr ;
    pthread_t 	     thid[N_THREADS+1];
#endif



	setbuf(stdout, NULL);
#if (0)
	if (argc != 2)
        {
                printf("Use: client <max_len> \n");
		exit(1);
        }
	max_len =atoi(argv[1]);
#endif

	/*
#if (1)
#if defined(__LINUX__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("/home/ssoo/gpmimd/FELIX/XMP/xmp/test/mpi/ping_r/ping.in","rt") ;
#endif
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
#endif
*/
	    max_len = 1024 * 1024 ;

        if ( (max_len <= 0) || (max_len >= 8*1024*1024) )
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

       

#if (0)
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


/* 
 *	tiempo en crear y esperar por N threads 
 */
	/*
if (me == 0)
{
	i = 1;
    while(i <= N_THREADS)
	{
		start_time = MPI_Wtime();

#if defined(HAVE_WINDOWS_H)
		for(j = 0; j < PRUEBAS_THREADS; j ++)
		{
		   for (k = 0; k < i; k++)
				thid[k] = CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE) nulo,NULL,0,&thinfo);

		   WaitForMultipleObjects(k, thid, TRUE, INFINITE);
		}
#else
		for(j = 0; j < PRUEBAS_THREADS; j ++)
		{
			for (k = 0; k < i; k++)
              	 pthread_create(&thid[k], &attr, (void *(*)(void *))nulo, NULL);

			for (k = 0; k < i; k++)
                 pthread_join(thid[k], NULL);
		}
#endif

		crear_threads[i]=((MPI_Wtime() - start_time)) / PRUEBAS_THREADS;
		printf("Tiempo para %d threads = %f\n", i, crear_threads[i]);

		  i *= 2;

	}
}
*/

/* 
 *	envios y recepciones... 
 */
	i = 1 ;
	while(i <= N_THREADS)
	{

		if (me == 0)
			printf("N_THREADS = %d \n\n", i);
		MPI_Barrier(MPI_COMM_WORLD) ;

		lenbuf = 1;
		while (lenbuf <= max_len)
       	{

			 buf = (char *) malloc((unsigned) lenbuf * N_THREADS );
		     if (buf == NULL)
			 {
                perror("Error en malloc");
                exit(1);
			 }

		 	start_time = MPI_Wtime();
	
#if (0)
			transfiere(&t[i]);
#endif


#if defined(HAVE_WINDOWS_H)
			for (k = 0; k < i; k++)
			{
				t[k].lenbuf = lenbuf;
				t[k].tag = k;
				t[k].buf = buf + (k * lenbuf);

				thid[k] = CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE) transfiere,&(t[k]),0,&thinfo);
			}

			WaitForMultipleObjects(k, thid, TRUE, INFINITE);
#else
			for (k = 0; k < i; k++)
			{
				t[k].lenbuf = lenbuf;
				t[k].tag = k;
				t[k].buf = buf + (k * lenbuf);

				pthread_create(&thid[k], &attr, (void *(*)(void *))transfiere, &t[k]);
			}

			for (k = 0; k < i; k++)
				pthread_join(thid[k], NULL);
#endif

			used_time = (MPI_Wtime() - start_time);
	
       		avg_time =  used_time / (float)  PRUEBAS;
	

			if (avg_time > 0)    /* rate is megabytes per second */
                   	us_rate = (double)((nproc * lenbuf * (i))/
					(avg_time*(double)1000000));
      			else
       				us_rate = 0.0;


			if (me == 0)
       			printf("len_bytes=%d avg_time_sec=%f rate_Mbytes_sec=%f\n", lenbuf, (double)avg_time/(2.0*i), (double)us_rate);
	
			lenbuf *= 2;
			free(buf);
		}

		i *= 2;

	}

		if (me == 0)
		{
			char c;
			read(0, &c, 1);
		}


#if (0)
	if (me != 0)
	    printf("\nclock resolution in seconds: %10.8f\n", MPI_Wtick());
#endif

	MPI_Finalize();
	exit(0);

}

