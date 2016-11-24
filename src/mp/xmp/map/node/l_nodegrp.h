

#ifndef L_NODEGRP_H
#define L_NODEGRP_H
 
 #ifdef  __cplusplus
    extern "C" {
 #endif
 

   /* ... Includes / Inclusiones ............................... */
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node/l_nodeinfo.h"
      #include "mp/xmp/map/node/l_nodes/l_params_xmp.h"
 

   /* ... Const. / Constantes .................................. */

      /**
       *  data type size
       */
      #define c_NODEGRP     sizeof(t_nodegrp)

 
   /* ... Types / Tipos ........................................ */

      typedef
      T_INT   t_nodegrp[MAX_SOCKS] ;


   /* ... Functions / Funciones ................................ */
 
      /**
       *
       *  Return TRUE if 'who' is member.
       *
       *     @params node group.
       *     @params who as member
       *     @return TRUE if member
       *
       */
      T_BOOL   L_NODEGRP_isMember
      (
        INOUT    t_nodegrp      nodeli,
        IN       T_INT          who
      ) ;

      /**
       *
       *  Add a new member.
       *  NOTE: if 'who' is '-1', this function do
       *  the same that 'L_NODEGRP_removeMember'.
       *
       *     @params node group.
       *     @params who as node id
       *     @return TRUE if no errors
       *
       */
      T_BOOL   L_NODEGRP_addMember
      (
        INOUT    t_nodegrp      nodeli,
        IN       T_INT          who
      ) ;

      /**
       *
       *  Remove a member from group
       *
       *     @params node group.
       *     @params who as node id
       *     @return TRUE if allright.
       *
       */
      T_BOOL   L_NODEGRP_removeMember
      (
        INOUT    t_nodegrp      nodeli,
        IN       T_INT          who
      ) ;

 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODEGRP_H */

