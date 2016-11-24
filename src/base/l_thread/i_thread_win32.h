

 #ifndef I_THREAD_WIN32_H
 #define I_THREAD_WIN32_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_string/x_dtd.h"


#if defined(HAVE_WINDOWS_H)

  /* ... Types / Tipos ........................................*/

     typedef
     struct
     {
       volatile CRITICAL_SECTION    mutex ;
       volatile HANDLE              event ;
       volatile T_BOOL              ready ;
       volatile T_BOOL              destroy ;
       volatile T_BOOL              locked ;
     } t_win32_mtsda ;

     typedef
     HANDLE                  t_win32_thread ;

     typedef
     LPTHREAD_START_ROUTINE  t_win32_thcode ;


  /* ... Const / Constantes ...................................*/

     #define  c_WIN32_MTSDA      sizeof(t_win32_mtsda)
     #define  c_WIN32_THREAD     sizeof(t_win32_thread)

     #define  WIN32_CREATE_JOINABLE  1


  /* ... Functions / Funciones ................................*/

     /*  
      *  Thread
      * -------- 
      */
     T_BOOL   I_THREAD_WIN32_createDetached  
     ( 
       OUT  t_win32_thread   *thid,
       IN   t_win32_thcode    thcode,
       IN   void             *tharg 
     ) ;

     T_BOOL   I_THREAD_WIN32_createJoinable  
     ( 
       OUT  t_win32_thread   *thid,
       IN   t_win32_thcode    thcode,
       IN   void             *tharg 
     ) ;

     T_BOOL   I_THREAD_WIN32_join            
     ( 
       IN   t_win32_thread    thid,
       OUT  void            **thret 
     ) ;


     /*  
      *  Condition
      * ---------- 
      */
     void     I_THREAD_WIN32_init            ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_destroy         ( IN   t_win32_mtsda  *mtsda ) ;
     T_BOOL   I_THREAD_WIN32_isDestroy       ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_lock            ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_unlock          ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_setReady        ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_setNotReady     ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_signalReady     ( IN   t_win32_mtsda  *mtsda ) ;
     void     I_THREAD_WIN32_waitReady       ( IN   t_win32_mtsda  *mtsda ) ;
     T_CHAR  *I_THREAD_WIN32_mtsdaToString   ( IN   t_win32_mtsda  *mtsda ) ;


  /* ... Inline / Macros ......................................*/

      #include "base/l_thread/i_thread_win32.m"


  /* ..........................................................*/

#endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_THREAD_WIN32_H */

