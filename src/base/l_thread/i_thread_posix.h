

 #ifndef I_THREAD_POSIX_H
 #define I_THREAD_POSIX_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_string/x_dtd.h"


#if defined(HAVE_PTHREAD_H)

  /* ... Types / Tipos ........................................*/

     typedef
     struct
     {
       pthread_mutex_t   mutex ;
       pthread_cond_t    cond ;
       T_BOOL            ready ;
       T_BOOL            destroy ;
     } t_posix_mtsda ;

     typedef
     pthread_t t_posix_thread ;

     typedef
     void *(*t_posix_thcode)(void *) ;


  /* ... Const / Constantes ...................................*/

     #define  c_POSIX_MTSDA      sizeof(t_posix_mtsda)
     #define  c_POSIX_THREAD     sizeof(t_posix_thread)

     #if defined(PTHREAD_CREATE_UNDETACHED)
         #define PTHREAD_CREATE_JOINABLE  PTHREAD_CREATE_UNDETACHED
     #endif


  /* ... Functions / Funciones ................................*/

     /*  
      *  Thread
      * -------- 
      */
     T_BOOL   I_THREAD_POSIX_createDetached  
     ( 
       OUT  t_posix_thread   *thid,
       IN   t_posix_thcode    thcode,
       IN   void             *tharg 
     ) ;

     T_BOOL   I_THREAD_POSIX_createJoinable  
     ( 
       OUT  t_posix_thread   *thid,
       IN   t_posix_thcode    thcode,
       IN   void             *tharg 
     ) ;

     T_BOOL   I_THREAD_POSIX_join            
     ( 
       IN   t_posix_thread    thid,
       OUT  void            **thret 
     ) ;


     /*  
      *  Condition
      * ---------- 
      */
     void     I_THREAD_POSIX_init            ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_destroy         ( IN   t_posix_mtsda  *mtsda ) ;
     T_BOOL   I_THREAD_POSIX_isDestroy       ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_lock            ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_unlock          ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_setReady        ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_setNotReady     ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_signalReady     ( IN   t_posix_mtsda  *mtsda ) ;
     void     I_THREAD_POSIX_waitReady       ( IN   t_posix_mtsda  *mtsda ) ;
     T_CHAR  *I_THREAD_POSIX_mtsdaToString   ( IN   t_posix_mtsda  *mtsda ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_thread/i_thread_posix.m"


  /* ..........................................................*/

#endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_THREAD_POSIX_H */

