/* ........................................................................
 *
 * Copyright Felix Garcia       (1999)
 * Copyright Jesus Carretero    (1999)
 * Copyright Alejandro Calderon (1999)
 * <fgarcia,jcarrete,acaldero@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


/*
 *
 *  prove zlib with buffers from several (Size x Datatype)
 *
 */


        #include "l_calloc_xy.h"
        #include "l_ztest_x.h"


        int zperf1_compress
        (
          int           argc,
          char         *argv[]        
        )
        {
                int     ret ;
                int     max_eltos ;


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
                 *  Int
                 */
                printf("Dense_Int %i\n", max_eltos) ;
                ret = l_ztest_n_compress_n(1,max_eltos,l_calloc_DenseInt) ;
                if (ret == -1)
                    return -1 ;
                printf("\n") ;

                printf("Sparse_Int %i\n", max_eltos) ;
                ret = l_ztest_n_compress_n(1,max_eltos,l_calloc_SparseInt) ;
                if (ret == -1)
                    return -1 ;
                printf("\n") ;


                /*
                 *  Char
                 */
                printf("Dense_Char %i\n", max_eltos) ;
                ret = l_ztest_n_compress_n(10,max_eltos,l_calloc_DenseChar) ;
                if (ret == -1)
                    return -1 ;
                printf("\n") ;

                /*
                 *  Double
                 */
                printf("Dense_Double %i\n", max_eltos) ;
                ret = l_ztest_n_compress_n(10,max_eltos,l_calloc_DenseDouble) ;
                if (ret == -1)
                    return -1 ;
                printf("\n") ;

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

                /*
                 * check values
                 */
                ret = zperf1_compress(argc,argv) ;

                /*
                 *  end
                 */
                printf("\n") ;
                return 0 ;
        }



