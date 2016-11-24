

#ifndef L_SOCIETY_H
#define L_SOCIETY_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"


   /* ... Const. / Constantes ......................................... */

      #define c_MEMBER      sizeof(t_member)
      #define c_MEMBERS     sizeof(t_members)
      #define c_SOCIETY     sizeof(t_society)
      #define c_SOCIETIES   sizeof(t_societies)

      #define MAX_SOCIETIES     4
      #define MAX_MEMBERS       MAX_SOCKS

      #define SOCIETY_WORLD     0


   /* ... Types / Tipos ............................................... */

      typedef
      int t_memberInfo ;

      typedef
      t_memberInfo t_members[MAX_MEMBERS] ;

      typedef
      long t_member ;

      typedef
      struct
      {
        long        nmembers ;
        t_members   members ;
        t_nodegrp   nodeli ;
      } t_societyInfo ;

      typedef
      t_societyInfo t_societies[MAX_SOCIETIES] ;

      typedef
      long t_society ;


   /* ... Glob. var / Var. globales ................................... */

      extern  long         L_SOCIETY_last_society ;
      extern  t_societies  L_SOCIETY_societies ;


   /* ... Functions / Funciones ....................................... */

      T_BOOL         L_SOCIETY_empty           
      ( 
        IN    t_society   s 
      ) ;
      /* - */
      /* - */

      long           L_SOCIETY_getNMembers     
      ( 
        IN    t_society    s 
      ) ;
      /* - */
      /* - */

      long           L_SOCIETY_setNMembers     
      ( 
        IN    t_society    s,
        IN    long         nm 
      ) ;
      /* - */
      /* - */

      t_memberInfo   L_SOCIETY_getMemberInfo   
      ( 
        IN    t_society    s,
        IN    t_member     rank 
      ) ;
      /* - */
      /* - */

      t_memberInfo   L_SOCIETY_setMemberInfo   
      ( 
        IN    t_society    s,
        IN    t_member     rank,
        IN    t_memberInfo node 
      ) ;
      /* - */
      /* - */

      t_memberInfo  *L_SOCIETY_getMembers      
      ( 
        IN    t_society    s 
      ) ;
      /* - */
      /* - */

      t_member       L_SOCIETY_getMember       
      ( 
        IN    t_society    s,
        IN    t_memberInfo myNID 
      ) ;
      /* - */
      /* - */


   /* ... Inline / Macros ............................................. */

      #define  L_SOCIETY_getNMembers(comm)                   \
               (L_SOCIETY_societies[(comm)].nmembers)

      #define  L_SOCIETY_setNMembers(comm,size)              \
               ((L_SOCIETY_societies[(comm)].nmembers) = (size))

      #define  L_SOCIETY_getMemberInfo(comm,rank)            \
               ((L_SOCIETY_societies[(comm)].members)[(rank)])

      #define  L_SOCIETY_setMemberInfo(comm,rank,node)       \
               {                                             \
                 L_NODEGRP_addMember                         \
                 (                                           \
                   (L_SOCIETY_societies[(comm)].nodeli),     \
                   node                                      \
                 ) ;                                         \
                                                             \
                 (((L_SOCIETY_societies[(comm)].members)[(rank)]) = (node)) ; \
               }

      #define  L_SOCIETY_getMembers(comm)                    \
               (L_SOCIETY_societies[(comm)].members)

      #define  L_SOCIETY_getNodeLi(comm)                     \
               (L_SOCIETY_societies[(comm)].nodeli)


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_SOCIETY_H */

