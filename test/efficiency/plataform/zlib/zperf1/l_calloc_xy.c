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
 *  alloc memory chuck of a datatype
 *
 */

        #include "l_calloc_xy.h"


        void *l_calloc_DenseInt
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        )
        {
           int   i ;

           /*
            *  alloc int chuck
            */
           (*O_size) = eltos_n * sizeof(int) ;
           (*O)      = malloc((*O_size)) ;
           if ((*O) == NULL)
              {
                perror("malloc:\t") ;
                return NULL ;
              }
           for (i=0; i<eltos_n; i++)
               {
                 ((int *)(*O))[i] = (int)3 ;
               }

           /*
            *  return
            */
           return (*O) ;
        }

        void *l_calloc_DenseChar
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        )
        {
           int   i ;

           /*
            *  alloc char chuck
            */
           (*O_size) = eltos_n * sizeof(char) ;
           (*O)      = malloc((*O_size)) ;
           if ((*O) == NULL)
              {
                perror("malloc:\t") ;
                return NULL ;
              }
           for (i=0; i<eltos_n; i++)
               {
                 ((char *)(*O))[i] = (char)'3' ;
               }

           /*
            *  return
            */
           return (*O) ;
        }

        void *l_calloc_DenseDouble
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        )
        {
           int   i ;

           /*
            *  alloc double chuck
            */
           (*O_size) = eltos_n * sizeof(double) ;
           (*O)      = malloc((*O_size)) ;
           if ((*O) == NULL)
              {
                perror("malloc:\t") ;
                return NULL ;
              }
           for (i=0; i<eltos_n; i++)
               {
                 ((double *)(*O))[i] = (double)3.0 ;
               }

           /*
            *  return
            */
           return (*O) ;
        }

        void *l_calloc_SparseInt
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        )
        {
           int   i ;

           /*
            *  alloc int chuck
            */
           (*O_size) = eltos_n * sizeof(int) ;
           (*O)      = malloc((*O_size)) ;
           if ((*O) == NULL)
              {
                perror("malloc:\t") ;
                return NULL ;
              }
           for (i=0; i<eltos_n; i++)
               {
                 ((int *)(*O))[i] = 1+(int)(10.0*rand()/(RAND_MAX+1.0));
               }

           /*
            *  return
            */
           return (*O) ;
        }

