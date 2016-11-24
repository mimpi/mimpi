/* ....................................................................
 *
 * Copyright Felix Garcia (1997-1999)
 * <fgarcia@laurel.datsi.fi.upm.es>
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "l_mpi_test.h"


   /* ... Funciones ................................................... */

      int   L_MPI_TEST_openFile
      (
        /* IN    */   char  *fnparam,
        /* IN    */   char  *fattrib,
        /* INOUT */   FILE **fparam
      )
      {
        char     *fcwd ;
        char     *fpath ;
        int       sfpath ;

        /*
         *  try set default values ...
         */
        if (fparam == NULL)
            return -1 ;
        (*fparam) = NULL ;

        /*
         *  try get full path ...
         */
        fcwd = getcwd(NULL,0) ;
        if (fcwd == NULL)
           {
             sfpath = 1 + 1 + strlen(fnparam) ;
             fpath = malloc(sfpath) ;
             if (fpath == NULL)
                {
                  printf("malloc(%i): ",sfpath) ; 
                  perror("") ; 
                  return -1 ;
                }
             sprintf(fpath,"./%s",fnparam) ;
           }
        else 
           {
             sfpath = strlen(fcwd) + 1 + strlen(fnparam) ;
             fpath = malloc(sfpath) ;
             free(fcwd) ;
             if (fpath == NULL)
                {
                  printf("malloc(%i): ",sfpath) ; 
                  perror("") ; 
                  return -1 ;
                }
             sprintf(fpath,"%s/%s",fcwd,fnparam) ;
           }

        /*
         *  try open file ...
         */
        (*fparam) = fopen(fpath,fattrib) ;
        if ((*fparam) == NULL)
           {
             printf("fopen(%s,%s): ",fpath,fattrib) ;
             perror("") ; 
             free(fpath) ;
             return -1 ;
           }

        /*
         *  return ok ...
         */
        free(fpath) ;
        return 1 ;
      }

      int   L_MPI_TEST_readLimits
      (
        /* IN    */   char *fnparam,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      )
      {
        int       ret ;
        FILE     *fparam ;

        /*
         *  try set default values ...
         */
        if (max_len == NULL)
            return -1 ;
        if (min_len == NULL)
            return -1 ;
        (*max_len) = -1 ;
        (*min_len) = -1 ;

        /*
         *  open file ...
         */
        ret = L_MPI_TEST_openFile(fnparam,"rt",&fparam) ;
        if (ret < 1)
            return -1 ;

        /*
         *  try get values ...
         */
        ret = fscanf(fparam,"max_len=%i",max_len) ;
        if (ret < 1)
           {
             fclose(fparam) ;
             printf("ERROR: can not read 'max_len' value from file.\n") ;
             return -1 ;
           }
        ret = fscanf(fparam,"min_len=%i",min_len) ;
        if (ret < 1)
           {
             fclose(fparam) ;
             printf("ERROR: can not read 'min_len' value from file.\n") ;
             return -1 ;
           }

        /*
         *  return ok ...
         */
        return 1 ;
      }

      int   L_MPI_TEST_malloc
      (
        /* IN    */   int    size,
        /* IN    */   char   fillch,
        /* INOUT */   void **buf
      )
      {
        /*
         *  try set default values ...
         */
        if (buf == NULL)
            return -1 ;
        (*buf) = NULL ;

        /*
         *  try get memory ...
         */
        (*buf) = malloc((unsigned)size) ;
        if ((*buf) == NULL)
           {
             printf("malloc(%i): ",size) ; 
             perror("") ; 
             return -1 ;
           }

        /*
         *  fill memory ...
         */
        memset((*buf),fillch,size) ;

        /*
         *  return ok ...
         */
        return -1 ;
      }

      int   L_MPI_TEST_getLimits
      (
        /* IN    */   char *vfile,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      )
      {
        int ret ;

        /*
         *  try get values ...
         */
        ret = L_MPI_TEST_getLimits(vfile,max_len,min_len) ;
        if (ret < 1)
           {
             printf("ERROR: can not read from %s, sorry.\n",vfile) ;
             return -1 ;
           }

        /*
         *  check values ...
         */
        if ( ((*max_len) <= 0) || ((*max_len) >= 8*1024*1024) )
           {
             printf("ERROR: ((*max_len) <= 0) || ((*max_len) >= 8*1024*1024)\n") ;
             return -1 ;
           }
        if ( ((*min_len) <= 0) || ((*min_len) >= 8*1024*1024) )
           {
             printf("ERROR: ((*min_len) <= 0) || ((*min_len) >= 8*1024*1024)\n") ;
             return -1 ;
           }
        if ( (*max_len) <= (*min_len) )
           {
             printf("ERROR: (*max_len) <= (*min_len)\n") ;
             return -1 ;
           }

        /*
         *  return ok
         */
        return 1 ;
      }

      int   L_MPI_TEST_getBufs
      (
        /* IN    */   int    send_buf_size,
        /* IN    */   int    recv_buf_size,
        /* INOUT */   char **send_buf,
        /* INOUT */   char **recv_buf
      )
      {
        int ret ;

        /*
         *  try get buffers ...
         */
        ret = L_MPI_TEST_malloc(send_buf_size,'x',(void **)send_buf) ;
	if (ret < 0)
	   {
		printf("ERROR: Can not alloc send buffer\n") ;
                return -1 ;
	   }

        ret = L_MPI_TEST_malloc(recv_buf_size,'x',(void **)recv_buf) ;
	if (ret < 0)
	   {
		printf("ERROR: Can not alloc receive buffer\n") ;
                return -1 ;
	   }

        /*
         *  return ok
         */
        return 1 ;
      }

      double L_MPI_TEST_getBarrierTime
      (
        /* IN    */   int n_test
      )
      {
	double start_time ;
	double barrier_time ;
	int    j ;

        /*
         *  test barrier
         */
        start_time = MPI_Wtime() ;
        for(j = 0; j < n_test; j++)
        {
          MPI_Barrier(MPI_COMM_WORLD) ;
        }
        barrier_time = (MPI_Wtime() - start_time) ;

        /*
         *  return barrier_time
         */
        return barrier_time ;
      }


  /* .................................................................... */

