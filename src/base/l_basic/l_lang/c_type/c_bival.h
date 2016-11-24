

 #ifndef C_BIVAL_H
 #define C_BIVAL_H


  /* ... Types / Tipos ........................................*/

     #define T_BOOL       char
     #define T_FLAG       char


  /* ... Consts / Constantes .................................. */

     #define c_BOOL       sizeof(T_BOOL)
     #define c_FLAG       sizeof(T_FLAG)


  /* ... Values / Valores ..................................... */

     #if (!defined(TRUE))
          #define TRUE        (1)
     #endif
     #if (!defined(FALSE))
          #define FALSE       (0)
     #endif

     #if (!defined(ON))
          #define ON          (1)
     #endif
     #if (!defined(OFF))
          #define OFF         (0)
     #endif


  /* .......................................................... */


#endif

