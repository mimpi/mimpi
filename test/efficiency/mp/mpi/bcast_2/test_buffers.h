

#ifndef TEST_BUFFERS_H
#define TEST_BUFFERS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include <stdlib.h>
     #include <stdio.h>


  /* ... Defines / Const ......................................*/

     #define   TB_FILL_CHAR   'x'


  /* ... Functions / Funciones ................................*/

      int   TEST_BUFFERS_getBufs
      (
        /* IN    */   int    send_buf_size,
        /* IN    */   int    recv_buf_size,
        /* INOUT */   char **send_buf,
        /* INOUT */   char **recv_buf
      ) ;

      int   TEST_BUFFERS_getBuf
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* TEST_BUFFERS_H */

