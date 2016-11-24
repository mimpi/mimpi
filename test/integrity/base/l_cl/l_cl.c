/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


/*
 *
 *  prove l_cl.c
 *
 */

	#include "base/l_basic/c_basic.h"
	#include "base/l_cl/l_cl.h"


	int main  
        (
          int   	argc,
	  char	       *argv[]	
        )
	{
          /*
           *  options cfg
           */
          T_INT   p_number =
                  2 ;
          T_CHAR *p_name[] =
                  {
                    "NS_HOST",
                    "NS_PORT"
                  } ;
          T_CHAR *p_help[] =
                  {
                    "nodeServer host",
                    "nodeServer port"
                  } ;
          T_BOOL  p_alone[] =
                  {
                    FALSE,
                    FALSE
                  } ;

          /*
           *  options
           */
          T_BOOL           ok ;
          t_listOptions    cl_opt ;
          t_cl_option     *elto_opt ;
          T_INT            i ;

          /*
           *  values
           */
          T_CHAR          *host ;
          T_INT            port ;


		/*
                 */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

                /*
                 *  setup our options
                 */
                _DO_( ok = L_CL_SetEmpty(&cl_opt) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;
                for (i=0; i<p_number; i++)
                    {
                      _DO_( elto_opt = L_CL_CreatOption() ) ;
                      if (elto_opt == NULL)
                          printf("ERROR\n") ;
                      NULL_RET_FALSE(elto_opt) ;

                      elto_opt->switch_name = X_STRING_StrDup(p_name[i]) ;
                      elto_opt->switch_help = X_STRING_StrDup(p_help[i]) ;
                      elto_opt->alone       = p_alone[i] ;

                      _DO_( ok = L_CL_Insert(&cl_opt,elto_opt) ) ;
                      if (ok == FALSE)
                          printf("ERROR\n") ;
                      FALSE_RET_FALSE(ok) ;
                    }
      
                /*
                 *  scan options
                 */
                (host)   = NULL ;
                (port)   = 0 ;
                _DO_( ok = L_CL_ArgProcess(argc,argv,&cl_opt) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;
                for (i=0; i<p_number; i++)
                {
                  _DO_( elto_opt = L_CL_ArgIn(&cl_opt,i) ) ;
                  if (elto_opt == NULL)
                      printf("ERROR\n") ;
                  NULL_RET_FALSE(elto_opt) ;

                  if (elto_opt->active == TRUE)
                     {
                       switch(i)
                       {
                         case 1 :
                              (host)   = strdup(elto_opt->value) ;
                              /* string never freed!, to do... */
                              break ;
                         case 2 :
                              (port)   = atoi(elto_opt->value) ;
                              break ;
                         default :
                              break ;
                       }
                     }
                }
        
                /*
                 *  L_CL_Empty
                 */
                _DO_( ok = L_CL_Empty(&cl_opt) ) ;
                if (ok == FALSE)
                    printf("ERROR\n") ;
      

		/*
                 */
		printf("end\n") ;
		return 1 ;
	}


