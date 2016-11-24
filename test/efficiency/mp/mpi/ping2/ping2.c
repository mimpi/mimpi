
/* check delay variation */
#include "mpi.h"
#include <stdio.h>

#define REPS 1000
#define PREC 1000000.
#define R2 20
double vec[REPS];
FILE *fp;

#define _ALING   8192

int main(argc,argv)
int argc;
char *argv[];
{
	double s,t,q,min,max,avrg,var,ovrhd,secs();
	char *vtmp ;
	int lth,i,me,np,tmp;
	int src,dst;
        MPI_Status status ;

    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &me );
    MPI_Comm_size( MPI_COMM_WORLD, &np );


	lth=8;
#if (0)
#if defined(__LINUX__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("/home/ssoo/gpmimd/mpich/fmpi_test/ping2/ping.in","rt") ;
#endif
        if (fparam == NULL)
        {
                printf("ERROR: can not open ping.in, sorry.\n");
                exit(1);
        }
        ret = fscanf(fparam,"max_len=%i",&lth) ;
        fclose(fparam) ;
        if (ret != 1)
        {
                printf("ERROR: can not read a valid 'max_len' value from ping.in, sorry.\n");
                exit(1);
        }
#endif
#if (1)
        if (argc > 1) 
            lth = atoi(argv[1]);
#endif

	vtmp = malloc(lth + _ALING +1);  /* page align for hot intel perf. */
	vtmp = (char *)((((unsigned long)vtmp) + _ALING-1) & ~(_ALING-1));
	for(i=0;i<lth;i++) vtmp[i]=0;  /* pre-touch and avoid VM delays */
	if (me ==0){
	   src=dst=1;
	   ovrhd = 777777;   /* determine clock overhead */
	   for(i=0;i<10;i++){
		t=secs();
		s=secs();
		t= s-t;
		if (t < ovrhd) ovrhd = t;
   	    }
	   for(i=0;i<REPS;i++)vec[i]=0;  /* avoid pg faults */
	   avrg = max = 0;
	   min = 777777;
		MPI_Send(&i,sizeof(i),MPI_BYTE,dst,0,MPI_COMM_WORLD);
		MPI_Recv(&tmp,sizeof(i),MPI_BYTE,src,0,MPI_COMM_WORLD,&status);
	   s = secs();
	   for(i=0;i<3;i++){ /* warmup */
		MPI_Send(vtmp,lth,MPI_BYTE,dst,0,MPI_COMM_WORLD);
		MPI_Recv(vtmp,lth,MPI_BYTE,src,0,MPI_COMM_WORLD,&status);
	   }
	   for(i=0;i<REPS;i++){
		t = secs();
		MPI_Send(vtmp,lth,MPI_BYTE,dst,0,MPI_COMM_WORLD);
		MPI_Recv(vtmp,lth,MPI_BYTE,src,0,MPI_COMM_WORLD,&status);
		q=secs();
		t = q-t-ovrhd;
		if (t < min) min=t;
		if (t > max) max=t;
		avrg += t;
		vec[i] = t;
	   }
	   t=secs();
           var=0.;
           avrg = avrg/REPS;
           for(i=0;i<REPS;i++) var += (vec[i]-avrg)*(vec[i]-avrg);
	   printf("at %f overhead %f us\n",t,ovrhd*1.e6);
	   printf("reps %d min %f max %f disp %f avrg %f var %g over %f secs\n",
	     REPS,min,max,max-min,avrg,var,t-s);
	    printf (" lth %d  %f MBs %f us 1-way avrg: %f %f\n",
	    lth, 2.e-6*lth/min,.5e6*min,2.e-6*lth/avrg,.5e6*avrg);

	   fp = fopen("v.tmp","w");
	   for (i=0;i<REPS;i++)fprintf(fp,"%d %d\n",i,(int)(10000000 * vec[i]));
	   fclose(fp);
	   printf("done on %d procs with %d byte messages\n",np,lth);
	}

	if (me== 1){
		src=dst=0;
		MPI_Recv(&tmp,sizeof(tmp),MPI_BYTE,src,0,MPI_COMM_WORLD,&status);
		MPI_Send(&i,sizeof(i),MPI_BYTE,dst,0,MPI_COMM_WORLD);
	   for(i=0;i<3;i++){  /* warmup */
		MPI_Recv(vtmp,lth,MPI_BYTE,src,0,MPI_COMM_WORLD,&status);
		MPI_Send(vtmp,lth,MPI_BYTE,dst,0,MPI_COMM_WORLD);
	   }
	   for(i=0;i<REPS;i++){
		MPI_Recv(vtmp,lth,MPI_BYTE,src,0,MPI_COMM_WORLD,&status);
		MPI_Send(vtmp,lth,MPI_BYTE,dst,0,MPI_COMM_WORLD);
	   }
	}
	
    MPI_Finalize() ;
    return 1 ;
}


double
secs()
{
#include <sys/time.h>
        struct timeval ru;
        gettimeofday(&ru, (struct timezone *)0);
        return(ru.tv_sec + ((double)ru.tv_usec)/1000000);
}

