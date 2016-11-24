/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_socket/i_socket_win32.h"


   /* ... Functions / Funciones ......................................... */


#if defined(HAVE_WINDOWS_H)

      T_BOOL     I_SOCKET_WIN32_init 
      ( 
        void
      )
      {
        WSADATA WSAData ;

        /*
         *  startup...
         */
        if (WSAStartup (MAKEWORD(1,1), &WSAData) != 0) 
          {
            L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"WSAStartup:") ;
            return FALSE ;
          }

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL     I_SOCKET_WIN32_finalize 
      ( 
        void
      )
      {
        /*
         *  end...
         */
        WSACleanup ();

        /*
         *  return ok
         */
        return TRUE ;
      }

#endif


   /* ................................................................... */

