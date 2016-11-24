

#ifndef L_NODELI_H
#define L_NODELI_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "mp/xmp/map/node_server/l_nsi.h"


  /* ... Const / Constantes ...................................*/
 
     #define c_NODEDATA       (sizeof(t_nodeData))
     #define c_NODELI         (sizeof(t_nodeli))


  /* ... Types / Tipos ........................................*/
 
     typedef 
     struct 
     {
       char                name[MAX_NODE_NAME] ;
       struct sockaddr_in  from ;
       int                 in_use ;
     } t_nodeData ;

     typedef
     t_nodeData t_nodeli[MAX_SOCKS] ;


  /* ... Functions / Funciones ................................*/

      T_BOOL   L_NODELI_init           
      ( 
        INOUT    t_nodeli *nodeli 
      ) ;

      T_INT    L_NODELI_whereIs        
      ( 
        INOUT    t_nodeli *nodeli,
        IN       T_CHAR   *name 
      ) ;

      T_BOOL   L_NODELI_search         
      ( 
        INOUT    t_nodeli *nodeli,
        IN       T_CHAR   *name 
      ) ;

      T_BOOL   L_NODELI_enter          
      ( 
        INOUT    t_nodeli            *nodeli,
        IN       T_CHAR              *name,
        IN       struct sockaddr_in   from 
      ) ;

      T_BOOL   L_NODELI_delete         
      ( 
        INOUT    t_nodeli *nodeli,
        IN       T_CHAR   *name 
      ) ;


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif /* L_NODELI_H */

