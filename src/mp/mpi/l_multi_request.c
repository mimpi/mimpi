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

      #include "mp/mpi/l_multi_request.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL  L_MULTI_REQUEST_init      
      ( 
        T_INT          howLaunch,
        t_req_param   *param 
      )
      {
         T_BOOL     ok ;

         /*
          *  check params  
          */
         NULL_RET_FALSE(param) ;

         /*
          *  default values
          */
         param->counter   = 0L ;
         param->nodeli    = NULL ;
         param->howLaunch = howLaunch ;

         /*
          *  init
          */
         switch(param->howLaunch)
         {
		   case MR_JOIN_THREAD :
           case MR_JOINLESS_THREAD :
                ok = L_MR_THREAD_init(param) ;
			    break ;
           case MR_SYNC_FUNCTION :
                ok = L_MR_SYNC_init(param) ;
			    break ;
           case MR_ASYNC_FUNCTION :
                ok = L_MR_ASYNC_init(param) ;
			    break ;
		   default :
                ok = FALSE ;
			    break ;
         }

         /*
          *  return 'ok'
          */
         return ok ;
      }
 
      T_BOOL  L_MULTI_REQUEST_finalize 
      ( 
        t_req_param   *param 
      )
      {
         T_BOOL     ok ;

         /*
          *  check params  
          */
         NULL_RET_TRUE(param) ;

         /*
          *  finalize
          */
         switch(param->howLaunch)
         {
		   case MR_JOIN_THREAD :
           case MR_JOINLESS_THREAD :
                ok = L_MR_THREAD_finalize(param) ;
			    break ;
           case MR_SYNC_FUNCTION :
                ok = L_MR_SYNC_finalize(param) ;
			    break ;
           case MR_ASYNC_FUNCTION :
                ok = L_MR_ASYNC_finalize(param) ;
			    break ;
		   default :
                ok = FALSE ;
			    break ;
         }

         /*
          *  return 'ok'
          */
         return ok ;
      }

      T_BOOL  L_MULTI_REQUEST_send      
      ( 
        t_req_param   *param 
      )
      {
         T_BOOL     ok ;

         /*
          *  check params  
          */
         NULL_RET_TRUE(param) ;

         /*
          *  send
          */
         switch(param->howLaunch)
         {
		   case MR_JOIN_THREAD :
           case MR_JOINLESS_THREAD :
                ok = L_MR_THREAD_send(param) ;
			    break ;
           case MR_SYNC_FUNCTION :
                ok = L_MR_SYNC_send(param) ;
			    break ;
           case MR_ASYNC_FUNCTION :
                ok = L_MR_ASYNC_send(param) ;
			    break ;
		   default :
                ok = FALSE ;
			    break ;
         }

         /*
          *  return 'ok'
          */
         return ok ;
      }

      T_BOOL  L_MULTI_REQUEST_recv
      ( 
        t_req_param  *param 
      )
      {
         T_BOOL     ok ;

         /*
          *  check params  
          */
         NULL_RET_TRUE(param) ;

         /*
          *  receive
          */
         switch(param->howLaunch)
         {
		   case MR_JOIN_THREAD :
           case MR_JOINLESS_THREAD :
                ok = L_MR_THREAD_recv(param) ;
			    break ;
           case MR_SYNC_FUNCTION :
                ok = L_MR_SYNC_recv(param) ;
			    break ;
           case MR_ASYNC_FUNCTION :
                ok = L_MR_ASYNC_recv(param) ;
			    break ;
		   default :
                ok = FALSE ;
			    break ;
         }

         /*
          *  return 'ok'
          */
         return ok ;
      }


   /* ................................................................. */


