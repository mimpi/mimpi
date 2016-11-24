

 #ifndef X_FILE_H
 #define X_FILE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_file/v_file.h"


  /* ... Functions / Funciones ................................*/

          int  X_FILE_open
	  ( 
	    const char *filename, 
                  int  oflag 
	  );

          int  X_FILE_creat
	  ( 
	    const char *filename, 
                  int  pmode 
	  );

          int  X_FILE_access
	  ( 
	    const char *filename, 
                  int  mode 
	  );

          int  X_FILE_close
	  ( 
	    int handle 
	  );

          int  X_FILE_creat
	  ( 
	    const char *filename,
                  int   pmode
	  );

          int  X_FILE_dup
	  ( 
	    int handle 
	  );

      int  X_FILE_eof
	  ( 
	    int handle 
	  );

      long X_FILE_lseek
	  ( 
	    int handle,
            long offset,
            int origin
	  );

      int  X_FILE_read
	  ( 
	    int handle,
            void *buffer,
            unsigned int count
	  );

      long X_FILE_tell
	  ( 
	    int handle 
	  );

      int  X_FILE_write
	  ( 
                  int handle, 
            const void *buffer, 
                  unsigned int count 
	  );


  /* ... Inline / Macros ......................................*/

      #include "base/l_file/x_file.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* X_FILE_H */

