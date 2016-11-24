/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusiones ....................................... */

      #include "mp/xmp/map/node/l_nodes/l_reqman/l_reqli.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL      L_REQLI_init
      (
        OUT   t_reqli    *reqli
      )
      {
        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin L_REQLI_init") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(reqli) ;

        /*
         *  set values
         */
        reqli->head   = NULL ;
        reqli->tail   = NULL ;
        reqli->nreqli = 0 ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"end L_REQLI_init") ;

        /*
         *  allways true
         */
        return TRUE ;
      }

      T_BOOL      L_REQLI_finalize
      (
        OUT   t_reqli    *reqli
      )
      {
        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin L_REQLI_finalize") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(reqli) ;

        /*
         *  reset values
         */
        reqli->head = NULL ;
        reqli->tail = NULL ;
        reqli->nreqli = 0 ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"end L_REQLI_finalize") ;

        /*
         *  allways true
         */
        return TRUE ;
      }

      T_BOOL      L_REQLI_isEmpty
      (
        IN    t_reqli    *reqli
      )
      {
        /*
         *  true if no elements.
         */
        NULL_RET_TRUE((reqli)) ;
        NULL_RET_TRUE((reqli->head)) ;

        /*
         *  else, false.
         */
        return FALSE ;
      }

      t_reqRef   *L_REQLI_first
      (
        IN    t_reqli    *reqli
      )
      {
        /*
         *  null if no elements
         */
        NULL_RET_NULL(reqli) ;

        /*
         *  else, first
         */
        return reqli->head ;
      }

      t_reqRef   *L_REQLI_next
      (
        IN    t_reqRef   *elto
      )
      {
        /*
         *  null if no elements
         */
        NULL_RET_NULL(elto) ;

        /*
         *  else, next
         */
        return elto->before ;
      }

      T_BOOL      L_REQLI_insert
      (
        IN    t_reqli    *reqli,
        IN    t_reqRef   *elto
      )
      {
        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin L_REQLI_insert") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(reqli) ;
        NULL__SET_ERROR__RET_FALSE(elto) ;

        /*
         *  link into list
         */
         (elto->before) = NULL ;
         (elto->after)  = reqli->tail ;
         if ( (reqli->tail) != NULL)
              (reqli->tail)->before = elto ;
         reqli->tail = elto ;
         if (reqli->head == NULL)
             reqli->head = elto ;
         reqli->nreqli++ ;

        /*
         *  setup req info
         */
         L_NODEREQ_addLink((elto->req)) ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"end L_REQLI_insert") ;

        /*
         *  all ok.
         */
        return TRUE ;
      }

      T_BOOL      L_REQLI_delete
      (
        IN    t_reqli    *reqli,
        IN    t_reqRef   *elto
      )
      {
        t_reqRef  *eltoAux ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin L_REQLI_delete") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(reqli) ;
        NULL__SET_ERROR__RET_FALSE(elto) ;

        /*
         *  search elto
         */
        for (eltoAux=reqli->head; eltoAux!=NULL; eltoAux=eltoAux->before)
            {
              if (eltoAux == elto)
                 {

                    /*
                     * unlink from list
                     */
		    if ((elto->after) != NULL)
		        (elto->after)->before = elto->before ;
		    if ((elto->before) != NULL)
		        (elto->before)->after = elto->after ;
		    if (reqli->head == elto)
		       {
		         reqli->head = elto->before ;
		         if (reqli->head != NULL)
		             (reqli->head)->after = NULL ;
		       }
		    if (reqli->tail == elto)
		       {
		         reqli->tail = elto->after ;
		         if (reqli->tail != NULL)
		             (reqli->tail)->before = NULL ;
		       }
                    (reqli->nreqli)-- ;

                    /*
                     *  setup req info
                     */
                    L_NODEREQ_subLink(&(elto->req)) ;
                    if (elto->isMalloc == TRUE)
                        free(elto) ;

                    /*
                     *  return
                     */
		    return TRUE ;

                 }
            }

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"end L_REQLI_delete") ;

        /*
         *  elto not found
         */
        return FALSE ;
      }

      T_BOOL      L_REQLI_allocReqAndInsert
      (
        IN    t_reqli    *reqli,
        OUT   t_reqRef  **elto
      )
      {
        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"begin L_REQLI_allocReqAndInsert") ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(reqli) ;
        NULL__SET_ERROR__RET_FALSE(elto) ;

        /*
         *  plan_A : try reuse a served request
         */
        for ((*elto)=reqli->head; (*elto)!=NULL; (*elto)=(*elto)->before)
            {
               if ( 
                    (((*elto)->req)->isServed == TRUE)
                                   &&
                    ((*elto)->isMalloc == TRUE)
                  )
                  {
                    if ( ((*elto)->req) != NULL )
                       {
                         L_NODEREQ_subLink(&((*elto)->req)) ;
                       }
                    return TRUE ;
                  }
            }

        /*
         *  plan_B : insert a new request
         */
        (*elto) = malloc( c_RECVREQ ) ;
        NULL_RET_FALSE((*elto)) ;
        ((*elto)->isMalloc) = TRUE ;
        ((*elto)->before)   = NULL ;
        ((*elto)->after)    = reqli->tail ;
        if ( (reqli->tail) != NULL)
             (reqli->tail)->before = (*elto) ;
        reqli->tail = (*elto) ;
        if (reqli->head == NULL)
            reqli->head = (*elto) ;
        reqli->nreqli++ ;

        /*
         *  trace
         */
        L_TRACE_MSG_PrintF(DEFCON_1,"end L_REQLI_allocReqAndInsert") ;

        /*
         *  allways true
         */
        return TRUE ;
      }

      T_CHAR     *L_REQLI_reqrefToString
      (
        IN    t_reqRef   *elto
      )
      {
        T_CHAR *ret ;
        T_CHAR *pstr, *pstr2 ;

        /*
         *  NULL value.
         */
        if (elto == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        /*
         *  build value.
         */
        if (elto != NULL)
           {
             /* ... set to null ... */
             pstr = NULL ;

             /* ... add subdtd ... */
             pstr2 = L_NODEREQ_nodereqToString(elto->req) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"boolean","isMalloc",
                                       "%i",elto->isMalloc) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
           }

        /*
         *  return string
         */
        return pstr ;
      }

      T_CHAR     *L_REQLI_xReqToString
      (
        IN    t_reqli    *reqli
      )
      {
        T_BOOL     isEmpty ;
        T_CHAR    *ret ;
        T_CHAR    *pstr, *pstr2 ;
        t_reqRef  *eltoAux ;

        /*
         *  NULL value.
         */
        isEmpty = L_REQLI_isEmpty(reqli) ;
        if (isEmpty == TRUE)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        /*
         *  build value.
         */
        if (isEmpty != TRUE)
           {
             /* ... set to null ... */
             pstr = NULL ;

             /* ... add subdtd ... */
             for (eltoAux=reqli->head; eltoAux!=NULL; eltoAux=eltoAux->before)
                 {
                   ret  = X_DTD_begin(&pstr,"reqref","reqli[]") ;
                   NULL_RET_NULL(ret) ;
                   pstr2 = L_REQLI_reqrefToString(eltoAux) ;
                   NULL_RET_NULL(pstr2) ;
                   ret  = X_DTD_put(&pstr,pstr2) ;
                   X_ALLOC_Free((void **)&(pstr2)) ;
                   NULL_RET_NULL(ret) ;
                   ret  = X_DTD_end(&pstr,"reqref","reqli[]") ;
                   NULL_RET_NULL(ret) ;
                   ret  = X_DTD_addln(&pstr) ;
                   NULL_RET_NULL(ret) ;
                 }
           }

        /*
         *  return string
         */
        return pstr ;
      }

      T_CHAR     *L_REQLI_reqliToString
      (
        IN    t_reqli    *reqli
      )
      {
        T_CHAR *ret ;
        T_CHAR *pstr, *pstr2 ;

        /*
         *  NULL value.
         */
        if (reqli == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        /*
         *  build value.
         */
        if (reqli != NULL)
           {
             /* ... set to null ... */
             pstr = NULL ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","nreqli",
                                       "%i",reqli->nreqli) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret   = X_DTD_begin(&pstr,"req[]","req[]") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_REQLI_xReqToString(reqli) ;
             NULL_RET_NULL(pstr2) ;
             ret   = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret   = X_DTD_end(&pstr,"req[]","req[]") ;
             NULL_RET_NULL(ret) ;
           }

        /*
         *  return string
         */
        return pstr ;
      }


  /* .................................................................... */

