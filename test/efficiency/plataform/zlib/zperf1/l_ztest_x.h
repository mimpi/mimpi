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
        #include <zlib.h>
        #include "l_time_ms.h"


        #define     MAX_NTEST         100


        int l_ztest_n_compress_1
        (
          int           test_n,
          void         *O,
          long          O_len
        ) ;

        int l_ztest_n_compress_n
        (
          int   test_n,
          int   eltos_n,
          void *(*alloc_chuck_XYZ) (long, void **, long *)
        ) ;


