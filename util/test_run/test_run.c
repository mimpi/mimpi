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


   int  main ( int argc, char *argv[] )
   {
            pid_t  pid, wpid ;
            int    i, n_test, d_wait, status, o_sav ;
            char   ch, f_err ;
            char  *p_name ;
     static char  *p_argv    [1024] ;
     static char   fout_name [1024] ;


     fprintf(stderr,
             "\n"
             "  test_run\n"
             " ----------\n"
             "\n") ;

     /* ... get params ... */
     f_err  = OFF ;
     p_name = NULL ;
     n_test = 1 ;
     d_wait = 0 ;
     ch = getopt(argc,argv,"p:n:d:") ;
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
       ch = getopt(argc,argv,"p:n:d:") ;
     }
     if ( (f_err == ON) || (argc != 7) )
        {
          fprintf(stderr,
                  "\n"
                  "   usage: %s [options]\n"
                  "    -p <program name>\n"
                  "    -n <number of tests>\n"
                  "    -d <delay between>\n"
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
                  " I can NOT do '0' tests, sorry.\n") ;
          return FALSE ;
        }

     /* ... hand on ... */
     fprintf(stderr,
             " executing '%s' '%i' times, waiting '%i' second\n"
             "\n",
             p_name,n_test,d_wait) ;
     for (i=0; i< n_test; i++)
         {
           /* prepare enviroment ... */
           p_argv[0] = p_name ;
           p_argv[1] = NULL ;
           sprintf(fout_name,"%s.out.%i",
                   p_name,
                   i) ;
           o_sav = dup(1) ;
           close(1) ;
           open(fout_name,O_RDWR | O_CREAT | O_TRUNC,0700) ;

           /* launch it ... */
           pid = fork() ;
           switch (pid)
           {
             case -1 :  /* error */
                  fprintf(stderr,
                          " I can NOT do fork, sorry.\n") ;
                  perror("fork: ") ;
                  return FALSE ;
             case 0 :   /* son */
                  execvp(p_argv[0],p_argv) ;
                  fprintf(stderr,
                          " I can NOT do exec, sorry.\n") ;
                  perror("execvp: ") ;
                  return FALSE ;
             default :  /* father */
                  close(1) ;
                  dup(o_sav) ;
                  close(o_sav) ;
                  fprintf(stderr,
                          " Test[%i] launch.\n",i) ;
                  do
                  {
                    wpid = wait(&status) ;
                  } while ( wpid != pid ) ;
                  fprintf(stderr,
                          " Test[%i] end.\n",i) ;
           }
           sleep(d_wait) ;
         }

     /* ... end work ... */
     free(p_name) ;
     fprintf(stderr,
             "\n"
             " executed.\n"
             "\n") ;
     return TRUE ;
   }


/* ..................................................................... */

