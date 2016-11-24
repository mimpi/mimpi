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

#define PRUEBAS 		10


int main(int argc, char *argv[])
{
	int             ret;
	char           *buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
        int             max_len, lenbuf;
        int             j;
	int             me, nproc;
        FILE           *fparam ;


	setbuf(stdout, NULL) ;
#if (0)
	if (argc != 2)
        {
                printf("Use: reduce <max_len> \n") ;
		exit(1) ;
        }
	max_len =atoi(argv[1]) ;
#endif
        fparam = fopen("reduce.in","rt") ;
        if (fparam == NULL)
        {
                printf("ERROR: can not open reduce.in, sorry.\n") ;
		exit(1) ;
        }
        ret = fscanf(fparam,"max_len=%i",&max_len) ;
        fclose(fparam) ;
        if (ret != 1)
        {
                printf("ERROR: can not read a valid 'max_len' value from reduce.in, sorry.\n") ;
		exit(1) ;
        }
        if ( (max_len <= 0) || (max_len >= 4*1024*1024) )
        {
                printf("ERROR: (max_len <= 0) || (max_len >= 4*1024*1024)\n") ;
                exit(1) ;
        }


	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("Can't init\n") ;
		exit(1) ;
	}

	MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
	MPI_Get_processor_name(processor_name,&namelen) ;
	MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;
        printf("reduce: Process id      = %d\n",me);
        printf("reduce: total nodes     = %d\n",nproc);
        printf("reduce: current machine = %s\n",processor_name);

        buf = (char *) malloc((unsigned) max_len) ;
        if (buf == NULL)
        {
                perror("reduce: Error en malloc") ;
                exit(1) ;
        }

        /* ... test ... */
	lenbuf = 1 ;
        while (lenbuf <= max_len)
        {
		if (me != 0)
		{
	                MPI_Barrier(MPI_COMM_WORLD) ;
			for(j = 0; j < PRUEBAS; j++)
                	{
	                        memset(buf,(char)('0'+me),max_len) ;
                                printf("reduce[%i].buff = %8.50s\n",
                                       me,buf);
				MPI_Reduce(buf,buf,lenbuf,
                                               MPI_CHAR,MPI_MAX,0,
				               MPI_COMM_WORLD) ;
	                        MPI_Barrier(MPI_COMM_WORLD) ;
			}
		}
		else
		{
	                MPI_Barrier(MPI_COMM_WORLD) ;
			for(j = 0; j < PRUEBAS; j++)
                        {
	                        memset(buf,(char)('0'),max_len) ;
                                printf("reduce[root_before].buff = %8.50s\n",
                                       buf);
				MPI_Reduce(buf,buf,lenbuf,
                                               MPI_CHAR,MPI_MAX,0,
				               MPI_COMM_WORLD) ;
	                        MPI_Barrier(MPI_COMM_WORLD) ;
                                printf("reduce[root_after].buff = %8.50s\n",
                                       buf);
			}
                }

                lenbuf *= 2;
        }

	MPI_Finalize() ;
        free(buf) ;
	exit(0) ;

}



