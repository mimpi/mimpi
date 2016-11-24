

 #ifndef I_THREAD_SHADOW_H
 #define I_THREAD_SHADOW_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"


  /* ... Types / Tipos ........................................*/

     typedef
     struct
     {
       T_BOOL          ready ;
       T_BOOL          destroy ;
     } t_shadow_mtsda ;

     typedef
     long t_shadow_thread ;

     typedef
     void *(*t_shadow_thcode)(void *) ;


  /* ... Functions / Funciones ................................*/

     /*  
      *  Thread
      * -------- 
      */
      T_BOOL   I_THREAD_SHADOW_createDetached  
      ( 
        OUT  t_shadow_thread   *thid,
        IN   t_shadow_thcode    thcode,
        IN   void              *tharg 
      ) ;

      T_BOOL   I_THREAD_SHADOW_createJoinable  
      ( 
        OUT  t_shadow_thread   *thid,
        IN   t_shadow_thcode    thcode,
        IN   void              *tharg 
      ) ;

      T_BOOL   I_THREAD_SHADOW_join            
      ( 
        IN   t_shadow_thread    thid,
        OUT  void             **thret 
      ) ;

     /*  
      *  Condition
      * ----------- 
      */
     void     I_THREAD_SHADOW_init            ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_destroy         ( IN   t_shadow_mtsda  *mtsda ) ;
     T_BOOL   I_THREAD_SHADOW_isDestroy       ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_lock            ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_unlock          ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_setReady        ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_setNotReady     ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_signalReady     ( IN   t_shadow_mtsda  *mtsda ) ;
     void     I_THREAD_SHADOW_waitReady       ( IN   t_shadow_mtsda  *mtsda ) ;
     T_CHAR  *I_THREAD_SHADOW_mtsdaToString   ( IN   t_shadow_mtsda  *mtsda ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_thread/i_thread_shadow.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_THREAD_SHADOW_H */

