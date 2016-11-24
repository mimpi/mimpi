

 #ifndef C_OP_H
 #define C_OP_H


   /* ... Include / Inclusiones ............................... */

      #include "base/l_basic/l_lang/c_type.h"


   /* ... Logic / Logica ...................................... */

     #define AND                 &&
     #define OR                  ||
     #define NOT                 !


   /* ... Arith. / Aritmeticos ................................ */

#ifndef MIN
     #define MIN(a,b)           ( ((a)<(b)) ? (a) : (b) )
#endif
#ifndef MAX
     #define MAX(a,b)           ( ((a)>(b)) ? (a) : (b) )
#endif


   /* ... byte / bytes ........................................ */

     #define HIGHB(a)            (((a) & 0xFF00) >> 8)
     #define LOWB(a)             ((a) & 0x00FF)
     #define DBYTE(h,l)          (((h) << 8) | ((l) & 0x00FF))

     #define HIGHDB(a)           (((a) & 0xFFFF0000) >> 16)
     #define LOWDB(a)            ((a) & 0x0000FFFF)
     #define DDBYTE(h,l)         (((long)(h) << 16) | ((long)(l) & 0x0000FFFF))


   /* ... bits / bits ......................................... */

     #define bAND                 &
     #define bOR                  |
     #define bXOR                 ^

     #define bC1                  -
     #define bC2                  ~


   /* ......................................................... */


#endif



