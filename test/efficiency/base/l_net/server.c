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


#define PRUEBAS 1


int main(int argc, char *argv[])
{
	int ret = 0;
	struct sockaddr sa[1];
	int sd;
	int sc;
	char *buf;
	int lenbuf;
	int max_len;
	int j, ok ;


        /*
         *  info
         */
	if (argc != 2)
        {
                printf("Use: server  <max_len> \n");
                exit(1);
        }
        printf("SERVER is up\n");

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
        ok = X_SOCKET_ln2address((struct sockaddr_in  *)sa,
                                 SERVER_HOST,SERVER_PORT) ;
        if (ok == FALSE)
	   {
		perror("Error en X_SOCKET_ln2address");
		exit(1);
	   }
        ok = X_SOCKET_beeper(&sd,
                             (struct sockaddr_in  *)sa) ;
        if (ok == FALSE)
	   {
		perror("Error en X_SOCKET_beeper");
		exit(1);
	   }
        ok = X_SOCKET_accept(&sc,
                             (struct sockaddr_in  *)sa,
                             sd) ;
        if (ok == FALSE)
	   {
		perror("Error en X_SOCKET_accept");
		exit(1);
	   }

        /*
         *  test
         */
	lenbuf = 1;
	while (lenbuf <= max_len)
	{

		for(j = 0; j < PRUEBAS; j++)
                {
                        ret = X_SOCKET_read(sc,buf,lenbuf) ;
			if (ret != lenbuf)
                        	perror("Error en read");

                        ret = X_SOCKET_write(sc,buf,lenbuf) ;
			if (ret != lenbuf)
                        	perror("Error en read");
		}

		lenbuf *= 2;
        }

        /*
         *  free resources
         */
	free(buf);
	close (sc);
	close (sd);

        /*
         *   end
         */
	return (0);
}	



