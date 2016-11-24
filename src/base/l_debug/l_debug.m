

 #ifndef L_DEBUG_M
 #define L_DEBUG_M


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"


   /* ... Inline / Expansiones .......................................... */
      
      #define XCHECK_RET_XRET(xcheck,xl,xret,xmsg)                    \
              {                                                       \
                if ((xcheck))                                         \
                   {                                                  \
                     L_DEBUG_MSG_Write(xl,FALSE,(xmsg)) ;             \
                     return (xret) ;                                  \
                   }                                                  \
              } 


      /*  TRUE condition  *
       * ---------------- */
      #define TRUE__SET_ERROR__RET_LONG(cond,xlong)                   \
              XCHECK_RET_XRET((cond)==TRUE,DBG_ERROR,xlong,#cond)
      #define TRUE__SET_WARNING__RET_LONG(cond,xlong)                 \
              XCHECK_RET_XRET((cond)==TRUE,DBG_WARNING,xlong,#cond)
      #define TRUE__SET_INFO__RET_LONG(cond,xlong)                    \
              XCHECK_RET_XRET((cond)==TRUE,DBG_INFO,xlong,#cond)


      /*  NULL value  *
       * ------------ */
      #define NULL__SET_ERROR__RET_NULL(ptr)                          \
              XCHECK_RET_XRET((ptr)==NULL,DBG_ERROR,NULL,#ptr" == NULL")
      #define NULL__SET_ERROR__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==NULL,DBG_ERROR,TRUE,#ptr" == NULL")
      #define NULL__SET_ERROR__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==NULL,DBG_ERROR,FALSE,#ptr" == NULL")
      #define NULL__SET_WARNING__RET_NULL(ptr)                          \
              XCHECK_RET_XRET((ptr)==NULL,DBG_WARNING,NULL,#ptr" == NULL")
      #define NULL__SET_WARNING__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==NULL,DBG_WARNING,TRUE,#ptr" == NULL")
      #define NULL__SET_WARNING__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==NULL,DBG_WARNING,FALSE,#ptr" == NULL")
      #define NULL__SET_INFO__RET_NULL(ptr)                          \
              XCHECK_RET_XRET((ptr)==NULL,DBG_INFO,NULL,#ptr" == NULL")
      #define NULL__SET_INFO__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==NULL,DBG_INFO,TRUE,#ptr" == NULL")
      #define NULL__SET_INFO__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==NULL,DBG_INFO,FALSE,#ptr" == NULL")


      /*  TRUE value  *
       * ------------ */
      #define TRUE__SET_ERROR__RET_NULL(ptr)                          \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_ERROR,NULL,#ptr" == NULL")
      #define TRUE__SET_ERROR__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_ERROR,TRUE,#ptr" == NULL")
      #define TRUE__SET_ERROR__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_ERROR,FALSE,#ptr" == NULL")
      #define TRUE__SET_WARNING__RET_NULL(ptr)                          \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_WARNING,NULL,#ptr" == NULL")
      #define TRUE__SET_WARNING__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_WARNING,TRUE,#ptr" == NULL")
      #define TRUE__SET_WARNING__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_WARNING,FALSE,#ptr" == NULL")
      #define TRUE__SET_INFO__RET_NULL(ptr)                          \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_INFO,NULL,#ptr" == NULL")
      #define TRUE__SET_INFO__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_INFO,TRUE,#ptr" == NULL")
      #define TRUE__SET_INFO__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==TRUE,DBG_INFO,FALSE,#ptr" == NULL")


      /*  FALSE value  *
       * ------------- */
      #define FALSE__SET_ERROR__RET_FALSE(ptr)                          \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_ERROR,FALSE,#ptr" == FALSE")
      #define FALSE__SET_ERROR__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_ERROR,TRUE,#ptr" == FALSE")
      #define FALSE__SET_ERROR__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_ERROR,FALSE,#ptr" == FALSE")
      #define FALSE__SET_WARNING__RET_FALSE(ptr)                          \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_WARNING,FALSE,#ptr" == FALSE")
      #define FALSE__SET_WARNING__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_WARNING,TRUE,#ptr" == FALSE")
      #define FALSE__SET_WARNING__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_WARNING,FALSE,#ptr" == FALSE")
      #define FALSE__SET_INFO__RET_FALSE(ptr)                          \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_INFO,FALSE,#ptr" == FALSE")
      #define FALSE__SET_INFO__RET_TRUE(ptr)                          \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_INFO,TRUE,#ptr" == FALSE")
      #define FALSE__SET_INFO__RET_FALSE(ptr)                         \
              XCHECK_RET_XRET((ptr)==FALSE,DBG_INFO,FALSE,#ptr" == FALSE")


   /* ................................................................... */


 #endif

