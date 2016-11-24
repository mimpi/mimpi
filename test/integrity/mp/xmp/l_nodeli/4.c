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
     *   test 4
     *   ------
     *
     *   probe garbage collection.
     *
     */

      #include "mp/xmp/map/node/l_nodes/l_reqman/l_reqli.h"


      int main
      ( 
        IN       int   argc,
        IN       char *argv[]
      )
      {
        T_BOOL     ok ;
        t_reqli    reqli ;
        t_nodeReq *req ;
        t_reqRef  *pelto ;

        /* 
         *  begin
         */
        ok = L_REQLI_init(&reqli) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(4,1) to L_REQLI_init(...)") ;
             return TRUE ;
           }

        /* 
         *  alloc pelto
         */
        ok = L_REQLI_allocReqAndInsert(&reqli,&pelto) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(4,2) to L_REQLI_allocReqAndInsert(...)") ;
             return TRUE ;
           }

        /* 
         *  fill peslabon
         */
        req = malloc(c_NODEREQ) ;
        if (req == NULL)
           {
             fprintf(stderr,
                     "fail(4,3) to malloc(...)") ;
             return TRUE ;
           }
        pelto->req      = req ;
        pelto->isMalloc = TRUE ;

        /* 
         *  delete
         */
        ok = L_REQLI_delete(&reqli,pelto) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(2,4) in L_REQLI_delete(...)") ;
             return TRUE ;
           }

        /* 
         *  finalize
         */
        ok = L_REQLI_finalize(&reqli) ;
        if (ok == FALSE)
           {
             fprintf(stderr,
                     "fail(4,2) to L_REQLI_finalize(...)") ;
             return TRUE ;
           }

        /* 
         *  return ok. 
         */
        return TRUE ;
      }


   /* ................................................................. */

