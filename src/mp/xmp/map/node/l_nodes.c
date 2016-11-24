/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/xmp/map/node/l_nodes.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODES_init         
      ( 
        OUT      t_nodeInfo      *node_info,
        IN       int             *argc,
        IN       char          ***argv 
      )
      {
        T_BOOL ok ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  init l_nodecmd 
         */
        ok = L_NODECMD_init(node_info,argc,argv) ;

        /*
         *  return 'ok'.
         */
        return ok ;
      }

      T_BOOL   L_NODES_request
      (
        INOUT    t_nodeInfo    *node_info,
        IN       T_INT         *nodeli,
        INOUT    t_nodeReq     *request
      )
      {
        T_BOOL ok ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(request) ;

        /*
         *  do request
         */
        switch ( request->requestId )
        {
          case REQ_SEND_X_SYNC :
               ok = L_NODECMD_send_X_sync(node_info,
                                          request,
                                          nodeli) ;
               break ;
          case REQ_SEND_X_ASYNC :
               ok = L_NODECMD_send_X_async(node_info,
                                           request,
                                           nodeli) ;
               break ;
          case REQ_RECEIVE_X_SYNC :
               ok = L_NODECMD_receive_X_sync(node_info,
                                             request,
                                             nodeli) ;
               break ;
          case REQ_RECEIVE_X_ASYNC :
               ok = L_NODECMD_receive_X_async(node_info,
                                              request,
                                              nodeli) ;
               break ;
          case REQ_RECEIVE_ANY_SYNC :
               ok = L_NODECMD_receive_ANY_sync(node_info,
                                               request,
                                               nodeli) ;
               break ;
          case REQ_RECEIVE_ANY_ASYNC :
               ok = L_NODECMD_receive_ANY_async(node_info,
                                                request,
                                                nodeli) ;
               break ;
          case REQ_WAIT :
               ok = L_NODECMD_wait(request) ;
               break ;
          default :
               ok = FALSE ;
               break ;
        }

        /*
         *  return 'ok'.
         */
        return ok ;
      }

      T_BOOL   L_NODES_finalize     
      ( 
         OUT      t_nodeInfo      *node_info 
      )
      {
        T_BOOL ok ;

        /*
         *  check params
         */
        NULL__SET_ERROR__RET_FALSE(node_info) ;

        /*
         *  finalize node
         */
        ok = L_NODECMD_finalize((node_info)) ;

        /*
         *  return 'ok'.
         */
        return ok ;
      }


   /* ................................................................. */

