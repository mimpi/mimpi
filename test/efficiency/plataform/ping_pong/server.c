/* ........................................................................
 *
 * Copyright Felix Garcia (1996-999)
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



struct sockaddr *dir2addr(struct sockaddr *sa, int port, char *machine)
{
        struct sockaddr_in *sin;

        sin = (struct sockaddr_in *) sa;

        sin->sin_family = AF_INET;
        sin->sin_port = htons(port);
        sin->sin_addr.s_addr = INADDR_ANY;

        return sa;
}


static int bind2port(int ch, int port)
{
	int val;
	int ret;
	struct sockaddr sa[1];

	val = 1;
	ret = setsockopt(ch, SOL_SOCKET, SO_REUSEADDR, (char *) &val, 
		sizeof(int));
	val = 1;
	ret =  setsockopt(ch, IPPROTO_TCP, TCP_NODELAY, (char *) &val, 
                sizeof(int));

	if (ret < 0)
		return(ret);

/*
	dir2addr(sa, port, NULL) ;
*/
	dir2addr(sa, port, "css44.sp.cesca.es");
	ret = bind(ch, sa, sizeof(struct sockaddr));
	if (ret < 0)
		return(ret);
	return(0);
}
	

int main(int argc, char *argv[])
{
	int ret = 0;
	struct sockaddr sa[1];
	size_t size;
	int sd;
	int val;
	int sc;
	char *buf;
	int lenbuf;
	int max_len;
	int j;

printf("SERVER is up\n");

/*
	if (argc != 2)
        {
                printf("Use: server  <max_len> \n");
                max_len = 1048576 ;
        }

	max_len =atoi(argv[1]);
        if ( (max_len <= 0) || (max_len >= 4*1024*1024) )
        	max_len = 4 * 1024 * 1024 ;
*/

        max_len = 32 * 1024 * 1024 ;
        buf = (char *) malloc((unsigned) max_len);
        if (buf == NULL)
        {
		perror("Error en malloc");
                exit(1);
        }


	sd =  socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sd < 0)
	{
		perror("Error en socket");
		exit(1);
	}

	ret = bind2port(sd, SERVER_PORT);
	if (ret < 0)
        {
                perror("Error en bind2port");
                exit(1);
        }

	if (listen(sd, SOMAXCONN) < 0) {
                close(sd);
		perror("Error en 1 listen");
		exit(1);
        }

	size = sizeof(struct sockaddr);
	sc = accept(sd, sa, &size);
printf("now conected!\n") ;
        if (sc < 0)
	{
		perror("Error en accept");
		exit(1);
	}

	val = 1;
        ret =  setsockopt(sc, IPPROTO_TCP, TCP_NODELAY, (char *) &val,
                sizeof(int));
	if (ret < 0)
        {
                perror("setsockopt 1");
                exit(0);
        }
	
/*
	val = (8 * 1024);
        ret =  setsockopt(sc, SOL_SOCKET, SO_RCVBUF, (char *) &val,
                sizeof(int));
	if (ret < 0)    
        {       
                perror("setsockopt 2"); 
                exit(0);        
        }       

	val = (8 * 1024);
        ret =  setsockopt(sc, SOL_SOCKET, SO_SNDBUF, (char *) &val,
                sizeof(int));
	if (ret < 0)    
        {       
                perror("setsockopt 3"); 
                exit(0);        
        }       

*/

	lenbuf = MIN_LENBUF ;
	while (lenbuf <= max_len)
	{

		for(j = 0; j < PRUEBAS; j++)
                {
			ret = chn_read(sc, buf, lenbuf);
			if (ret != lenbuf)
                        	perror("Error en read");

			ret = chn_write(sc, buf, lenbuf);
			if (ret != lenbuf)
                        	perror("Error en read");
		}

		lenbuf *= 2;
        }

	free(buf);

	close (sc);
	close (sd);

	return (0);
}	

	
	
