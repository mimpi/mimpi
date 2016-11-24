

#ifndef L_DATATYPE_OP_H
#define L_DATATYPE_OP_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "base/l_alloc/x_alloc.h"


   /* ... Types / Tipos ............................................... */

      typedef
      struct {
               t_mtsda      boot ;
               T_LONG       count ;
               void        *result ;
               void        *oper1 ;
               void        *oper2 ;
               T_BOOL       isAssociative ;
               T_BOOL       isCommutative ;
             } t_op_param ;


   /* ... Const. / Constantes ......................................... */

      #define  c_OP_PARAM     (sizeof(t_op_param))


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_OP_H */


