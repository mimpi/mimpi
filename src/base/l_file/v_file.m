

 #ifndef V_FILE_M
 #define V_FILE_M

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_file/v_file.h"


   /* ... Inline / Macros ............................................... */

      #if defined(HAVE_WINDOWS_H)

          #define  V_FILE_open    \
                   I_FILE_WIN32_open

          #define  V_FILE_close   \
                   I_FILE_WIN32_close

          #define  V_FILE_creat   \
                   I_FILE_WIN32_creat

          #define  V_FILE_access  \
                   I_FILE_WIN32_access

          #define  V_FILE_dup     \
                   I_FILE_WIN32_dup  

          #define  V_FILE_eof     \
                   I_FILE_WIN32_eof  

          #define  V_FILE_lseek   \
                   I_FILE_WIN32_lseek

          #define  V_FILE_read    \
                   I_FILE_WIN32_read 

          #define  V_FILE_tell    \
                   I_FILE_WIN32_tell 

          #define  V_FILE_write   \
                   I_FILE_WIN32_write


      #else

          #define  V_FILE_open    \
                   I_FILE_POSIX_open

          #define  V_FILE_close   \
                   I_FILE_POSIX_close

          #define  V_FILE_creat   \
                   I_FILE_POSIX_creat

          #define  V_FILE_access  \
                   I_FILE_POSIX_access

          #define  V_FILE_dup     \
                   I_FILE_POSIX_dup  

          #define  V_FILE_eof     \
                   I_FILE_POSIX_eof  

          #define  V_FILE_lseek   \
                   I_FILE_POSIX_lseek

          #define  V_FILE_read    \
                   I_FILE_POSIX_read 

          #define  V_FILE_tell    \
                   I_FILE_POSIX_tell 

          #define  V_FILE_write   \
                   I_FILE_POSIX_write


      #endif


 /* ...................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif 

