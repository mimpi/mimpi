

 #ifndef C_RET_H
 #define C_RET_H


   /* ... Include / Inclusiones ......................................... */

      #include "base/l_basic/l_lang/c_type.h"


   /* ... Macros / Macros ............................................... */

      #define NULL_RET_NULL(p)      \
              if (!(p)) { return NULL ; }
      #define NULL_RET_TRUE(p)      \
              if (!(p)) { return TRUE ; }
      #define NULL_RET_FALSE(p)     \
              if (!(p)) { return FALSE ; }

      #define FALSE_RET_TRUE(p)     \
              if ((p)==FALSE) { return TRUE ; }
      #define FALSE_RET_FALSE(p)    \
              if ((p)==FALSE) { return FALSE ; }
      #define TRUE_RET_TRUE(p)      \
              if ((p)==TRUE)  { return TRUE ; }
      #define TRUE_RET_FALSE(p)     \
              if ((p)==TRUE)  { return FALSE ; }

      #define FALSE_RET_NULL(p)     \
              if ((p)==FALSE) { return NULL ; }
      #define TRUE_RET_NULL(p)      \
              if ((p)==TRUE)  { return NULL ; }


   /* ................................................................... */


 #endif


