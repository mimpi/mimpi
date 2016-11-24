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


#define PRUEBAS 		20

#include "pingpong.h"

void table_top(int, int, int, int, double, char *);
void table_body(int, int, int, int, int, double, double*, FILE *);
void InitTimer(void);

int RecvSocket(SOCKET, char *, int);
int SendSocket(SOCKET, char *, int);

LARGE_INTEGER StartTime;
LARGE_INTEGER GetStartTime(void);
double ElapsedMicroseconds();
double timer();




int main(int argc, char *argv[])
{

	int             ret;
	char           *buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
	double          start_time;
        double          used_time;
        double          avg_time;
        double          us_rate;
        int             max_len, lenbuf;
        int             j;
	int             me, nproc;
	MPI_Status      status;
        FILE           *fparam ;

		double     tf[SAMPLES + 1], t_call;
  int        log2nbyte, nbyte, ns, n_pp, npes, bytes;
  int        n_init, n_mess;
  int        enable = 1;
  char       *Title ="Single Messages --- MPI";
  FILE       *ifp;


	setbuf(stdout, NULL);


/*
	if (argc != 2)
        {
                printf("Use: ping <max_len> \n");
		exit(1);
        }
	max_len =atoi(argv[1]);
*/
/*
#if defined(__LINUX__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("/u/fperez/XMP/MiMPI/test/mp/mpi/performance/ping/ping.in","rt") ;
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
*/
        max_len = 1 * 1024 * 1024;


        if ( (max_len <= 0) || (max_len >= 32*1024*1024) )
        {
                printf("ERROR: max_len = %i\n",max_len);
                printf("ERROR: (max_len <= 0) || (max_len >= 32*1024*1024)\n");
                exit(1) ;
        }


	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("Can't init\n");
		exit(1);
	}

	InitTimer();
	StartTime = GetStartTime(); /* Get StartTime */

  tf[0] = timer();
  for (ns = 1; ns <= SAMPLES; ++ns) {
     tf[ns] = timer();
  }
  t_call = (tf[SAMPLES] - tf[0]) / SAMPLES;


n_init = 2 * PINGPONGS;
  n_mess = 2 * PINGPONGS;

  ifp = fopen("mpi_single.dat","w");
  table_top(2, n_init, n_mess, SAMPLES, t_call, Title);


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



		for (log2nbyte = 0; log2nbyte <= LOG2N_MAX; ++log2nbyte) {

	 nbyte = (1<< log2nbyte);
     inBuffer = malloc(nbyte);
     memset(inBuffer, '1', nbyte);


	if (me == 0) {
     tf[0] = timer();

	 for (ns = 0; ns < SAMPLES; ns++) {
        for (n_pp = 0; n_pp < PINGPONGS; n_pp++) {


		MPI_Recv(inBuffer,nbyte,MPI_CHAR,1,1,
						MPI_COMM_WORLD, &status);
                            
                		
		MPI_Send(inBuffer,nbyte,MPI_CHAR,1,1,
					MPI_COMM_WORLD);

	        }

        tf[ns+1] = timer();
	 }

     table_body(2, nbyte, n_init, n_mess, SAMPLES, t_call, tf, ifp);

	}
	else {
		for (ns = 0; ns < SAMPLES; ns++) {
         for (n_pp = 0; n_pp < PINGPONGS; n_pp++) {

			MPI_Send(inBuffer,nbyte,MPI_CHAR,0,1,
					MPI_COMM_WORLD);

	 	MPI_Recv(inBuffer,nbyte,MPI_CHAR,0,1,
						MPI_COMM_WORLD, &status);
                            	
		}
      
	 }

	}
  }

	MPI_Finalize();
        free(buf);
	exit(0);

}

		
	
	
	
	
