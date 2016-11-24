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

      #include "base/l_thread/x_thread.h"


   /* ... Functions / Funciones ......................................... */

      /*  
       *  thread 
       * -------- 
       */
      T_BOOL   I_THREAD_SHADOW_createDetached  
      ( 
        OUT  t_shadow_thread   *thid,
        IN   t_shadow_thcode    thcode,
        IN   void              *tharg 
      )
      {
        NULL_RET_FALSE(thid) ;

        (*thid) = (t_shadow_thread)(*thcode)(tharg) ;

        return TRUE ;
      }

      T_BOOL   I_THREAD_SHADOW_createJoinable  
      ( 
        OUT  t_shadow_thread  *thid,
        IN   t_shadow_thcode   thcode,
        IN   void             *tharg 
      )
      {
        NULL_RET_FALSE(thid) ;

        (*thid) = (t_shadow_thread)(*thcode)(tharg) ;

        return TRUE ;
      }

      T_BOOL   I_THREAD_SHADOW_join            
      ( 
        IN   t_shadow_thread    thid,
        OUT  void             **thret 
      )
      {
        (*thret) = (void *)thid ;

        return TRUE ;
      }


      /*  
       *  mtsdaToXZY
       * ------------
       */
      T_CHAR  *I_THREAD_SHADOW_mtsdaToString   
      ( 
        IN   t_shadow_mtsda  *mtsda 
      )
      {
        T_CHAR  *pstr ;
        T_CHAR  *ret ;

        /*
         *  NULL mtsda value.
         */
        if (mtsda == NULL)
           {
             pstr = X_STRING_StrDup("NULL") ;
           }

        /*
         *  build mtsda value.
         */
        if (mtsda != NULL)
           {
             /* ... set to null ... */
             pstr = NULL ;
     
             /* ... add boolean ... */
             ret  = X_DTD_vBeginPutEnd(&pstr,"bool","ready",
                                       "%i",(mtsda)->ready) ;
             NULL_RET_NULL(ret) ;
             ret  = X_DTD_addln(&pstr) ;
             NULL_RET_NULL(ret) ;
           }

        /*
         *  return dtd
         */
        return pstr ;
      }


   /* ................................................................... */

