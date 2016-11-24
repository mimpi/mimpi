


/* 
 * example.c -- usage example of the zlib compression library
 * Copyright (C) 1995-1996 Jean-loup Gailly.
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */


/* example.c,v 1.4 1996/10/02 19:54:39 koziol Exp */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zlib.h>
#include <sys/time.h>



        void CHECK_ERR (int err, char *msg)
        {
          if (err != Z_OK) {
              fprintf(stderr, 
                      "%s error: %d\n", 
                      msg, err) ;
              fprintf(stderr, 
                      "ERROR(%i): %s\n", 
                      err, zError(err)) ;
              exit(1) ;
          }
        }

        double mclock (void)
        {
          #define USECPSEC 1000000

          struct timeval  t;
          double diff;

          gettimeofday(&t, 0);
          diff = (
                   ((double)t.tv_sec + (double)t.tv_usec)
                   /
                   ((double)USECPSEC)
                 ) ;
          return (diff);
        }


        /*
         *  dict
         */
		const char dictionary[] = "hello";
		uLong dictId; /* Adler32 value of the dictionary */

        /*
		 *  timers for performance
         */
		double start, end;



/* ======================================================================= */

int main(argc, argv)
    int argc;
    char *argv[];
{
    uLong comprLen = 10000*sizeof(int); /* don't overflow on MSDOS */
    uLong uncomprLen = comprLen;

    int err, i;
    double start, end;
    double compress_ratio;

    if (zlibVersion()[0] != ZLIB_VERSION[0]) {
        fprintf(stderr, "incompatible zlib version\n");
        exit(1);

    } else if (strcmp(zlibVersion(), ZLIB_VERSION) != 0) {
        fprintf(stderr, "warning: different zlib version\n");
    }


/* === Testing with big buffers (4 Mbytes ) === */
{
    Byte *compr, *uncompr, *decompress;

    uncomprLen = 1024*1024* 4; 
    comprLen = uncomprLen;

    compr    = (Byte*)calloc((uInt)comprLen, 1);
    uncompr  = (Byte*)calloc((uInt)uncomprLen, 1);
    decompress  = (Byte*)calloc((uInt)uncomprLen, 1);

    for (i=0; i < uncomprLen; i++)
		uncompr[i] = i%256;

    printf("Testing on VERY Large Block of 4 MBytes of chars \n");
    printf("----------------------\n");

    start = mclock();
    err = compress(compr, &comprLen, uncompr, uncomprLen);
    end = mclock();
    compress_ratio = ((float) uncomprLen / (float) comprLen);
    printf("compress_ratio is %7.4f:1 time is %8.4f sec\n",
        compress_ratio, end-start);

    CHECK_ERR(err, "compress");


    start = mclock();
    err = uncompress(decompress, &uncomprLen, compr, comprLen);
    end = mclock();
    printf("uncompress  time is %8.4f sec\n",  end-start);

    CHECK_ERR(err, "uncompress");

    if (uncomprLen != (4*1024*1024))
        printf ("Error in uncompressed buffer length \n");

    for (i=0; i < uncomprLen; i++)
        if (uncompr[i] != decompress[i])
		printf ("Error %d ", i);
    printf("\n");

    free(compr);
    free(uncompr);
    free(decompress);
}

/* === Testing with dense doubles === */
{
    double *compr, *uncompr, *decompress;

   uncomprLen = 1024*1024* 4; 
   comprLen = uncomprLen;

    compr    = (double*)calloc((uInt)comprLen, 1);
    uncompr  = (double*)calloc((uInt)uncomprLen, 1);
    decompress  = (double*)calloc((uInt)uncomprLen, 1);

    for (i=0; i < uncomprLen/sizeof(double); i++)
        uncompr[i] = i * 0.345;

    printf("Testing on VERY Large Block of 4 MBytes of dense doubles \n");
    printf("----------------------\n");

    start = mclock();
    err = compress((char *)compr, &comprLen, (char *)uncompr, uncomprLen);
    end = mclock();
    compress_ratio = ((float) uncomprLen / (float) comprLen);
    printf("compress_ratio is %7.4f:1 time is %8.4f sec\n",
        compress_ratio, end-start);

    CHECK_ERR(err, "compress");


    start = mclock();
    err = uncompress((char *)decompress, &uncomprLen, (char *)compr, comprLen);
    end = mclock();
    printf("uncompress  time is %8.4f sec\n",  end-start);

    CHECK_ERR(err, "uncompress");

    if (uncomprLen != (4*1024*1024))
        printf ("Error in uncompressed buffer length \n");

    for (i=0; i < uncomprLen /sizeof(double); i++)
        if (uncompr[i] != decompress[i])
		printf ("Error %d ", i);
    printf("\n");


    free(compr);
    free(uncompr);
    free(decompress);
}

/* === Testing with sparse doubles === */
{
    double *compr, *uncompr, *decompress;

   uncomprLen = 1024*1024* 4; 
   comprLen = uncomprLen;

    compr    = (double*)calloc((uInt)comprLen, 1);
    uncompr  = (double*)calloc((uInt)uncomprLen, 1);
    decompress  = (double*)calloc((uInt)uncomprLen, 1);

    for (i=0; i < uncomprLen/sizeof(double); i++)
     	if ((i%1000) ==0)
             uncompr[i] = i * 0.345;
  	else
             uncompr[i] = 0.0;

    printf("Testing on VERY Large Block of 4 MBytes of sparse doubles \n");
    printf("----------------------\n");

    start = mclock();
    err = compress((char *)compr, &comprLen, (char *)uncompr, uncomprLen);
    end = mclock();
    compress_ratio = ((float) uncomprLen / (float) comprLen);
    printf("compress_ratio is %7.4f:1 time is %8.4f sec\n",
        compress_ratio, end-start);

    CHECK_ERR(err, "compress");


    start = mclock();
    err = uncompress((char *)decompress, &uncomprLen, (char *)compr, comprLen);
    end = mclock();
    printf("uncompress  time is %8.4f sec\n",  end-start);

    CHECK_ERR(err, "uncompress");

    if (uncomprLen != (4*1024*1024))
        printf ("Error in uncompressed buffer length \n");

   for (i=0; i < uncomprLen /sizeof(double); i++)
        if (uncompr[i] != decompress[i])
                printf ("Error %d ", i);
    printf("\n");


    free(compr);
    free(uncompr);
    free(decompress);
}

/* === Testing with dense ints === */
{
    int *compr, *uncompr;

   uncomprLen = 1024*1024* 4; 
   comprLen = uncomprLen;

	
    

    compr    = (int*)calloc((uInt)comprLen, 1);
    uncompr  = (int*)calloc((uInt)uncomprLen, 1);

    for (i=0; i < uncomprLen/sizeof(int); i++)
        uncompr[i] = i;

    printf("Testing on VERY Large Block of 4 MBytes of dense int \n");
    printf("----------------------\n");

    start = mclock();
    err = compress((char *)compr, &comprLen, (char *)uncompr, uncomprLen);
    end = mclock();
    compress_ratio = ((float) uncomprLen / (float) comprLen);
    printf("compress_ratio is %7.4f:1 time is %8.4f sec\n",
        compress_ratio, end-start);

    CHECK_ERR(err, "compress");


    start = mclock();
    err = uncompress((char *)uncompr, &uncomprLen, (char *)compr, comprLen);
    end = mclock();
    printf("uncompress  time is %8.4f sec\n",  end-start);

    CHECK_ERR(err, "uncompress");

    if (uncomprLen != (4*1024*1024))
        printf ("Error in uncompressed buffer length \n");
    printf("\n");

    free(compr);
    free(uncompr);
}

/* === Testing with sparse ints === */
{
    int *compr, *uncompr, *decompress;

   uncomprLen = 1024*1024* 4; 
   comprLen = uncomprLen;

    compr = (int *) malloc(uncomprLen);
    uncompr = (int *) malloc(uncomprLen);
    decompress = (int *) malloc(uncomprLen);


    for (i=0; i < uncomprLen/sizeof(int); i++)
	if ((i%1000)==0)
        	uncompr[i] = i;
	else
        	uncompr[i] = 0 ;

    printf("Testing on VERY Large Block of 4 MBytes of sparse ints \n");
    printf("----------------------\n");

    start = mclock();
    err = compress((char *)compr, &comprLen, (char *)uncompr, uncomprLen);
    end = mclock();
    compress_ratio = ((float) uncomprLen / (float) comprLen);
    printf("compress_ratio is %7.4f:1 time is %8.4f sec\n",
        compress_ratio, end-start);

    CHECK_ERR(err, "compress");


    start = mclock();
    err = uncompress((char *)decompress, &uncomprLen, (char *)compr, comprLen);
    end = mclock();
    printf("uncompress  time is %8.4f sec\n",  end-start);

    CHECK_ERR(err, "uncompress");

    if (uncomprLen != (4*1024*1024))
		printf ("Error in uncompressed buffer length \n");

    for (i=0; i < uncomprLen/sizeof(int); i++)
        if (uncompr[i] != decompress[i])
			printf ("Error in uncompressed buffer data \n");
    printf("\n");

    free(compr);
    free(uncompr);
}



    return 0; /* to avoid warning */
}

