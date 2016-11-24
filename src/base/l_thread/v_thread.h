

 #ifndef V_THREAD_H
 #define V_THREAD_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_thread/i_thread_win32.h"
      #include "base/l_thread/i_thread_posix.h"
      #include "base/l_thread/i_thread_shadow.h"


  /* ... Types / Tipos ........................................*/

      #if defined(HAVE_WINDOWS_H)
           #define  t_mtsda   t_win32_mtsda
           #define  t_thcode  t_win32_thcode
           #define  t_thread  t_win32_thread
      #elif defined(HAVE_PTHREAD_H)
           #define  t_mtsda   t_posix_mtsda
           #define  t_thcode  t_posix_thcode
           #define  t_thread  t_posix_thread
      #else
           #define  t_mtsda   t_shadow_mtsda
           #define  t_thcode  t_shadow_thcode
           #define  t_thread  t_shadow_thread
      #endif


  /* ... Const / Constantes ...................................*/

     #define  c_MTSDA    sizeof(t_mtsda)
     #define  c_THCODE   sizeof(t_thcode)
     #define  c_VTHREAD  sizeof(t_thread)


  /* ... Functions / Funciones ................................*/

     /*
      *  Thread
      * --------
      */
      T_BOOL   V_THREAD_createDetached  
      ( 
        OUT  t_thread     *thid,
        IN   t_thcode      thcode,
        IN   void         *tharg 
      ) ;

      T_BOOL   V_THREAD_createJoinable  
      ( 
        OUT  t_thread    *thid,
        IN   t_thcode     thcode,
        IN   void        *tharg 
      ) ;

      T_BOOL   V_THREAD_join            
      ( 
        IN   t_thread     thid,
        OUT  void       **thret 
      ) ;


     /*
      *  Condition
      * -----------
      */
     void     V_THREAD_init            ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_destroy         ( IN   t_mtsda      *mtsda ) ;
     T_BOOL   V_THREAD_isDestroy       ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_lock            ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_unlock          ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_setReady        ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_setNotReady     ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_signalReady     ( IN   t_mtsda      *mtsda ) ;
     void     V_THREAD_waitReady       ( IN   t_mtsda      *mtsda ) ;
     T_CHAR  *V_THREAD_mtsdaToString   ( IN   t_mtsda      *mtsda ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_thread/v_thread.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* V_THREAD_H */

