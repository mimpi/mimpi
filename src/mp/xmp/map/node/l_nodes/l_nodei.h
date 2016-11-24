

#ifndef L_NODEI_H
#define L_NODEI_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodereq.h"
      #include "mp/xmp/map/node/l_nodes/l_nodei/l_nodeheader.h"
      #include "mp/xmp/map/node/l_nodes/l_nodei/l_nodedata.h"


   /* ... Functions / Funciones ................................*/

      /**
       *
       *  Write a send request.
       *
       *     @params scrollbar
       *     @params 'sock' from scrollbar
       *     @params node header to use.
       *     @params send request.
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEI_writeSendReq    
      ( 
        INOUT  t_sb                 *sb,
        INOUT  int                   sock,
        IN     t_nodeHeader         *outHeader,
        INOUT  t_nodeReq            *psend 
      ) ;

      /**
       *
       *  Receive a conection request.
       *
       *     @params scrollbar
       *     @params 'sock' from where conection comes 
       *     @params source node id 
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEI_recvConnect     
      ( 
        INOUT  t_sb                 *sb,
        OUT    int                  *sock,
        OUT    int                  *who 
      ) ;

      /**
       *
       *  Write a send request.
       *
       *     @params scrollbar
       *     @params source node id 
       *     @params socket address
       *     @params conection sock
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEI_sendConnect     
      ( 
        INOUT  t_sb                 *sb,
        IN     T_INT                *nodeid,
        IN     struct sockaddr_in   *sa,
        OUT    int                  *sock 
      ) ;


   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODEI_H */

