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

      #include "test_buffers.h"


   /* ... Funciones ................................................... */

      int   TEST_BUFFERS_malloc
      (
        /* IN    */   int    size,
        /* INOUT */   void **buf
      )
      {
        /*
         *  try set default values ...
         */
        if (buf == NULL)
            return -1 ;
        (*buf) = NULL ;

        /*
         *  try get memory ...
         */
        (*buf) = malloc((unsigned)size) ;
        if ((*buf) == NULL)
           {
             printf("malloc(%i): ",size) ; 
             perror("") ; 
             return -1 ;
           }

        /*
         *  return ok ...
         */
        return -1 ;
      }


      int   TEST_BUFFERS_mallocv2
      (
        /* IN    */   int    send_buf_size,
        /* IN    */   int    recv_buf_size,
        /* INOUT */   char **send_buf,
        /* INOUT */   char **recv_buf
      )
      {
        int ret ;

        /*
         *  try get buffers ...
         */
        ret = TEST_BUFFERS_malloc(send_buf_size,
                                  (void **)send_buf) ;
	if (ret < 0)
	   {
		printf("ERROR: Can not alloc send buffer\n") ;
                return -1 ;
	   }

        ret = TEST_BUFFERS_malloc(recv_buf_size,
				                  (void **)recv_buf) ;
	if (ret < 0)
	   {
		printf("ERROR: Can not alloc receive buffer\n") ;
                return -1 ;
	   }

        /*
         *  return ok
         */
        return 1 ;
      }

      int   TEST_BUFFERS_fill_fixed
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf,
        /* IN    */   char   buf_bg
      )
      {
        /*
         *  fill memory ...
         */
        memset((*buf),buf_bg,buf_size) ;

        /*
         *  return ok
         */
        return 1 ;
      }

      int   TEST_BUFFERS_fill_sparse
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf,
        /* IN    */   char   buf_bg
      )
      {
        int i ;

        /*
         *  fill memory ...
         */
        memset((*buf),buf_bg,buf_size) ;

        /*
         *  fill noise ...
         */
#if (0)
/*
 *  DEBUG here!!!
 */
		for (i=0; i<buf_size; i++)
		{
		  if (i % 10)
		     (*buf)[i] = (char) i ;
		}
#endif

        /*
         *  return ok
         */
        return 1 ;
      }

      int   TEST_BUFFERS_fill_dense
      (
        /* IN    */   int    buf_size,
        /* INOUT */   char **buf,
        /* IN    */   char   buf_bg
      )
      {
        int i ;

        /*
         *  fill memory ...
         */
        memset((*buf),buf_bg,buf_size) ;

        /*
         *  fill noise ...
         */
#if (0)
/*
 *  DEBUG here!!!
 */
		for (i=0; i<buf_size; i++)
		{
		  (*buf)[i] = (char) i ;
		}
#endif

        /*
         *  return ok
         */
        return 1 ;
      }


  /* .................................................................... */

