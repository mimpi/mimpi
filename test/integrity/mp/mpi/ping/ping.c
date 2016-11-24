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
	int             ret ;
	int             tosend, torecv ;
	char           *buf, *bug ;
	char            processor_name[MPI_MAX_PROCESSOR_NAME];
	int             namelen;
        int             max_len, lenbuf;
        int             j;
	int             me, nproc;
	MPI_Status      status;
        FILE           *fparam ;


	setbuf(stdout, NULL);
#if (0)
	if (argc != 2)
        {
                printf("Use: client <max_len> \n");
		exit(1);
        }
	max_len =atoi(argv[1]);
#endif
#if (1)
#if defined(__LINUX__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("ping.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("/u/fperez/XMP/xmp.b/test/mpi/ping/ping.in","rt") ;
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
        if ( (max_len <= 0) || (max_len >= 8*1024*1024) )
        {
                printf("ERROR: max_len = %i\n",max_len);
                printf("ERROR: (max_len <= 0) || (max_len >= 4*1024*1024)\n");
                exit(1) ;
        }

        fparam = fopen("data.in","r") ;
        if (fparam == NULL)
        {
                printf("ERROR: can not open data.in, sorry.\n");
                exit(1) ;
        }
        setbuf(fparam,NULL) ;

	ret = MPI_Init(&argc, &argv);	
	if (ret < 0)
	{
		printf("ping: Can't MPI_Init\n");
		exit(1);
	}

	MPI_Comm_rank(MPI_COMM_WORLD,&me);
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);
	MPI_Get_processor_name(processor_name,&namelen);

        bug = (char *) malloc((unsigned) max_len);
        buf = (char *) malloc((unsigned) max_len);
        if (buf == NULL)
        {
                perror("ping: Error en malloc");
                exit(1);
        }

	lenbuf = max_len ;
	if (me == 0)
	{
		while (! feof(fparam) )
		{
			torecv = fread(buf,1,lenbuf,fparam) ;
			ret = MPI_Recv(buf,torecv,MPI_CHAR,1,1,
				       MPI_COMM_WORLD, &status);
			if (ret != MPI_SUCCESS)
				perror("ping: Error en MPI_Recv");

			fwrite(buf,status.count,1,stdout);
		}
	}
	else
	{
		while (! feof(fparam) )
		{
			tosend = fread(buf,1,lenbuf,fparam) ;
			/*fprintf(stdout,"\n(%d) tosend: %d\n",me,tosend);*/

			ret = MPI_Send(buf,tosend,MPI_CHAR,0,1,
				       MPI_COMM_WORLD);
			if (ret != MPI_SUCCESS)
			    perror("ping: Error en MPI_Send\n");
		}
	}

	MPI_Finalize();
        fclose(fparam) ;
        free(buf);
	exit(0);
}



