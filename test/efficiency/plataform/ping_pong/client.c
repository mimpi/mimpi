/* ........................................................................
 *
 * Copyright Felix Garcia (1996-2000)
 * <fgarcia@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


#include "config.h"


int chn_read(int fd, char *buf, int size)
{
	int ret;
	int size_aux = size;

	do {
		if (size > MAX_SIZE)
                        ret = read (fd, buf, MAX_SIZE);
                else
			ret = read (fd, buf, size);
                size  -=  ret;
                buf += ret;
        } while ((size > 0) && (ret >= 0));
	return(size_aux);
}

int chn_write(int fd, char *buf, int size)
{
        int ret;
        int size_aux = size;

        do {
		if (size > MAX_SIZE)
                        ret = write (fd, buf, MAX_SIZE);
                else
			ret = write (fd, buf, size);
                size  -=  ret;
                buf += ret;
        } while ((size > 0) && (ret >= 0));
        return(size_aux);
}



double Get_time(void)
{
        struct timeval tp;
        struct timezone tzp;

        gettimeofday(&tp,&tzp);
        return((double) tp.tv_sec + .000001 * (double) tp.tv_usec);
}

double Get_tick(void)
{
        static double tickval = -1.0;
        double t1, t2;
        int    cnt;
        int    icnt;

        if (tickval < 0.0) {
                tickval = 1.0e6;
                for (icnt=0; icnt<10; icnt++) {
                        cnt = 1000;
                        t1  = Get_time();
                        while (cnt-- && (t2 = Get_time()) <= t1) ;
                        if (cnt && t2 - t1 < tickval)
                        tickval = t2 - t1;
                }
        }
        return tickval;
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
	struct hostent *hp;
	int i, j;
	int val;
	int ns_port;
    char *ns_host;

#if defined(__SP2__)
	char *buf, *pch;
        char ns_host_css[1024];
#endif




printf("CLIENT is up\n");

	if ((getenv ("NS_PORT") == NULL))
        {
                fprintf (stderr, "NS_PORT must be in enviroment\n");
                exit (1);
        }
        ns_port = atoi(getenv ("NS_PORT"));

#if defined(__LINUX__)
        if ((getenv ("NS_HOST") == NULL))
        {
                fprintf (stderr, "NS_HOST must be in enviroment\n");
                exit (1);
        }
        ns_host = getenv ("NS_HOST");
#endif
#if defined(__SP2__)
	if ((getenv ("LOADL_PROCESSOR_LIST") == NULL))
           {
             fprintf (stderr, "LOADL_PROCESSOR_LIST must be in enviroment\n") ;
             return FALSE ;
           }
        pch = getenv ("LOADL_PROCESSOR_LIST");
	ns_host = pch ; 
	/* " x " */
	/*  ^    */
	pch ++ ; 
	/* " x " */
	/*   ^  */
	for(;pch[0]!=' ';pch++) ;
	/* " x " */
	/*    ^  */
	pch[0] = '\0' ;
	/* " x" */
	/*    ^  */
	ns_host += 2 ; 
	/* "inX" */
	/*  ^    */
	sprintf(ns_host_css,"css%s",ns_host) ;
	ns_host = ns_host_css ;
	/* "cssX" */
	/*  ^     */
	printf("ns_host=%s\n",ns_host_css) ;
#endif


	if (argc != 2)
        {
                printf("Use: client <max_len> \n");
		max_len = 1048576 ;
        }

/*
	max_len =atoi(argv[1]);
        if ( (max_len <= 0) || (max_len >= 4*1024*1024) )
        	max_len = 32 * 1024 * 1024;
*/

        max_len = 32 * 1024 * 1024;
        buf = (char *) malloc((unsigned) max_len);
        if (buf == NULL)
        {
		perror("Error en malloc");
                exit(1);
        }


	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sd < 0)
	{
		perror("Error en socket");
		exit(1);
	}
	val = 1;
	ret = setsockopt(sd, IPPROTO_TCP,  TCP_NODELAY, 
		(char *) &val, sizeof(int));
	if (ret < 0)
        {
                perror("setsockopt 1");
                exit(0);
        }

/*
	val = 32 * 1024;
        ret = setsockopt(sd, SOL_SOCKET,  SO_RCVBUF,
                (char *) &val, sizeof(int));
        if (ret < 0)
        {
                perror("setsockopt 2");
                exit(0);
        }

	val = 32 * 1024;
        ret = setsockopt(sd, SOL_SOCKET,  SO_SNDBUF,
                (char *) &val, sizeof(int));
        if (ret < 0)
        {
                perror("setsockopt 3");
                exit(0);
        }

*/


	bzero((char *)&sa, sizeof(sa));
	sa.sin_family = AF_INET;

	hp = gethostbyname (ns_host);
        if (hp == NULL)
        {
                perror("Error en gethostbyname");
                printf("ns_host = %s\n",ns_host);
                exit(1);
        }
        memcpy (&(sa.sin_addr), hp->h_addr, hp->h_length);

	sa.sin_port = htons(ns_port);
	

	ret = connect(sd, (struct sockaddr *) &sa, sizeof(sa));
	for (i=0; (i<20)  && (ret!=0); i++)
	{
		sleep(0) ;
		ret = connect(sd, (struct sockaddr *) &sa, sizeof(sa));
	}
	if (ret)
	{
		perror("Error en connect");
		exit(1);
	}
printf("now connected!\n") ;

	lenbuf = MIN_LENBUF ;

	while (lenbuf <= max_len)
        {
		avg_time = 0.0;
                for(j = 0; j < PRUEBAS; j++)
                {
			start_time = Get_time();

        		ret = chn_write(sd, buf, lenbuf);
			if (ret != lenbuf)
				perror("Error en write");

			ret = chn_read(sd, buf, lenbuf);
			if (ret != lenbuf)
				perror("Error en read");

			used_time = (Get_time() - start_time);
			avg_time = avg_time + used_time;
		}

		avg_time =  avg_time / (float)  PRUEBAS;

		if (avg_time > 0)    /* rate is megabytes per second */
                        us_rate = (double)((2.0 * lenbuf)/(avg_time*(double)1000000));
                else
                        us_rate = 0.0;

/*->back
                printf("len_bytes=%d avg_time_sec=%f rate_Mbytes_sec=%f\n",
                        lenbuf, used_time, us_rate);
*/
                printf("len_bytes=%d avg_time_sec=%e\n",
                        lenbuf, used_time );

		lenbuf *= 2;
	}

	printf("clock resolution in seconds: %10.8f\n", Get_tick());


	free(buf);

        close (sd);

	return (0);
}

		
	
	
	
	
