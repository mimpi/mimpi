

 #ifndef I_FILE_WIN32_M
 #define I_FILE_WIN32_M

 #ifdef  __cplusplus
    extern "C" {
 #endif

 #if defined(HAVE_WINDOWS_H)


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"


  /* ... Inline / Macros ......................................*/

     #define  I_FILE_WIN32_open    \
              _open

     #define  I_FILE_WIN32_close   \
              _close

     #define  I_FILE_WIN32_creat   \
              _creat

     #define  I_FILE_WIN32_access  \
              _access

     #define  I_FILE_WIN32_dup     \
              _dup  

     #define  I_FILE_WIN32_eof     \
              _eof  

     #define  I_FILE_WIN32_lseek   \
              _lseek

     #define  I_FILE_WIN32_read    \
              _read 

     #define  I_FILE_WIN32_tell    \
              _tell 

     #define  I_FILE_WIN32_write   \
              _write


  /* ..........................................................*/


 #endif

 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_FILE_WIN32_M */

