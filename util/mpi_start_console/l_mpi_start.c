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

      #include "l_mpi_start.h"


   /* ... Funciones ................................................... */

      T_BOOL   L_MPI_START_assist  ( void )
      {
         T_CHAR  *basebin ;
         T_CHAR  *launcher ;
         T_CHAR  *nnodes ;
         T_CHAR  *progname ;
         T_CHAR  *initialdir ;
         T_CHAR  *usermail ;

         T_INT    last ;
         T_CHAR  *largv[1024] ;


         /*
          *  get params
          */
         basebin  = L_BASEBIN_chose() ;
         launcher = L_RUNNER_chose() ;
         nnodes   = L_NNODES_chose() ;
         progname = L_PROGNAME_chose() ;

         /*
          *  be verbose
          */
         fprintf 
         (
           stdout,
           "\n"
           " Values to use will be :\n"
           "\n"
           "   basebin = %s\n"
           "   launcher = %s\n"
           "   nnodes   = %s\n"
           "   progname = %s\n"
           "\n"
           "\n",
           basebin,launcher,nnodes,progname
         ) ;

         /*
          *  build mpi_exec call
          */
         last = 0 ;
         largv[last] = malloc(1024) ;
         sprintf(largv[last], "env" ) ;
         last ++ ;
         largv[last] = malloc(1024) ;
         sprintf(largv[last], "REQUEST=%s",      launcher ) ;
         last ++ ;
         largv[last] = malloc(1024) ;
         sprintf(largv[last], "NNODES=%s",       nnodes ) ;
         last ++ ;
         largv[last] = malloc(1024) ;
         sprintf(largv[last], "PROG_NAME=%s",    progname ) ;
         last ++ ;
         largv[last] = malloc(1024) ;
         sprintf(largv[last], "NS_NAME=%s/%s",   basebin,"ns.exe" ) ;
         last ++ ;
         if (strncmp(launcher,"poe_xmp",strlen("poe_xmp")) == 0)
            {
              largv[last] = malloc(1024) ;
              sprintf(largv[last], "JOB_NAME=%s", progname) ;
              last ++ ;
              largv[last] = malloc(1024) ;
              sprintf(largv[last], "POE_NAME=%s", "poe") ;
              last ++ ;
              largv[last] = malloc(1024) ;
              initialdir = L_INITIALDIR_chose() ;
              sprintf(largv[last], "INITIALDIR=%s", initialdir) ;
              last ++ ;
              largv[last] = malloc(1024) ;
              usermail = L_USERMAIL_chose() ;
              sprintf(largv[last], "USERMAIL=%s", usermail) ;
              last ++ ;
            }
         if (strncmp(launcher,"poe_mpich",strlen("poe_mpich")) == 0)
            {
              largv[last] = malloc(1024) ;
              sprintf(largv[last], "JOB_NAME=%s", progname) ;
              last ++ ;
              largv[last] = malloc(1024) ;
              sprintf(largv[last], "MPIRUN_NAME=%s", "mpi") ;
              last ++ ;
              largv[last] = malloc(1024) ;
              initialdir = L_INITIALDIR_chose() ;
              sprintf(largv[last], "INITIALDIR=%s", initialdir) ;
              last ++ ;
              largv[last] = malloc(1024) ;
              usermail = L_USERMAIL_chose() ;
              sprintf(largv[last], "USERMAIL=%s", usermail) ;
              last ++ ;
            }
         if (strncmp(launcher,"mpirun_mpich",strlen("mpirun_mpich")) == 0)
            {
              largv[last] = malloc(1024) ;
              sprintf(largv[last], "MPIRUN_NAME=%s", "mpirun") ;
              last ++ ;
            }
         largv[last] = malloc(1024) ;
         sprintf(largv[last], "%s/%s", basebin,"mpi_exec.exe" ) ;
         largv[last+1] = NULL ;

         /*
          *  exec command
          */
         execvp(largv[0], largv) ;
         exit(-1) ;

         /*
          *  return ok
          */
         return TRUE ;
      }
 

  /* .................................................................... */


