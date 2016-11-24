

 #ifndef I_ALLOC_DEBUG_H
 #define I_ALLOC_DEBUG_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/l_alloc.h"
      #include "base/l_debug/l_debug.h"
      #include "base/l_debug/l_debug_dfa.h"


   /* ... Functions / Funciones ......................................... */

      /*
       *   Standard Memory Functions
       *  ---------------------------
       */
      T_POINTER  I_ALLOC_DEBUG_Malloc   
      ( 
        IN     T_U_INT    size,
        IN     T_CHAR    *file,
        IN     T_INT      line 
      ) ;
      /* - totalmemo-=size, return 'size' bytes */
      /* - da 'size' bytes del total disponible */

      void       I_ALLOC_DEBUG_Free     
      ( 
        INOUT  T_POINTER *ptr,
        IN     T_CHAR    *file,
        IN     T_INT      line 
      ) ;
      /* - totalmemo+=size (**ptr), (*ptr)=NULL */
      /* - retorna 'size' bytes al total disponible */

      T_POINTER  I_ALLOC_DEBUG_Realloc  
      ( 
        IN     T_POINTER  block, 
        IN     T_U_INT    size,
        IN     T_CHAR    *file,
        IN     T_INT      line 
      ) ;
      /* - Change 'block' memory size into 'size' bytes. */
      /* - Cambia el taman~o del bloque 'block' a 'size' bytes */
      

      /*
       *   Advanced Memory Functions
       *  ---------------------------
       */
      T_POINTER  I_ALLOC_DEBUG_MemMove  
      ( 
        IN     T_POINTER  dest,
        IN     T_POINTER  src,
        IN     T_U_INT    count,
        IN     T_CHAR    *file,
        IN     T_INT      line 
      ) ;
      /* - Copy from 'src' to 'dest' 'count' bytes */
      /* - Copia en 'dest' los 'count' primeros bytes de 'src' */

      T_POINTER  I_ALLOC_DEBUG_MemSet   
      ( 
        IN     T_POINTER  dest,
        IN     T_BYTE     byte,
        IN     T_U_INT    count,
        IN     T_CHAR    *file,
        IN     T_INT      line 
      ) ;
      /* - Fill 'count' first bytes of 'dest' with 
          'byte' value */
      /* - Rellena los 'count' primeros bytes de 'dest' con 
           el byte 'byte'. */


      /*
       *   Control Memory Functions
       *  ---------------------------
       */
      T_U_LONG   I_ALLOC_DEBUG_Available 
      ( 
        IN     T_CHAR    *file,
        IN     T_INT      line 
      ) ;
      /* - Return total memory available.
           In Unix, can be changes using 'limit' */
      /* - Retorna totalmemo, salvo en unix, pues es 
           ampliable hasta el valor definido por el 
           comando 'limit' */


      T_POINTER  I_ALLOC_DEBUG_ChkPtr    
      ( 
        IN     T_POINTER   b,
        IN     T_CHAR     *file,
        IN     T_INT       line 
      ) ;
      /* - Explore if 'b' is a valid memory block.
           If any error, print a message.
           Any way, return 'b'. */
      /* - Explora que 'b' sea la referencia valida a un bloque
           de memoria, retornando ese mismo 'b'.
           Ante errores, informa con un mensaje */


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

