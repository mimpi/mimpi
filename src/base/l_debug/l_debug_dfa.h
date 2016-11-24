

 #ifndef L_DEBUG_DFA_H
 #define L_DEBUG_DFA_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_debug/l_debug_msg.h"
      #include "base/l_file/x_file.h"


   /* ... Types / Tipos ................................................. */

      typedef
      struct
      {
         T_CHAR  *state_orig ;
         T_CHAR  *state_dest ;
      } t_dfaTransition ;

      typedef
      struct
      {
        T_CHAR          *name ;
        t_dfaTransition *transitions ;
      } t_dfa ;


   /* ... Functions / Funciones ......................................... */
      
      /*  Basic functions  *
       * ----------------- */
      void       L_DEBUG_DFA_creat         
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      ) ;

      void       L_DEBUG_DFA_remove        
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      ) ;

      void       L_DEBUG_DFA_rename        
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *olddfaId,
        IN     void      *newdfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      ) ;

      T_BOOL     L_DEBUG_DFA_exist         
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      ) ;


      /*  Moving dfa  *
       * ------------ */
      T_BOOL     L_DEBUG_DFA_doTransition  
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *newState,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      ) ;


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif


 #endif

