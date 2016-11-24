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
     *   test 3
     *   ------
     *
     *   probe first and next.
     *
     */

      #include "mp/xmp/map/node/l_nodes/l_reqman/l_reqli.h"


      int main
      ( 
        IN       int   argc,
        IN       char *argv[]
      )
      {
        t_reqli   reqli ;
        t_reqRef  elto ;
        t_reqRef *pelto ;

        /* 
         *  begin
         */
        L_REQLI_init(&reqli) ;
        pelto = L_REQLI_first(&reqli) ;
        if (pelto != NULL)
           {
             fprintf(stderr,
                     "fail(3,1) in L_REQLI_first(...)") ;
             return TRUE ;
           }
        L_REQLI_insert(&reqli,&elto) ;
        pelto = L_REQLI_first(&reqli) ;
        if (pelto == NULL)
           {
             fprintf(stderr,
                     "fail(3,2) in L_REQLI_first(...)") ;
             return TRUE ;
           }
        if (pelto != &elto)
           {
             fprintf(stderr,
                     "fail(3,3) in L_REQLI_first(...)") ;
             return TRUE ;
           }
        pelto = L_REQLI_next(pelto) ;
        if (pelto != NULL)
           {
             fprintf(stderr,
                     "fail(3,4) in L_REQLI_next(...)") ;
             return TRUE ;
           }
        L_REQLI_finalize(&reqli) ;

        /* 
         *  return ok. 
         */
        return TRUE ;
      }


   /* ................................................................. */

