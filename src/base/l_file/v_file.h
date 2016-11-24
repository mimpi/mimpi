

 #ifndef V_FILE_H
 #define V_FILE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

      #include "base/l_basic/c_basic.h"
      #include "base/l_file/i_file_win32.h"
      #include "base/l_file/i_file_posix.h"


  /* ... Const / Constantes ...................................*/

      #if defined(__MSDOS__)
          #define NULL_DEVICE_PATH  "nul"
      #endif
      #if defined(__UNIX95__)
          #define NULL_DEVICE_PATH  "/dev/null"
      #endif
      #if defined(__WIN__)
          #define NULL_DEVICE_PATH  "NUL"

          #define F_OK      00
          #define F_W       02
          #define F_R       04
          #define F_RW      06

          #define S_IRWXU   _S_IREAD | _S_IWRITE
      #endif


  /* ... Functions / Funciones ................................*/

  	  int  V_FILE_open
	  ( 
	    const char *filename, 
        int  oflag 
	  );

	  int  V_FILE_close
	  ( 
	    int handle 
	  );

	  int  V_FILE_creat
	  ( 
	    const char *filename,
        int   pmode
	  );

          int  V_FILE_access
	  ( 
	    const char *filename, 
        int  mode 
	  );

	  int  V_FILE_dup
	  ( 
	    int handle 
	  );

      int  V_FILE_eof
	  ( 
	    int handle 
	  );

      long V_FILE_lseek
	  ( 
	    int handle,
        long offset,
        int origin
	  );

      int  V_FILE_read
	  ( 
	    int handle,
        void *buffer,
        unsigned int count
	  );

      long V_FILE_tell
	  ( 
	    int handle 
	  );

      int  V_FILE_write
	  ( 
        int handle, 
        const void *buffer, 
        unsigned int count 
	  );


  /* ... Inline / Macros ......................................*/

      #include "base/l_file/v_file.m"


  /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif  /* V_FILE_H */

