/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_adt/l_buffa.h"


   /* ... Functions / Funciones ......................................... */
   
      T_BOOL  L_BUFFA_F_CatOneByteToCache 
      ( 
        INOUT  T_CHAR   **b, 
   	INOUT  T_U_INT   *cb,
        IN     T_CHAR     ch 
      )
      {
        T_CHAR *nbuff ;
   
        /*
         *  check if realloc
         */
        if ( ((*cb) % c_BUFFSIZE) == 0 )
   	   {
   	     nbuff=X_ALLOC_Realloc((*b),(*cb)+c_BUFFSIZE) ;
             NULL_RET_FALSE(nbuff) ;
   	     (*b)=nbuff ;
   	   }

        /*
         *  add
         */
        (*b)[(*cb)++]=ch ;

        /*
         *  return
         */
        return TRUE ;
      }
   
      T_BOOL  L_BUFFA_CatNBytesToCache 
      ( 
        INOUT T_CHAR  **b,
        INOUT T_U_INT  *cb,
        IN    T_CHAR   *s, 
        IN    T_U_INT  cs 
      )
      {
        T_CHAR *nbuff ;
        T_U_INT need_free, have_free ;
   
        /*
         *  check if realloc
         */
        have_free = ((*cb) % c_BUFFSIZE) ;
        need_free = (c_BUFFSIZE - have_free) ;
        if ( 
             (have_free == 0) 
                   ||
             (cs > need_free) 
           )
   	   {
             T_U_INT sizeb, faltan ;
   
   	     faltan = cs - ( (have_free) ? need_free : 0 ) ;
   	     sizeb  = ((faltan / c_BUFFSIZE)+1)*c_BUFFSIZE ;
   	     nbuff  = X_ALLOC_Realloc((*b),(*cb)+need_free+sizeb) ;
             NULL_RET_FALSE(nbuff) ;
   	     (*b) = nbuff ;
   	   }

        /*
         *  add
         */
        X_ALLOC_MemMove( &((*b)[(*cb)]), s, cs ) ;
        (*cb)+=cs ;

        /*
         *  return
         */
        return TRUE ;
      }
   
      T_BOOL  L_BUFFA_AjustCache          
      ( 
        INOUT  T_CHAR  **b,
        IN     T_U_INT   cb 
      )
      {
        (*b)=X_ALLOC_Realloc((*b),cb) ;
        return ( ! ((cb!=0) && ((*b)==NULL)) ) ;
      }
   

   /* ................................................................... */


