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



#include "l_mpi_test.h"

#define PRUEBAS 		20


int main(int argc, char *argv[])
{
	int             ret;
	char           *send_buf;
	char           *recv_buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
	double          start_time;
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
          "\t gather\n"
          "\t--------\n"
          "\n"
        ) ;

        /*
         *  try get values ...
         */
        ret = L_MPI_TEST_getLimits("gather.in",&max_len,&min_len) ;
	if (ret < 1)
           {
             exit(1) ;
           }

        /*
         *  init mpi ...
         */
	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	   {
		printf("ERROR: Can not MPI_init\n") ;
		exit(1) ;
	   }

	MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
	MPI_Get_processor_name(processor_name,&namelen) ;
	MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;

        /*
         *  try get buffers ...
         */
        ret = L_MPI_TEST_getBufs( max_len,
                                  max_len * nproc,
                                 &send_buf,
                                 &recv_buf) ;
	if (ret < 1)
           {
             exit(1) ;
           }

        /*
         *  barrier_time
         */
        MPI_Barrier(MPI_COMM_WORLD) ;
        barrier_time = L_MPI_TEST_getBarrierTime(PRUEBAS) ;
        if (me == 0)
            printf("BARRERA1=%e\n",  barrier_time);

        /*
         *  test gather
         */
        for (lenbuf = min_len; (lenbuf <= max_len); lenbuf *= 2)
        {
	  MPI_Barrier(MPI_COMM_WORLD) ;

	  if (me != 0)
	     {
		for(j = 0; j < PRUEBAS; j++)
               	{
			MPI_Gather(send_buf,lenbuf*nproc,MPI_CHAR,
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
			MPI_Gather(send_buf,lenbuf*nproc,MPI_CHAR,
			           recv_buf,lenbuf,MPI_CHAR,
                                   0,MPI_COMM_WORLD) ;
                        MPI_Barrier(MPI_COMM_WORLD) ;
		   }
		used_time = (MPI_Wtime() - start_time) ;
               	avg_time =  (used_time - barrier_time)  / (float)  PRUEBAS;
		if (avg_time > 0)    /* rate is megabytes per second */
                       	us_rate = (double)((nproc * lenbuf)/
				(avg_time*(double)1000000)) ;
               	else
                       	us_rate = 0.0;

               	printf("len_bytes=%e avg_time_sec=%e rate_Mbytes_sec=%e\n", 
		        (double)lenbuf, (double)avg_time, (double)us_rate) ;
	     }

        }

        /*
         *  finished
         */
	MPI_Finalize() ;
        free(send_buf) ;
        free(recv_buf) ;

        /*
         *  return ok
         */
	return (0) ;
}



