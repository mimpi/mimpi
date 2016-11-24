

 #ifndef C_SYSTEM_H
 #define C_SYSTEM_H


  /* ... Includes .............................................*/

      #include <errno.h>
      #include <stdio.h>
      #include <stdlib.h>
      #include <stdarg.h>
      #include <string.h>
      #include <ctype.h>
      #include <sys/types.h>
      #include <signal.h>
      #include <limits.h>
      #include <fcntl.h>
      #include <math.h>


  #if (defined(__UNIX95__))
      #include <malloc.h>
      #include <strings.h>
      #include <fcntl.h>
      #include <termio.h>
      #include <sys/stat.h>
      #include <sys/wait.h>
      #include <sys/resource.h>
      #include <sys/time.h>
      #include <sys/ioctl.h>
      #include <arpa/inet.h>
      #include <sys/socket.h>
      #include <netdb.h>
      #include <pwd.h>
  #endif


  #if defined(__MSDOS__)
      #include <graphics.h>
      #include <conio.h>
      #include <io.h>
      #include <dos.h>
      #include <alloc.h>
      #include <process.h>
      #include <sys\stat.h>
      #include <time.h>
  #endif


  #if (defined(__WIN__))
      #include <process.h>
      #include <stddef.h>
      #include <conio.h>
      #include <time.h>
      #include <io.h>
      #include <sys/types.h>
      #include <sys/timeb.h>
      #include <sys/stat.h>
  #endif


  #if defined(HAVE_PTHREAD_H)
      #include <pthread.h>
  #endif

  #if defined(HAVE_VALUES_H)
      #include <values.h>
  #endif

  #if defined(HAVE_INET_TCP_H)
      #include <inet/tcp.h>
  #endif

  #if defined(HAVE_NETINET_TCP_H)
      #include <netinet/tcp.h>
  #endif

  #if defined(HAVE_NETINET_IN_H)
      #include <netinet/in.h>
  #endif

  #if defined(HAVE_SYS_POLL_H)
      #include <sys/poll.h>
  #endif

  #if defined(HAVE_POLL_H)
      #include <poll.h>
  #endif

  #if defined(HAVE_SELECT_H)
      #include <sys/select.h>
  #endif

  #if defined(HAVE_SYS_TTOLD_H)
      #include <sys/ttold.h>
  #endif

  #if defined(HAVE_DIRENT_H)
      #include <dirent.h>
  #endif

  #if defined(HAVE_UNISTD_H)
      #include <unistd.h>
  #endif

  #if defined(HAVE_WINDOWS_H)
      #include <windows.h>
  #endif

  #if defined(HAVE_ZLIB_H)
      #include <zlib.h>
  #endif

  #if defined(HAVE_LZRW3_H)
      #include "../../../../include/lzrw3.h"
  #endif

  #if defined(HAVE_LZO_H)
      #include "../../../../include/lzo.h"
  #endif

  #if defined(HAVE_SYS_PARAM_H)
      #include <sys/param.h>
  #endif

  #if defined(HAVE_SYS_XTI_H)
      #include <sys/xti.h>
  #endif


  /* .......................................................... */


#endif

