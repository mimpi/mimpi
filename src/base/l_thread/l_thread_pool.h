

 #ifndef L_THREAD_POOL_H
 #define L_THREAD_POOL_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_thread/v_thread.h"
      #include "base/l_thread/c_thread_ret.h"


  /* ... Types / Tipos ........................................*/

     typedef 
     T_U_LONG t_thread_id ;

     typedef 
     struct t_thread_pool_elto *t_thread_pool_elto_pointer ;

     typedef
     struct t_thread_pool      *t_thread_pool_pointer ;

     typedef
     struct
     {

       t_thcode  pf ;
       void     *pf_params ;
       void     *pf_return ;
       t_mtsda   begin ;
       t_mtsda   end ;
       t_mtsda   joined ;

       t_thread              tid ;
       T_U_LONG              me ;
       T_U_LONG              nextFree ;
       t_thread_pool_pointer list ;

     } t_thread_pool_elto ;

     typedef
     struct
     {

       t_thread_pool_elto         **list ;
       T_U_LONG                     neltos ;
       t_mtsda                      monitor ;
       T_U_LONG                     firstFree ;

     } t_thread_pool ;


  /* ... Const / Constantes ................................... */

      #define  c_THREAD_POOL_ELTO     (sizeof(t_thread_pool_elto))
      #define  c_THREAD_POOL          (sizeof(t_thread_pool))
      #define  c_THREAD_ID            (sizeof(t_thread_id))

      #define  THREAD_BUCKET           32


  /* ... Functions / Funciones ................................*/

     /*
      *  thread elto
      *  -----------
      */

     t_thread_pool_elto    *L_THREAD_POOL_ELTO_Creat
     (
       IN     T_U_LONG       me,
       IN     T_U_LONG       nextFree,
       IN     t_thread_pool *list
     ) ;

      T_BOOL          L_THREAD_POOL_ELTO_Finalize
      (
        INOUT  t_thread_pool_elto   *telto
      ) ;

      void *          L_THREAD_POOL_ELTO_core
      (
        IN     void    *tparams
      ) ;


     /*
      *  thread list
      *  -----------
      */

     t_thread_pool    *L_THREAD_POOL_LIST_Creat
     (
       void
     ) ;

      T_BOOL          L_THREAD_POOL_LIST_Destroy
      (
        INOUT  t_thread_pool  **tcache
      ) ;

      T_BOOL               L_THREAD_POOL_LIST_insertFree
      ( 
        INOUT  t_thread_pool       *tcache,
        IN     T_U_LONG             index
      ) ; 

      t_thread_pool_elto *L_THREAD_POOL_LIST_removeFree
      ( 
        INOUT  t_thread_pool       *tcache
      ) ; 

      t_thread_pool_elto *L_THREAD_POOL_LIST_getElto
      ( 
        INOUT  t_thread_pool       *tcache,
        IN     long                 index
      ) ; 


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_THREAD_POOL_H */

