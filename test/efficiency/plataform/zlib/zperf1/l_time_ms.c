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
 *  prove time
 *
 */

        #include "l_time_ms.h"


        double l_time_ms_GetTime
        (
           double *out_diff
        )
        {
          struct timeval  t;	
          double diff;

          gettimeofday(&t, NULL);
          diff = (double)t.tv_sec * 1000000.0 + (double)t.tv_usec ;
          if (out_diff != NULL)
	     (*out_diff) = diff;
          return (diff);
        }


