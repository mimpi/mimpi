/* ....................................................................
 *
 * Copyright Felix Garcia (1997-2000)
 * <fgarcia@laurel.datsi.fi.upm.es>
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "test_user.h"


   /* ... Funciones ................................................... */

      void   TEST_USER_getKey
      (
        /* VOID */
      )
      {
        char c ;

        /*
         *  read any key.
         */
#if defined(HAVE_WINDOWS_H)
		_read(0, &c, 1);
#else
		read(0, &c, 1);
#endif
      }


  /* .................................................................... */

