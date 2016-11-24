

#ifndef TEST_BUFFERS_H
#define TEST_BUFFERS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include <stdlib.h>
     #include <stdio.h>


  /* ... Functions / Funciones ................................*/

      int   TEST_BUFFERS_malloc
      (
        /* IN    */   int    size,
        /* INOUT */   void **buf
      ) ;

      int   TEST_BUFFERS_mallocv2
      (
        /* IN    */   int    send_buf_size,
        /* IN    */   int    recv_buf_size,
        /* INOUT */   char **send_buf,
        /* INOUT */   char **recv_buf
      ) ;

      int   TEST_BUFFERS_fill_fixed
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf,
        /* IN    */   char   buf_bg
      ) ;

      int   TEST_BUFFERS_fill_sparse
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf,
        /* IN    */   char   buf_bg
      ) ;

      int   TEST_BUFFERS_fill_dense
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf,
        /* IN    */   char   buf_bg
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* TEST_BUFFERS_H */

