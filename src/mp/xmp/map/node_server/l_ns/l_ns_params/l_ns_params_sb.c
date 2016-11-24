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

      #include "mp/xmp/map/node_server/l_ns/l_ns_params/l_ns_params_sb.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NS_PARAMS_SB_getInfoFromEnv 
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
        (*host)    =      getenv ("NS_HOST") ;
        (*port)    = atoi(getenv ("NS_PORT")) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"_PROC_ID = %d\n", 
                        (*nodeid) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"_N_PROCS = %d\n", 
                        (*nnodes) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_HOST  = %s\n", 
                        (*host) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_PORT  = %d\n", 
                        (*port) ) ;
        return TRUE ;
      }

      T_BOOL   L_NS_PARAMS_SB_getInfoFromEnv_SP2  
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
           {
             X_ALLOC_Free((void **)&(node_list)) ;
           }
        (node_list) = X_STRING_StrDup(getenv("LOADL_PROCESSOR_LIST")) ;
        paux = node_list + X_STRING_StrLen(node_list) - 1 ;
        /* paux    -> " localhost " */
        /*                       ^  */
        while (
                (paux != node_list)
                      &&
                ((*paux) == ' ')
              )
        {
          paux-- ;
        }
        paux[1] = '\0' ;
        /* paux    -> " localhost " */
        /*             ^            */
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
             L_TRACE_MSG_PrintF
             ( 
               DBG_WARNING,TRUE,
               "Empty LOADL_PROCESSOR_LIST !? (LOADL_PROCESSOR_LIST = %s)\n",
               node_list 
             ) ;
             (*host) = node_list ;
           }
        if ( paux != node_list )
           {
             (*host) = paux + 1 ;
             /* (*host) -> " localhost" */
             /*             ^           */
           }
 
 
/*deb*/
printf("getenv(\"LOADL_PROCESSOR_LIST\") = %s\n",
        getenv("LOADL_PROCESSOR_LIST")) ;
printf("node_list = %s\n",
        node_list) ;
printf("(*host) = %s\n",
        (*host)) ;
/*deb*/
 

        L_TRACE_MSG_PrintF( DEFCON_1,"_PROC_ID = %d\n", 
                        (*nodeid) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"_N_PROCS = %d\n", 
                        (*nnodes) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_HOST  = %s\n", 
                        (*host) ) ;
        L_TRACE_MSG_PrintF( DEFCON_1,"NS_PORT  = %d\n", 
                        (*port) ) ;
        return TRUE ;
      }

      T_BOOL  L_NS_PARAMS_SB_put          
      ( 
        IN       int              argc,
        IN       char           **argv,
        OUT      t_params_ns     *params 
      )
      {
        T_BOOL   ok ;
        T_INT    nodeid ;
        T_INT    nnodes ;
        T_CHAR  *host ;
        T_INT    port ;

        /* 
         *   Get Info
         */
        if (getenv("LOADL_PROCESSOR_LIST") == NULL)
           {
             /* .1.- enviroment */
             ok = L_NS_PARAMS_SB_getInfoFromEnv(&nodeid,&nnodes,
                                                &host,&port) ;
           }
        else
           {
             /* .2.- enviroment in SP2 */
             ok = L_NS_PARAMS_SB_getInfoFromEnv_SP2(&nodeid,&nnodes,
                                                    &host,&port) ;
           }
        FALSE_RET_FALSE(ok) ;

        /* 
         *   Put values
         */
        params->nodeid = nodeid ;
        params->nnodes = nnodes ;
        params->host   = host ;
        params->port   = port ;

        /*
         *  return ok
         */
        return TRUE ;
      }


   /* ................................................................. */

