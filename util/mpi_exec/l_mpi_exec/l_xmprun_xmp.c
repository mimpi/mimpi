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

      #include "l_xmprun_xmp.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_XMPRUN_XMP_parserRequest   
      ( 
        OUT     int       *nnodes, 
        OUT     T_CHAR   **xmp_runname, 
        OUT     T_CHAR   **progname 
      )
      {
         T_CHAR  *pch ;

         /* 
          *  default values 
          */
         (*nnodes)   = 0 ;
         (*xmp_runname)   = NULL ;
         (*progname) = NULL ;

         /* 
          *  nnodes 
          */
         pch = L_RUNNER_LIB_getValue("NNODES") ;
	 NULL_RET_FALSE(pch) ;
         (*nnodes) = atoi(pch) ;

         /* 
          *  xmp_runname 
          */
         pch = L_RUNNER_LIB_getValue("MPI_EXEC_NAME") ;
	 NULL_RET_FALSE(pch) ;
         (*xmp_runname) = pch ;

         /* 
          *  progname 
          */
         pch = L_RUNNER_LIB_getValue("PROG_NAME") ;
	 NULL_RET_FALSE(pch) ;
         (*progname) = pch ; 

         return TRUE ;
      }

      T_BOOL   L_XMPRUN_XMP_creatRunner     
      ( 
        IN      T_CHAR  *frunnerName,
        IN      T_CHAR  *frunnerOutput,
        IN      T_CHAR  *frunnerError,
        IN      int      nnodes, 
        IN      T_CHAR  *xmp_runname, 
        IN      T_CHAR  *progname 
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
                 "(%s -n %i -p %s -d 1 -e > %s) >& %s\n",
                  xmp_runname,nnodes,progname,
                  frunnerOutput,frunnerError) ;
         fclose(frunner) ;

         /* 
          *  return ok 
          */
         return TRUE ;
      }

      T_BOOL   L_XMPRUN_XMP_main
      ( 
        void 
      )
      {
         T_BOOL   ok ;
         pid_t    pid ;
         T_CHAR   runnerName[1024] ;
         T_CHAR   runnerOutput[1024] ;
         T_CHAR   runnerError[1024] ;
         T_CHAR   runnerJID[1024] ;

         /* req params */
         int      nnodes, nodeid ;
         T_CHAR  *xmp_runname, *progname ;


         /* 
          *  init 
          */
         pid              = getpid() ;
         nnodes           = 0 ;
         nodeid           = 0 ;
         xmp_runname      = NULL ;
         progname         = NULL ;

         /* 
          *  parser request 
          */
         ok = L_XMPRUN_XMP_parserRequest(&nnodes,
			                 &xmp_runname,
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
         sprintf(runnerOutput,
                 "./%li.err",
                 (T_U_LONG)pid) ;
         ok = L_XMPRUN_XMP_creatRunner(runnerName,
                                       runnerOutput,
                                       runnerError,
			               nnodes,
				       xmp_runname,
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


