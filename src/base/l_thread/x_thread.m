

 #ifndef X_THREAD_M
 #define X_THREAD_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Macros ............................................... */


      /*  Thread  *
       * -------- */
#if (0)
      #define X_THREAD_createDetached(thid,thcode,tharg)       \
              V_THREAD_POOL_createDetached((thid),(thcode),(tharg))

      #define X_THREAD_createJoinable(thid,thcode,tharg)       \
              V_THREAD_POOL_createJoinable((thid),(thcode),(tharg))

      #define X_THREAD_join(thid,thret)                        \
              V_THREAD_POOL_join((thid),(thret))
#else
      #define X_THREAD_createDetached(thid,thcode,tharg)       \
              V_THREAD_createDetached((thid),(thcode),(tharg))

      #define X_THREAD_createJoinable(thid,thcode,tharg)       \
              V_THREAD_createJoinable((thid),(thcode),(tharg))

      #define X_THREAD_join(thid,thret)                        \
              V_THREAD_join((thid),(thret))
#endif


      /*  Condition  *
       * ----------- */
      #define X_THREAD_init(mtsda)                    \
              V_THREAD_init((mtsda))

      #define X_THREAD_destroy(mtsda)                 \
              V_THREAD_destroy((mtsda))

      #define X_THREAD_isDestroy(mtsda)               \
              V_THREAD_isDestroy((mtsda))

      #define X_THREAD_lock(mtsda)                    \
              V_THREAD_lock((mtsda))

      #define X_THREAD_unlock(mtsda)                  \
              V_THREAD_unlock((mtsda))

      #define X_THREAD_setReady(mtsda)                \
              V_THREAD_setReady((mtsda))

      #define X_THREAD_setNotReady(mtsda)             \
              V_THREAD_setNotReady((mtsda))

      #define X_THREAD_signalReady(mtsda)             \
              V_THREAD_signalReady((mtsda))

      #define X_THREAD_waitReady(mtsda)               \
              V_THREAD_waitReady((mtsda))

      #define X_THREAD_mtsdaToString(mtsda)           \
              V_THREAD_mtsdaToString((mtsda))


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

