

 #ifndef I_FILE_WIN32_H
 #define I_FILE_WIN32_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_string/x_dtd.h"


 #if defined(HAVE_WINDOWS_H)

  /* ... Functions / Funciones ................................*/

      int  I_FILE_WIN32_open
	  ( 
	    const char *filename, 
		int oflag 
	  );

      int  I_FILE_WIN32_close
	  ( 
	    int handle 
	  );

      int  I_FILE_WIN32_creat
	  ( 
	    const char *filename,
                  int pmode
	  );

      int  I_FILE_WIN32_access
	  ( 
	    const char *filename, 
                  int  mode 
	  );

      int  I_FILE_WIN32_dup
	  ( 
	    int handle 
	  );

      int  I_FILE_WIN32_eof
	  ( 
	    int handle 
	  );

      long I_FILE_WIN32_lseek
	  ( 
	    int handle, long offset, int origin 
	  );

      int  I_FILE_WIN32_read
	  ( 
	    int handle, void *buffer, unsigned int count 
	  );

      long I_FILE_WIN32_tell
	  ( 
	    int handle 
	  );

      int  I_FILE_WIN32_write
	  ( 
	    int handle, 
		const void *buffer, 
		unsigned int count 
	  );


  /* ... Inline / Macros ......................................*/

      #include "base/l_file/i_file_win32.m"


  /* ..........................................................*/

 #endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_FILE_WIN32_H */

