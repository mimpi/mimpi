

 #ifndef V_THREAD_M
 #define V_THREAD_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_thread/v_thread.h"


   /* ... Inline / Macros ............................................... */

      #if defined(HAVE_WINDOWS_H)

           /*  Thread  *
            * -------- */
           #define V_THREAD_createDetached(thid,thcode,tharg)       \
                   I_THREAD_WIN32_createDetached((thid),(thcode),(tharg))

           #define V_THREAD_createJoinable(thid,thcode,tharg)       \
                   I_THREAD_WIN32_createJoinable((thid),(thcode),(tharg))

           #define V_THREAD_join(thid,thret)                        \
                   I_THREAD_WIN32_join((thid),(thret))


           /*  Condition  *
            * ----------- */
           #define V_THREAD_init(mtsda)                    \
                   I_THREAD_WIN32_init((mtsda))

           #define V_THREAD_destroy(mtsda)                 \
                   I_THREAD_WIN32_destroy((mtsda))

           #define V_THREAD_isDestroy(mtsda)               \
                   I_THREAD_WIN32_isDestroy((mtsda))

           #define V_THREAD_lock(mtsda)                    \
                   I_THREAD_WIN32_lock((mtsda))

           #define V_THREAD_unlock(mtsda)                  \
                   I_THREAD_WIN32_unlock((mtsda))

           #define V_THREAD_setReady(mtsda)                \
                   I_THREAD_WIN32_setReady((mtsda))

           #define V_THREAD_setNotReady(mtsda)             \
                   I_THREAD_WIN32_setNotReady((mtsda))

           #define V_THREAD_signalReady(mtsda)             \
                   I_THREAD_WIN32_signalReady((mtsda))

           #define V_THREAD_waitReady(mtsda)               \
                   I_THREAD_WIN32_waitReady((mtsda))

           #define V_THREAD_mtsdaToString(mtsda)           \
                   I_THREAD_WIN32_mtsdaToString((mtsda))

      #elif defined(HAVE_PTHREAD_H)

           /*  Thread  *
            * -------- */
           #define V_THREAD_createDetached(thid,thcode,tharg)       \
                   I_THREAD_POSIX_createDetached((thid),(thcode),(tharg))

           #define V_THREAD_createJoinable(thid,thcode,tharg)       \
                   I_THREAD_POSIX_createJoinable((thid),(thcode),(tharg))

           #define V_THREAD_join(thid,thret)                        \
                   I_THREAD_POSIX_join((thid),(thret))


           /*  Condition  *
            * ----------- */
           #define V_THREAD_init(mtsda)                    \
                   I_THREAD_POSIX_init((mtsda))

           #define V_THREAD_destroy(mtsda)                 \
                   I_THREAD_POSIX_destroy((mtsda))

           #define V_THREAD_isDestroy(mtsda)               \
                   I_THREAD_POSIX_isDestroy((mtsda))

           #define V_THREAD_lock(mtsda)                    \
                   I_THREAD_POSIX_lock((mtsda))

           #define V_THREAD_unlock(mtsda)                  \
                   I_THREAD_POSIX_unlock((mtsda))

           #define V_THREAD_setReady(mtsda)                \
                   I_THREAD_POSIX_setReady((mtsda))

           #define V_THREAD_setNotReady(mtsda)             \
                   I_THREAD_POSIX_setNotReady((mtsda))

           #define V_THREAD_signalReady(mtsda)             \
                   I_THREAD_POSIX_signalReady((mtsda))

           #define V_THREAD_waitReady(mtsda)               \
                   I_THREAD_POSIX_waitReady((mtsda))

           #define V_THREAD_mtsdaToString(mtsda)           \
                   I_THREAD_POSIX_mtsdaToString((mtsda))

      #else

           /*  Thread  *
            * -------- */
           #define V_THREAD_createDetached(thid,thcode,tharg)       \
                   I_THREAD_SHADOW_createDetached((thid),(thcode),(tharg))

           #define V_THREAD_createJoinable(thid,thcode,tharg)       \
                   I_THREAD_SHADOW_createJoinable((thid),(thcode),(tharg))

           #define V_THREAD_join(thid,thret)                        \
                   I_THREAD_SHADOW_join((thid),(thret))


           /*  Condition  *
            * ----------- */
           #define V_THREAD_init(mtsda)                    \
                   I_THREAD_SHADOW_init((mtsda))

           #define V_THREAD_destroy(mtsda)                 \
                   I_THREAD_SHADOW_destroy((mtsda))

           #define V_THREAD_isDestroy(mtsda)               \
                   I_THREAD_SHADOW_isDestroy((mtsda))

           #define V_THREAD_lock(mtsda)                    \
                   I_THREAD_SHADOW_lock((mtsda))

           #define V_THREAD_unlock(mtsda)                  \
                   I_THREAD_SHADOW_unlock((mtsda))

           #define V_THREAD_setReady(mtsda)                \
                   I_THREAD_SHADOW_setReady((mtsda))

           #define V_THREAD_setNotReady(mtsda)             \
                   I_THREAD_SHADOW_setNotReady((mtsda))

           #define V_THREAD_signalReady(mtsda)             \
                   I_THREAD_SHADOW_signalReady((mtsda))

           #define V_THREAD_waitReady(mtsda)               \
                   I_THREAD_SHADOW_waitReady((mtsda))

           #define V_THREAD_mtsdaToString(mtsda)           \
                   I_THREAD_SHADOW_mtsdaToString((mtsda))

      #endif


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

