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

      #include "l_runner_lib.h"


   /* ... Funciones ................................................... */

      T_CHAR  *L_RUNNER_LIB_getValue
      ( 
        IN      T_CHAR    *value 
      )
      {
         T_CHAR  *pch ;

         /* 
          *  try get value...
          */
         pch = getenv(value) ;
         if (pch == NULL)
            {
              fprintf( stderr,
                       "You forgot \"%s=...\"\n",
		       value ) ;
              return NULL ;
            }

         /* 
          *  ...and return it.
          */
         return pch ;
      }

      T_BOOL   L_RUNNER_LIB_execRunner
      ( 
        IN      T_CHAR    *runnerOutput,
        IN      T_CHAR    *runnerError,
        IN      T_CHAR    *runnerName 
      )
      {
         T_INT    ret ;
         int      frunnerOutput ;
         int      frunnerError ;
         T_CHAR  *runnerArgv[2] ;

         /* 
          *  open output & error
          */
         frunnerOutput = open( runnerOutput, 
                                 O_WRONLY | O_CREAT | O_TRUNC,
                                 S_IRWXU ) ;
         NULL_RET_FALSE(frunnerOutput) ;

         frunnerError  = open( runnerError, 
                                 O_WRONLY | O_CREAT | O_TRUNC,
                                 S_IRWXU ) ;
         NULL_RET_FALSE(frunnerError) ;

         /* 
          *  connect output & error to client 
          */
         close(1) ;
         dup(frunnerOutput) ;
         close(frunnerOutput) ;

         close(2) ;
         dup(frunnerError) ;
         close(frunnerError) ;

         /* 
          *  try exec laucher
          */
         runnerArgv[0] = runnerName ;
         runnerArgv[1] = NULL ;
         ret = chmod(runnerArgv[0],
                     S_IRUSR | S_IWUSR | S_IXUSR | S_IXGRP ) ;
         if (ret < 0)
             perror("chmod") ;
         ret = execvp(runnerArgv[0],runnerArgv) ;
         if (ret < 0)
             perror("execvp") ;

         /* 
          *  fail
          */
         fprintf( stderr,
                  "execvp can exec \"%s\".\n",
                  runnerArgv[0] ) ;
         fflush(stderr) ;
         return FALSE ;
      }


  /* .................................................................... */


