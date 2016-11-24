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



/*

    ToDo
    ----
    - First, user could say '-h host.list', and we 
     launch each node to machine according this file
     ( using perhaps 'rsh -c "..."' )

*/

/* ... Includes / Inclusiones .......................................... */

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <unistd.h>
   #include <fcntl.h>
   #include <sys/wait.h>
   #include <sys/stat.h>
   #include <sys/types.h>


/* ... Const / Constantes .............................................. */

   #define TRUE    (1)
   #define FALSE   (0)
   #define ON      (1)
   #define OFF     (0)


/* ... Functions / Funciones ........................................... */

   char *fr_basename ( char *buff,
                    char *argv0 )
   {
     char *pch ;

     sprintf(buff,"%s",argv0) ;
     pch    = strrchr(buff,'/') ;
     pch[1] = '\0' ;
     return buff ; /* skip '/' */
   }

   pid_t  spawn ( char **cl_arg )
   {
            pid_t  pid ;
     extern int    errno ;

     pid = fork() ;
     switch (pid)
     {
       case -1 :  /* error */
            fprintf(stderr,
                    " I can NOT do fork, sorry.\n") ;
            perror("fork: ") ;
            break ;
       case 0 :   /* son */
            execvp(cl_arg[0],cl_arg) ;
            fprintf(stderr,
                    " I can NOT do exec, sorry.\n") ;
            perror("execvp: ") ;
            exit(errno) ;
       default :  /* father */
            /* nothing */ ;
     }
     return pid ;
   }

   int  main ( int argc, char *argv[] )
   {
            pid_t  pid, wpid ;
            int    i, n_test, d_wait, status ;
            char   ch, f_err ;
            char  *p_name ;
            char  *pch ;
     static char  *p_argv      [1024] ;
     static char   ns_exe      [1024] ;
     static char   proc_id_str [1024] ;
     static char   n_procs_str [1024] ;



     fprintf(stderr,
             "\n"
             "  xmp_run\n"
             " ---------\n"
             "\n") ;

     /* ... get params ... */
     f_err  = OFF ;
     p_name = NULL ;
     n_test = 1 ;
     d_wait = 0 ;
     ch = getopt(argc,argv,"p:n:d") ;
     while ( ch != EOF )
     {
       switch (ch)
       {
         case 'p' :
              p_name = strdup(optarg) ;
              break ;
         case 'n' :
              n_test = atoi(optarg) ;
              break ;
         case 'd' :
              d_wait = atoi(optarg) ;
              break ;
         default : ;
              f_err = ON ;
       }
       ch = getopt(argc,argv,"p:n:d") ;
     }
     if ( (f_err == ON) || (argc < 7) )
        {
          fprintf(stderr,
                  "\n"
                  "   usage: %s [options]\n"
                  "    -p <program name>\n"
                  "    -n <number of nodes>\n"
                  "    -d <delay between launchs>\n"
                  "\n"
                  "\n",
                  argv[0]) ;
          return TRUE ;
        }

     /* ... check params ... */
     if (p_name == NULL)
        {
          fprintf(stderr,
                  " I can NOT exec 'NULL' program, sorry.\n") ;
          return FALSE ;
        }
     if (n_test == 0)
        {
          fprintf(stderr,
                  " I can NOT launch '0' program, sorry.\n") ;
          return FALSE ;
        }

     /* ... hand on ... */
     fprintf(stderr,
             " ready to launch '%s', '%i' nodes, waiting '%i' second ...\n"
             "\n",
             p_name,n_test,d_wait) ;
     p_argv[0] = "env" ;
     p_argv[1] = "NS_PORT=6500" ;
     p_argv[2] = "NS_HOST=localhost" ;
     pch       = fr_basename(ns_exe,argv[0]) ;
     strcat(pch,"ns.exe") ;
     p_argv[3] = ns_exe ;
     p_argv[4] = NULL ;

     pid = spawn(p_argv) ;
     if (pid == -1)
         return FALSE ;
     for (i=0; i< n_test; i++)
         {
           /* prepare enviroment ... */
           p_argv[0] = "env" ;
           p_argv[1] = "NS_PORT=6500" ;
           p_argv[2] = "NS_HOST=localhost" ;
           sprintf(proc_id_str,"_PROC_ID=%i",i) ;
           p_argv[3] = proc_id_str ;
           sprintf(n_procs_str,"_N_PROCS=%i",n_test) ;
           p_argv[4] = n_procs_str ;
           p_argv[5] = p_name ;
           p_argv[6] = NULL ;

           /* launch it ... */
           pid = spawn(p_argv) ;
           if (pid == -1)
               return FALSE ;
           if (pid > 0)
               fprintf(stderr,
                       " node[%i] launched.\n",
                       (int)pid) ;
           sleep(d_wait) ;
         }
     for (i=0; i< n_test + 1; i++)
         {
           wpid = wait(&status) ;
           fprintf(stderr,
                   " node[%i] end. (status=%i)\n",
                   (int)wpid, status) ;
         }

     /* ... end work ... */
     free(p_name) ;
     fprintf(stderr,
             "\n"
             " end xmp_run.\n"
             "\n") ;
     return TRUE ;
   }


/* ..................................................................... */

