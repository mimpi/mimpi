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

      #include "base/l_zlib/i_zl_lzo.h"
      #include "base/l_thread/v_thread.h"


   /* ... Glob. Var. / Var. Globales .................................. */

      T_BOOL   I_ZL_LZO_isInit = FALSE ;


   /* ... Inline / Macros ............................................. */

      /*
	   *  Allocate memory in units of `long' (instead of `char') 
	   *  to make sure it is properly aligned.
	   */
      #define I_ZL_LZO_ALLOC_SIZE(size) \
		      (sizeof(long) * ( ((size) + (sizeof(long) - 1)) / sizeof(long) ))


   /* ... Funciones / Functions ....................................... */

      T_STATUS  I_ZL_LZO_init
      ( 
        void
      )
      {
#if defined(HAVE_LZO_H)

        int    r ;

        /*
         *  check lzo_init was called.
         */
        if (I_ZL_LZO_isInit == FALSE) 
	   {
             r = lzo_init() ;
             if (r != LZO_E_OK)
                 return STATUS_ERROR ;
             I_ZL_LZO_isInit = TRUE ;
	   }

        /*
         *  return ok
         */
        return ZL_OK ;

#else

        /*
         *  return ok
         */
        return ZL_OK ;

#endif
      }

      T_STATUS  I_ZL_LZO_finalize
      ( 
        void
      )
      {
        /*
         *  return ok
         */
        return ZL_OK ;
      }

      T_STATUS  I_ZL_LZO_compress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen,
        IN       int     level
      )
      {
#if defined(HAVE_LZO_H)

        int    r ;
        void  *I_ZL_LZO_wrkmem ;

        /*
         *  check lzo_init was called.
         */
        if (I_ZL_LZO_isInit == FALSE) 
	   {
	     r = lzo_init() ;
             if (r != LZO_E_OK)
                 return STATUS_ERROR ;
	     I_ZL_LZO_isInit = TRUE ;
	   }

        /*
         *  alloc workmemory
         */
        I_ZL_LZO_wrkmem = X_ALLOC_Malloc
                          (
                            I_ZL_LZO_ALLOC_SIZE(LZO1X_1_MEM_COMPRESS)
                          ) ;
        if (I_ZL_LZO_wrkmem == NULL) 
            return STATUS_ERROR ;

        /*
         *  compress
         */
        r = lzo1x_1_compress
        ( 
          source,
          (lzo_uint)sourceLen,
          dest, 
          (lzo_uint *)destLen,
          (long *)I_ZL_LZO_wrkmem
        ) ;

        /*
         *  free workmemory
         */
        X_ALLOC_Free((void **)&(I_ZL_LZO_wrkmem)) ;

        /*
         *  return 'r'
         */
        return (r == LZO_E_OK) ? ZL_OK : STATUS_ERROR ;

#else

        X_ALLOC_MemMove(dest,
                        source,
                        MIN((*destLen),sourceLen)) ;

        /*
         *  return 'r'
         */
        return  ZL_OK  ;

#endif
      }

      T_STATUS  I_ZL_LZO_uncompress
      ( 
        OUT      void   *dest,
        OUT      long   *destLen,
        IN       void   *source,
        IN       long    sourceLen
      )
      {
#if defined(HAVE_LZO_H)

        int    r ;

        /*
         *  check lzo_init was called.
         */
        if (I_ZL_LZO_isInit == FALSE) 
	   {
	     r = lzo_init() ;
             if (r != LZO_E_OK)
                 return STATUS_ERROR ;
	     I_ZL_LZO_isInit = TRUE ;
	   }

        /*
         *  decompress
         */
        r = lzo1x_decompress
        ( 
          source,
          (lzo_uint)sourceLen,
          dest, 
          (lzo_uint *)destLen,
          NULL
        ) ;

        /*
         *  return 'r'
         */
        return (r == LZO_E_OK) ? ZL_OK : STATUS_ERROR ;

#else

        X_ALLOC_MemMove(dest,
                        source,
                        MIN((*destLen),sourceLen)) ;

        /*
         *  return 'r'
         */
        return  ZL_OK  ;

#endif
      }


  /* .................................................................... */

