
#define SERVER        "css6"
#define SERVER_PORT	7500
#define CLIENT_PORT	7000

#define MAX_SIZE	4000000
#define MAXCHANNELS 64

#define PRUEBAS		1
#define MIN_LENBUF  1
#define MAX_LENBUF  32 * 1024 * 1024


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <netdb.h>
#include <poll.h>
#include <stropts.h>

