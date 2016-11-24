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

      #include "mp/xmp/map/node/l_nodereq.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL      L_NODEREQ_init
      ( 
        INOUT    t_nodeReq  *nodereq 
      )
      {
        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(nodereq) ;

        /* 
         *  fill with defaults
         */
        nodereq->requestId = 1 ;
        nodereq->to = 0 ;
        nodereq->from = 0 ;
        nodereq->tagX = 0 ;
        nodereq->tagY = 0 ;
        nodereq->data_size = 0 ;
        nodereq->data_buff = NULL ;
        nodereq->code = 0 ;
        nodereq->ret_size = 0 ;
        nodereq->ch = 0 ;
        nodereq->isMalloc = FALSE ;
        nodereq->isServed = FALSE ;
        nodereq->nlinks = 0L ;
        nodereq->reqptr = nodereq ;
        X_THREAD_init( &(nodereq->mtsda) ) ;

        /*
         *  allways true
         */
        return TRUE ;
      }

      T_BOOL      L_NODEREQ_init_2
      ( 
        INOUT    t_nodeReq  *nodereq,
        IN       T_INT       reqid,
        IN       int         tx,
        IN       int         ty,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      )
      {
        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(nodereq) ;

        /* 
         *  fill with defaults
         */
        nodereq->requestId = reqid ;
        nodereq->to   = to ;
        nodereq->from = from ;
        nodereq->tagX = tx ;
        nodereq->tagY = ty ;
        nodereq->data_size = data_size ;
        nodereq->data_buff = data_buff ;
        nodereq->code = 0 ;
        nodereq->ret_size = 0 ;
        nodereq->ch = 0 ;
        nodereq->isMalloc = FALSE ;
        nodereq->isServed = FALSE ;
        nodereq->nlinks = 0L ;
        nodereq->reqptr = nodereq ;
        X_THREAD_init( &(nodereq->mtsda) ) ;

        /*
         *  allways true
         */
        return TRUE ;
      }

      t_nodeReq  *L_NODEREQ_new
      ( 
        void
      )
      {
         t_nodeReq  *result ;

        /* 
         *  request memory
         */
        result = X_ALLOC_Malloc(c_NODEREQ) ;
        NULL_RET_NULL(result) ;

        /* 
         *  set values 
         */
        L_NODEREQ_init(result) ;
        result->isMalloc = TRUE ;

        /*
         *  return result
         */
        return result ;
      }

      t_nodeReq  *L_NODEREQ_dup
      ( 
        INOUT    t_nodeReq  *nodereq 
      )
      {
         t_nodeReq  *result ;

        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(nodereq) ;

        /* 
         *  request memory
         */
        result = X_ALLOC_MemDup(nodereq,c_NODEREQ) ;
        NULL_RET_FALSE(result) ;

        /* 
         *  set values 
         */
        result->isMalloc = TRUE ;
        X_THREAD_init( &(result->mtsda) ) ;

        /*
         *  return result
         */
        return result ;
      }

      T_CHAR  *L_NODEREQ_nodereqToString   
      ( 
        IN       t_nodeReq  *nodereq 
      )
      {
        T_CHAR *ret ;
        T_CHAR *pstr, *pstr2 ;

        /*
         *  NULL value.
         */
        if (nodereq == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        /*
         *  build value.
         */
        if (nodereq != NULL)
           {
             /* ... set to null ... */
             pstr = NULL ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","requestId",
                                       "%i",nodereq->requestId) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","to",
                                       "%i",nodereq->to) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","from",
                                       "%i",nodereq->from) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","tagX",
                                       "%i",nodereq->tagX) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","tagY",
                                       "%i",nodereq->tagY) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","data_size",
                                       "%i",nodereq->data_size) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"pointer","data_buff",
                                       "%p",nodereq->data_buff) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","code",
                                       "%i",nodereq->code) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","ret_size",
                                       "%i",nodereq->ret_size) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","ch",
                                       "%i",nodereq->ch) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"boolean","isMalloc",
                                       "%i",nodereq->isMalloc) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"boolean","isServed",
                                       "%i",nodereq->isServed) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","nlinks",
                                       "%i",nodereq->nlinks) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"pointer","reqptr",
                                       "%i",nodereq->reqptr) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_begin(&pstr,"mtsda","mtsda") ;
             NULL_RET_NULL(ret) ;
             pstr2 = X_THREAD_mtsdaToString(&(nodereq->mtsda)) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"mtsda","mtsda") ;
             NULL_RET_NULL(ret) ;
           }

        /*
         *  return pstr
         */
        return pstr ;
      }

      T_BOOL      L_NODEREQ_addLink
      (
        INOUT    t_nodeReq  *nodereq
      )
      {
        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(nodereq) ;

        /*
         *  incr. links 
         */
        ((nodereq)->nlinks)++ ;

        /*
         *  allways true
         */
        return TRUE ;
      }

      /**
       *
       *  Decrementa el numero de referencias.
       *
       */
      T_BOOL      L_NODEREQ_subLink
      (
        INOUT    t_nodeReq  **nodereq 
      )
      {
        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(nodereq) ;
        NULL__SET_ERROR__RET_FALSE((*nodereq)) ;

        /*
         *  decr. links 
         */
        ((*nodereq)->nlinks)-- ;
        if (((*nodereq)->nlinks) == 0)
           {
             if (((*nodereq)->isMalloc) == TRUE)
                {
                  X_THREAD_destroy( &((*nodereq)->mtsda) ) ;
                  X_ALLOC_Free((void **)nodereq) ;
                }
           }

        /*
         *  allways true
         */
        return TRUE ;
      }


  /* .................................................................... */



