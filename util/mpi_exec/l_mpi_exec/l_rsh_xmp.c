/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "l_sh_xmp.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_RSH_XMP_parserRequest  
      ( 
        OUT     int       *nnodes, 
        OUT     T_CHAR   **ns_path, 
        OUT     T_CHAR   **ns_name, 
        OUT     T_CHAR   **ns_host,
        OUT     T_CHAR   **prog_name,
        OUT     T_CHAR   **prog_host,
        OUT     T_CHAR   **prog_path
      )
      {
         T_CHAR  *pch ;

         /* 
          *  setup default values 
          */
         (*nnodes)    = 0 ;
         (*ns_path)   = NULL ;
         (*ns_name)   = NULL ;
         (*ns_host)   = NULL ;
         (*prog_name) = NULL ;
         (*prog_host) = NULL ;
         (*prog_path) = NULL ;

         /*  
          *  nnodes 
          */
         pch = L_RUNNER_LIB_getValue("NNODES") ;
         NULL_RET_FALSE(pch) ;
         (*nnodes) = atoi(pch) ;

         /*  
          *  ns_path 
          */
         pch = L_RUNNER_LIB_getValue("NS_PATH") ;
         NULL_RET_FALSE(pch) ;
         (*ns_path) = pch ; 

         /*  
          *  ns_name 
          */
         pch = L_RUNNER_LIB_getValue("NS_NAME") ;
         NULL_RET_FALSE(pch) ;
         (*ns_name) = pch ;

         /*  
          *  ns_host 
          */
         pch = L_RUNNER_LIB_getValue("NS_HOST") ;
         NULL_RET_FALSE(pch) ;
         (*ns_host) = pch ; 

         /*  
          *  prog_path 
          */
         pch = L_RUNNER_LIB_getValue("PROG_PATH") ;
         NULL_RET_FALSE(pch) ;
         (*prog_path) = pch ; 

         /*  
          *  prog_name 
          */
         pch = L_RUNNER_LIB_getValue("PROG_NAME") ;
         NULL_RET_FALSE(pch) ;
         (*prog_name) = pch ; 

         /*  
          *  prog_host 
          */
         pch = L_RUNNER_LIB_getValue("PROG_HOST") ;
         NULL_RET_FALSE(pch) ;
         (*prog_host) = pch ; 

         /*  
          *  return ok
          */
         return TRUE ;
      }

      T_BOOL   L_RSH_XMP_creatRunner    
      ( 
        IN      T_CHAR    *frunnerName,
        IN      T_CHAR    *frunnerOutput,
        IN      T_CHAR    *frunnerError,
        IN      T_CHAR    *fscriptName,
        IN      int        nnodes, 
        IN      T_CHAR    *ns_path, 
        IN      T_CHAR    *ns_name, 
        IN      T_CHAR    *ns_host, 
        IN      T_CHAR    *prog_path,
        IN      T_CHAR    *prog_name,
        IN      T_CHAR    *prog_host
      )
      {
         FILE  *fscript ;
         FILE  *frunner ;
         int    nodeid ;

         /*  
          *  fscriptName
          */
         fscript = fopen(fscriptName,"w") ;
         NULL_RET_FALSE(fscript) ;
         for (nodeid=0; nodeid<nnodes; nodeid++)
             {
               fprintf
               (
                 fscript,

                 "rsh %s \"( cd %s ; env NS_HOST=%s NS_PORT=7500"
                 "      _N_PROCS=%i _PROC_ID=%i ./%s )\" &\n",
                 prog_host,prog_path,ns_host,
		 nnodes,nodeid,prog_name
               ) ;
             }
         fprintf
         (
           fscript,

           "rsh %s \"( cd %s ; env NS_HOST=%s NS_PORT=7500"
           "      _N_PROCS=%i _PROC_ID=%i ./%s )\"\n",
           ns_host,ns_path,ns_host,
           nnodes,nnodes,ns_name
         ) ;
         fclose(fscript) ;

         /*  
          *  frunnerName
          */
         frunner = fopen(frunnerName,"w") ;
         NULL_RET_FALSE(frunner) ;
         fprintf
         (
           frunner,

           "#!/bin/sh\n"
           "echo \"running...\".\n"
           "(sh < %s > %s) >& %s \n",
           fscriptName,
           frunnerOutput,frunnerError
         ) ;
         fclose(frunner) ;

         /*  
          *  return ok 
          */
         return TRUE ;
      }

      T_BOOL   L_RSH_XMP_main
      ( 
        void 
      )
      {
         T_BOOL   ok ;
         pid_t    pid ;
         T_CHAR   runnerName[1024] ;
         T_CHAR   runnerOutput[1024] ;
         T_CHAR   runnerError[1024] ;
         T_CHAR   scriptName[1024] ;
         T_CHAR   runnerJID[1024] ;

         /* req params */
         int      nnodes, nodeid ;
         T_CHAR  *ns_path, *ns_name, *ns_host ;
         T_CHAR  *prog_path, *prog_name, *prog_host ;


         /* 
          *  setup default values 
          */
         pid       = getpid() ;
         nnodes    = 0 ;
         nodeid    = 0 ;
         ns_path   = NULL ;
         ns_name   = NULL ;
         ns_host   = NULL ;
         prog_path = NULL ;
         prog_name = NULL ;
         prog_host = NULL ;

         /*  
          *  parser request 
          */
         ok = L_RSH_XMP_parserRequest(&nnodes,
                                      &ns_path,
                                      &ns_name,
                                      &ns_host,
                                      &prog_name,
                                      &prog_host,
                                      &prog_path) ;
         FALSE_RET_FALSE(ok) ;

         /*  
          *  build runner 
          */
         sprintf(runnerName,
                 "./%li.sh",
                 (T_U_LONG)pid) ;
         sprintf(runnerOutput,
                 "./%li.out",
                 (T_U_LONG)pid) ;
         sprintf(runnerError,
                 "./%li.err",
                 (T_U_LONG)pid) ;
         sprintf(scriptName,
                 "./%li.script",
                 (T_U_LONG)pid) ;
         ok = L_RSH_XMP_creatRunner(runnerName,
                                    runnerOutput,
                                    runnerError,
                                    scriptName,
			            nnodes,
                                    ns_path,
                                    ns_name,
                                    ns_host,
                                    prog_path,
				    prog_name,
                                    prog_host) ;
         FALSE_RET_FALSE(ok) ;

         /*  
          *  exec laucher 
          */
         sprintf(runnerJID,
                 "./%li.jid",
                 (T_U_LONG)pid) ;
         ok = L_RUNNER_LIB_execRunner(runnerJID,
                                      runnerJID,
                                      runnerName) ;
         FALSE_RET_FALSE(ok) ;

         /*
          *  return
          */
         return FALSE ;
      }
 

  /* .................................................................... */


