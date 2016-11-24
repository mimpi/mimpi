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



        #include <stdio.h>
        #include <stdlib.h>


        void *l_calloc_DenseInt
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        ) ;

        void *l_calloc_DenseChar
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        ) ;

        void *l_calloc_DenseDouble
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        ) ;

        void *l_calloc_SparseInt
        (
          long    eltos_n,    /* IN  (int)    n eltos */
          void  **O,          /* OUT (void *) buffer */
          long   *O_size      /* OUT (int)    buffer size */
        ) ;


