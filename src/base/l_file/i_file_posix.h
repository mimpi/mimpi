

 #ifndef I_FILE_POSIX_H
 #define I_FILE_POSIX_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_string.h"
      #include "base/l_string/x_dtd.h"


 #if defined(HAVE_UNISTD_H)

  /* ... Functions / Funciones ................................*/

      int  I_FILE_POSIX_open
	  ( 
	    const char *filename, 
		int oflag 
	  );

      int  I_FILE_POSIX_close
	  ( 
	    int handle 
	  );

      int  I_FILE_POSIX_creat
	  ( 
	    const char *filename,
                  int pmode
	  );

      int  I_FILE_POSIX_access
	  ( 
	    const char *filename, 
                  int  mode 
	  );

      int  I_FILE_POSIX_dup
	  ( 
	    int handle 
	  );

      int  I_FILE_POSIX_eof
	  ( 
	    int handle 
	  );

      long I_FILE_POSIX_lseek
	  ( 
	    int handle, long offset, int origin 
	  );

      int  I_FILE_POSIX_read
	  ( 
	    int handle, void *buffer, unsigned int count 
	  );

      long I_FILE_POSIX_tell
	  ( 
	    int handle 
	  );

      int  I_FILE_POSIX_write
	  ( 
	    int handle, 
		const void *buffer, 
		unsigned int count 
	  );


  /* ... Inline / Macros ......................................*/

      #include "base/l_file/i_file_posix.m"


  /* ..........................................................*/

 #endif


 #ifdef  __cplusplus
    }
 #endif

#endif  /* I_FILE_POSIX_H */

