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


   void    skipTillChar  ( FILE  *out_files,
                           char   ch )
   {
     int  i ;
     char chaux ;

     i=0 ;
     do
     {
       fread(&(chaux),sizeof(char),1,out_files) ;
     } while ( (chaux != ch) && (!feof(out_files)) ) ;
   }

   char   *freadTillChar ( FILE  *out_files,
                           char   ch )
   {
     int i ;
     static char str[1024] ;

     i=0 ;
     memset(str,0,1024) ;
     do
     {
       fread(&(str[i]),sizeof(char),1,out_files) ;
       i++ ;
     } while ( (str[i-1] != ch) && (!feof(out_files)) ) ;
     str[i] = '\0' ;
     return str ;
   }

   double  media     ( double  *iarray,
                       int      first_test,
                       int      last_test )
   {
     int     i ;
     double  result ;

     result = 0.0 ;
     for (i=first_test; i<= last_test; i++)
     {
       result = result + iarray[i] ;
     }
     return ( (double)result / (double)(last_test - first_test + 1) ) ;
   }

   double  min       ( double  *iarray,
                       int      first_test,
                       int      last_test )
   {
     int     i ;
     double  result ;

     result = iarray[first_test] ;
     for (i=first_test+1; i<= last_test; i++)
     {
       if (iarray[i] < result)
           result = iarray[i] ;
     }
     return ( (double)result ) ;
   }

   double  max       ( double  *iarray,
                       int      first_test,
                       int      last_test )
   {
     int     i ;
     double  result ;

     result = iarray[first_test] ;
     for (i=first_test+1; i<= last_test; i++)
     {
       if (iarray[i] > result)
           result = iarray[i] ;
     }
     return ( (double)result ) ;
   }


   int  main ( int argc, char *argv[] )
   {
            int       i, first_test, last_test ;
            char     *p_name, *pstr, f_err, ch ;
            FILE     *fmedia, *fmin, *fmax ;
     static char      fout_name [1024] ;
     static FILE     *out_files [1024] ;
     static double    out_data  [1024] ;


     fprintf(stderr,
             "\n"
             "  test_reduce\n"
             " -------------\n"
             "\n") ;

     /* ... get params ... */
     f_err      = OFF ;
     p_name     = NULL ;
     first_test = 0 ;
     last_test  = 0 ;
     ch = getopt(argc,argv,"p:f:l:") ;
     while ( ch != EOF )
     {
       switch (ch)
       {
         case 'p' :
              p_name = strdup(optarg) ;
              break ;
         case 'f' :
              first_test = atoi(optarg) ;
              break ;
         case 'l' :
              last_test = atoi(optarg) ;
              break ;
         default : ;
              f_err = ON ;
       }
       ch = getopt(argc,argv,"p:f:l:") ;
     }
     if ( (f_err == ON) || (argc != 7) )
        {
          fprintf(stderr,
                  "\n"
                  "   usage: %s [options]\n"
                  "    -p <program name>\n"
                  "    -f <first test index>\n"
                  "    -l <last  test index>\n"
                  "\n"
                  "\n",
                  argv[0]) ;
          return TRUE ;
        }

     /* ... check params ... */
     if (p_name == NULL)
        {
          fprintf(stderr,
                  " I can NOT work with 'NULL' program name, sorry.\n"
                  "\n") ;
          return FALSE ;
        }
     if (last_test <= first_test)
        {
          fprintf(stderr,
                  " I can NOT reduce '0' tests, sorry.\n"
                  "\n") ;
          return FALSE ;
        }


     /* ... hand on ... */

     /* ... 1.- input files ... */
     for (i=first_test; i<= last_test; i++)
         {
           sprintf(fout_name,"%s.out.%i",
                   p_name,
                   i) ;
           out_files[i] = fopen(fout_name,"rt") ;
           if (out_files[i] == NULL)
              {
                fprintf(stderr,
                        " I can NOT open '%s' file, sorry.\n"
                        "\n",
                        fout_name) ;
                return FALSE ;
              }
         }

     /* ... 2.- output files ... */
     /* media */
     sprintf(fout_name,"%s.out.media",
             p_name) ;
     fmedia = fopen(fout_name,"wb") ;
     if (fmedia == NULL)
        {
          fprintf(stderr,
                  " I can NOT open output file '%s', sorry.\n"
                  "\n",
                  fout_name) ;
          return FALSE ;
        }
     /* min */
     sprintf(fout_name,"%s.out.min",
             p_name) ;
     fmin = fopen(fout_name,"wb") ;
     if (fmin == NULL)
        {
          fprintf(stderr,
                  " I can NOT open output file '%s', sorry.\n"
                  "\n",
                  fout_name) ;
          return FALSE ;
        }
     /* max */
     sprintf(fout_name,"%s.out.max",
             p_name) ;
     fmax = fopen(fout_name,"wb") ;
     if (fmax == NULL)
        {
          fprintf(stderr,
                  " I can NOT open output file '%s', sorry.\n"
                  "\n",
                  fout_name) ;
          return FALSE ;
        }

     /* ... 3.- working ... */
     fprintf(stderr,
             " reducing '%s.out.[%i-%i]' ...\n"
             "\n",
             p_name,first_test,last_test) ;
     while ( ! feof(out_files[first_test]) )
     {
       pstr = freadTillChar(out_files[first_test],'=') ;
       fscanf(out_files[first_test],"%le",&(out_data[first_test])) ;
       for (i=first_test+1; i<= last_test; i++)
           {
             skipTillChar(out_files[i],'=') ;
             fscanf(out_files[i],"%le",&(out_data[i])) ;
           }
       if (feof(out_files[first_test]))
          {
            fprintf(fmedia,"%s", pstr) ;
            fprintf(fmin,"%s",   pstr) ;
            fprintf(fmax,"%s",   pstr) ;
          }
       else /* (!feof(out_files[first_test])) */
          {
            fprintf(fmedia,"%s%e",
                    pstr,media(out_data,first_test,last_test)) ;
            fprintf(fmin,"%s%e",
                    pstr,min(out_data,first_test,last_test)) ;
            fprintf(fmax,"%s%e",
                    pstr,max(out_data,first_test,last_test)) ;
          }
     }

     /* ... end work ... */
     fclose(fmedia) ;
     fclose(fmin) ;
     fclose(fmax) ;
     for (i=first_test; i<= last_test; i++)
         {
           fclose(out_files[i]) ;
         }
     free(p_name) ;
     fprintf(stderr,
             "\n"
             " reduced.\n"
             "\n") ;
     return TRUE ;
   }


/* ..................................................................... */

