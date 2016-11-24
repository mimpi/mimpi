

#ifndef MPIX_MATH_H
#define MPIX_MATH_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ....................................... */

     #include "console/l_verbose_msg.h"
     #include "mp/mpi/c_base.h"
     #include "mp/mpi/params_mpi.h"


   /* ... Functions / Funciones ....................................... */

      /**
       *
       * Evaluate pow(x,2).
       *
       * @param x base
       *
       * @see MPIX_log_x_2()
       *
       * @return pow(x,2).
       */

      int MPIX_MATH_pow_x_2 
      (
	IN    int  x
      ) ;


      /**
       *
       * Computes "T log2(n) T"
       *
       * @param x base
       *
       * @see MPIX_pow_x_2()
       *
       * @return log(x,2).
       */

      int MPIX_MATH_log_x_2_ge
      (
        int n
      ) ;
 
      /**
       *
       * Computes "L log2(n) J"
       *
       * @param x base
       *
       * @see MPIX_pow_x_2()
       *
       * @return log(x,2).
       */

      int MPIX_MATH_log_x_2_le
      (
        int n
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* MPIX_MATH_H */


