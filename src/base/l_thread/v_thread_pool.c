
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

      #include "base/l_thread/v_thread_pool.h"


   /* ... Glob Var / Var Glob ........................................... */

      T_BOOL          V_THREAD_POOL_LIST_listIsInit = FALSE ;
      t_thread_pool  *V_THREAD_POOL_LIST_list ;


   /* ................................................................... */

      T_BOOL   V_THREAD_POOL_init
      (
        void
      )
      {
        if (FALSE == V_THREAD_POOL_LIST_listIsInit)
           {
             V_THREAD_POOL_LIST_list = L_THREAD_POOL_LIST_Creat() ;
             V_THREAD_POOL_LIST_listIsInit = TRUE ;
           }

        NULL_RET_FALSE(V_THREAD_POOL_LIST_list) ;
        return TRUE ;
      }

      T_BOOL   V_THREAD_POOL_finalize
      (
        void
      )
      {
        T_BOOL    ok ;

        ok = FALSE ;
        if (TRUE == V_THREAD_POOL_LIST_listIsInit)
           {
             ok = L_THREAD_POOL_LIST_Destroy( &V_THREAD_POOL_LIST_list ) ;
             V_THREAD_POOL_LIST_listIsInit = FALSE ;
           }

        return ok ;
      }

      T_BOOL   V_THREAD_POOL_createDetached
      (
        OUT  t_thread_id  *thid,
        IN   t_thcode     thcode,
        IN   void         *tharg
      )
      {
        t_thread_pool_elto *telto ;

        /*
         *  check params
         */
        NULL_RET_FALSE(thid) ;
        NULL_RET_FALSE(thcode) ;

        /*
         *  alloc thread from free list
         */
        if (FALSE == V_THREAD_POOL_LIST_listIsInit)
            V_THREAD_POOL_init() ;
        telto = L_THREAD_POOL_LIST_removeFree(V_THREAD_POOL_LIST_list) ;
        NULL_RET_FALSE(telto) ;
        (*thid) = (telto)->me ;

        /*
         *  go
         */
        telto->pf        = thcode ;
        telto->pf_params = tharg ;
        V_THREAD_signalReady( &(telto->begin) ) ;
        V_THREAD_signalReady( &(telto->joined) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   V_THREAD_POOL_createJoinable
      (
        OUT  t_thread_id *thid,
        IN   t_thcode     thcode,
        IN   void        *tharg
      )
      {
        t_thread_pool_elto *telto ;

        /*
         *  check params
         */
        NULL_RET_FALSE(thid) ;
        NULL_RET_FALSE(thcode) ;

        /*
         *  alloc thread from free list
         */
        if (FALSE == V_THREAD_POOL_LIST_listIsInit)
            V_THREAD_POOL_init() ;
        telto = L_THREAD_POOL_LIST_removeFree(V_THREAD_POOL_LIST_list) ;
        NULL_RET_FALSE(telto) ;
        (*thid) = (telto)->me ;

        /*
         *  go
         */
        telto->pf        = thcode ;
        telto->pf_params = tharg ;
        V_THREAD_signalReady( &(telto->begin) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   V_THREAD_POOL_join
      (
        IN   t_thread_id     thid,
        OUT  void          **thret
      )
      {
        t_thread_pool_elto *telto ;

        /*
         *  check params
         */
        NULL_RET_FALSE(thret) ;

        /*
         *  get thid-th thread from list
         */
        telto = L_THREAD_POOL_LIST_getElto(V_THREAD_POOL_LIST_list,thid) ;
        NULL_RET_FALSE(telto) ;

        /*
         *  wait
         */
        V_THREAD_waitReady( &(telto->end) ) ;
        (*thret) = telto->pf_return ;
        V_THREAD_signalReady( &(telto->joined) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................... */

