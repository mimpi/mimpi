/* ....................................................................
 *
 * Copyright Felix Garcia (1997-2000)
 * <fgarcia@laurel.datsi.fi.upm.es>
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "test_params.h"


   /* ... Funciones ................................................... */

      int   TEST_PARAMS_openFile
      (
        /* IN    */   char  *fnparam,
        /* IN    */   char  *fattrib,
        /* INOUT */   FILE **fparam
      )
      {
        char     *fcwd ;
        char     *fpath ;
        int       sfpath ;

        /*
         *  try set default values ...
         */
        if (fparam == NULL)
            return -1 ;
        (*fparam) = NULL ;

        /*
         *  try get full path ...
         */
#if defined(HAVE_WINDOWS_H)
        fcwd = _getcwd(NULL,0) ;
#else
        fcwd = (char *)getcwd(NULL,0) ;
#endif
        if (fcwd == NULL)
           {
             sfpath = 1 + 1 + strlen(fnparam) ;
             fpath = malloc(sfpath) ;
             if (fpath == NULL)
                {
                  printf("malloc(%i): ",sfpath) ; 
                  perror("") ; 
                  return -1 ;
                }
             sprintf(fpath,"./%s",fnparam) ;
           }
        else 
           {
             sfpath = strlen(fcwd) + 1 + strlen(fnparam) ;
             fpath = malloc(sfpath) ;
             if (fpath == NULL)
                {
                  printf("malloc(%i): ",sfpath) ; 
                  perror("") ; 
                  free(fcwd) ;
                  return -1 ;
                }
             sprintf(fpath,"%s/%s",fcwd,fnparam) ;
             free(fcwd) ;
           }

        /*
         *  try open file ...
         */
        (*fparam) = fopen(fpath,fattrib) ;
        if ((*fparam) == NULL)
           {
             printf("fopen(%s,%s): ",fpath,fattrib) ;
             perror("") ; 
             free(fpath) ;
             return -1 ;
           }

        /*
         *  return ok ...
         */
        free(fpath) ;
        return 1 ;
      }

      int   TEST_PARAMS_readLimits
      (
        /* IN    */   char *fnparam,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      )
      {
        int       ret ;
        FILE     *fparam ;

        /*
         *  try set default values ...
         */
        if (max_len == NULL)
            return -1 ;
        if (min_len == NULL)
            return -1 ;
        (*max_len) = -1 ;
        (*min_len) = -1 ;

        /*
         *  open file ...
         */
        ret = TEST_PARAMS_openFile(fnparam,"rt",&fparam) ;
        if (ret < 1)
            return -1 ;

        /*
         *  try get values ...
         */
        ret = fscanf(fparam,"max_len=%i",max_len) ;
        if (ret < 1)
           {
             fclose(fparam) ;
             printf("ERROR: can not read 'max_len' value from file.\n") ;
             return -1 ;
           }

        fscanf(fparam,"\n") ;

        ret = fscanf(fparam,"min_len=%i",min_len) ;
        if (ret < 1)
           {
             fclose(fparam) ;
             printf("ERROR: can not read 'min_len' value from file.\n") ;
             return -1 ;
           }

        /*
         *  return ok ...
         */
        return 1 ;
      }

      int   TEST_PARAMS_getLimits
      (
        /* IN    */   char *vfile,
        /* INOUT */   int  *max_len,
        /* INOUT */   int  *min_len
      )
      {
        int ret ;

        /*
         *  try get values ...
         */
        ret = TEST_PARAMS_readLimits(vfile,max_len,min_len) ;
        if (ret < 1)
           {
             printf("ERROR: can not read from %s, sorry.\n",vfile) ;
             return -1 ;
           }

        /*
         *  check values ...
         */
        if ( ((*max_len) <= 0) || ((*max_len) >= 32*1024*1024) )
           {
             printf("ERROR: ((*max_len) <= 0) || ((*max_len) >= 32*1024*1024)\n") ;
             return -1 ;
           }
        if ( ((*min_len) <= 0) || ((*min_len) >= 32*1024*1024) )
           {
             printf("ERROR: ((*min_len) <= 0) || ((*min_len) >= 32*1024*1024)\n") ;
             return -1 ;
           }
        if ( (*max_len) <= (*min_len) )
           {
             printf("ERROR: (*max_len) <= (*min_len)\n") ;
             return -1 ;
           }

        /*
         *  return ok
         */
        return 1 ;
      }


  /* .................................................................... */

