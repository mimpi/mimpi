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

      #include "mp/xmp/map/node/l_nodes/l_nodei/l_nodeheader.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODEHEADER_nodeheaderInit
      (
        INOUT  t_nodeHeader  *header
      )
      {
        /*
         *  set values
         */
        header->size = 0 ;
        header->tagX = 0 ;
        header->tagY = 0 ;
        header->id   = NH_NOP ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_CHAR  *L_NODEHEADER_codeToString       
      ( 
        IN     T_INT          code 
      )
      {
        /*
         *  to string 
         */
        switch (code)
        {
          case NH_NOP :
               return "NH_NOP" ;
               break ;
          case NH_DATA :
               return "NH_DATA" ;
               break ;
          default : ;
        }

        /*
         *  return unknow 
         */
        return "NH_UNKNOW" ;
      }

      T_CHAR  *L_NODEHEADER_nodeheaderToString
      (
        IN    t_nodeHeader  *header
      )
      {
        T_CHAR *ret ;
        T_CHAR *pstr ;

        /*
         *  NULL nodeHeader value.
         */
        if (header == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        /*
         *  build nodeHeader value.
         */
        if (header != NULL)
           {
             /* ... set to null ... */
             pstr = NULL ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","hId",
                                       "%s",
                                       L_NODEHEADER_codeToString(header->id)) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","size",
                                       "%i",header->size) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","tagX",
                                       "%i",header->tagX) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;

             /* ... add subdtd ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"int","tagY",
                                       "%i",header->tagY) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
           }

        /*
         *  return pstr
         */
        return pstr ;
      }


  /* .................................................................... */

