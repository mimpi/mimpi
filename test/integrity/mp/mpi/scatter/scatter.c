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

#define PRUEBAS                 10


int main(int argc, char *argv[])
{
        int             ret;
        char           *send_buf;
        char           *recv_buf;
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
                printf("Use: scatter <max_len> \n") ;
                exit(1) ;
        }
        max_len =atoi(argv[1]) ;
#endif

#if defined(__LINUX__)
        fparam = fopen("scatter.in","rt") ;
#endif
#if defined(__SUNOS__)
        fparam = fopen("scatter.in","rt") ;
#endif
#if defined(__SP2__)
        fparam = fopen("scatter.in","rt") ;
#endif

        if (fparam == NULL)
        {
                printf("ERROR: can not open scatter.in, sorry.\n") ;
                exit(1) ;
        }
        ret = fscanf(fparam,"max_len=%i",&max_len) ;
        fclose(fparam) ;
        if (ret != 1)
        {
                printf("ERROR: can not read a valid 'max_len' value from scatter.in, sorry.\n") ;
                exit(1) ;
        }
        if ( (max_len <= 0) || (max_len >= 1*1024*1024) )
        {
                printf("ERROR: (max_len <= 0) || (max_len >= 1*1024*1024)\n") ;
                exit(1) ;
        }


        ret = MPI_Init(&argc, &argv);   
        if (ret < 0)
        {
                printf("scatter: Can't MPI_Init\n") ;
                exit(1) ;
        }

        MPI_Comm_rank(MPI_COMM_WORLD,&me) ;
        MPI_Get_processor_name(processor_name,&namelen) ;
        MPI_Comm_size(MPI_COMM_WORLD, &nproc) ;
        printf("scatter: Process id      = %d\n",me);
        printf("scatter: total nodes     = %d\n",nproc);
        printf("scatter: current machine = %s\n",processor_name);

        /*
         *  buffers
         */
        send_buf = (char *) malloc((unsigned) max_len) ;
        if (send_buf == NULL)
        {
                perror("scatter: Error en malloc") ;
                exit(1) ;
        }
        memset(send_buf,'x',max_len) ;

        recv_buf = (char *) malloc((unsigned) max_len * nproc) ;
        if (recv_buf == NULL)
        {
                perror("Error en malloc") ;
                exit(1) ;
        }
        memset(recv_buf,'x',max_len * nproc) ;

        /*
         *  test
         */
        lenbuf = 1;
        while (lenbuf <= max_len)
        {
                if (me != 0)
                {
                        for(j = 0; j < PRUEBAS; j++)
                        {
                                memset(recv_buf,(char)'x',max_len) ;
                                MPI_Barrier(MPI_COMM_WORLD) ;
                                MPI_Scatter(send_buf,lenbuf,MPI_CHAR,
                                            recv_buf,lenbuf,MPI_CHAR,
                                            0,MPI_COMM_WORLD) ;
                                printf("scatter[%d].buff = %8.50s\n",
                                       me,recv_buf);
                        }
                }
                else
                {
                        for(j = 0; j < PRUEBAS; j++)
                        {
                                memset(recv_buf,(char)('0'+j),max_len) ;
                                MPI_Barrier(MPI_COMM_WORLD) ;
                                MPI_Scatter(send_buf,lenbuf,MPI_CHAR,
                                            recv_buf,lenbuf,MPI_CHAR,
                                            0,MPI_COMM_WORLD) ;
                                printf("scatter[%d].buff = %8.50s\n",
                                       me,recv_buf);
                        }
                }

                lenbuf *= 2;
        }

        MPI_Finalize() ;
        free(send_buf) ;
        free(recv_buf) ;
        exit(0) ;

}



