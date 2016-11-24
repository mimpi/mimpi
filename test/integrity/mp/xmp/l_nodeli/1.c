/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 * <fgarcia@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



    /*
     *
     *   test 1
     *   ------
     *
     *   probe init and finalize
     *
     */

      #include "mp/xmp/map/node/l_nodes/l_reqman/l_reqli.h"


      int main
      ( 
        IN       int   argc,
        IN       char *argv[]
      )
      {
        T_BOOL    ok ;
        t_reqli   reqli ;

        /* 
         *  begin
         */
        ok = L_REQLI_init(&reqli) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(1,1) to L_REQLI_init(...)") ;
             return TRUE ;
           }
        ok = L_REQLI_finalize(&reqli) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(1,2) to L_REQLI_finalize(...)") ;
             return TRUE ;
           }

        /* 
         *  return ok. 
         */
        return TRUE ;
      }


   /* ................................................................. */

