

 #ifndef C_THREAD_RET_H
 #define C_THREAD_RET_H


   /* ... Include / Inclusiones ......................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Macros / Macros ............................................... */

      #define NULL_UNLOCK_RET_NULL(p,c)      \
              if (!(p)) { X_THREAD_unlock((c)) ; return NULL ; }
      #define NULL_UNLOCK_RET_TRUE(p,c)      \
              if (!(p)) { X_THREAD_unlock((c)) ; return TRUE ; }
      #define NULL_UNLOCK_RET_FALSE(p,c)     \
              if (!(p)) { X_THREAD_unlock((c)) ; return FALSE ; }

      #define FALSE_UNLOCK_RET_TRUE(p,c)     \
              if ((p)==FALSE) { X_THREAD_unlock((c)) ; return TRUE ; }
      #define FALSE_UNLOCK_RET_FALSE(p,c)    \
              if ((p)==FALSE) { X_THREAD_unlock((c)) ; return FALSE ; }
      #define TRUE_UNLOCK_RET_TRUE(p,c)      \
              if ((p)==TRUE)  { X_THREAD_unlock((c)) ; return TRUE ; }
      #define TRUE_UNLOCK_RET_FALSE(p,c)     \
              if ((p)==TRUE)  { X_THREAD_unlock((c)) ; return FALSE ; }

      #define FALSE_UNLOCK_RET_NULL(p,c)     \
              if ((p)==FALSE) { X_THREAD_unlock((c)) ; return NULL ; }
      #define TRUE_UNLOCK_RET_NULL(p,c)      \
              if ((p)==TRUE)  { X_THREAD_unlock((c)) ; return NULL ; }


   /* ................................................................... */

 #endif


