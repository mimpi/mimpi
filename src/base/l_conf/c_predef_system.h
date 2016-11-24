

 #ifndef C_PREDEF_SYSTEM_H
 #define C_PREDEF_SYSTEM_H


   /* ... Include / Inclusiones ......................................... */
 

 #if defined(__PREDEF_CONF__)

      #if defined(__LINUX__)
          #include "base/l_conf/c_predef_system/c_linux.h"
      #endif

      #if defined(__SUNOS__)
          #include "base/l_conf/c_predef_system/c_sunos.h"
      #endif

      #if defined(__AIX__)
          #include "base/l_conf/c_predef_system/c_aix.h"
      #endif

      #if defined(__SP2__)
          #include "base/l_conf/c_predef_system/c_sp2.h"
      #endif

      #if defined(__IRIX64__)
          #include "base/l_conf/c_predef_system/c_irix64.h"
      #endif

      #if defined(__WIN__)
          #include "base/l_conf/c_predef_system/c_win32.h"
      #endif

 #endif


   /* ................................................................... */


 #endif

