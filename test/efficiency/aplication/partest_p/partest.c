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
#include <unistd.h>
#include "mpi.h"

#define DO_READ		0
#define DO_WRITE	1
#define KB	1024
#define MB	(1024*1024)



struct param_rw
{
	int fs_call;                      /* operation code */
	int a_size;                   /* num blocks */
	int who;
	int pthread_id;
	int err;                          /* error code */
};


struct param_server
{
	int num_servers;
	int server;
	pthread_mutex_t lock_servers;   
     	pthread_cond_t cond_servers;   
     	pthread_mutex_t lock_busy;    
     	pthread_cond_t cond_busy;    
	int a_size;			  /* access size */
	int num_ops;			  /* operation number */
	int busy;
	int op_rw;
	int err; 
};
	

int me;
pthread_mutex_t lock;
pthread_cond_t cond;
pthread_mutexattr_t lock_attr;
int busy = TRUE;
int who;
int cont = 0;

static void do_transfer (struct param_server *param);


int read_from_servers(int servers,int ops,int size)
{
	int i;
	int server;
	char *data;
	struct param_rw rw;
        MPI_Status status;


	data = (char *) malloc(size);

	rw.fs_call = DO_READ;
	rw.a_size = size;

        for (i= 0; i< ops; i++)
        {
		server = i % servers;
                rw.pthread_id = server;
                rw.who = me;

                MPI_Send((char *)& rw, sizeof(rw), MPI_CHAR,
                        server, 0, MPI_COMM_WORLD);

                MPI_Recv(data, size, MPI_CHAR, server, (int) rw.pthread_id,
                        MPI_COMM_WORLD, &status);

                MPI_Recv((char *)& rw, sizeof(rw), MPI_CHAR,
                        server, (int) rw.pthread_id, MPI_COMM_WORLD, &status);
	}

        return 1 ;
}


	




static int read_data(int servers, int clients, int fs, int size)
{
	int j;
	int ops;
	pthread_attr_t attr;
	pthread_t th;
	struct param_server param;

	ops = (fs / size);
	ops =  ops / clients;


        pthread_attr_init(&attr);
        pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_mutex_init(&(param.lock_servers), NULL);
     	pthread_cond_init(&(param.cond_servers), NULL);
	
     	pthread_mutex_init(&(param.lock_busy), NULL);
     	pthread_cond_init(&(param.cond_busy), NULL);

	param.op_rw = DO_READ;
	param.num_servers = servers;
	param.a_size = size;
	param.num_ops = ops / servers;


	for (j=0; j < servers; j++)
	{
		param.busy = TRUE;
		param.server = j;
	
                pthread_create(&th,&attr,(void * (*)(void *))do_transfer,
				&param);

		pthread_mutex_lock(&param.lock_busy);
       		while (param.busy)
          		pthread_cond_wait(&param.cond_busy, &param.lock_busy);
       		pthread_mutex_unlock(&param.lock_busy);
    	}

	pthread_mutex_lock(&param.lock_servers);
    	while (param.num_servers > 0)
       		pthread_cond_wait(&param.cond_servers, &param.lock_servers);
    	pthread_mutex_unlock(&param.lock_servers);

        return 1 ;
}


static void do_transfer (struct param_server *param)
{
	int ops;
	int server;
	char *data;
	int i = 0;
	struct param_rw rw;	
	MPI_Status status;

	ops = param->num_ops;
	server = param->server;

	
	pthread_mutex_lock(&param->lock_busy);
	param->busy = FALSE;
	pthread_cond_signal(&param->cond_busy);
     	pthread_mutex_unlock(&param->lock_busy);


	data = (char *) malloc(param->a_size);

	for (i= 0; i< ops; i++)
	{
		rw.fs_call = DO_READ;
		rw.a_size = param->a_size;

		rw.pthread_id = (int)pthread_self();
		rw.who = me;
	
		MPI_Send((char *)& rw, sizeof(rw), MPI_CHAR,
			server, 0, MPI_COMM_WORLD);

		MPI_Recv(data, param->a_size, MPI_CHAR, server, (int) rw.pthread_id,
			MPI_COMM_WORLD, &status);

		MPI_Recv((char *)& rw, sizeof(rw), MPI_CHAR,
                        server, (int) rw.pthread_id, MPI_COMM_WORLD, &status);

	}

	pthread_mutex_lock(&param->lock_servers);
	param->num_servers--;
     	pthread_cond_signal(&param->cond_servers);
     	pthread_mutex_unlock(&param->lock_servers);

	free(data);
	
	pthread_exit(0);
}


void do_mess(char *mess)
{
	int my_tag;
	int my_who;
	int ret;
	MPI_Status status;
	struct param_rw param;
	char *data;

	pthread_mutex_lock(&lock);
	memcpy((char *) &param, mess, sizeof(struct param_rw));
	my_who = who;
	my_tag = param.pthread_id;


	cont ++;
	busy = FALSE;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&lock);

	data = (char *) malloc(param.a_size);

	if (param.fs_call == DO_READ)
	{
		ret=MPI_Send(data,param.a_size,MPI_CHAR,my_who,my_tag,
                                        MPI_COMM_WORLD);
        	if (ret != MPI_SUCCESS)
        		perror("Error en MPI_Send 1.\n");
	}
	else
	{
		ret=MPI_Recv(data,param.a_size,MPI_CHAR,my_who,my_tag,
                                        MPI_COMM_WORLD, &status);
                if (ret != MPI_SUCCESS)
                        perror("Error en MPI_Send 2.\n");
	}

/*
        if ( (cont % 256) == 0 )
	      printf("SERVER %d: MESS (%d) recibido de %d %d\n", me, cont, my_who, my_tag);
*/
	
	MPI_Send((char *)&param,sizeof(struct param_rw),MPI_CHAR,
				my_who,my_tag, MPI_COMM_WORLD);


	free(data);

	if (ret != MPI_SUCCESS)
		perror("Error en MPI_Send\n");

	pthread_exit(0);

}


int parserver ( int me, int nproc, char *processor_name )
{
	struct param_rw buf;
	pthread_t thid;
	pthread_attr_t attr;
	MPI_Status status;
        int ret ;


	printf("Server %d; total %d is alive on %s\n",me,nproc,processor_name);

	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_attr_init(&attr);
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);	
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	while (TRUE)
        {
	
		ret=MPI_Recv((char *)&buf,sizeof(struct param_rw), MPI_CHAR,
				MPI_ANY_SOURCE,0, MPI_COMM_WORLD,&status);

		if (ret != MPI_SUCCESS)
                   {
			perror("Error en MPI_Recv\n");
                   }

		who = status.MPI_SOURCE;

		pthread_create(&thid, &attr, (void * (*)(void *))do_mess, 
					(char *) &buf);

		pthread_mutex_lock(&lock);
                while (busy)
                	pthread_cond_wait(&cond, &lock);
                busy = TRUE;
                pthread_mutex_unlock(&lock);



        }

	printf("SERVER FIN \n");
}

int parclient ( int me, int nproc, char *processor_name, 
  	        int clients, int servers, int file_size, int a_size, int fs )
{

	double start_time;
        double used_time;
	double us_rate;
	int j ;
        MPI_Comm world, clients_world;
        MPI_Group world_group, client_group;
        int ranks[32];

        printf("Client %d; total %d is alive on %s\n",me,nproc,processor_name);
	start_time = MPI_Wtime();	
	read_data(servers, clients, file_size, a_size);
	used_time = (MPI_Wtime() - start_time);

	us_rate = (double)(( file_size )/ (used_time*(double)1000000));
	printf("FS=%d KB, time= %f sec., rate=%f Mbytes/sec\n",
                        fs*KB, used_time, us_rate);


	world = MPI_COMM_WORLD;

        MPI_Comm_group(world, &world_group);
        for (j = 0; j < servers; j++)
                ranks[j] = j;
        MPI_Group_excl(world_group, servers, ranks, &client_group);
        MPI_Comm_create(world, client_group, &clients_world);

        MPI_Barrier(clients_world);

        printf("Client %d finished\n", me);
        return 1 ;
}

int main(int argc, char *argv[])
{
	int ret;
  	int file_size;
	int fs;
	int a_size;
	int servers;
	int clients;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int namelen;
	int nproc;

	setbuf(stdout,NULL);

        if (getenv("SERVERS") == NULL)
           {
             printf("SERVERS not in enviroment, sorry\n") ;
             exit(1) ;
           }
        servers = atoi(getenv("SERVERS")) ;
        if (getenv("CLIENTS") == NULL)
           {
             printf("CLIENTS not in enviroment, sorry\n") ;
             exit(1) ;
           }
        clients = atoi(getenv("CLIENTS")) ;
        if (getenv("FILESIZE") == NULL)
           {
             printf("FILESIZE not in enviroment, sorry\n") ;
             exit(1) ;
           }
        fs = atoi(getenv("FILESIZE")) ;
	file_size = fs * MB;
        if (getenv("ACCESSSIZE") == NULL)
           {
             printf("ACCESSSIZE is not in enviroment, sorry\n") ;
             exit(1) ;
           }
        a_size = atoi(getenv("ACCESSSIZE")) ;

	ret = MPI_Init(&argc, &argv);
        if (ret < 0)
           {
             printf("Can't init\n");
             exit(0);
           }
	MPI_Comm_rank(MPI_COMM_WORLD,&me);
        MPI_Get_processor_name(processor_name,&namelen);
        MPI_Comm_size(MPI_COMM_WORLD, &nproc);
	if (servers + clients < nproc)
	{
          printf("servers + clients < nproc\n");
          exit(1) ;
	}

	printf(">>>>>>>>>>>>>>> >>>>>>>>%d; total %d is alive on %s\n",me,nproc,processor_name);
	if (me < servers)
	{
          printf("servers[%i] on...\n",me);
          parserver(me,nproc,processor_name) ;
	}
	else
	{
          printf("client[%i] on...\n",me);
          parclient(me,nproc,processor_name,clients,
		    servers,file_size,a_size,fs) ;
	}

	return (0) ;
}




