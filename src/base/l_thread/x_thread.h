

 #ifndef X_THREAD_H
 #define X_THREAD_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_thread/v_thread.h"
      #include "base/l_thread/v_thread_pool.h"


  /* ... Types / Tipos ........................................*/

      #if defined(__LINUX__)
           #define  T_THREAD  t_thread
      #else
           #define  T_THREAD  t_thread_id
      #endif


  /* ... Const / Constantes ...................................*/

     #define  c_THREAD  sizeof(T_THREAD)


  /* ... Functions / Funciones ................................*/

     /*
      *  Thread
      * --------
      */
      T_BOOL   X_THREAD_createDetached  
      ( 
        OUT  T_THREAD     *thid,
        IN   t_thcode     thcode,
        IN   void         *tharg 
      ) ;

      T_BOOL   X_THREAD_createJoinable  
      ( 
        OUT  T_THREAD    *thid,
        IN   t_thcode     thcode,
        IN   void        *tharg 
      ) ;

      T_BOOL   X_THREAD_join            
      ( 
        IN   T_THREAD     thid,
        OUT  void       **thret 
      ) ;


     /*
      *  Condition
      * -----------
      */
     void     X_THREAD_init            ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_destroy         ( IN   t_mtsda      *mtsda ) ;
     T_BOOL   X_THREAD_isDestroy       ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_lock            ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_unlock          ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_setReady        ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_setNotReady     ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_signalReady     ( IN   t_mtsda      *mtsda ) ;
     void     X_THREAD_waitReady       ( IN   t_mtsda      *mtsda ) ;
     T_CHAR  *X_THREAD_mtsdaToString   ( IN   t_mtsda      *mtsda ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_thread/x_thread.m"
      #include "base/l_thread/c_thread_ret.h"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* X_THREAD_H */

