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



   /* ... Includes / Inclusiones ...................................... */

      #include "base/l_zlib/i_zl_zlib.h"


   /* ... Funciones / Functions ....................................... */

      T_STATUS  I_ZL_ZLIB_init
      ( 
        void
      )
      {
        /*
         *  return ok
         */
        return ZL_OK ;
      }

      T_STATUS  I_ZL_ZLIB_finalize
      ( 
        void
      )
      {
        /*
         *  return ok
         */
        return ZL_OK ;
      }

      T_STATUS  I_ZL_ZLIB_compress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen,
        IN       int     level
      )
      {
#if defined(HAVE_ZLIB_H)

        int  ret ;

        /*
         *  compress
         */
        ret = compress2( dest, 
                         destLen,
                         source,
                         sourceLen,
                         level ) ;
        if (ret != Z_OK) 
           {
             L_DEBUG_MSG_PrintF(DBG_ERROR,TRUE,
                                "zlib.compress: %s\n",
                                zError(ret)) ;
             return ret ;
           }

        /*
         *  return 'ret'
         */
        return ret ;

#else

        X_ALLOC_MemMove(dest,
                        source,
                        MIN((*destLen),sourceLen)) ;

        /*
         *  return 'ret'
         */
        return ZL_OK ;

#endif
      }

      T_STATUS  I_ZL_ZLIB_uncompress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen
      )
      {
#if defined(HAVE_ZLIB_H)

        int  ret ;

        ret = uncompress(dest, 
                         destLen,
                         source,
                         sourceLen) ;
        if (ret != Z_OK) 
           {
             L_DEBUG_MSG_PrintF(DBG_ERROR,TRUE,
                                "zlib.compress: %s\n",
                                zError(ret)) ;
             return ret ;
           }

        /*
         *  return 'ret'
         */
        return ret ;

#else

        X_ALLOC_MemMove(dest,
                        source,
                        MIN((*destLen),sourceLen)) ;

        /*
         *  return 'ret'
         */
        return ZL_OK ;

#endif
      }


  /* .................................................................... */

