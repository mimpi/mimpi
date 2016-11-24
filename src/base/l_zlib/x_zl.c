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



   /* ... Includes .................................................... */

      #include "base/l_zlib/x_zl.h"


   /* ... Funciones ................................................... */

      T_STATUS  X_ZL_compress_to
      ( 
        IN       void   *source,
        IN       long    sourceLen,
        OUT      void  **dest,
        OUT      long   *destLen,
        IN       int     level
      )
      {
        int  ret ;

        /*
         *  check params
         */
        TRUE__SET_ERROR__RET_LONG((dest==NULL),STATUS_ERROR) ;
        TRUE__SET_ERROR__RET_LONG((destLen==NULL),STATUS_ERROR) ;

        /*
         *  default values, default returns ...
         */
        (*destLen) = 0 ;
        (*dest)    = NULL ;
        if (source == NULL) 
            return ZL_OK ;
        if (sourceLen == 0L) 
            return ZL_OK ;

        /*
         *  alloc compress buffer
         */
        (*destLen) = (sourceLen < 400) ? 400 : sourceLen + 12 ;
        (*dest)    = X_ALLOC_Malloc((*destLen)) ;
        if ((*dest) == NULL) 
           {
             L_DEBUG_MSG_PrintF(DBG_ERROR,TRUE,
                                "X_ALLOC_Malloc: problems\n") ;
             return STATUS_ERROR ;
           }

        /*
         *  compress
         */
        ret = V_ZL_compress( 
                             (*dest), 
                             destLen,
                             source,
                             sourceLen,
                             level 
                           ) ;

        /*
         *  return ok
         */
        return ret ;
      }

      T_STATUS  X_ZL_compress_into
      ( 
        IN       void   *source,
        IN       long    sourceLen,
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       int     level
      )
      {
        int  ret ;

        /*
         *  check params
         */
        TRUE__SET_ERROR__RET_LONG((dest==NULL),STATUS_ERROR) ;
        TRUE__SET_ERROR__RET_LONG((destLen==NULL),STATUS_ERROR) ;

        /*
         *  default values, default returns ...
         */
        if (
             (source == NULL) 
                     ||
             (sourceLen == 0L) 
           )
           {
             (*destLen) = 0 ;
             return ZL_OK ;
           }

        /*
         *  compress
         */
        ret = V_ZL_compress( 
                             dest, 
                             destLen,
                             source,
                             sourceLen,
                             level 
                           ) ;

        /*
         *  return ok
         */
        return ret ;
      }

      T_STATUS  X_ZL_uncompress_into
      ( 
        IN       void   *source,
        IN       long    sourceLen,
        OUT      void   *dest,
        OUT      long   *destLen
      )
      {
        int  ret ;

        /*
         *  check params
         */
        TRUE__SET_ERROR__RET_LONG((dest==NULL),STATUS_ERROR) ;
        TRUE__SET_ERROR__RET_LONG((destLen==NULL),STATUS_ERROR) ;

        /*
         *  default values, default returns ...
         */
        if (
             (source == NULL) 
                     ||
             (sourceLen == 0L) 
           )
           {
             (*destLen) = 0 ;
             return ZL_OK ;
           }

        /*
         *  uncompress
         */
        ret = V_ZL_uncompress( 
                               dest, 
                               destLen,
                               source,
                               sourceLen
                             ) ;

        /*
         *  return ok
         */
        return ret ;
      }


  /* .................................................................... */

