

 #ifndef L_DSTACK_H
 #define L_DSTACK_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "base/l_debug/l_debug.h"


   /* ... Types / Tipos .................................................. */

      typedef struct deslabon *t_pointerDStack ;
      struct  deslabon
      {
	T_POINTER elemento ;
	t_pointerDStack anterior ;
      } ;


   /* ... Consts / Constantes ............................................ */

      /* 
       *  data size 
       */
      #define c_POINTERPILA    sizeof(struct deslabon)


   /* ... Functions / Funciones .......................................... */

      /**
       *
       *  Return the (t_pointerDStack)NULL 
       *
       *     @params nothing
       *     @return a empty DStack
       *
       */
      t_pointerDStack   L_DSTACK_CreatEmpty 
      ( 
        void 
      ) ;

      /**
       *
       *  Check if stack is empty. 
       *
       *     @param a stack
       *     @return TRUE if empty
       *
       */
      T_BOOL          L_DSTACK_IsEmpty    
      ( 
        IN     t_pointerDStack p 
      ) ;
 
      /**
       *
       *  Return 'top' element in stack 
       *
       *     @param a stack
       *     @return top elto 
       *
       */
      T_POINTER       L_DSTACK_Pop        
      ( 
        INOUT t_pointerDStack *p 
      ) ;
 
      /**
       *
       *  Insert 'e' in 'p'. 
       *
       *     @param a stack
       *     @param a element
       *     @return TRUE if allright
       *
       */
      t_pointerDStack   L_DSTACK_Push     
      ( 
        INOUT t_pointerDStack *p,
        IN    T_POINTER        e 
      ) ;
 
      /**
       *
       *  Insert element 'e' in 'p' stack, only if
       *  'e' is not allready in 'p'. 
       *
       *     @param a stack
       *     @param a element
       *     @return TRUE if allright
       *
       */
      t_pointerDStack   L_DSTACK_PushNew  
      ( 
        INOUT t_pointerDStack *p,
 	IN    T_POINTER        e 
      ) ;
 
      /**
       *
       *  Free memory used by stack, 
       *  BUT DO NOT free per element memory. 
       *
       *     @param a stack
       *     @return nothing
       *
       */
      void            L_DSTACK_Empty      
      ( 
        INOUT t_pointerDStack *p 
      ) ;
 

   /* ... Inline / Expansiones ........................................... */

      #define L_DSTACK_CreatEmpty() \
              (t_pointerDStack)NULL

      #define L_DSTACK_IsEmpty(p)   \
              (p==(t_pointerDStack)NULL)


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

