

 #ifndef L_DHASH_H
 #define L_DHASH_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_debug/l_debug.h"
      #include "base/l_adt/l_darray.h"


   /* ... Types / Tipos ................................................. */
 
      /*
       *  we will store key and value
       */
      typedef
      struct field_descriptor t_field ;
      struct field_descriptor
      {
        T_CHAR     *key ;
        T_POINTER   value ;
      } ;
 
 
      /* 
       *  we use a table to store, but we see as binary
       *  tree when looking for entry.
       */
      typedef 
      struct entry_descriptor t_entry ;
      struct entry_descriptor
      {
        t_field    entry ;
        t_entry   *left ;
        t_entry   *right ;
      } ;
 

      /*
       *  we will store as table.
       */
      typedef 
      struct dhash_descriptor t_dhash ;
      struct dhash_descriptor
      {
        t_entry    **table ;
        T_U_LONG     neltos  ;
      } ;
 
 
   /* ... Const / Constantes ............................................ */

      #define  c_FIELD    (sizeof(t_field))
      #define  c_ENTRY    (sizeof(t_entry))
      #define  c_DHASH    (sizeof(t_dhash))


   /* ... Functions / Funciones ......................................... */
 
      /**
       *
       *  Return a pointer to dhash header 
       *
       *     @param nothing
       *     @return a empty hash
       *
       */
      t_dhash    *L_DHASH_Creat           
      ( 
        void 
      ) ;

      /**
       *
       *  Free all entry in '(*dhash)' and (*dhash)' 
       *
       *     @param a hash
       *     @return TRUE if allright
       *
       */
      T_BOOL      L_DHASH_Destroy        
      ( 
        INOUT t_dhash     **dhash 
      ) ;
 
      /**
       *
       *  Return number elements in dhash. 
       *
       *     @param a hash
       *     @return number of elements
       *
       */
      T_U_LONG    L_DHASH_NumberKV       
      ( 
        IN    t_dhash      *dhash 
      ) ;

      /**
       *
       *  Return value link to 'key'. 
       *
       *     @param a hash
       *     @return associate value.
       *
       */
      T_POINTER   L_DHASH_ValueOf        
      ( 
        IN    t_dhash     *dhash,
        IN    T_CHAR      *key,
        IN    T_BOOL       caseSense 
      ) ;

      /**
       *
       *  Add 'key-value' into 'dhash' tree 
       *
       *     @param a hash
       *     @param a key
       *     @param a value
       *     @return TRUE if allright
       *
       */
      T_BOOL      L_DHASH_InsertKV       
      ( 
        INOUT t_dhash     *dhash,
        IN    T_CHAR      *key,
        IN    T_POINTER    value 
      ) ;

 
   /* ... Inline / Macros ............................................... */

      #define L_DHASH_NumberKV(UBT)        \
              (                            \
                ((UBT) == NULL) ?          \
                                           \
                   (0L)                    \
                   :                       \
                   ((UBT)->neltos)         \
              )


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif


