

#ifndef L_REQLI_H
#define L_REQLI_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones .............................. */
 
      #include "base/l_basic/c_basic.h"
      #include "mp/xmp/map/node/l_nodereq.h"
 
 
   /* ... Const / Constantes .................................. */
  
      /**
       *  data type size
       */
      #define c_RECVREQ        (sizeof(t_reqRef))
      #define c_REQLI          (sizeof(t_reqli))
 
 
   /* ... Types / Tipos ....................................... */
  
      typedef 
      struct reqRef
      {
 
         /*
          *  request
          */
        t_nodeReq       *req ;
 
         /*
          *  list link
          */
        struct reqRef   *after ;
        struct reqRef   *before ;
 
         /*
          *  this is a mallocated memory block.
          */
        T_BOOL           isMalloc ;
 
      } t_reqRef ;
 
 
      typedef
      struct
      {
 
         /*
          *  list link to begin and end
          */
        struct reqRef   *head ;
        struct reqRef   *tail ;
 
         /*
          *  number of eltos in list.
          */
        T_INT            nreqli ;
 
      } t_reqli ;
 
 
   /* ... Functions / Funciones ............................... */
 
      /**
       *
       *  Set with default values.
       *
       *     @params request list to init
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_REQLI_init              
      ( 
        INOUT   t_reqli    *reqli 
      ) ;

      /**
       *
       *  Free resources.
       *
       *     @params request list to clear
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_REQLI_finalize          
      ( 
        OUT   t_reqli    *reqli 
      ) ;
 
      /**
       *
       *  Check if list is empty.
       *
       *     @params request list to inspect
       *     @return TRUE if is empty
       *
       */
      T_BOOL      L_REQLI_isEmpty           
      ( 
        IN    t_reqli    *reqli 
      ) ;

      /**
       *
       *  Return first element at list.
       *
       *     @params request list to inspect
       *     @return first element.
       *
       */
      t_reqRef   *L_REQLI_first             
      ( 
        IN    t_reqli    *reqli 
      ) ;

      /**
       *
       *  Return next element from 'elto' element.
       *
       *     @params request list to inspect
       *     @return next element.
       *
       */
      t_reqRef   *L_REQLI_next              
      ( 
        IN    t_reqRef   *elto 
      ) ;

      /**
       *
       *  Inserts 'elto' at list.
       *  DO NOT check if allready is at list.
       *
       *     @params request list where add
       *     @params elto to add
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_REQLI_insert            
      ( 
        IN    t_reqli    *reqli,
        IN    t_reqRef   *elto 
      ) ;

      /**
       *
       *  Inserts 'elto' ( using dinamic memory ).
       *  DO NOT check if allready is at list.
       *
       *     @params request list where add
       *     @params elto that has been added
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_REQLI_allocReqAndInsert 
      ( 
        IN    t_reqli    *reqli,
        OUT   t_reqRef  **elto 
      ) ;

      /**
       *
       *  Remove 'elto' from list.
       *
       *     @params request list where remove
       *     @params elto to remove
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_REQLI_delete            
      ( 
        IN    t_reqli    *reqli, 
        IN    t_reqRef   *elto 
      ) ;

      /**
       *
       *  't_reqRef' information is respresented
       *  as string.
       *
       *     @params request reference
       *     @return elto information as string.
       *
       */
      T_CHAR     *L_REQLI_reqrefToString    
      ( 
        IN    t_reqRef   *elto 
      ) ;

      /**
       *
       *  't_reqli' information is respresented
       *  as string.
       *
       *     @params request list
       *     @return elto information as string.
       *
       */
      T_CHAR     *L_REQLI_reqliToString     
      ( 
        IN    t_reqli    *reqli 
      ) ;
 
 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_REQLI_H */

