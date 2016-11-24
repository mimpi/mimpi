/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/mpi/node.h"


   /* ... Glob. var / Var. globales ................................... */

      t_nodeInfo  NODE_info ;
      T_BOOL      NODE_active = FALSE ;


   /* ... Functions / Funciones ....................................... */

      int NODE_init
      (
        IN    int     *argc,
        IN    char  ***argv
      )
      {
        T_BOOL ok ;

        /* 
         *  try init node
         */
        ok = L_NODES_init(&NODE_info,argc,argv) ;
        FALSE_RET_FALSE(ok) ;

        /* 
         *  node is booted !
         */
        NODE_active = TRUE ;
        return TRUE ;
      }

      int NODE_finalize
      (
        void
      )
      {
        T_BOOL ok ;

        /* 
         *  try finish node
         */
        ok = L_NODES_finalize(&NODE_info) ;
        FALSE_RET_FALSE(ok) ;

        /* 
         *  node is shutdown !
         */
        NODE_active = FALSE ;
        return TRUE ;
      }

      void NODE_request
      (
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request,
        IN       T_INT      *nodeli,
        IN       T_INT       reqid,
        IN       int         tx,
        IN       int         ty,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      )
      {
        /*
         *  init req. values
         */
        L_NODEREQ_init_2
	    ( 
    	  request,
          reqid,
          tx,
          ty,
          data_buff,
          data_size,
          from,
          to 
    	) ;

        /*
         *  do request
         */
        (*ok) = L_NODES_request
	            ( 
            	  &(NODE_info),
                  (nodeli),
                  (request) 
            	) ;
      }

      void NODE_wait
      (
        INOUT    T_BOOL     *ok,
        INOUT    t_nodeReq  *request
      )
      {
        /*
         *  wait request
         */
        (request->requestId) = REQ_WAIT ;

        /*
         *  do request
         */
        (*ok) = L_NODES_request
	            ( 
            	  &(NODE_info),
                  (NULL),
                  (request) 
            	) ;
      }


   /* ................................................................. */


