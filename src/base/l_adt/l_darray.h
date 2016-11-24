

 #ifndef L_DARRAY_H
 #define L_DARRAY_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_debug/l_debug.h"
      #include "base/l_alloc/x_alloc.h"


   /* ... Types / Tipos .................................................. */

      /* 
       *  Dinamic array, NULL end.
       */
      typedef 
      T_POINTER  *t_pointerDArray ;


   /* ... Consts / Constantes ............................................ */

      /* 
       *  type sizes
       */
      #define c_POINTERTABLA   sizeof(t_pointerDArray)


   /* ... Functions / Funciones .......................................... */

      /**
       *
       *  Insert 'gptr' at end of 't', with '(*n)' eltos and
       *  add one more ( (*n) = (*n) + 1 ) 
       *
       *     @params table
       *     @params number of elements
       *     @params element to insert
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_InsEndDarray 
      ( 
        INOUT t_pointerDArray *t,
        INOUT T_U_LONG        *n,
        IN    T_POINTER        gptr 
      ) ;

      /**
       *
       *  Delete last elto of 't' and subtract one elto
       *  ( (*n) = (*n) - 1 ) 
       *
       *     @params table
       *     @params number of elements
       *     @params element removed
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_DelEndDarray 
      ( 
        INOUT t_pointerDArray *t,
        INOUT T_U_LONG        *n,
        INOUT T_POINTER       *delGPtr 
      ) ;

      /**
       *
       *  Delete first element of 't' Darray, subtract one to
       *  '*n' and return element at 'delGPtr'. 
       *
       *     @params table
       *     @params number of elements
       *     @params element removed
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_DelBeginDarray 
      ( 
        INOUT t_pointerDArray *t,
        INOUT T_U_LONG        *n,
        INOUT T_POINTER       *delGPtr 
      ) ;

      /**
       *
       *  Remove element at position 'orden' from table 't', decr. 
       *  number of table elements ('n') and set 'delGPtr' to point
       *  to removed elementd.
       *
       *     @params table
       *     @params number of elements
       *     @params position
       *     @params element removed
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_DelNFromDarray 
      ( 
        IN    t_pointerDArray *t,
        INOUT T_U_LONG        *n,
        IN    T_U_LONG         orden,
        INOUT T_POINTER       *delGPtr 
      ) ;

      /** 
       *
       *  Change 'Darray[orden]' elto to 'nPtr' 
       *
       *     @params table
       *     @params number of elements
       *     @params position
       *     @params element removed
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_ChangeNFromDarray 
      ( 
        IN    t_pointerDArray *t,
        INOUT T_U_LONG        *n,
        IN    T_U_LONG         orden,
        INOUT T_POINTER        nPtr 
      ) ;

      /**
       *
       *  Go through 't' Darray, calling 'freef' function on
       *  every element. When it finish, do a 'free(t)' 
       *
       *     @params table
       *     @params number of elements
       *     @params free function
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_FreeEltosDarray 
      ( 
        INOUT t_pointerDArray *t,
        INOUT T_U_LONG        *n,
        IN    void (*freef)(T_POINTER) 
      ) ;

      /**
       *
       *  Return element at 'orden' position.
       *  NOTE: if 'orden' is 3, return t[3] ( fourth element )
       *  NOTE: bound check is NOT performed.
       *
       *     @params table
       *     @params position
       *     @return element
       *
       */
      T_POINTER  L_DARRAY_GetNFromDarray 
      ( 
        IN t_pointerDArray t,
        IN T_U_LONG orden 
      ) ;

      /**
       *
       *  Search in Darray first element that :
       *   (*findf)(gptr,<elemento darray) == TRUE. 
       *
       *     @params table
       *     @params number of elements
       *     @params element
       *     @params find function
       *     @return TRUE if no problem is found.
       *
       */
      T_POINTER  L_DARRAY_FindEltoDarray 
      ( 
        IN     t_pointerDArray  t,
        INOUT  T_U_LONG         n,
        IN     T_POINTER        gptr,
        IN     T_BOOL (*findf)(T_POINTER,T_POINTER) 
      ) ;
 
      /** 
       *  
       *  Return number of element at 't' Darray 
       *  
       *     @params table
       *     @return number of elements
       *  
       */
      T_U_LONG     L_DARRAY_GetNDarray 
      ( 
        IN t_pointerDArray t 
      ) ;

      /**
       *
       *  Try delete 'elto' element from 't'. 
       *  First, search it and is not at 't', return FALSE.
       *  Then, remove from table and reajust table.
       *  NOTE: this function do not use 'n' param.
       *
       *     @params table
       *     @params element
       *     @return TRUE if no problem is found.
       *
       */
      T_BOOL       L_DARRAY_DelEltoDarray 
      ( 
        INOUT t_pointerDArray *t,
        IN    T_POINTER        elto 
      ) ;


   /* ................................................................... */

      #define    L_DARRAY_GetNFromDarray(t,orden)    \
                 ( (t==(t_pointerDArray)NULL) ? NULL : t[orden] ) 


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

