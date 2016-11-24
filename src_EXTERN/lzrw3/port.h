/******************************************************************************/
/*                                                                            */
/*                                    PORT.H                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* This module contains macro definitions and types that are likely to        */
/* change between computers.                                                  */
/*                                                                            */
/******************************************************************************/

#ifndef DONE_PORT       /* Only do this if not previously done.                   */

      #define UBYTE unsigned char      /* Unsigned byte                       */
      #define UWORD unsigned int       /* Unsigned word (2 bytes)             */
      #define ULONG unsigned long      /* Unsigned word (4 bytes)             */
      #define BOOL  unsigned char      /* Boolean                             */
      #define FOPEN_BINARY_READ  "rb"  /* Mode string for binary reading.     */
      #define FOPEN_BINARY_WRITE "wb"  /* Mode string for binary writing.     */
      #define FOPEN_TEXT_APPEND  "a"   /* Mode string for text appending.     */
      #define REAL double              /* USed for floating point stuff.      */


   #define DONE_PORT                   

   #define MALLOC_FAIL NULL            /* Failure status from malloc()        */
   #define LOCAL static                /* For non-exported routines.          */
   #define EXPORT                      /* Signals exported function.          */
   #define then                        /* Useful for aligning ifs.            */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


#endif

/******************************************************************************/
/*                              End of PORT.H                                 */
/******************************************************************************/

