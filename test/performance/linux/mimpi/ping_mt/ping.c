
/* ....................................................................
 *
 * Copyright (1997-2000)
 *  Felix Garcia Carballeira   <fgarcia@arcos.inf.uc3m.es>
 *  Alejandro Calderon Mateos   <acaldero@arcos.inf.uc3m.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



#include "mpi.h"
#include "test_params.h"
#include "test_buffers.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#if defined(HAVE_WINDOWS_H)
    #include <windows.h>
#endif



int             me ;
int             nproc ;
char            processor_name[MPI_MAX_PROCESSOR_NAME] ;
int             max_len, min_len ;

#define UNKNOW  0
#define FIXED   1
#define SPARSE  2
#define DENSE   3
int             fill_pattern = UNKNOW ;

int main_test_thread () ;

#define DSPL_SHORT


int main(int argc, char *argv[])
{
	    int             ret;
	    char            msg[1024];
	    int             namelen;
	    MPI_Status      status;


        /*
         *  welcome
         */
	    setbuf(stdout, NULL);


        /*
         *  max_len  ...
         */
        max_len = 4 * 1024 * 1024;
        ret = TEST_PARAMS_getLimits("ping.in",&max_len,&min_len) ;
        if (ret < 1)
            exit(1) ;


        /*
         *  MPI_Init  ...
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
    	printf("Process %d; total %d is alive on %s\n",
                me,nproc,processor_name);
        if (me == 0)
            printf("\nclock resolution in seconds: %10.8f\n", 
                   MPI_Wtick()) ;

#endif


        /*
         *  MPI_Barrier  ...
         */
	    MPI_Barrier(MPI_COMM_WORLD) ;

       
        /*
         *  test ping pong  ...
         */
#if (0)
	    if (me == 0)
	    {
          sprintf(msg,"Ping-Pong ready") ;
	      ret=MPI_Send(msg,30,MPI_CHAR,1,1, MPI_COMM_WORLD);
	      printf("send.msg   = %s\n", msg);
	      printf("send.ret   = %d\n", ret);
	    }
	    else
	    {
	      ret=MPI_Recv(msg,30,MPI_CHAR,0,1, MPI_COMM_WORLD, &status);
	      printf("recv.msg   = %s\n", msg);
	      printf("recv.count = %d\n", status.count);
	    }
	    printf("PING ready\n");
#endif


        /* 
         *	Test itself
         */
        main_test_test() ;

        /* 
         *	NO compression
         */
		unsetenv("COMPRESSION") ;
        fill_pattern = FIXED ;
		if (me == 0)
			printf("\n\nWithout compression / Fixed buffer\n\n") ;
		main_test_thread() ;

        /* 
         *	WITH compression
         */
		setenv("COMPRESSION","BEST_SPEED",0) ;
        for (fill_pattern = UNKNOW; fill_pattern <= DENSE; fill_pattern++)
        {
          switch(fill_pattern)
          {
    	     case FIXED:
		          if (me == 0)
                      printf("\n\nWith compression / FIXED fill\n\n") ;
                  break ;
             case SPARSE:
		          if (me == 0)
                      printf("\n\nWith compression / Sparse fill\n\n") ;
                  break ;
             case DENSE:
		          if (me == 0)
                      printf("\n\nWith compression / Dense fill\n\n") ;
                  break ;
             default:
		          if (me == 0)
                      printf("\n\nWith compression / Unknow fill\n\n") ;
                  break ;
   	      }
          main_test_thread() ;
        }


        /*
         *  get a key
         */
        if (me == 0)
           {
             char c ;

             read(0, &c, 1);
           }


        /*
         *  finished
         */
        MPI_Finalize() ;


        /*
         *  return ok
         */
        exit (0) ;

}







/******************************************************************/


#define	N_THREADS		    16
#define PRUEBAS 		    1
#define PRUEBAS_NULO		1
#if defined(HAVE_WINDOWS_H)
#else
    #define DWORD   long
    #define WINAPI
#endif


struct thr
{
 int      lenbuf;
 int 	  tag;
 double	  used_time;
 char     *buf;
};


DWORD WINAPI nulo (void *p)
{
#if defined(HAVE_WINDOWS_H)
    ExitThread(0);
#else
	return 0;
#endif
}

		
DWORD WINAPI transfiere (struct thr *t)
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
 

int main_test_test
(
        /* VOID */
)
{
    int         i ;
    int         j ;
    int         k ;

    int         lenbuf;
    char       *buf;
    int         i_fill;

	double      start_time;
    double      used_time;
    double      avg_time;
    double      us_rate;

	double      barrier_time ;
	double		crear_threads[N_THREADS+1];

	struct thr	t[N_THREADS+1];

#if defined(HAVE_WINDOWS_H)
    HANDLE 	         thid[N_THREADS+1];
	DWORD            thinfo ;
#else
    pthread_t 	     thid[N_THREADS+1];
	pthread_attr_t   attr ;
#endif


/* 
 *	tiempo barrier
 */
if (me == 0)
{
    printf("\n\nbarrier overheat\n") ;
}
    start_time = MPI_Wtime() ;
    for(j = 0; j < PRUEBAS; j++)
    {
      MPI_Barrier(MPI_COMM_WORLD) ;
    }
    barrier_time = (MPI_Wtime() - start_time) ;
if (me == 0)
{
    printf("avg_time %f\n", barrier_time);
}


/* 
 *	tiempo en crear y esperar por N threads 
 */
if (me == 0)
{
    printf("\n\nthread overheat\n") ;
    for (i=1; i <= N_THREADS; i*=2)
	{
		start_time = MPI_Wtime();

		for(j = 0; j < PRUEBAS_NULO; j ++)
		{
#if defined(HAVE_WINDOWS_H)
		   for (k = 0; k < i; k++)
				thid[k] = CreateThread(NULL, 0,
                                      (LPTHREAD_START_ROUTINE) nulo,NULL,
                                      0,&thinfo);

		   WaitForMultipleObjects(k, thid, TRUE, INFINITE);
#else
			pthread_attr_init(&attr) ;
			for (k = 0; k < i; k++)
              	 pthread_create(&thid[k], &attr, (void *(*)(void *))nulo, NULL);

			for (k = 0; k < i; k++)
                 pthread_join(thid[k], NULL);
#endif
		}

		crear_threads[i]=((MPI_Wtime() - start_time)) / PRUEBAS_NULO;
		printf("threads %d avg_time %f\n",
				i, crear_threads[i]);
	}
}


/* 
 *	buffer ... 
 */
if (me == 0)
{
  printf("\n\nbuffer overheat\n") ;

#if defined(DSPL_SHORT)
		if (me == 0)
		{
       	    printf("len_bytes") ; 
		    for(lenbuf = 1; (lenbuf <= max_len); lenbuf *= 2)
       	        printf(" %d ", lenbuf) ;
       	    printf("\n") ; 
		}
#endif

  for (i_fill = UNKNOW; i_fill <= DENSE; i_fill++)
  {

#if defined(DSPL_LARGE)
     switch(i_fill)
     {
    	case FIXED:
             printf("FIXED fill\n") ;
             break ;
        case SPARSE:
             printf("SPARSE fill\n") ;
             break ;
        case DENSE:
             printf("DENSE fill\n") ;
             break ;
        default:
             printf("UNKNOW fill\n") ;
             break ;
   	 }
#endif

#if defined(DSPL_SHORT)
     switch(i_fill)
     {
        case FIXED:
             printf("FIXED_rate") ;
             break ;
        case SPARSE:
             printf("SPARSE_rate") ;
             break ;
        case DENSE:
             printf("DENSE_rate") ;
             break ;
        default:
             printf("UNKNOW_rate") ;
             break ;
     }
#endif

     for (lenbuf = 1; lenbuf <= max_len; lenbuf *= 2)
     {
        start_time = MPI_Wtime();
        for (i=1; i <= PRUEBAS; i++)
        {
      		 buf = (char *) malloc((unsigned) lenbuf);
      	     if (buf == NULL)
      			 {
                      perror("Error en malloc");
                      exit(1);
      			 }
       		 switch(i_fill)
       		 {
       			   case FIXED:
       			        TEST_BUFFERS_fill_fixed(lenbuf,
       									        &buf,
       											'\0') ;
       			        break ;
       			   case SPARSE:
       			        TEST_BUFFERS_fill_sparse(lenbuf,
       									        &buf,
       											'\0') ;
       			        break ;
       			   case DENSE:
       			        TEST_BUFFERS_fill_dense(lenbuf,
       									        &buf,
       											'\0') ;
       			        break ;
       			   default:
       			        break ;
       		 }
      		 free(buf);
        }
        used_time = (MPI_Wtime() - start_time);
        avg_time =  used_time / (double) PRUEBAS;
      
        us_rate = 0.0;
        if (avg_time > 0)
        {
            /* rate is megabytes per second */
            us_rate = (double) ( lenbuf / (avg_time * (double)(1000000)) ) ;
        }
      
#if defined(DSPL_LARGE)
        printf("len_bytes %d avg_time_sec %f rate_Mbytes_sec %f\n", 
                lenbuf, (double)avg_time, (double)us_rate);
#endif
#if defined(DSPL_SHORT)
        printf(" %f ", (double)us_rate);
#endif
     }

#if defined(DSPL_SHORT)
        printf("\n") ;
#endif

  }
}
	

/*
 *  return ok
 */
return (1) ;

}


int main_test_thread
(
        /* VOID */
)
{
    int         i ;
    int         j ;
    int         k ;

    int         lenbuf;
    char       *buf;

	double      start_time;
    double      used_time;
    double      avg_time;
    double      us_rate;

	double      barrier_time ;
	double		crear_threads[N_THREADS+1];

	struct thr	t[N_THREADS+1];

#if defined(HAVE_WINDOWS_H)
    HANDLE 	         thid[N_THREADS+1];
	DWORD            thinfo ;
#else
    pthread_t 	     thid[N_THREADS+1];
	pthread_attr_t   attr ;
#endif


/* 
 *	envios y recepciones... 
 */
#if defined(DSPL_SHORT)
		if (me == 0)
		{
       	    printf("len_bytes") ; 
		    for(lenbuf = 1; (lenbuf <= max_len); lenbuf *= 2)
       	        printf(" %d ", lenbuf) ;
       	    printf("\n") ; 
		}
#endif

    for (i=1; i <= N_THREADS; i*=2)
	{

#if defined(DSPL_LARGE)
		if (me == 0)
			printf("\n\nN_THREADS = %d\n", i);
#endif

		MPI_Barrier(MPI_COMM_WORLD) ;


#if defined(DSPL_SHORT)
		if (me == 0)
       	    printf("%d_threads", i) ; 
#endif

		lenbuf = 1;
		while (lenbuf <= max_len)
       	{

			 buf = (char *) malloc((unsigned) lenbuf * N_THREADS );
		     if (buf == NULL)
			 {
                perror("Error en malloc");
                exit(1);
			 }
			 switch(fill_pattern)
			 {
			   case FIXED:
			        TEST_BUFFERS_fill_fixed(lenbuf * N_THREADS,
									        &buf,
											'\0') ;
			        break ;
			   case SPARSE:
			        TEST_BUFFERS_fill_sparse(lenbuf * N_THREADS,
									        &buf,
											'\0') ;
			        break ;
			   case DENSE:
			        TEST_BUFFERS_fill_dense(lenbuf * N_THREADS,
									        &buf,
											'\0') ;
			        break ;
			   default:
			        break ;
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

				thid[k] = CreateThread( NULL, 0, 
                                        (LPTHREAD_START_ROUTINE) transfiere,
                                        &(t[k]),0,&thinfo );
			}

			WaitForMultipleObjects(k, thid, TRUE, INFINITE);
#else
			pthread_attr_init(&attr) ;
			for (k = 0; k < i; k++)
			{
				t[k].lenbuf = lenbuf;
				t[k].tag = k;
				t[k].buf = buf + (k * lenbuf);

				pthread_create(&thid[k], &attr, 
                               (void *(*)(void *))transfiere, &(t[k]));
			}

			for (k = 0; k < i; k++)
				 pthread_join(thid[k], NULL);
#endif

			used_time = (MPI_Wtime() - start_time);
       		avg_time =  used_time / (double) PRUEBAS;
	
       		us_rate = 0.0;
			if (avg_time > 0)
               {
                  /* rate is megabytes per second */
                  us_rate = (double) 
                            (
                              (nproc * lenbuf * (i)) 
                              / 
                              (avg_time * (double)(1000000))
                            ) ;
               }


#if defined(DSPL_LARGE)
			if (me == 0)
       			printf("len_bytes %d avg_time_sec %f rate_Mbytes_sec %f\n", 
                       lenbuf, (double)avg_time/(2.0*i), (double)us_rate);
#endif

#if defined(DSPL_SHORT)
			if (me == 0)
       			printf(" %f ", (double)us_rate);
#endif
	
			lenbuf *= 2;
			free(buf);
		}

#if defined(DSPL_SHORT)
		if (me == 0)
    		printf("\n");
#endif

	}


/*
 *  return ok
 */
return (1) ;

}

