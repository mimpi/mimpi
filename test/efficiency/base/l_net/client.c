/* ........................................................................
 *
 * Copyright Felix Garcia (1996-1999)
 * <fgarcia@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */




#include "net.h"
#include "base/l_basic/c_basic.h"
#include "base/l_socket/x_socket.h"


#define PRUEBAS 	1


double Get_time(void)
{
        struct timeval tp;
        struct timezone tzp;

        gettimeofday(&tp,&tzp);
        return((double) tp.tv_sec + .000001 * (double) tp.tv_usec);
}



int main(int argc, char *argv[])
{
	int ret = 0;
	struct sockaddr_in sa;
	int sd;
	char *buf;
	double start_time;
        double used_time;
        double avg_time;
	double us_rate;
	int max_len, lenbuf;
	int j,ok;


        /*
         *  info
         */
	if (argc != 2)
        {
                printf("Use: client <max_len> \n");
                exit(1);
        }
        printf("CLIENT is up \n");

        /*
         *  malloc
         */
	max_len =atoi(argv[1]);
        if ( (max_len <= 0) || (max_len >= 4*1024*1024) )
        max_len = 512*1024;
        buf = (char *) malloc((unsigned) max_len);
        if (buf == NULL)
        {
		perror("Error en malloc");
                exit(1);
        }

        /*
         *  connect
         */
        ok = X_SOCKET_ln2address((struct sockaddr_in  *)&sa,
                                 SERVER_HOST,SERVER_PORT) ;
	if (ok == FALSE)
	   {
		perror("Error en X_SOCKET_ln2address");
		exit(1);
	   }
        ok = X_SOCKET_connect(&sd,
                             (struct sockaddr_in  *)&sa) ;
	if (ok == FALSE)
	   {
		perror("Error en X_SOCKET_connect");
		exit(1);
	   }

        /*
         *  test
         */
	lenbuf = 1;
	while (lenbuf <= max_len)
        {
		avg_time = 0.0;
                for(j = 0; j < PRUEBAS; j++)
                {
			start_time = Get_time();

                        ret = X_SOCKET_write(sd,buf,lenbuf) ;
			if (ret != lenbuf)
				perror("Error en write");

                        ret = X_SOCKET_read(sd,buf,lenbuf) ;
			if (ret != lenbuf)
				perror("Error en read");

			used_time = (Get_time() - start_time);
			avg_time = avg_time + used_time;
		}

		avg_time =  avg_time / (float)  PRUEBAS;

		if (avg_time > 0)    /* rate is megabytes per second */
                        us_rate = (double)
                                  ((2.0 * lenbuf)/(avg_time*(double)1000000));
                else
                        us_rate = 0.0;

                printf("len=%d bytes, used= %f sec., rate=%f Mbytes/sec\n",
                   lenbuf, used_time, us_rate);

		lenbuf *= 2;

	}

        /*
         *  free resources
         */
	free(buf);
        close (sd);

        /*
         *  end
         */
	return (0);
}



