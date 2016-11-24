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
     *   test 2
     *   ------
     *
     *   probe insert, delete and isEmpty.
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
        t_reqRef  elto ;

        /* 
         *  begin
         */
        ok = L_REQLI_init(&reqli) ;
        ok = L_REQLI_isEmpty(&reqli) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(2,1) in L_REQLI_isEmpty(...)") ;
             return TRUE ;
           }
        ok = L_REQLI_insert(&reqli,&elto) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(2,2) in L_REQLI_insert(...)") ;
             return TRUE ;
           }
        ok = L_REQLI_isEmpty(&reqli) ;
        if (ok == TRUE)
           {
             fprintf(stderr,
                     "fail(2,3) in L_REQLI_isEmpty(...)") ;
             return TRUE ;
           }
        ok = L_REQLI_delete(&reqli,&elto) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(2,4) in L_REQLI_delete(...)") ;
             return TRUE ;
           }
        ok = L_REQLI_isEmpty(&reqli) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(2,5) in L_REQLI_isEmpty(...)") ;
             return TRUE ;
           }
        ok = L_REQLI_finalize(&reqli) ;

        /* 
         *  return ok. 
         */
        return TRUE ;
      }


   /* ................................................................. */

