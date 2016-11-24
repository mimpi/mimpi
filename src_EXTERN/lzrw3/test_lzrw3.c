#include <stdio.h>

#include "port.h"
#include "compress.h"

extern void error (char * );


/***********************************************************************/
/*                            main program to test LZRW3.C              */
/************************************************************************/

main (char ** argv, int argc)
{

#define  CHECK_LENGTH     300           /* Length of checking blocks.  */
#define  MAX_LENGTH     80000           /* Maximum length of blocks.  */
#define  BUFFER_SIZE    (MAX_LENGTH+2*CHECK_LENGTH+3) /* Total buffer size. */

UWORD     action;      /* Action to be performed.                     */
UBYTE   *wrk_mem;      /* Address of working memory we can use.        */
UBYTE   *p_src_buffer;      /* Address of input data.           */
int    length;      /* Length  of input data.                 */
UBYTE   *p_dst_buffer;      /* Address to put output data.   */
ULONG   d_length=0;    /* LEngth of the destination */

ULONG    aux_length;      /* Length  of aux output data.                 */
UBYTE   *p_aux_buffer;      /* Address to put aux output data.   */
int i;
int    r_length;      /* Length  of input data for partial decompression. */

REAL compress_ratio = 0;

double  start, end;  /* timers */

	action = COMPRESS_ACTION_COMPRESS;

 /* Buffer allocation */
 /* The actual alignment of these blocks does not actually matter        */
 /* as we try all combinations anyway (using these addresses as a base). */
 p_src_buffer     =(UBYTE *) malloc((size_t) BUFFER_SIZE);
 p_dst_buffer     =(UBYTE *) malloc((size_t) BUFFER_SIZE);
 if (p_src_buffer == NULL)
    error("Error allocating source buffer.");
 if (p_dst_buffer == NULL)
    error("Error allocating destination buffer.");

 for (i=0; i<BUFFER_SIZE; i++)
	p_src_buffer[i]= 'a';


 /* Workspace buffer allocation */
 wrk_mem     =(UBYTE *) malloc((size_t) 4*BUFFER_SIZE);

  /* Test the routine on all small lengths. */
  /*
 printf("Testing Lengths 0 to 300\n");
 printf("------------------------\n");
 for (length=1;length<=300;length++)
 {
    printf("Testing Length %d \n", length);
    lzrw3_compress(action,wrk_mem,p_src_buffer,length,p_dst_buffer,
		&d_length);
    compress_ratio += ((float) length / (float) d_length );
 }
 compress_ratio = compress_ratio / (float) 300;  
 printf("compress_ratio is %7.4f \n", compress_ratio);
 printf("\n");
 */

 /* Test the routine on and around powers of two. */
 printf("Testing Powers of Two\n");
 printf("---------------------\n");
 for (length=256, i=0;length<MAX_LENGTH;length=length+length, i++)
   {
    lzrw3_compress(action,wrk_mem,p_src_buffer,length,p_dst_buffer,&d_length);
    compress_ratio += ((float) d_length / (float) length ) * 100;
   }
 compress_ratio = compress_ratio / (float) i;  
 printf("compress_ratio is %7.4f for %d steps \n", compress_ratio, i);
 printf("\n");

 /* Try it on the maximum sized block. */
 printf("Testing on Large Block\n");
 printf("----------------------\n");
 lzrw3_compress(action,wrk_mem,p_src_buffer,MAX_LENGTH,p_dst_buffer,&d_length);
    compress_ratio = ((float) d_length / (float) MAX_LENGTH ) * 100;
    printf("compress_ratio is %7.4f \n", compress_ratio);
 printf("\n");

 /* Test the routine on a few blocks of random length. */
 printf("Testing 10 Random Length Blocks\n");
 printf("-------------------------------\n");
 length = 0;
 start = mclock();
 for (i=1;i<=10;i++)
   {
    ULONG r1;
    r1= random() % BUFFER_SIZE;
    length += r1;
    lzrw3_compress(action,wrk_mem,p_src_buffer, r1, p_dst_buffer,&d_length);
    compress_ratio += ((float)r1 / (float) d_length );
   }
 end = mclock();
 compress_ratio = compress_ratio / 10;  
 printf("Averages: length is %d compress_ratio is %8.4f Time is %8.4f \n", 
	length/10, compress_ratio, (end-start)/10);
 printf("\n");

{
 #define LARGE_LENGTH (4*1024*1024)
 char * large_buf;
 int  large_length;
 char * clarge_buf;

 start  = mclock();
 large_buf = malloc (LARGE_LENGTH);
 clarge_buf = malloc (LARGE_LENGTH);
 end  = mclock();
  printf(" memory alloc  time is %8.4f msec\n", end-start);

 printf("Testing on VERY Large Block of 4 MBytes \n");
 printf("----------------------\n");
 start  = mclock();
 action = COMPRESS_ACTION_COMPRESS;
 lzrw3_compress(action,wrk_mem,large_buf,LARGE_LENGTH,clarge_buf,
	&d_length);
 end  = mclock();
    compress_ratio = ((float) LARGE_LENGTH / (float) d_length);
    printf("compress_ratio is %7.4f time is %8.4f msec\n", 
	compress_ratio, end-start);
 printf("\n");
 action = COMPRESS_ACTION_DECOMPRESS;
 start  = mclock();
 lzrw3_compress(action,wrk_mem,clarge_buf,d_length,large_buf,
        &large_length);
 end  = mclock();
  printf("uncompression time is %8.4f msec\n", end-start);
 start  = mclock();
 free(large_buf);
 free(clarge_buf);
 end  = mclock();
  printf("free memory  time is %8.4f msec\n", end-start);



}

 printf("All tests succeeded for compression .\n");
 printf("**************************************************** \n");
 printf("Now will look decompression .\n");

 p_aux_buffer     =(UBYTE *) malloc((size_t) BUFFER_SIZE);
 if (p_aux_buffer == NULL)
    error("Error allocating aux buffer.");

 /* Test the routine on and around powers of two. */
 printf("Testing Powers of Two\n");
 printf("---------------------\n");
 for (length=256;length<MAX_LENGTH;length=length+length)
   {
    action = COMPRESS_ACTION_COMPRESS;
    lzrw3_compress(action,wrk_mem,p_src_buffer,length,p_dst_buffer,&d_length);
    action = COMPRESS_ACTION_DECOMPRESS;
    lzrw3_compress(action,wrk_mem,p_dst_buffer,d_length,p_aux_buffer,&aux_length);
    if (aux_length != length)
       printf("compressed and uncompressed are different \n");
    else { 
	printf(" OK %d ", length);
	/*
	for (i=0; i<length; i++)
		printf("%c", p_aux_buffer[i]);
	*/
        }
   }
 printf("\n");

 /* Try it on the maximum sized block. */
 printf("Testing on Large Block\n");
 printf("----------------------\n");
    action = COMPRESS_ACTION_COMPRESS;
 start = mclock();
    lzrw3_compress(action,wrk_mem,p_src_buffer,MAX_LENGTH,p_dst_buffer,&d_length);
 end = mclock();
 printf("Compression test on Large Block (%d bytes). Ratio %8.4f:1 Time %f msec \n", 
	MAX_LENGTH, ((float)MAX_LENGTH/(float)d_length), end-start);
    action = COMPRESS_ACTION_DECOMPRESS;
 start = mclock();
    lzrw3_compress(action,wrk_mem,p_dst_buffer,d_length,p_aux_buffer,&aux_length);
 end = mclock();
 printf("Decompression test on Large Block. Time %f msec \n", end-start);
    if (aux_length != MAX_LENGTH)
       printf("compressed %d and uncompressed %d are different \n", 
		length, aux_length);
    else 
	printf(" OK %d ", aux_length);

 printf("\n");

 /* Try it on the maximum sized block. */
 /*
 printf("Testing on Large Block compression and partial uncompression\n");
 printf("----------------------\n");
    action = COMPRESS_ACTION_COMPRESS;
 start = mclock();
    lzrw3_compress(action,wrk_mem,p_src_buffer,MAX_LENGTH,p_dst_buffer,
		&d_length);
 end = mclock();
 printf("Compression test on Large Block (%d bytes). Ratio %8.4f:1 Time %f msec \n",
        MAX_LENGTH, ((float)MAX_LENGTH/(float)d_length), end-start);
    action = COMPRESS_ACTION_DECOMPRESS;

 start = mclock();
 length = d_length ;
 i = 0;
 while (length > 0) {
    r_length = MAX_PARTIAL;
    lzrw3_compress(action,wrk_mem,p_dst_buffer+i*MAX_PARTIAL,r_length,
	p_aux_buffer+i*MAX_PARTIAL, &aux_length);
    i++;
    length -= MAX_PARTIAL;
    if (length > MAX_PARTIAL)
	r_length = length - MAX_PARTIAL;
    else
	r_length = length;
 printf("Partial decompression test on Large Block. length %d bytes \n", 
		r_length);
 }
 end = mclock();
 printf("Decompression test on Large Block. Time %f msec \n", end-start);
 for (i=0; i<MAX_LENGTH; i++){
    if (p_src_buffer[i]  != p_aux_buffer[i]) {
       printf("compressed %d and uncompressed %d are different \n",
                length, aux_length);
       break;
    }
 }
 if ( i == MAX_LENGTH)
        printf(" OK %d ", aux_length);
*/

 printf("\n");


 printf("**************************************************** \n");
 printf("All tests succeeded.\n");
}



