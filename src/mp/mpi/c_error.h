

#ifndef C_ERROR_H
#define C_ERROR_H


   /* ... Consts / Ctes ................................................. */

      /*
       * Valid return values will be zero or positive (>=0).
       * Operation and error codes will be negative values (<0).
       *	-1	Current errno error code.
       *	..-256	Standard error codes (-1*(errcode + 1)).
       *	..-1024	Especific error codes.
       *	..-4086	Operation codes.
       */
      
      #define EC_GETHOST	-256
      
      #define MINSYSERR	-256
      #define MINESPERR	-1024
      
      #define SYSERR(errno)		(-1 * ((errno) + 1))
      #define ESPERR(errndx)		(MINESPERR + (errndx))
      
      #define SYSERR2NUM(errno)	        (((errno) * -1) - 1)
      #define ESPERR2NUM(errndx)	((errndx) - MINESPERR)

      
      /*
       * Standard system error codes will me named as usual but with
       * an underscore prepended.
       */
      
      #define _ENOTDIR	        SYSERR(ENOTDIR)
      #define _ENOENT		SYSERR(ENOENT)
      #define _EBUSY		SYSERR(EBUSY)
      #define _EEXIST		SYSERR(EEXIST)
      #define _EINVAL		SYSERR(EINVAL)
      #define _ENODEV		SYSERR(ENODEV)
      #define _EIO		SYSERR(EIO)
      #define _ENFILE		SYSERR(ENFILE)
      
      #define EC_UNKMSG	        ESPERR(1)
      #define EC_ULKDBLK	ESPERR(2)
      #define EC_TIMEOUT	ESPERR(3)
      #define EC_INVREX        	ESPERR(4)
      #define EC_ITMNOEXS	ESPERR(5)
      #define EC_NAMNOEXS	ESPERR(6)
      #define EC_DEVNOEXS	ESPERR(7)
      #define EC_BLKNOEXS	ESPERR(8)
      #define EC_ITMALEXS	ESPERR(9)
      #define EC_NAMALEXS	ESPERR(10)
      #define EC_DEVALEXS	ESPERR(11)
      #define EC_BLKALEXS	ESPERR(12)
      #define EC_NULLPTR	ESPERR(13)
      #define EC_INVSIZE	ESPERR(14)
      #define EC_INVFLG	        ESPERR(15)
      #define EC_PARNOOPN	ESPERR(16)
      #define EC_PARALOPN	ESPERR(17)
      #define EC_MBNOCONF	ESPERR(18)
      #define EC_PARNOMAI	ESPERR(19)
      #define EC_INVARGCO	ESPERR(20)
      #define EC_INVARG	        ESPERR(21)
      #define EC_INVPASWD	ESPERR(22)
      #define EC_INVOWNER	ESPERR(23)
      #define EC_PARALACQ	ESPERR(24)
      #define EC_PARALMAI	ESPERR(25)
      #define EC_PARNOEXS	ESPERR(26)
      #define EC_NOINIYET	ESPERR(27)
      #define EC_ALRINIT	ESPERR(28)
      #define EC_PROTOERR	ESPERR(29)
      #define EC_SYSERR	        ESPERR(30)
      

   /* ................................................................... */


#endif	/* C_ERROR_H */

