
#include <stdio.h>
#include <windows.h>

#include "mpi.h"

double timer();

int ranks;
CRITICAL_SECTION thread_cs;

#define NUM_ITERS 1000
#define BUFFER_SIZE 524288

#define NUM_ITERS_TAG   1
#define BUFFER_SIZE_TAG 2
#define PING_TAG        3
#define PONG_TAG        4

void MakePingPong
  (
    int,
    int
  );

void ThreadCode
  (
  );


void main
  (
    int argc,
    char **argv
  )
{

  HANDLE *array_of_threads;
  int my_rank, comp_size;
  int i;
  int num_iters;
  int buffer_size;

  if(argc<3) {
    num_iters = NUM_ITERS;
    buffer_size = BUFFER_SIZE;
  } else {
    num_iters = atoi(argv[1]);
    buffer_size = atoi(argv[2]);
  }

  if(num_iters < 1 ) {
    printf("Number of iteractions must be higher than 0.\n");
  }

  if(buffer_size<0) {
    printf("The buffer cannot be negative.\n");
  }

  MPI_Init(&argc,&argv);

  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

  MPI_Comm_size(MPI_COMM_WORLD,&comp_size);

  if(my_rank == 0) {

    ranks = 0;

    InitializeCriticalSection(&thread_cs);

    array_of_threads = (HANDLE *) malloc(comp_size * sizeof(HANDLE));

    for(i=0; i<comp_size; i++) {
      array_of_threads[i] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadCode,NULL,(DWORD)0,NULL);
    }
  }

  MPI_Send(&num_iters,1,MPI_INT,0,NUM_ITERS_TAG,MPI_COMM_WORLD);

  MPI_Send(&buffer_size,1,MPI_INT,0,BUFFER_SIZE_TAG,MPI_COMM_WORLD);

  MakePingPong(num_iters, buffer_size);

  if(my_rank == 0) {
    if(WaitForMultipleObjects(comp_size,array_of_threads,TRUE,INFINITE) == WAIT_TIMEOUT) {
      for(i=0; i<comp_size; i++) {
        TerminateThread(array_of_threads[i],0);
      }
    }
  }

  MPI_Finalize();
  
  if(my_rank==0) {
    DeleteCriticalSection(&thread_cs);
  }

}


void MakePingPong
  (
    int num_iters,
    int buffer_size
  )
{
  int i;
  char *buffer;
  MPI_Status status;

  buffer = (char *) malloc(buffer_size * sizeof(char));

  printf("PingPonging...");

  for(i=0; i<num_iters; i++) {

    MPI_Send(buffer, buffer_size, MPI_CHAR, 0, PING_TAG, MPI_COMM_WORLD);

    MPI_Recv(buffer, buffer_size, MPI_CHAR, 0, PONG_TAG,MPI_COMM_WORLD,&status);

    printf(".");

  }

  printf("ended!");

  free(buffer);
}

void ThreadCode
  (
  )
{

  int work_rank;
  int i;
  char *buffer;
  MPI_Status status;
  double start_time, end_time;
  int iters, size;

  EnterCriticalSection(&thread_cs);
  work_rank = ranks;
  ranks++;
  LeaveCriticalSection(&thread_cs);

  InitTimer();
  GetStartTime();

  MPI_Recv(&iters,1,MPI_INT,work_rank,NUM_ITERS_TAG,MPI_COMM_WORLD,&status);

  MPI_Recv(&size,1,MPI_INT,work_rank,BUFFER_SIZE_TAG,MPI_COMM_WORLD,&status);

  buffer = (char *) malloc(size * sizeof(char));

  printf("Process %d: %d times pinpong with a buffer of size %d!\n",work_rank,iters,size);

  start_time = timer();

  for(i=0; i< iters; i++) {
    MPI_Recv(buffer,size,MPI_CHAR,work_rank,PING_TAG,MPI_COMM_WORLD,&status);
    
    MPI_Send(buffer,size,MPI_CHAR,work_rank,PONG_TAG,MPI_COMM_WORLD);
  }

  end_time = timer();

  printf("Process %d: Average time per iteration %lf sec!", work_rank, (end_time-start_time)/iters);

  free(buffer);
}