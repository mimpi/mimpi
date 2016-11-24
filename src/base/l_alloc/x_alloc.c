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

      #include "base/l_alloc/x_alloc.h"


   /* ... Functions / Funciones ......................................... */

      T_POINTER  X_ALLOC_MemDup 
      ( 
        IN  T_POINTER b,
        IN  T_U_INT   bsize 
      )
      {
        void *pvoid ;

        /*
         *  Try malloc and copy data
         */
        NULL_RET_NULL(b) ;
        pvoid = X_ALLOC_Malloc(bsize) ;
        NULL_RET_NULL(pvoid) ;
        X_ALLOC_MemMove(pvoid,b,bsize) ;

        /*
         *  Return
         */
        return pvoid ;
      }

      T_POINTER  X_ALLOC_AllocAndSet 
      ( 
        IN  T_U_INT  bsize,
        IN  T_CHAR   setval 
      )
      {
        void *pvoid ;

        /*
         *  Try malloc and set value
         */
        pvoid = X_ALLOC_Malloc(bsize) ;
        NULL_RET_NULL(pvoid) ;
        X_ALLOC_MemSet(pvoid,setval,bsize) ;

        /*
         *  Return
         */
        return pvoid ;
      }


/* ...................................................................... */

