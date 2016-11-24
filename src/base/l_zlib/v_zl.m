

 #ifndef V_ZL_M
 #define V_ZL_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_zlib/i_zl_zlib.h"
      #include "base/l_zlib/i_zl_lzrw3.h"
      #include "base/l_zlib/i_zl_lzo.h"


   /* ... Inline / Macros ............................................... */

      #if defined(__LZRW3__)

          #define V_ZL_compress(dest,destLen,src,srcLen,level) \
                  I_ZL_LZRW3_compress((dest),(destLen),(src),(srcLen),(level))
     
          #define V_ZL_uncompress(dest,destLen,src,srcLen) \
                  I_ZL_LZRW3_uncompress((dest),(destLen),(src),(srcLen))
     
          #define V_ZL_init() \
                  I_ZL_LZRW3_init()

          #define V_ZL_finalize() \
                  I_ZL_LZRW3_finalize()

      #elif defined(__ZLIB__)

          #define V_ZL_compress(dest,destLen,src,srcLen,level) \
                  I_ZL_ZLIB_compress((dest),(destLen),(src),(srcLen),(level))
     
          #define V_ZL_uncompress(dest,destLen,src,srcLen) \
                  I_ZL_ZLIB_uncompress((dest),(destLen),(src),(srcLen))

          #define V_ZL_init() \
                  I_ZL_ZLIB_init()

          #define V_ZL_finalize() \
                  I_ZL_ZLIB_finalize()

      #else

          #define V_ZL_compress(dest,destLen,src,srcLen,level) \
                  I_ZL_LZO_compress((dest),(destLen),(src),(srcLen),(level))
     
          #define V_ZL_uncompress(dest,destLen,src,srcLen) \
                  I_ZL_LZO_uncompress((dest),(destLen),(src),(srcLen))
     
          #define V_ZL_init() \
                  I_ZL_LZO_init()

          #define V_ZL_finalize() \
                  I_ZL_LZO_finalize()

      #endif


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

