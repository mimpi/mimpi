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

      #include "base/l_zlib/i_zl_lzrw3.h"


   /* ... Glob. Var. / Var. Globales .................................. */

      T_BOOL   I_ZL_LZRW3_isInit = FALSE ;
#if defined(HAVE_LZRW3_H)
      struct compress_identity *I_ZL_LZRW3_identity ;
#endif


   /* ... Funciones / Functions ....................................... */

      T_STATUS  I_ZL_LZRW3_init
      ( 
        void
      )
      {
#if defined(HAVE_LZRW3_H)

        /*
         *  ident
         */
        lzrw3_compress
        ( 
          COMPRESS_ACTION_IDENTITY,
          NULL,
          NULL,
          0,
          NULL, 
          (ULONG *)&(I_ZL_LZRW3_identity)
        ) ;

        /*
         *  is initialized
         */
        I_ZL_LZRW3_isInit = TRUE ;

#endif

        /*
         *  return ok
         */
        return ZL_OK ;
      }

      T_STATUS  I_ZL_LZRW3_finalize
      ( 
        void
      )
      {
        /*
         *  return ok
         */
        return ZL_OK ;
      }

      T_STATUS  I_ZL_LZRW3_compress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen,
        IN       int     level
      )
      {
#if defined(HAVE_LZRW3_H)

        struct compress_identity *I_ZL_LZRW3_identity ;
        void  *I_ZL_LZRW3_wrkmem ;

        /*
         *  ident
         */
        lzrw3_compress
        ( 
          COMPRESS_ACTION_IDENTITY,
          NULL,
          NULL,
          0,
          NULL, 
          (ULONG *)&(I_ZL_LZRW3_identity)
        ) ;

        /*
         *  alloc workmemory
         */
        I_ZL_LZRW3_wrkmem = X_ALLOC_Malloc
                            (
                              I_ZL_LZRW3_identity->memory      
                            ) ;
        if (I_ZL_LZRW3_wrkmem == NULL) 
            return STATUS_ERROR ;

        /*
         *  compress
         */
        lzrw3_compress
        ( 
          COMPRESS_ACTION_COMPRESS,
          I_ZL_LZRW3_wrkmem,
          source,
          sourceLen,
          dest, 
          (ULONG *)destLen
        ) ;

        /*
         *  free workmemory
         */
        X_ALLOC_Free((void **)&(I_ZL_LZRW3_wrkmem)) ;

        /*
         *  return 'ret'
         */
        return ZL_OK ;

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

      T_STATUS  I_ZL_LZRW3_uncompress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen
      )
      {
#if defined(HAVE_LZRW3_H)

        struct compress_identity *I_ZL_LZRW3_identity ;
        void  *I_ZL_LZRW3_wrkmem ;

        /*
         *  ident
         */
        lzrw3_compress
        ( 
          COMPRESS_ACTION_IDENTITY,
          NULL,
          NULL,
          0,
          NULL, 
          (ULONG *)&(I_ZL_LZRW3_identity)
        ) ;

        /*
         *  alloc workmemory
         */
        I_ZL_LZRW3_wrkmem = X_ALLOC_Malloc
                            (
                              I_ZL_LZRW3_identity->memory      
                            ) ;
        if (I_ZL_LZRW3_wrkmem == NULL) 
            return STATUS_ERROR ;


        /*
         *  decompress
         */
        lzrw3_compress
        ( 
          COMPRESS_ACTION_DECOMPRESS,
          I_ZL_LZRW3_wrkmem,
          source,
          sourceLen,
          dest, 
          (ULONG *)destLen
        ) ;

        /*
         *  free workmemory
         */
        X_ALLOC_Free((void **)&(I_ZL_LZRW3_wrkmem)) ;

        /*
         *  return 'ret'
         */
        return ZL_OK ;

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

