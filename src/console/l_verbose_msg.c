/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */



   /* ... Include / Inclusion ........................................... */

      #include "console/l_verbose_msg.h"


   /* ... Globla var. / Variables glob. ................................. */

      T_INT  (*L_VERBOSE_MSG_PrintMsg)(const T_CHAR *, va_list) = NULL ;


   /* ... Functions / Funciones ......................................... */

      void   L_VERBOSE_MSG_setPrinter 
      ( 
        IN    T_INT (*printer) (const T_CHAR *, va_list) 
      )
      {
        L_VERBOSE_MSG_PrintMsg = (T_INT (*)(const T_CHAR *, va_list)) printer ;
      }

      void   L_VERBOSE_MSG_doPrint    
      ( 
        IN    T_CHAR  *fto,
        ... 
      )
      {
        if (L_VERBOSE_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             (*L_VERBOSE_MSG_PrintMsg)(fto,vl) ; 
             va_end(vl) ;
           }
      }

      void   L_VERBOSE_MSG_VPrintF    
      ( 
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      )
      {
        if (L_VERBOSE_MSG_PrintMsg != NULL)
           {
             T_CHAR   *msg ;

             msg = X_STRING_Dvsprintf(fto,vl) ;
             L_VERBOSE_MSG_doPrint("msg_verbose(\"%s\").",msg) ;
             X_ALLOC_Free( (void **) &(msg) ) ;
           }
      }

      void   L_VERBOSE_MSG_PrintF     
      ( 
        IN    T_CHAR  *fto, 
        ... 
      )
      {
        if (L_VERBOSE_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             L_VERBOSE_MSG_VPrintF(fto,vl) ;
       	     va_end(vl) ;
           }
      }


   /* ................................................................... */

