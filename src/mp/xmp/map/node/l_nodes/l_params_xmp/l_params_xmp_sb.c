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

      #include "mp/xmp/map/node/l_nodes/l_params_xmp.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_PARAMS_XMP_SB_getInfoFromEnv 
      (
         OUT      T_INT         *nodeid,
         OUT      T_INT         *nnodes,
         OUT      char         **host,
         OUT      int           *port 
      )
      {
        /* 
         *  checking 
         */
        if ((getenv ("_PROC_ID") == NULL))
           {
             fprintf (stderr, "_PROC_ID must be in enviroment\n") ;
             return FALSE ;
           }
        if ((getenv ("_N_PROCS") == NULL))
           {
             fprintf (stderr, "_N_PROCS must be in enviroment\n") ;
             return FALSE ;
           }
        if ((getenv ("NS_HOST") == NULL))
           {
             fprintf (stderr, "NS_HOST must be in enviroment\n") ;
             return FALSE ;
           }
        if ((getenv ("NS_PORT") == NULL))
           {
             fprintf (stderr, "NS_PORT must be in enviroment\n") ;
             return FALSE ;
           }

        /* 
         *  setup node
         */
        (*nodeid) = atoi(getenv ("_PROC_ID")) ;
        (*nnodes) = atoi(getenv ("_N_PROCS")) ;
        (*host)   =      getenv ("NS_HOST") ;
        (*port)   = atoi(getenv ("NS_PORT")) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"_PROC_ID = %d", 
                        (*nodeid) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"_N_PROCS = %d", 
                        (*nnodes) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_HOST  = %s", 
                        (*host) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_PORT  = %d", 
                        (*port) ) ;

        /* 
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL   L_PARAMS_XMP_SB_getInfoFromEnv_SP2  
      (
        OUT      T_INT         *nodeid,
        OUT      T_INT         *nnodes,
        OUT      char         **host,
        OUT      int           *port 
      )
      {
        static T_CHAR *node_list = NULL ;
               T_CHAR *paux ;

        /* 
         *  checking 
         */
        if ((getenv ("_N_PROCS") == NULL))
           {
             fprintf (stderr, "_N_PROCS must be in enviroment\n") ;
             return FALSE ;
           }
        if ((getenv ("_PROC_ID") == NULL))
           {
             fprintf (stderr, "_PROC_ID must be in enviroment\n") ;
             return FALSE ;
           }
        if ((getenv ("NS_PORT") == NULL))
           {
             fprintf (stderr, "NS_PORT must be in enviroment\n") ;
             return FALSE ;
           }
        if ((getenv ("LOADL_PROCESSOR_LIST") == NULL))
           {
             fprintf (stderr, "LOADL_PROCESSOR_LIST must be in enviroment\n") ;
             return FALSE ;
           }

        /* 
         *  setup node
         */
        (*nodeid) = atoi(getenv ("_PROC_ID")) ;
        (*nnodes) = atoi(getenv ("_N_PROCS")) ;
        (*port)   = atoi(getenv ("NS_PORT")) ;
        if (node_list != NULL)
            X_ALLOC_Free((void **)&(node_list)) ;
        (node_list) = X_STRING_StrDup(getenv("LOADL_PROCESSOR_LIST")) ;

        /*            " localhost " */
        /* paux    ->            ^  */
        paux = node_list + X_STRING_StrLen(node_list) - 1 ;

        /*            " localhost"  */
        /* paux    ->            ^  */
        while (
                (paux != node_list)
                      &&
                ((*paux) == ' ')
              )
        {
          paux-- ;
        }
        paux[1] = '\0' ;

        /*            " localhost"  */
        /* paux    ->  ^            */
        while (
                (paux != node_list)
                      &&
                ((*paux) != ' ')
              )
        {
          paux-- ;
        }

        if ( paux == node_list )
           {
             L_TRACE_MSG_PrintF( DBG_WARNING,TRUE,
                                  "Empty LOADL_PROCESSOR_LIST !? (LOADL_PROCESSOR_LIST = %s)",
                                  node_list ) ;
             (*host) = node_list ;
           }
        if ( paux != node_list )
           {
             /*            " localhost" */
             /* (*host) ->   ^          */
             (*host) = paux + 1 ;
           }
 
        L_TRACE_MSG_PrintF( DEFCON_1,"_PROC_ID = %d", 
                        (*nodeid) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"_N_PROCS = %d", 
                        (*nnodes) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_HOST  = %s", 
                        (*host) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_PORT  = %d", 
                        (*port) ) ;

        /* 
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL  L_PARAMS_XMP_SB_put
      (
         IN     int            argc,
         IN     char         **argv,
         IN     char         **envv,
         OUT    t_params_xmp  *params
      )
      {
        T_BOOL   ok ;
        T_INT    nodeid ;
        T_INT    nnodes ;
        T_CHAR  *host ;
        T_INT    port ;

        /* 
         * Get Info
         */
        if (getenv("LOADL_PROCESSOR_LIST") == NULL)
           {
             /* .1.- enviroment */
             ok = L_PARAMS_XMP_SB_getInfoFromEnv(&nodeid,&nnodes,
                                                 &host,&port) ;
           }
        else
           {
             /* .2.- enviroment in SP2 */
             ok = L_PARAMS_XMP_SB_getInfoFromEnv_SP2(&nodeid,&nnodes,
                                                     &host,&port) ;
           }
        FALSE_RET_FALSE(ok) ;

        /* 
         * Put values
         */
        params->nodeid = nodeid ;
        params->nnodes = nnodes ;
        params->host   = host ;
        params->port   = port ;

        /* 
         * return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

