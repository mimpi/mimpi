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

#define PRUEBAS 		1


int main(int argc, char *argv[])
{
	int             ret;
	char           *buf;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
        int             max_len, lenbuf;
        int             i, j, k;
	int             me, nproc;
        FILE           *fparam ;


	setbuf(stdout, NULL) ;
#if (0)
	if (argc != 2)
        {
                printf("Use: bcast <max_len> \n") ;
		exit(1) ;
        }
	max_len =atoi(argv[1]) ;
#endif

#if defined(__LINUX__)
        fparam = fopen("bcast.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("bcast.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("bcast.in","rt") ;
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
        if ( (max_len <= 0) || (max_len > 4*1024*1024) )
        {
                printf("ERROR: (max_len <= 0) || (max_len > 4*1024*1024)\n") ;
                exit(1) ;
        }


	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("bcast: Can't MPI_Init\n") ;
		exit(1) ;
	}

	MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
	MPI_Get_processor_name(processor_name,&namelen) ;
	MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;
        printf("bcast: Process id      = %d\n",me);
        printf("bcast: total nodes     = %d\n",nproc);
        printf("bcast: current machine = %s\n",processor_name);

        buf = (char *) malloc((unsigned) max_len) ;
        if (buf == NULL)
        {
                perror("bcast: Error en malloc") ;
                exit(1) ;
        }

        /* ... test ... */
	lenbuf = 1 ;
        while (lenbuf <= max_len)
        {
		if (me != 0)
		{
			for(j = 0; j < PRUEBAS; j++)
                	{
	                        memset(buf,(char)'x',max_len) ;
                                MPI_Barrier(MPI_COMM_WORLD) ;
				MPI_Bcast(buf,lenbuf,MPI_CHAR,0,
				              MPI_COMM_WORLD) ;
                                printf("bcast[%d].size = %d\n", me,lenbuf);
				/*
                                for(k=0; k<lenbuf; k++)
                                {
                                  if (buf[k] != ('0'+j))
                                      printf("bcast[%d].buff[%d] = %c\n",
                                              me,k,buf[k]);
                                }
				*/
			}
		}
		else
		{
			for(j = 0; j < PRUEBAS; j++)
                        {
				memset(buf,(char)('0'+j),max_len) ;
                                MPI_Barrier(MPI_COMM_WORLD) ;
				MPI_Bcast(buf,lenbuf,MPI_CHAR,0,
                                                MPI_COMM_WORLD) ;
                                printf("bcast[%d].size = %d\n", me,lenbuf);
			}
                }

                lenbuf *= 2;
        }

	MPI_Finalize() ;
        free(buf) ;
	exit(0) ;

}



