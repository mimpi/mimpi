
/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2001)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_thread/l_thread_pool.h"


   /* ................................................................... */

     /*
      *  thread elto
      *  -----------
      */

     t_thread_pool_elto    *L_THREAD_POOL_ELTO_Creat
     (
       IN     T_U_LONG       me,
       IN     T_U_LONG       nextFree,
       IN     t_thread_pool *list
     )
     {
        T_BOOL               ok ;
        t_thread_pool_elto  *telto ;

        /*
         *  alloc
         */
        telto = X_ALLOC_Malloc(c_THREAD_POOL_ELTO) ;
        NULL_RET_NULL(telto) ;

        /*
         *  set
         */
        telto->pf        = NULL ;
        telto->pf_params = NULL ;
        telto->pf_return = NULL ;
        V_THREAD_init( &(telto->begin) ) ;
        V_THREAD_init( &(telto->end) ) ;
        V_THREAD_init( &(telto->joined) ) ;
        telto->me        = me ;
        telto->nextFree  = nextFree ;
        telto->list      = (t_thread_pool_pointer) list ;
        ok = V_THREAD_createDetached( &(telto->tid),
                                       (t_thcode)L_THREAD_POOL_ELTO_core,
                                       (void   *)telto ) ;
        if (FALSE == ok)
           {
             V_THREAD_destroy( &(telto->begin) ) ;
             V_THREAD_destroy( &(telto->end) ) ;
             V_THREAD_destroy( &(telto->joined) ) ;
             return NULL ;
           }

        /*
         *  return
         */
        return telto ;
     }

      T_BOOL          L_THREAD_POOL_ELTO_Finalize
      (
        INOUT  t_thread_pool_elto   *telto
      )
      {
        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(telto) ;

        /*
         *  destroy
         */
        telto->pf_return = NULL ;
        V_THREAD_destroy( &(telto->begin) ) ;
        V_THREAD_destroy( &(telto->end) ) ;
        V_THREAD_destroy( &(telto->joined) ) ;

        /*
         *  return
         */
        return TRUE ;
      }

      void *          L_THREAD_POOL_ELTO_core
      (
        IN     void    *tparams
      )
      {
        t_thread_pool_elto  *telto ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_NULL(tparams) ;
        telto = (t_thread_pool_elto *)tparams ;

        /*
         *  servering execution ...
         */
        while ( TRUE )
        {
          /* 1.- wait begin */
              V_THREAD_waitReady( &(telto->begin) ) ;
          if (V_THREAD_isDestroy( &(telto->begin) ))
               break ;

          /* 2.- signal end */
          if (NULL != telto->pf)
              telto->pf_return = telto->pf(telto->pf_params) ;
          V_THREAD_signalReady( &(telto->end) ) ;

          /* 3.- wait joined */
              V_THREAD_waitReady( &(telto->joined) ) ;
          if (V_THREAD_isDestroy( &(telto->joined) ))
               break ;

          /* 4.- prepare next iteration */
          V_THREAD_setNotReady( &(telto->begin) ) ;
          V_THREAD_setNotReady( &(telto->end) ) ;
          V_THREAD_setNotReady( &(telto->joined) ) ;
          L_THREAD_POOL_LIST_insertFree( (t_thread_pool *)telto->list,
                                                          telto->me ) ;
        }

        /*
         *  return
         */
        return NULL ;
      }


     /*
      *  thread list
      *  -----------
      */

     t_thread_pool    *L_THREAD_POOL_LIST_Creat
     (
       void
     )
     {
        t_thread_pool  *lpaux ;

        /*
         *  alloc  ...
         */
        lpaux = X_ALLOC_Malloc(c_THREAD_POOL) ;
        NULL_RET_NULL(lpaux) ;

        /*
         *  ... and set
         */
        lpaux->list      = NULL ;
        lpaux->neltos    = 0L   ;
        lpaux->firstFree = 0L   ;
        V_THREAD_init( &(lpaux->monitor) ) ;

        /*
         *  return
         */
        return lpaux ;
     }

      T_BOOL          L_THREAD_POOL_LIST_Destroy
      (
        INOUT  t_thread_pool  **tcache
      )
      {
        T_U_LONG  i ;
        T_BOOL    ok ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(tcache) ;
        NULL_RET_TRUE((*tcache)) ;

        /*
         *  destroy list
         */
        for (i=0; i<(**tcache).neltos; i++)
            {
              ok = L_THREAD_POOL_ELTO_Finalize( (**tcache).list[i] ) ;
              FALSE_RET_FALSE(ok) ;
            }

        /*
         *  destroy itselft
         */
        V_THREAD_destroy( &((*tcache)->monitor) ) ;
        X_ALLOC_Free((void **)&((*tcache)->list)) ;
        X_ALLOC_Free((void **)(tcache)) ;

        /*
         *  return
         */
        return TRUE ;
      }

      T_BOOL               L_THREAD_POOL_LIST_insertFree
      ( 
        INOUT  t_thread_pool       *tcache,
        IN     T_U_LONG             index
      ) 
      {
        /*
         *  check params
         */
        NULL_RET_FALSE(tcache) ;
        TRUE_RET_FALSE((index >= tcache->neltos)) ;

        /*
         *  get first free
         */
        V_THREAD_lock( &(tcache->monitor) ) ;
        ((tcache->list)[index])->nextFree = tcache->firstFree ;
        tcache->firstFree                 = index ;
        V_THREAD_unlock( &(tcache->monitor) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL               L_THREAD_POOL_LIST_addFree
      ( 
        INOUT  t_thread_pool       *tcache,
        IN     T_U_LONG             nToAdd
      ) 
      {
        t_thread_pool_elto **newList ;
        T_U_LONG             newNEltos ;
        T_U_LONG             firstFree ;
        T_U_LONG             i ;

        /*
         *  check params
         */
        NULL_RET_FALSE(tcache) ;

        /*
         *  alloc list
         */
        newNEltos = tcache->neltos + nToAdd ;
        newList   = X_ALLOC_Realloc( tcache->list,
                                     newNEltos * c_THREAD_POOL_ELTO ) ;
        NULL_RET_FALSE(newList) ;

        /*
         *  alloc eltos
         */
        firstFree = tcache->firstFree ;
        for (i=tcache->neltos; i<newNEltos; i++)
        {
          newList[i] = L_THREAD_POOL_ELTO_Creat(i,
                                                firstFree,
                                                tcache) ;
          firstFree  = i ;
        }
        tcache->firstFree = firstFree ;
        tcache->neltos    = newNEltos ;
        tcache->list      = newList ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      t_thread_pool_elto *L_THREAD_POOL_LIST_removeFree
      ( 
        INOUT  t_thread_pool       *tcache
      ) 
      {
        T_BOOL               ok ;
        T_U_LONG             firstFree ;
        t_thread_pool_elto  *telto ;

        /*
         *  check params
         */
        NULL_RET_FALSE(tcache) ;

        /*
         *  return first free
         */
        V_THREAD_lock( &(tcache->monitor) ) ;
        if (0L == tcache->firstFree)
           {
             ok = L_THREAD_POOL_LIST_addFree(tcache,THREAD_BUCKET) ;
             if (FALSE == ok)
                {
                  V_THREAD_unlock( &(tcache->monitor) ) ;
                  return NULL ;
                }
           }
        firstFree          =  tcache->firstFree ;
        telto              = (tcache->list)[firstFree] ;
        tcache->firstFree  =  telto->nextFree ;
        V_THREAD_unlock( &(tcache->monitor) ) ;

        /*
         *  return elto
         */
        return telto ;
      }

      t_thread_pool_elto *L_THREAD_POOL_LIST_getElto
      ( 
        INOUT  t_thread_pool       *tcache,
        IN     long                 index
      ) 
      {
        t_thread_pool_elto *telto ;

        /*
         *  check params
         */
        NULL_RET_FALSE(tcache) ;
        TRUE_RET_NULL((index >= (tcache->neltos))) ;

        /*
         *  return elto
         */
        V_THREAD_lock( &(tcache->monitor) ) ;
        telto = (tcache->list)[index] ;
        V_THREAD_unlock( &(tcache->monitor) ) ;

        /*
         *  return elto
         */
        return telto ;
      }


   /* ................................................................... */

