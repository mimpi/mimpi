

 #ifndef I_THREAD_WIN32_M
 #define I_THREAD_WIN32_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"


  /* ... Inline / Macros ......................................*/

#if defined(HAVE_WINDOWS_H)

     #define  I_THREAD_WIN32_init(mtsda)                             \
              {                                                      \
                (mtsda)->ready   = FALSE ;                           \
                (mtsda)->destroy = FALSE ;                           \
                (mtsda)->locked  = FALSE ;                           \
                                                                     \
                InitializeCriticalSection(&((mtsda)->mutex)) ;       \
                                                                     \
                (mtsda)->event = CreateEvent(NULL,FALSE,TRUE,NULL) ; \
                if ((mtsda)->event == NULL)                          \
                    L_DEBUG_MSG_Write(DBG_INFO,FALSE,                \
                                      "CreateEvent fail\n") ;        \
              }

     #define  I_THREAD_WIN32_destroy(mtsda)                          \
              {                                                      \
                int ret ;                                            \
                                                                     \
                (mtsda)->ready   = FALSE ;                           \
                (mtsda)->destroy = TRUE ;                            \
                (mtsda)->locked  = FALSE ;                           \
                                                                     \
                PulseEvent((mtsda)->event) ;                      \
                                                                     \
                ret = CloseHandle((mtsda)->event) ;                  \
                if (ret == FALSE)                                    \
                    L_DEBUG_MSG_Write(DBG_INFO,FALSE,                \
                                      "locked condition\n") ;        \
                                                                     \
                DeleteCriticalSection(&((mtsda)->mutex)) ;           \
              }

     #define  I_THREAD_WIN32_isDestroy(mtsda)                        \
              (                                                      \
                ((mtsda) == NULL) ?                                  \
                (TRUE) :                                             \
                ((mtsda)->destroy == TRUE)                           \
              )

     #define  I_THREAD_WIN32_lock(mtsda)                             \
              {                                                      \
                  EnterCriticalSection(&((mtsda)->mutex)) ;          \
              }

     #define  I_THREAD_WIN32_unlock(mtsda)                           \
              {                                                      \
                LeaveCriticalSection(&((mtsda)->mutex)) ;          \
                                                                   \
              }

     #define  I_THREAD_WIN32_setNotReady(mtsda)                      \
              {                                                      \
                (mtsda)->ready = FALSE ;                             \
              }

     #define  I_THREAD_WIN32_setReady(mtsda)                         \
              {                                                      \
                (mtsda)->ready = TRUE ;                              \
              }

     #define  I_THREAD_WIN32_signalReady(mtsda)                      \
              {                                                      \
                 (mtsda)->ready = TRUE ;                              \
                 SetEvent((mtsda)->event) ;                      \
              }

     #define  I_THREAD_WIN32_waitReady(mtsda)                        \
              {                                                      \
                while                                                  \
                (                                                    \
                  ((mtsda)->ready == FALSE)                          \
                                                                   \
                ) \
				{                                                    \
                  LeaveCriticalSection(&((mtsda)->mutex)) ;        \
                  WaitForSingleObject((mtsda)->event,INFINITE) ;     \
                  EnterCriticalSection(&((mtsda)->mutex)) ;          \
                }                                                    \
              }


  /* ..........................................................*/


#endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_THREAD_WIN32_M */

