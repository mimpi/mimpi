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


     int test_lock_lock
     (
       int     argc, 
       char   *argv[]
	 )
     {
     	pthread_mutex_t   *buf1;
     	double             t1 ;
     	double             t2 ;
        double             used_time;
        double             avg_time;
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
        if ( (max_len <= MIN_LEN) || (max_len >= MAX_LEN) )
           {
             printf("ERROR: (max_len <= %d) || (max_len >= %d)\n",
				    MIN_LEN,MAX_LEN) ;
             exit(1) ;
           }
     
        /* ... malloc ... */
        buf1 = malloc( max_len * sizeof(pthread_mutex_t) ) ;
        if (buf1 == NULL)
           {
             perror("Error en malloc") ;
             exit(1) ;
           }
     
        /* ... test ... */
     	lenbuf = 1 ;
     	for(k = 0; k < max_len; k++)
            pthread_mutex_init( &(buf1[k]), NULL ) ;
        while (lenbuf <= max_len)
        {
     		used_time = .0 ;
     		for(j = 0; j < MAX_TEST; j++)
               {
     		       t1 = TIME_time() ;
     	     	   for(k = 0; k < lenbuf; k++)
                   	   pthread_mutex_lock( &(buf1[k]) ) ;
     		       t2 = TIME_time() ;
     		       used_time += t2 - t1 ;
     	           for(k = 0; k < lenbuf; k++)
                       pthread_mutex_unlock( &(buf1[k]) ) ;
     		   }
            avg_time  = (used_time) / (double)  MAX_TEST;

            printf("len_lock=%e avg_time_sec=%e\n", 
     		        (double)lenbuf, (double)avg_time) ;
     
            lenbuf *= 2;
        }
     	for(k = 0; k < max_len; k++)
            pthread_mutex_destroy( &(buf1[k]) ) ;
     
        /* ... end ... */
        free(buf1) ;
     	return (1) ;
     }

     int test_lock_unlock
     (
       int     argc, 
       char   *argv[]
	 )
	 {
     	pthread_mutex_t   *buf1;
     	double        t1 ;
     	double        t2 ;
        double        used_time;
        double        avg_time;
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
        if ( (max_len <= MIN_LEN) || (max_len >= MAX_LEN) )
           {
             printf("ERROR: (max_len <= %d) || (max_len >= %d)\n",
				    MIN_LEN,MAX_LEN) ;
             exit(1) ;
           }
     
        /* ... malloc ... */
        buf1 = malloc( max_len * sizeof(pthread_mutex_t) ) ;
        if (buf1 == NULL)
           {
             perror("Error en malloc") ;
             exit(1) ;
           }
     
        /* ... test ... */
     	lenbuf = 1 ;
     	for(k = 0; k < max_len; k++)
            pthread_mutex_init( &(buf1[k]), NULL ) ;
        while (lenbuf <= max_len)
        {
     		used_time = .0 ;
     		for(j = 0; j < MAX_TEST; j++)
               {
     	           for(k = 0; k < lenbuf; k++)
                       pthread_mutex_lock( &(buf1[k]) ) ;
     		       t1 = TIME_time() ;
     	     	   for(k = 0; k < lenbuf; k++)
                   	   pthread_mutex_unlock( &(buf1[k]) ) ;
     		       t2 = TIME_time() ;
     		       used_time += t2 - t1 ;
     		   }
            avg_time  = (used_time) / (double)  MAX_TEST;

            printf("len_lock=%e avg_time_sec=%e\n", 
     		        (double)lenbuf, (double)avg_time) ;

            lenbuf *= 2;
        }
     	for(k = 0; k < max_len; k++)
            pthread_mutex_destroy( &(buf1[k]) ) ;
     
        /* ... end ... */
        free(buf1) ;
     	return (1) ;
     }
	
     int test_lock_trylock
     (
       int     argc, 
       char   *argv[]
	 )
	 {
     	pthread_mutex_t   *buf1;
     	double        t1 ;
     	double        t2 ;
        double        used_time;
        double        avg_time;
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
        if ( (max_len <= MIN_LEN) || (max_len >= MAX_LEN) )
           {
             printf("ERROR: (max_len <= %d) || (max_len >= %d)\n",
				    MIN_LEN,MAX_LEN) ;
             exit(1) ;
           }
     
        /* ... malloc ... */
        buf1 = malloc( max_len * sizeof(pthread_mutex_t) ) ;
        if (buf1 == NULL)
           {
             perror("Error en malloc") ;
             exit(1) ;
           }
     
        /* ... test ... */
     	lenbuf = 1 ;
     	for(k = 0; k < max_len; k++)
            pthread_mutex_init( &(buf1[k]), NULL ) ;
        while (lenbuf <= max_len)
        {
     		used_time = .0 ;
     		for(j = 0; j < MAX_TEST; j++)
               {
     		       t1 = TIME_time() ;
     	     	   for(k = 0; k < lenbuf; k++)
                   	   pthread_mutex_trylock( &(buf1[k]) ) ;
     		       t2 = TIME_time() ;
     		       used_time += t2 - t1 ;
     	           for(k = 0; k < lenbuf; k++)
                       pthread_mutex_unlock( &(buf1[k]) ) ;
     		   }
            avg_time  = (used_time) / (double)  MAX_TEST;

            printf("len_lock=%e avg_time_sec=%e\n", 
     		        (double)lenbuf, (double)avg_time) ;

            lenbuf *= 2;
        }
     	for(k = 0; k < max_len; k++)
            pthread_mutex_destroy( &(buf1[k]) ) ;
     
        /* ... end ... */
        free(buf1) ;
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
        ret = test_lock_lock(argc,argv) ;
        ret = test_lock_trylock(argc,argv) ;
        ret = test_lock_unlock(argc,argv) ;

		/*
         */
		printf("end\n") ;
		return 1 ;
	}



