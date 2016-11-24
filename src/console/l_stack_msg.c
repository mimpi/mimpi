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

      #include "console/l_stack_msg.h"


   /* ... Globla var. / Variables glob. ................................. */

      T_INT  (*L_STACK_MSG_PrintMsg)(const T_CHAR *, va_list) = NULL ;


   /* ... Functions / Funciones ......................................... */

      void   L_STACK_MSG_setPrinter 
      ( 
        IN    T_INT (*printer) (const T_CHAR *, va_list) 
      )
      {
        L_STACK_MSG_PrintMsg = (T_INT (*)(const T_CHAR *, va_list)) printer ;
      }

      void   L_STACK_MSG_doPrint    
      ( 
        IN    T_CHAR  *fto,
        ... 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             (*L_STACK_MSG_PrintMsg)(fto,vl) ; 
             va_end(vl) ;
           }
      }

      void   L_STACK_MSG_vPush    
      ( 
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             T_CHAR   *msg ;

             msg = X_STRING_Dvsprintf(fto,vl) ;
             L_STACK_MSG_doPrint("msg_stack(PUSH,\"%s\").",msg) ;
             X_ALLOC_Free( (void **) &(msg) ) ;
           }
      }

      void   L_STACK_MSG_Push     
      ( 
        IN    T_CHAR  *fto, 
        ... 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             L_STACK_MSG_vPush(fto,vl) ;
       	     va_end(vl) ;
           }
      }

      void   L_STACK_MSG_vPop
      ( 
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             T_CHAR   *msg ;

             msg = X_STRING_Dvsprintf(fto,vl) ;
             L_STACK_MSG_doPrint("msg_stack(POP,\"%s\").",msg) ;
             X_ALLOC_Free( (void **) &(msg) ) ;
           }
      }

      void   L_STACK_MSG_Pop
      ( 
        IN    T_CHAR  *fto, 
        ... 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             L_STACK_MSG_vPop(fto,vl) ;
       	     va_end(vl) ;
           }
      }

      void   L_STACK_MSG_vPopPush    
      ( 
        IN    T_CHAR  *fto,
        IN    va_list  vl 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             T_CHAR   *msg ;

             msg = X_STRING_Dvsprintf(fto,vl) ;
             L_STACK_MSG_doPrint("msg_stack(POP_PUSH,\"%s\").",msg) ;
             X_ALLOC_Free( (void **) &(msg) ) ;
           }
      }

      void   L_STACK_MSG_PopPush     
      ( 
        IN    T_CHAR  *fto, 
        ... 
      )
      {
        if (L_STACK_MSG_PrintMsg != NULL)
           {
             va_list vl ;

             va_start(vl,fto) ;
             L_STACK_MSG_vPopPush(fto,vl) ;
       	     va_end(vl) ;
           }
      }


   /* ................................................................... */

