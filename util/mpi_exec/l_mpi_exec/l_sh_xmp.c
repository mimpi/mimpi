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

      T_BOOL   L_SH_XMP_parserRequest  
      ( 
        OUT     int       *nnodes, 
        OUT     T_CHAR   **nsname, 
        OUT     T_CHAR   **progname 
      )
      {
         T_CHAR  *pch ;

         /* 
          *  setup default values 
          */
         (*nnodes)   = 0 ;
         (*nsname)   = NULL ;
         (*progname) = NULL ;

         /*  
          *  nnodes 
          */
         pch = L_RUNNER_LIB_getValue("NNODES") ;
         NULL_RET_FALSE(pch) ;
         (*nnodes) = atoi(pch) ;

         /*  
          *  nsname 
          */
         pch = L_RUNNER_LIB_getValue("NS_NAME") ;
         NULL_RET_FALSE(pch) ;
         (*nsname) = pch ;

         /*  
          *  progname 
          */
         pch = L_RUNNER_LIB_getValue("PROG_NAME") ;
         NULL_RET_FALSE(pch) ;
         (*progname) = pch ; 

         /*  
          *  return ok
          */
         return TRUE ;
      }

      T_BOOL   L_SH_XMP_creatRunner    
      ( 
        IN      T_CHAR    *frunnerName,
        IN      T_CHAR    *frunnerOutput,
        IN      T_CHAR    *frunnerError,
        IN      T_CHAR    *fscriptName,
        IN      int        nnodes, 
        IN      T_CHAR    *nsname, 
        IN      T_CHAR    *progname 
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

                 "( env NS_HOST=localhost NS_PORT=7500"
                 "      _N_PROCS=%i _PROC_ID=%i %s & ) \n",
                 nnodes,nodeid,progname
               ) ;
             }
         fprintf
         (
           fscript,

           "( env NS_HOST=localhost NS_PORT=7500"
           "      _N_PROCS=%i _PROC_ID=%i %s )\n",
           nnodes,nnodes,nsname
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

      T_BOOL   L_SH_XMP_main
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
         T_CHAR  *nsname, *progname ;


         /* 
          *  setup default values 
          */
         pid      = getpid() ;
         nnodes   = 0 ;
         nodeid   = 0 ;
         nsname   = NULL ;
         progname = NULL ;

         /*  
          *  parser request 
          */
         ok = L_SH_XMP_parserRequest(&nnodes,
                                     &nsname,
                                     &progname) ;
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
         ok = L_SH_XMP_creatRunner(runnerName,
                                   runnerOutput,
                                   runnerError,
                                   scriptName,
			           nnodes,
                                   nsname,
				   progname) ;
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


