/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



     #include "config.h"
     #include "time.c"


     int test_fpu_max
     (
       int     argc, 
       char   *argv[]
	 )
     {
     	char           *buf1;
     	char           *buf2;
     	double        t1 ;
     	double        t2 ;
        double        used_time;
        double        avg_time;
        double          us_rate;
        int             max_len, lenbuf;
        int             j,k;
     
     
        /* ... use ... */
     	if (argc != 2)
           {
             printf("Use: %s <max_len> \n",argv[0]) ;
     		 exit(1) ;
           }
     
        /* ... max_len ... */
     	max_len =atoi(argv[1]) ;
        if ( (max_len <= 0) || (max_len >= 4*1024*1024) )
           {
             printf("ERROR: (max_len <= 0) || (max_len >= 4*1024*1024)\n") ;
             exit(1) ;
           }
     
        /* ... malloc ... */
        buf1 = (char *) malloc((unsigned) max_len) ;
        if (buf1 == NULL)
           {
             perror("Error en malloc") ;
             exit(1) ;
           }
        buf2 = (char *) malloc((unsigned) max_len) ;
        if (buf2 == NULL)
           {
             perror("Error en malloc") ;
             exit(1) ;
           }
     
        /* ... test ... */
     	lenbuf = 1 ;
        while (lenbuf <= max_len)
        {
     		memset(buf1,'3',lenbuf) ;
     		memset(buf2,'8',lenbuf) ;
     
     		avg_time = 0.0;
     		t1 = TIME_time() ;
     		for(j = 0; j < MAX_TEST; j++)
               {
     	     	   for(k = 0; k < lenbuf; k++)
                      {
                     	  if (buf2[k] > buf1[k])
                     	           buf1[k] = buf2[k] ;
                      }
     		   }
     		t2 = TIME_time() ;
     		used_time = t2 - t1 ;
            avg_time  = (used_time) / (float)  MAX_TEST;

     		if (avg_time > 0)    /* rate is megabytes per second */
                us_rate = (double)((lenbuf) / (avg_time*(double)1000000)) ;
            else
                us_rate = 0.0;
     
            printf("len_bytes=%e avg_time_sec=%e rate_Mbytes_sec=%e\n", 
     		        (double)lenbuf, (double)avg_time, (double)us_rate) ;
     
            lenbuf *= 2;
        }
     
        /* ... end ... */
        free(buf1) ;
        free(buf2) ;
     	return (1) ;
     }

	
	
	


	int main  
    (
      int   	argc,
	  char	   *argv[]	
    )
	{
	    int         ret ;

		/*
         */
     	setbuf(stdout, NULL) ;
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
         * check values
         */
        ret = test_fpu_max(argc,argv) ;

		/*
         */
		printf("end\n") ;
		return 1 ;
	}



