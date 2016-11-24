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

      #include "base/l_alloc/l_alloc.h"


   /* ... Functions / Funciones ......................................... */

      /* 
       *   Control Memory Functions
       *  --------------------------
       */

      T_U_LONG   L_ALLOC_Available ( void )
      {

        #if defined(__MSDOS__)
            #if (!defined(_Windows))
                 return (T_U_LONG) farcoreleft() ;
            #else
                 return 0L ;
            #endif
        #endif

        #if defined(__UNIX95__)
             struct rlimit rl ;

             getrlimit(RLIMIT_DATA,&rl) ;
             return rl.rlim_cur ;
        #endif

        #if defined(__WIN__)
            return LONG_MAX ;
        #endif

      }


   /* ................................................................... */

