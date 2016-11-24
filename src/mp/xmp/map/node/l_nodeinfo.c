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

      #include "mp/xmp/map/node/l_nodeinfo.h"


   /* ... Functions / Funciones ....................................... */

      T_CHAR *L_NODEINFO_x2yToString 
      ( 
        IN   int           *x2y 
      )
      {
        T_CHAR  *ret ;
        T_CHAR  *pstr ;
        T_INT    i ;

        /* ... set null ... */
        pstr = NULL ;

        /* ... add size - 1 ... */
        for (i=0; i<(MAX_SOCKS-1); i++)
            {
              ret = X_DTD_vBeginPutEnd(&pstr,"int","node2sock[]",
                                       "%i",(x2y)[i]) ;
              NULL_RET_NULL(ret) ;
              ret = X_DTD_addln(&pstr) ;
              NULL_RET_NULL(ret) ;
            }

        /* ... add last ... */
        ret  = X_DTD_vBeginPutEnd(&pstr,"int","node2sock[]",
                                  "%i",(x2y)[MAX_SOCKS]) ;
        NULL_RET_NULL(ret) ;

        /* ... return ... */
        return pstr ;
      }
     
      T_CHAR *L_NODEINFO_xHeaderToString 
      ( 
        IN   t_nodeHeader *xHeader 
      )
      {
        T_CHAR  *ret ;
        T_CHAR  *pstr, *pstr2 ;
        T_INT    i ;

        /* ... set to null ... */
        pstr = NULL ;

        /* ... add size - 1 ... */
        for (i=0; i<(MAX_SOCKS-1); i++)
            {
              pstr2 = L_NODEHEADER_nodeheaderToString( &(xHeader[i]) ) ;
              NULL_RET_NULL(pstr2) ;
              ret   = X_DTD_put(&pstr,pstr2) ;
              X_ALLOC_Free((void **)&(pstr2)) ;
              NULL_RET_NULL(ret) ;
              ret = X_DTD_addln(&pstr) ;
              NULL_RET_NULL(ret) ;
            }

        /* ... add last ... */
        pstr2 = L_NODEHEADER_nodeheaderToString( &(xHeader[i]) ) ;
        NULL_RET_NULL(pstr2) ;
        ret   = X_DTD_put(&pstr,pstr2) ;
        X_ALLOC_Free((void **)&(pstr2)) ;
        NULL_RET_NULL(ret) ;

        /* ... return ... */
        return pstr ;
      } 

      T_CHAR *L_NODEINFO_xReqliToString 
      ( 
        IN   t_reqli      *xReqli 
      )
      {
        T_CHAR  *ret ;
        T_CHAR  *pstr, *pstr2 ;
        T_INT    i ;

        /* ... set to null ... */
        pstr = NULL ;

        /* ... add size - 1 ... */
        for (i=0; i<(MAX_SOCKS-1); i++)
            {
              pstr2 = L_REQLI_reqliToString( &(xReqli[i]) ) ;
              NULL_RET_NULL(pstr2) ;
              ret   = X_DTD_put(&pstr,pstr2) ;
              X_ALLOC_Free((void **)&(pstr2)) ;
              NULL_RET_NULL(ret) ;
              ret = X_DTD_addln(&pstr) ;
              NULL_RET_NULL(ret) ;
            }

        /* ... add last ... */
        pstr2 = L_REQLI_reqliToString( &(xReqli[i]) ) ;
        NULL_RET_NULL(pstr2) ;
        ret   = X_DTD_put(&pstr,pstr2) ;
        X_ALLOC_Free((void **)&(pstr2)) ;
        NULL_RET_NULL(ret) ;

        /* ... return ... */
        return pstr ;
      }
     
      T_CHAR *L_NODEINFO_nodeinfoToString 
      ( 
        IN   t_nodeInfo *nodeinfo 
      )
      {
        T_CHAR  *ret ;
        T_CHAR  *pstr, *pstr2 ;


        if (nodeinfo == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        if (nodeinfo != NULL)
           {
             /* 
              *  set to null
              */
             pstr = NULL ;

             /* 
              * nodeid
              */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","nodeid",
                                       "%i",nodeinfo->nodeid) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * nnodes
              */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","nnodes",
                                       "%i",nodeinfo->nnodes) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * shutdown
              */
             ret  = X_DTD_vBeginPutEnd(&pstr,"boolean","shutdown",
                                       "%i",nodeinfo->shutdown) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * node2sock
              */
             ret  = X_DTD_begin(&pstr,"int[]","node2sock") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_NODEINFO_x2yToString(nodeinfo->node2sock) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"int[]","node2sock") ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * sock2node
              */
             ret  = X_DTD_begin(&pstr,"int[]","sock2node") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_NODEINFO_x2yToString(nodeinfo->sock2node) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"int[]","sock2node") ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * inHeader
              */
             ret  = X_DTD_begin(&pstr,"nodeHeader","inHeader") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_NODEINFO_xHeaderToString(nodeinfo->inHeader) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"nodeHeader","inHeader") ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * outHeader
              */
             ret  = X_DTD_begin(&pstr,"nodeHeader","outHeader") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_NODEINFO_xHeaderToString(nodeinfo->outHeader) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"nodeHeader","outHeader") ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * recvli
              */
             ret  = X_DTD_begin(&pstr,"reqli","recvli") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_NODEINFO_xReqliToString(nodeinfo->recvli) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"reqli","recvli") ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* 
              * sendli
              */
             ret  = X_DTD_begin(&pstr,"reqli","sendli") ;
             NULL_RET_NULL(ret) ;
             pstr2 = L_NODEINFO_xReqliToString(nodeinfo->sendli) ;
             NULL_RET_NULL(pstr2) ;
             ret  = X_DTD_put(&pstr,pstr2) ;
             X_ALLOC_Free((void **)&(pstr2)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_end(&pstr,"reqli","sendli") ;
             NULL_RET_NULL(ret) ;
           }
     
        /* 
         *  return 
         */
        return pstr ;
      }


  /* .................................................................... */

