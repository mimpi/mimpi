

 #ifndef C_EXT_SYSTEM_H
 #define C_EXT_SYSTEM_H


   /* ... add conf / mas conf ........................................... */

       #if defined(WIN32) 
           #define __WIN__
       #endif
 
       #if defined(__MSDOS__) && defined(_Windows)
           #define __WIN__
       #endif
 
       #if (defined(__LINUX__) || defined(__SUNOS__) || defined(__AIX__) || defined(__IRIX64__))
           #define __UNIX95__
       #endif
 

   /* ................................................................... */


 #endif

