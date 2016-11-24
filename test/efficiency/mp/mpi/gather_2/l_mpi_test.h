

#ifndef L_MPI_TEST_H
#define L_MPI_TEST_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include <stdlib.h>
     #include <stdio.h>
     #include <pthread.h>
     #include "mpi.h"


  /* ... Functions / Funciones ................................*/

      int   L_MPI_TEST_openFile
      (
        /* IN    */   char  *fnparam,
        /* IN    */   char  *fattrib,
        /* INOUT */   FILE **fparam
      ) ;

      int   L_MPI_TEST_readLimits
      (
        /* IN    */   char *fnparam,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      ) ;

      int   L_MPI_TEST_malloc
      (
        /* IN    */   int    size,
        /* IN    */   char   fillch,
        /* INOUT */   void **buf
      ) ;

      int   L_MPI_TEST_getLimits
      (
        /* IN    */   char *vfile,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      ) ;

      int   L_MPI_TEST_getBufs
      (
        /* IN    */   int    send_buf_size,
        /* IN    */   int    recv_buf_size,
        /* INOUT */   char **send_buf,
        /* INOUT */   char **recv_buf
      ) ;

      double L_MPI_TEST_getBarrierTime
      (
        /* IN    */   int n_test
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_MPI_TEST_H */

