/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


/*
 *
 *  prove x_alloc.c and l_debug if __DEBUG_ALLOC__
 *  is defined (#define __DEBUG_ALLOC__)
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_alloc/x_alloc.h"
	#include "base/l_time/x_time.h"


        #define     MAX_NTEST         20
        #define     MAX_MALLOC_FREE   2*1024*1024
        #define     MAX_REALLOC       2*1024*1024


	int test_x_alloc_malloc
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                T_INT       ntest ;
                T_INT       chuck_size ;
                T_TIME      t1 ;
                T_TIME      t2 ;
                T_ACCTIME   outdiff ;
		void       *p[MAX_NTEST] ;


		/*
                 * check values
                 */
                for (chuck_size=1; chuck_size<=MAX_MALLOC_FREE; chuck_size*=2)
                    {
		      /*
                       *  next chuck
                       */
                      printf("size=%-8.0i\t",
                              chuck_size) ;

		      /*
                       *  malloc
                       */
                      X_TIME_GetTime(&t1) ;
                      for (ntest=0; ntest<MAX_NTEST; ntest++)
                          {
                            p[ntest] = X_ALLOC_Malloc(chuck_size) ;
                            if (p[ntest]  == NULL)
                                printf("ERROR\n") ;
                          }
                      X_TIME_GetTime(&t2) ;
                      outdiff = X_TIME_DiffTime(t2,t1) ;
                      printf("avg_malloc=%e\n",
                              outdiff / MAX_NTEST) ;
      
                      /*
                       *  setup chuck
                       */
                      for (ntest=0; ntest<MAX_NTEST; ntest++)
                          {
      	                    X_ALLOC_Free(&(p[ntest])) ;
                          }
                    }


		/*
                 */
		return 1 ;
	}

	int test_x_alloc_free
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                T_INT       ntest ;
                T_INT       chuck_size ;
                T_TIME      t1 ;
                T_TIME      t2 ;
                T_ACCTIME   outdiff ;
		void       *p[MAX_NTEST] ;


		/*
                 * check values
                 */
                for (chuck_size=1; chuck_size<=MAX_MALLOC_FREE; chuck_size*=2)
                    {
		      /*
                       *  next chuck
                       */
                      printf("size=%-8.0i\t",
                              chuck_size) ;

		      /*
                       *  setup chuck
                       */
                      for (ntest=0; ntest<MAX_NTEST; ntest++)
                          {
                            p[ntest] = X_ALLOC_Malloc(chuck_size) ;
                            if (p[ntest]  == NULL)
                                printf("ERROR\n") ;
                          }
      
                      /*
                       *  free
                       */
                      X_TIME_GetTime(&t1) ;
                      for (ntest=0; ntest<MAX_NTEST; ntest++)
                          {
      	                    X_ALLOC_Free(&(p[ntest])) ;
                          }
                      X_TIME_GetTime(&t2) ;
                      outdiff = X_TIME_DiffTime(t2,t1) ;
                      printf("avg_free=%e\n",
                              outdiff / MAX_NTEST) ;
                    }


		/*
                 */
		return 1 ;
	}

	int test_x_alloc_realloc
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
                T_INT       ntest ;
                T_INT       chuck_size ;
                T_TIME      t1 ;
                T_TIME      t2 ;
                T_ACCTIME   outdiff ;
		void       *p[MAX_NTEST] ;


		/*
                 *  setup values
                 */
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
                      p[ntest] = X_ALLOC_Malloc(1) ;
                      if (p[ntest]  == NULL)
                          printf("ERROR\n") ;
                    }

		/*
                 *  test realloc
                 */
                for (chuck_size=1; chuck_size<=MAX_REALLOC; chuck_size*=2)
                    {
		      /*
                       *  next chuck
                       */
                      printf("size=%-8.0i\t",
                              chuck_size) ;

		      /*
                       *  realloc
                       */
                      X_TIME_GetTime(&t1) ;
                      for (ntest=0; ntest<MAX_NTEST; ntest++)
                          {
                            p[ntest] = X_ALLOC_Realloc(p[ntest],chuck_size) ;
                            if (p[ntest]  == NULL)
                                printf("ERROR\n") ;
                          }
                      X_TIME_GetTime(&t2) ;
                      for (ntest=0; ntest<MAX_NTEST; ntest++)
                          {
                            p[ntest] = X_ALLOC_Realloc(p[ntest],1) ;
                            if (p[ntest]  == NULL)
                                printf("ERROR\n") ;
                          }
                      outdiff = X_TIME_DiffTime(t2,t1) ;
                      printf("avg_realloc=%e\n",
                              outdiff / MAX_NTEST) ;
                    }

		/*
                 *  setup values
                 */
                for (ntest=0; ntest<MAX_NTEST; ntest++)
                    {
      	              X_ALLOC_Free(&(p[ntest])) ;
                    }

		/*
                 */
		return 1 ;
	}


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
	        int         ret ;

		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
                 * check values
                 */
                ret = test_x_alloc_malloc(argc,argv) ;
                ret = test_x_alloc_free(argc,argv) ;
                ret = test_x_alloc_realloc(argc,argv) ;

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


