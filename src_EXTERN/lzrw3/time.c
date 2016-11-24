#include <stdio.h>
#include <sys/time.h>

#define USECPSEC 1000000

double TimevaltoFloat(struct timeval timet)
{
   return( (double)(timet.tv_sec + (double)timet.tv_usec/ (double)USECPSEC));
}


double mclock(void)
{

     struct timeval  t;	
     double diff;

     gettimeofday(&t, 0);


     diff = TimevaltoFloat(t);

     return (diff);

}



