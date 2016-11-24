/* ........................................................................
 *
 * Copyright Felix Garcia       (1999)
 * Copyright Alejandro Calderon (1999)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


/*
 *
 *  prove x_zl.
 *
 */


        #include "base/l_basic/c_basic.h"
        #include "base/l_zlib/x_zl.h"



        int test_zlib_compress
        (
          int           argc,
          char         *argv[]        
        )
        {
                int     ret ;
                int     max_eltos ;
                int     i ;
                void   *b_original ;
                void   *b_compress_to ;
                void   *b_compress_into ;
                void   *b_uncompress_into ;
                long    b_originalLen ;
                long    b_compress_toLen ;
                long    b_compress_intoLen ;
                long    b_uncompress_intoLen ;


                /*
                 *  begin
                 */
                if (argc != 2)
                   {
                     printf("Use: %s <max_eltos> \n",
                            argv[0]) ;
                     return -1 ;
                   }
                printf("\n") ;

                /*
                 *  get values
                 */
                max_eltos = atoi(argv[1]) ;
                if (max_eltos > 1024*1024)
                   {
                     printf("Warning: max_eltos=%i\n",
                            max_eltos) ;
                     printf("Warning: change this check at %s:%i\n",
                            __FILE__,__LINE__ - 5) ;
                     return -1 ;
                   }

                /*
                 *  check version
                 */
                if (strcmp(zlibVersion(), ZLIB_VERSION) != 0) 
                   {
                     printf("zlib: using different zlib version\n") ;
                   }

                /*
                 *  alloc buffers
                 */
                b_originalLen        = max_eltos ;
                b_compress_intoLen   = b_originalLen ;
                b_compress_toLen     = 0 ;
                b_uncompress_intoLen = b_originalLen ;
            
                b_original         = malloc(b_originalLen) ;
                b_compress_into    = malloc(b_originalLen) ;
                b_compress_to      = NULL ;
                b_uncompress_into  = malloc(b_originalLen) ;
            
                /*
                 *  fill with values
                 */
                for (i=0; i < b_originalLen; i++)
                    {
                      ((char *)b_original)[i] = i%256 ;
                    }
            
                /*
                 *  b_compress_into
                 *  b_uncompress_into
                 */
                printf("b_compress_into ...\n") ;
                ret = X_ZL_compress_into( b_original, 
                                          b_originalLen,
                                          b_compress_into, 
                                         &b_compress_intoLen,
                                          ZL_BEST_SPEED) ;
                printf("b_originalLen is %li\n",b_originalLen) ;
                printf("b_compress_intoLen is %li\n",b_compress_intoLen) ;
                printf("\n") ;
                if (ret != Z_OK)
                   {
                     printf("zlib: %s\n",zError(ret)) ;
                     return -1 ;
                   }
            
                printf("b_uncompress_into ...\n") ;
                ret = X_ZL_uncompress_into( b_compress_into, 
                                            b_compress_intoLen,
                                            b_uncompress_into, 
                                           &b_uncompress_intoLen) ;
                printf("b_compress_intoLen is %li\n",b_compress_intoLen) ;
                printf("b_uncompress_intoLen is %li\n",b_uncompress_intoLen) ;
                printf("\n") ;
                if (ret != Z_OK)
                   {
                     printf("zlib: %s\n",zError(ret)) ;
                     return -1 ;
                   }
            
                if (b_originalLen != b_uncompress_intoLen)
                   {
                     printf ("Error in b_uncompress_intoed buffer length \n") ;
                   }
            
                for (i=0; i < b_originalLen; i++)
                {
                    if (
                         ((char *)b_original)[i] 
                                  != 
                         ((char *)b_uncompress_into)[i]
                       )
                       {
                         printf ("b_original VS b_uncompress_into: %d ", i) ;
                       }
                }


                /*
                 *  b_compress_to
                 *  b_uncompress_into
                 */
                printf("b_compress_to ...\n") ;
                ret = X_ZL_compress_to(   b_original, 
                                          b_originalLen,
                                         &b_compress_to, 
                                         &b_compress_toLen,
                                          ZL_BEST_SPEED) ;
                printf("b_originalLen is %li\n",b_originalLen) ;
                printf("b_compress_intoLen is %li\n",b_compress_intoLen) ;
                if (ret != Z_OK)
                   {
                     printf("zlib: %s\n",zError(ret)) ;
                     return -1 ;
                   }
            
                printf("b_uncompress_into ...\n") ;
                ret = X_ZL_uncompress_into( b_compress_into, 
                                            b_compress_intoLen,
                                            b_uncompress_into, 
                                           &b_uncompress_intoLen) ;
                if (ret != Z_OK)
                   {
                     printf("zlib: %s\n",zError(ret)) ;
                     return -1 ;
                   }

                if (b_originalLen != b_uncompress_intoLen)
                   {
                     printf ("Error in b_uncompress_intoed buffer length \n") ;
                   }
            
                for (i=0; i < b_originalLen; i++)
                {
                   if (
                        ((char *)b_original)[i] 
                                 != 
                        ((char *)b_uncompress_into)[i]
                      )
                      {
                        printf ("b_original VS b_uncompress_into: %d ", i) ;
                      }
                }

                /*
                 *  free
                 */
                free(b_original) ;
                free(b_compress_to) ;
                free(b_compress_into) ;
                free(b_uncompress_into) ;

                /*
                 *  end
                 */
                printf("\n") ;
                return 1 ;
        }



        int main  
        (
          int           argc,
          char         *argv[]        
        )
        {
                int         ret ;

                /*
                 *  begin
                 */
                printf("\n") ;
                printf("%s\n",argv[0]) ;
                printf("begin\n") ;

                /*
                 * check values
                 */
                ret = test_zlib_compress(argc,argv) ;

                /*
                 *  end
                 */
                printf("end\n") ;
                return 0 ;
        }



