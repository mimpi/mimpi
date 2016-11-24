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

      #include "console/l_condition_msg.h"


   /* ... Globla var. / Variables glob. ................................. */

      T_INT  (*L_CONDITION_MSG_PrintMsg)(const T_CHAR *, va_list) = NULL ;


   /* ... Functions / Funciones ......................................... */

      void   L_CONDITION_MSG_setPrinter 
      ( 
        IN    T_INT (*printer) (const T_CHAR *, va_list) 
      )
      {
        L_CONDITION_MSG_PrintMsg = (T_INT (*)(const T_CHAR *, va_list)) printer ;
      }

      void   L_CONDITION_MSG_doPrint    
      ( 
        IN    T_CHAR  *fto,
        ... 
      )
      {
        if (L_CONDITION_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             (*L_CONDITION_MSG_PrintMsg)(fto,vl) ; 
       	     va_end(vl) ;
           }
      }

      void   L_CONDITION_MSG_VPrintF    
      ( 
        IN    T_U_INT  line,
        IN    T_CHAR  *name,
        IN    T_PID    pid,
        IN    T_INT    type,
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      )
      {
        if (L_CONDITION_MSG_PrintMsg != NULL)
           {
             T_CHAR   *msg ;
             T_CHAR   *zspid ;

             msg   = X_STRING_Dvsprintf(fto,vl) ;
			 zspid = X_PROCESS_pidToString(&pid) ;
             L_CONDITION_MSG_doPrint("msg_condition(%i,\"%s\",%li,%i,\"%s\").",
                                  line,
                                  name,
                                  zspid,
                                  type,
                                  msg) ;
             X_ALLOC_Free( (void **)&(msg) ) ;
             X_ALLOC_Free( (void **)&(zspid) ) ;
           }
      }

      void   L_CONDITION_MSG_PrintF     
      ( 
        IN    T_U_INT  line,
        IN    T_CHAR  *name,
        IN    T_PID    pid,
	    IN    T_INT    type,
	    IN    T_CHAR  *fto, 
        ... 
      )
      {
        if (L_CONDITION_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             L_CONDITION_MSG_VPrintF(line,name,pid,type,fto,vl) ;
       	     va_end(vl) ;
           }
      }


   /* ................................................................... */

