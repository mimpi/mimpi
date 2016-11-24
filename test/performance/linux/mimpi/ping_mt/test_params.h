

#ifndef TEST_PARAMS_H
#define TEST_PARAMS_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include <stdlib.h>
     #include <stdio.h>

#if defined(HAVE_WINDOWS_H)
     #include <direct.h>
#endif


  /* ... Functions / Funciones ................................*/

      int   TEST_PARAMS_getLimits
      (
        /* IN    */   char *vfile,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* TEST_PARAMS_H */

