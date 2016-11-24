

#ifndef L_NODEDATA_H
#define L_NODEDATA_H


   /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "mp/xmp/base/l_sb.h"


   /* ... Functions / Funciones ................................*/

      /**
       *
       *  Write data.
       *
       *     @params scrollbar
       *     @params 'sock' from scrollbar
       *     @params buffer
       *     @params buffer size
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEDATA_writeData  
      ( 
        INOUT    t_sb          *sb,
        INOUT    int            sock,
        IN       T_CHAR        *buff,
        IN       T_INT          size 
      ) ;

      /**
       *
       *  Read data.
       *
       *     @params scrollbar
       *     @params 'sock' from scrollbar
       *     @params buffer
       *     @params buffer size
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEDATA_readData   
      ( 
        INOUT    t_sb          *sb,
        INOUT    int            sock,
        IN       T_CHAR        *buff,
        IN       T_INT          size 
      ) ;

      /**
       *
       *  Skip data.
       *
       *     @params scrollbar
       *     @params 'sock' from scrollbar
       *     @params buffer
       *     @params buffer size
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEDATA_skipData   
      ( 
        INOUT    t_sb          *sb,
        INOUT    int            sock,
        IN       T_INT          size 
      ) ;
 
 
   /* ... Inline / Macros ......................................*/
 
      #define   L_NODEDATA_writeData(sb,sock,buff,size)           \
                L_SB_write((sb),(sock),(void *)(buff),(size)) ;
 
      #define   L_NODEDATA_readData(sb,sock,buff,size)            \
                L_SB_read((sb),(sock),(void *)(buff),(size)) ;
 
 
   /* ..........................................................*/


#endif  /* L_NODEDATA_H */

