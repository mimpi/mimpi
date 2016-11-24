/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_thread/i_thread_posix.h"


   /* ... Functions / Funciones ......................................... */


#if defined(HAVE_PTHREAD_H)

     /*
      *  Thread
      * --------
      */

     T_BOOL   I_THREAD_POSIX_createDetached
     (
       OUT  t_posix_thread   *thid,
       IN   t_posix_thcode    thcode,
       IN   void             *tharg
     )
     {
       pthread_attr_t attr ;
       int ret ;

       /*
        *  check params
        */
       NULL_RET_FALSE(thid) ;

       /*
        *  setup thread attr
        */
       pthread_attr_init(&attr);
       pthread_attr_setscope(&attr,
		             PTHREAD_SCOPE_SYSTEM) ;
       pthread_attr_setdetachstate(&attr, 
		             PTHREAD_CREATE_DETACHED) ;
       pthread_attr_setschedpolicy(&attr, 
		             SCHED_OTHER) ;

       /*
        *  create thread
        */
       ret = pthread_create( thid, &attr, thcode, tharg ) ;
       if (ret < 0)
          {
            L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"pthread_create:") ;
            return FALSE ;
          }

       /*
        *  return ok
        */
       return TRUE ;
     }

     T_BOOL   I_THREAD_POSIX_createJoinable
     (
       OUT  t_posix_thread   *thid,
       IN   t_posix_thcode    thcode,
       IN   void             *tharg
     )
     {
       pthread_attr_t attr ;
       int ret ;

       /*
        *  check params
        */
       NULL_RET_FALSE(thid) ;

       /*
        *  setup thread attr
        */
       pthread_attr_init(&attr);
       pthread_attr_setscope(&attr,
		             PTHREAD_SCOPE_SYSTEM) ;
       pthread_attr_setdetachstate(&attr, 
		             PTHREAD_CREATE_JOINABLE) ;
       pthread_attr_setschedpolicy(&attr, 
		             SCHED_OTHER) ;

       /*
        *  create thread
        */
       ret = pthread_create( thid, &attr, thcode, tharg ) ;
       if (ret < 0)
          {
            L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"pthread_create:") ;
            return FALSE ;
          }

       /*
        *  return ok
        */
       return TRUE ;
     }

     T_BOOL   I_THREAD_POSIX_join
     (
       IN   t_posix_thread    thid,
       OUT  void            **thret
     )
     {
       int ret ;

       /*
        *  join thread
        */
       ret = pthread_join(thid,thret) ;
       if (ret < 0)
          {
            L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"pthread_join:") ;
            return FALSE ;
          }

       /*
        *  return ok
        */
       return TRUE ;
     }


     /*  mtsdaToXZY  *
      * ------------ */
     T_CHAR  *I_THREAD_POSIX_mtsdaToString   
     ( 
       IN   t_posix_mtsda  *mtsda 
     )
     {
        T_CHAR  *pstr ;
        T_CHAR  *ret ;
        T_INT    mstat ;

       /*
        *  NULL mtsda value.
        */
        if (mtsda == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

       /*
        *  build mtsda value.
        */
        if (mtsda != NULL)
           {
             /* ... set to null ... */
             pstr = NULL ;
     
             /* ... add boolean ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"bool","ready",
                                       "%i",(mtsda)->ready) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
     
             /* ... add lock ... */
             mstat = pthread_mutex_trylock( &((mtsda)->mutex) ) ;
             switch (mstat)
             {
               case EBUSY :
                    ret  = X_DTD_vBeginPutEnd(&pstr,"pMutex","mutex",
                                              "lock") ;
                    break ;
               case EINVAL :
                    ret  = X_DTD_vBeginPutEnd(&pstr,"pMutex","mutex",
                                              "invalid") ;
                    break ;
               default : ; 
                    pthread_mutex_unlock( &((mtsda)->mutex) ) ;
                    ret  = X_DTD_vBeginPutEnd(&pstr,"pMutex","mutex",
                                              "unlock") ;
                    break ;
             }
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
     
             /* ... add cond ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"pCond","cond",
                                       "%p",(void *)&((mtsda)->cond)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
           }

       /*
        *  return dtd
        */
        return pstr ;
     }

#endif


/* ...................................................................... */

