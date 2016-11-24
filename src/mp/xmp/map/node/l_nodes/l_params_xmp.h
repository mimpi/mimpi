

#ifndef L_PARAMS_XMP_H
#define L_PARAMS_XMP_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "base/l_string/x_string.h"
      #include "console/l_trace_msg.h"
 
 
  /* ... Types / Tipos ........................................*/

     typedef
     struct
     {

       /**
        **   l_sb
        **/

       T_INT          nodeid ;
       T_INT          nnodes ;
       char          *host ;
       int            port ;


       /**
        **   l_nodes
        **/

       /*
        *
        *    DYNAMIC_LINK (default = 0)
        *
        *       1        -> dynamic link
        *                   enlaces bajo demanda
        *       0        -> static link
        *                   enlaces por adelantado
        *
        */
       long           DYNAMIC_LINK ;

       /*
        *
        *    MAX_RECV_THROUGH (default = LONG_MAX)
        *
        *        LONG_MAX -> try receive without enqueue.
        *                    tratar de recibir sin encolar
        *        x        -> try receive if less than x.
        *                    tratar de recibir sin encolar si menos que x
        *        0        -> receive allways enqueued.
        *                    encolar siempre
        *
        */
       T_LONG         MAX_RECV_THROUGH ;

       /*
        *
        *    MAX_SEND_THROUGH (default = LONG_MAX)
        *
        *        LONG_MAX -> try send without enqueue.
        *                    tratar de enviar sin encolar
        *        x        -> try send if less than x.
        *                    tratar de enviar sin encolar si menos que x
        *        0        -> send allways enqueued.
        *                    encolar siempre
        *
        */
       T_LONG         MAX_SEND_THROUGH ;

     } t_params_xmp ;


   /* ... Functions / Funciones ................................*/

      /**
       *
       *  Set params values.
       *
       *     @params table where load values.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_PARAMS_XMP_NODES_put
      (
        OUT    t_params_xmp  *params
      ) ;

      /**
       *
       *  Set default params values.
       *
       *     @params 'argc' from main function.
       *     @params 'argv' from main function.
       *     @params 'envv' from main function.
       *     @params table where load values.
       *     @return TRUE if allright.
       *
       */
      T_BOOL  L_PARAMS_XMP_SB_put
      (
         IN     int            argc,
         IN     char         **argv,
         IN     char         **envv,
         OUT    t_params_xmp  *params
      ) ;


   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif /* L_PARAMS_XMP_H */

