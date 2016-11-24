

#ifndef L_NODEHEADER_H
#define L_NODEHEADER_H


   /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_dtd.h"
      #include "mp/xmp/base/l_sb.h"


   /* ... Const / Constantes ...................................*/

      /**
       *  data inmediaty
       */
#if defined(__SP2__)
      #define NH_IDATA  1024
#else
      #define NH_IDATA  0
#endif


   /* ... Types / Tipos ........................................*/

      typedef
      struct
      {

         T_INT    id ;
         T_INT    size ;
         T_INT    tagX ;
         T_INT    tagY ;
	 T_CHAR   idata[NH_IDATA] ;

      } t_nodeHeader ;


   /* ... Const / Constantes ...................................*/

      /**
       *  data type size
       */
      #define c_NODEHEADER (sizeof(t_nodeHeader))

      /**
       *  node header identification
       */
      #define NH_NOP      0
      #define NH_DATA   111


   /* ... Functions / Funciones ................................*/

      /**
       *
       *  Set default values.
       *
       *     @params header to set defaults values
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEHEADER_nodeheaderInit  
      ( 
        INOUT  t_nodeHeader  *header 
      ) ;

      /**
       *
       *  Write header.
       *
       *     @params scrollbar
       *     @params 'sock' from scrollbar
       *     @params header to send
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEHEADER_writeHeader     
      (   
        INOUT  t_sb          *sb,
        INOUT  int            sock,
        IN     t_nodeHeader  *header 
      ) ;

      /**
       *
       *  Read header.
       *
       *     @params scrollbar
       *     @params 'sock' from scrollbar
       *     @params header to receive
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEHEADER_readHeader      
      ( 
        INOUT  t_sb          *sb,
        INOUT  int            sock,
        OUT    t_nodeHeader  *header 
      ) ;

      /**
       *
       *  't_nodeHeader' information is respresented
       *  as string.
       *
       *     @params header to see as string
       *     @return header info as string
       *
       */
      T_CHAR  *L_NODEHEADER_nodeheaderToString 
      ( 
        IN    t_nodeHeader  *header  
      ) ;


   /* ... Inline / Macros ......................................*/

      #define   L_NODEHEADER_writeHeader(sb,sock,header)            \
                L_SB_write((sb),(sock),(void *)(header),c_NODEHEADER) ;

      #define   L_NODEHEADER_readHeader(sb,sock,header)             \
                L_SB_read((sb),(sock),(void *)(header),c_NODEHEADER) ;


   /* ..........................................................*/


#endif  /* L_NODEHEADER_H */

