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
 *  prove zlib
 *
 */

        #include "l_ztest_x.h"


        /* ................................................................................ */

        void l_ztest_n_print_header
        (
          void
        )
        {
          /*
           *  header
           */
          printf("len ") ;
          printf("avg_time(malloc+zlib+free) ") ;
          printf("avg_C ") ;
          printf("\n") ;
        }

        void l_ztest_n_print_values
        (
          long          initial_size,
          double        total_time,
          long          compress_size
        )
        {
          /*
           *  values
           */
          printf(" %li\t", initial_size ) ;
          printf(" %e\t",  total_time ) ;
          printf(" %li\t", compress_size ) ;
          printf("\n") ;
        }


        /* ................................................................................ */

        int l_ztest_n_compress_1
        (
          int           test_n,
          void         *O,
          long          O_len
        )
        {
                double      t1 ;
                double      t2 ;
                double      acc_t ;

                int         err ;
                int         test_i ;

                void       *C[MAX_NTEST] ;
                long        buff_C ;
                long        acc_C ;

                /*
                 *  initial values
                 */
                acc_t = 0.0 ;
                acc_C = 0 ;

                /*
                 *  do test
                 */
                for (test_i=0; test_i<test_n; test_i++)
                    {

                      /*
                       *  !.- start crono
                       */
                      t1 = l_time_ms_GetTime(NULL) ;

                      /*
                       *  1.- malloc for compressed chuck
                       */
                      buff_C = O_len + 12 ;
                      C[test_i] = malloc(buff_C) ;
                      if (C[test_i]  == NULL)
                         {
                           perror("malloc:\t") ;
                           return -1 ;
                         }

                      /*
                       *  2.- compress original chuck into compressed chuck
                       */
                      err = compress(C[test_i],
                                     &buff_C,
                                     O,
                                     O_len) ; 
                      if (err != Z_OK)
                         {
                           printf("compress: %s\t",zError(err)) ;
                           return -1 ;
                         }

                      /*
                       *  3.- free compressed chuck
                       */
                      free(C[test_i]) ;

                      /*
                       *  !.- stop crono
                       */
                      t2 = l_time_ms_GetTime(NULL) ;
                      acc_t = acc_t + t2 - t1 ;
                      acc_C = acc_C + buff_C ;

                    }

                /*
                 *  print values
                 */
                l_ztest_n_print_values( O_len,
                                       (double)acc_t / (double)test_n,
                                       acc_C / test_n) ;

                /*
                 *  return ok
                 */
                return 1 ;
        }

        int l_ztest_n_compress_n
        (
          int   test_n,
          int   eltos_n,
          void *(*alloc_x_chuck) (long, void **, long *)
        )
        {
                int     ret ;
                int     eltos_i ;
                void   *O ;
                long    O_len ;


                /*
                 *  begin
                 */
                l_ztest_n_print_header() ;
                for (eltos_i=1; eltos_i<=eltos_n; eltos_i*=2)
                    {

                      /*
                       *  setup original chuck
                       */
                      if (alloc_x_chuck == NULL)
                          return -1 ;
                      O = (*alloc_x_chuck)(eltos_i,
                                           &O,
                                           &O_len) ;
                      if (O == NULL)
                          return -1 ;

                      /*
                       *  compress it
                       */
                      ret = l_ztest_n_compress_1(test_n,
                                                O,
                                                O_len) ;
                      if (ret == -1)
                          return -1 ;

                      /*
                       *  free chuck
                       */
                      free(O) ;
                    }


                /*
                 *  end
                 */
                return 1 ;
        }



