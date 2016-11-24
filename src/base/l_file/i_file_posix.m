

 #ifndef I_FILE_POSIX_M
 #define I_FILE_POSIX_M

 #ifdef  __cplusplus
    extern "C" {
 #endif

 #if defined(HAVE_UNISTD_H)


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"


  /* ... Inline / Macros ......................................*/

     #define  I_FILE_POSIX_open    \
              open

     #define  I_FILE_POSIX_close   \
              close

     #define  I_FILE_POSIX_creat   \
              creat

     #define  I_FILE_POSIX_access  \
              access

     #define  I_FILE_POSIX_dup     \
              dup  

     #define  I_FILE_POSIX_eof     \
              eof  

     #define  I_FILE_POSIX_lseek   \
              lseek

     #define  I_FILE_POSIX_read    \
              read 

     #define  I_FILE_POSIX_tell    \
              tell 

     #define  I_FILE_POSIX_write   \
              write


  /* ..........................................................*/


 #endif

 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_FILE_POSIX_M */

