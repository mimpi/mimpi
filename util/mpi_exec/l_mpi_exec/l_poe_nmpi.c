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

      #include "l_poe_nmpi.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_POE_NMPI_parserRequest 
      ( 
        OUT     int       *nnodes,
        OUT     T_CHAR   **poename,
        OUT     T_CHAR   **jobname,
        OUT     T_CHAR   **initialdir,
        OUT     T_CHAR   **usermail,
        OUT     T_CHAR   **progname 
      )
      {
         T_CHAR  *pch ;

         /* 
          *  init 
          */
         (*nnodes)       = 0 ;
         (*poename)      = NULL ;
         (*jobname)      = NULL ;
         (*initialdir)   = NULL ;
         (*usermail)     = NULL ;
         (*progname)     = NULL ;

         /* 
          *  nnodes 
          */
         pch = L_RUNNER_LIB_getValue("NNODES") ;
	 NULL_RET_FALSE(pch) ;
         (*nnodes) = atoi(pch) ;

         /* 
          *  jobname 
          */
         pch = L_RUNNER_LIB_getValue("JOB_NAME") ;
	 NULL_RET_FALSE(pch) ;
         (*jobname) = pch ;

         /* 
          *  poename 
          */
         pch = L_RUNNER_LIB_getValue("POE_NAME") ;
	 NULL_RET_FALSE(pch) ;
         (*poename) = pch ;

         /* 
          *  initialdir 
          */
         pch = L_RUNNER_LIB_getValue("INITIALDIR") ;
	 NULL_RET_FALSE(pch) ;
         (*initialdir) = pch ;

         /* 
          *  usermail 
          */
         pch = L_RUNNER_LIB_getValue("USERMAIL") ;
	 NULL_RET_FALSE(pch) ;
         (*usermail) = pch ;

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

      T_BOOL   L_POE_NMPI_creatRunner   
      ( 
        IN      T_CHAR    *frunnerName,
        IN      T_CHAR    *frunnerOutput,
        IN      T_CHAR    *frunnerError,
        IN      T_CHAR    *fcmdFileName,
        IN      T_CHAR    *fprocFileName,
        IN      T_CHAR    *initialdir,
        IN      T_CHAR    *usermail,
        IN      T_CHAR    *jobname,
        IN      T_CHAR    *poename,
        IN      T_CHAR    *progname,
        IN      int        nnodes 
      )
      {
         FILE  *frunner ;
         FILE  *fcmd ;
         FILE  *fproc ;
         int    nodeid ;

         /* 
          *  fprocFileName 
          */
         fproc = fopen(fprocFileName,"w") ;
         NULL_RET_FALSE(fproc) ;
         for (nodeid=0; nodeid<nnodes; nodeid++)
             {
               fprintf
               (
                 fproc,
                 "%s &\n",
                 progname
               ) ;
             }
          ;
         fclose(fproc) ;

         /* 
          *  fcmdFileName 
          */
         fcmd = fopen(fcmdFileName,"w") ;
         NULL_RET_FALSE(fcmd) ;
         fprintf
         (
           fcmd,

           "#!/bin/csh\n"
           "# @ job_name       = %s\n"
           "# @ output         = %s\n"
           "# @ error          = %s\n"
           "# @ initialdir     = %s\n"
           "# @ job_type       = parallel\n"
           "# @ class          = parallel\n"
           "# @ min_processors = %i\n"
           "# @ max_processors = %i\n"
	   "# @ notify_user    = %s\n"
           "# @ environment    = MP_EUILIB=us; MP_EUIDEVICE=css0;"
           "                     MP_PROCS=%i; MP_PGMMODEL=mpmd;"
           "                     MP_NEWJOB=yes;\n"
           "# notification     = complete\n"
           "# @ requirements   = (Adapter == \"hps_user\")\n"
           "# @ restart        = yes\n"
           "# @ queue\n"
           "%s -procs %i < %s/%s\n"
           "quit\n",

           jobname,frunnerOutput,frunnerError,initialdir,
	   nnodes,nnodes,usermail,nnodes,poename,nnodes,
           initialdir,fprocFileName
         ) ;
         fclose(fcmd) ;

         /*
          *  frunnerName
          */
         frunner = fopen(frunnerName,"w") ;
         NULL_RET_FALSE(frunner) ;
         fprintf
         (
           frunner,

           "#!/bin/sh\n"
           "llsubmit %s\n",
           fcmdFileName
         ) ;
         fclose(frunner) ;

         /*
          *  return ok
          */
         return TRUE ;
      }

      T_BOOL   L_POE_NMPI_main    
      ( 
        void 
      )
      {
         T_BOOL   ok ;
         pid_t    pid ;
         T_CHAR   runnerName[1024] ;
         T_CHAR   runnerOutput[1024] ;
         T_CHAR   runnerError[1024] ;
         T_CHAR   procFileName[1024] ;
         T_CHAR   cmdFileName[1024] ;
         T_CHAR   runnerJID[1024] ;

         /* req params */
         int      nnodes, nodeid ;
         T_CHAR  *progname, *poename, *jobname ;
         T_CHAR  *usermail, *initialdir ;


         /* 
          *  init 
          */
         pid          = getpid() ;
         nnodes       = 0 ;
         nodeid       = 0 ;
         jobname      = NULL ;
         poename      = NULL ;
         progname     = NULL ;
         initialdir   = NULL ;
         usermail     = NULL ;

         /* 
          *  parser request 
          */
         ok = L_POE_NMPI_parserRequest(&nnodes,
				       &poename,
                                       &jobname,
				       &initialdir,
				       &usermail,
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
         sprintf(procFileName,
                 "./%li.proc",
                 (T_U_LONG)pid) ;
         sprintf(cmdFileName,
                 "./%li.cmd",
                 (T_U_LONG)pid) ;
         ok = L_POE_NMPI_creatRunner(runnerName,
                                     runnerOutput,
                                     runnerError,
                                     cmdFileName,
                                     procFileName,
                                     initialdir,
                                     usermail,
                                     jobname,
                                     poename,
                                     progname,
                                     nnodes) ;
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


