

 #ifndef V_THREAD_POOL_H
 #define V_THREAD_POOL_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_thread/l_thread_pool.h"


  /* ... Functions / Funciones ................................*/

     /*
      *  Thread
      * --------
      */
      T_BOOL   V_THREAD_POOL_createDetached  
      ( 
        OUT  t_thread_id     *thid,
        IN   t_thcode         thcode,
        IN   void            *tharg 
      ) ;

      T_BOOL   V_THREAD_POOL_createJoinable  
      ( 
        OUT  t_thread_id    *thid,
        IN   t_thcode        thcode,
        IN   void           *tharg 
      ) ;

      T_BOOL   V_THREAD_POOL_join            
      ( 
        IN   t_thread_id     thid,
        OUT  void          **thret 
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* V_THREAD_POOL_H */

