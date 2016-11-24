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

      #include "l_mpirun_mpich.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_MPIRUN_MPICH_parserRequest  
      ( 
        OUT     int       *nnodes, 
        OUT     T_CHAR   **mpirunname, 
        OUT     T_CHAR   **progname 
      )
      {
         T_CHAR  *pch ;

         /* 
          *  set default values
          */
         (*nnodes)   = 0 ;
         (*mpirunname)   = NULL ;
         (*progname) = NULL ;

         /* 
          *  nnodes 
          */
         pch = L_RUNNER_LIB_getValue("NNODES") ;
	 NULL_RET_FALSE(pch) ;
         (*nnodes) = atoi(pch) ;

         /* 
          *  mpirunname 
          */
         pch = L_RUNNER_LIB_getValue("MPIRUN_NAME") ;
	 NULL_RET_FALSE(pch) ;
         (*mpirunname) = pch ;

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

      T_BOOL   L_MPIRUN_MPICH_creatRunner    
      ( 
        IN      T_CHAR    *frunnerName,
        IN      T_CHAR    *frunnerOutput,
        IN      T_CHAR    *frunnerError,
        IN      int        nnodes, 
        IN      T_CHAR    *mpirunname, 
        IN      T_CHAR    *progname 
      )
      {
         FILE  *frunner ;

         /* 
          *  frunnerName 
          */
         frunner = fopen(frunnerName,"w") ;
         NULL_RET_FALSE(frunner) ;
         fprintf(frunner,
                 "#!/bin/csh\n") ;
         fprintf(frunner,
                 "echo \"running...\".\n") ;
         fprintf(frunner,
                 "(%s -n %i %s > %s) >& %s\n",
                  mpirunname,nnodes,progname,
                  frunnerOutput,frunnerError) ;
         fclose(frunner) ;

         /* 
          *  return ok 
          */
         return TRUE ;
      }

      T_BOOL   L_MPIRUN_MPICH_main ( void )
      {
         T_BOOL   ok ;
         pid_t    pid ;
         T_CHAR   runnerName[1024] ;
         T_CHAR   runnerOutput[1024] ;
         T_CHAR   runnerError[1024] ;
         T_CHAR   runnerJID[1024] ;

         /* 
          *  req params 
          */
         int      nnodes, nodeid ;
         T_CHAR  *mpirunname, *progname ;


         /* 
          *  init 
          */
         pid          = getpid() ;
         nnodes       = 0 ;
         nodeid       = 0 ;
         mpirunname   = NULL ;
         progname     = NULL ;

         /* 
          *  parser request 
          */
         ok = L_MPIRUN_MPICH_parserRequest(&nnodes,
			                   &mpirunname,
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
         ok = L_MPIRUN_MPICH_creatRunner(runnerName,
			                 runnerOutput,
			                 runnerError,
			                 nnodes,
					 mpirunname,
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


