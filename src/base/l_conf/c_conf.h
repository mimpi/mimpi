

 #ifndef C_CONF_H
 #define C_CONF_H


   /* ... Include / Inclusiones ......................................... */

      /*
       *   load
       */
      #if defined(HAVE_CONFIG_H)
         #include <config.h>
      #endif
      #if defined(__PREDEF_CONF__)
         #include "base/l_conf/c_predef_system.h"
         #include "base/l_conf/c_predef_user.h"
      #endif
      #if defined(HAVE_CONFIG_H) && defined(__PREDEF_CONF__)
         #error "warning: using both, PREDEF_CONF and HAVE_CONFIG_H"
      #endif
      #if (!defined(HAVE_CONFIG_H)) && (!defined(__PREDEF_CONF__))
         #error "warning: define PREDEF_CONF or HAVE_CONFIG_H first"
      #endif
  
      /*
       *   extend
       */
      #include "base/l_conf/c_ext_system.h"
      #include "base/l_conf/c_ext_user.h"


   /* ................................................................... */


 #endif

