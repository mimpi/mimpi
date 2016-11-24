/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */



   /* ... Include / Inclusion ........................................... */

      #include "base/l_debug/l_debug_dfa.h"


   /* ... Functions / Funciones ......................................... */

      /*  State functions  *
       * ----------------- */
      T_BOOL     L_DEBUG_DFA_writeState    
      ( 
        IN     int        dfa,
        IN     T_CHAR    *state,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        T_CHAR  line1024[1024] ;

        /* 
         *  write 
         */
        sprintf(line1024,
                "%s %s:%li",
                state,file,line) ;
        X_FILE_lseek(dfa,0,SEEK_SET) ;
        X_FILE_write(dfa,line1024,strlen(line1024)) ;

        /* 
         *  return 
         */
        return TRUE ;
      }

      T_BOOL     L_DEBUG_DFA_readState     
      ( 
        IN     int         dfa,
        INOUT  T_CHAR     *state,
        INOUT  T_CHAR     *file,
        INOUT  T_U_LONG   *line 
      )
      {
        T_CHAR  line1024[1024] ;

        /* 
         *  read 
         */
        lseek(dfa,0,SEEK_SET) ;
        X_FILE_read(dfa,line1024,sizeof(line1024)) ;
        sscanf(line1024,
               "%s %s:%li",
               state,file,line) ;

        /* 
         *  return 
         */
        return TRUE ;
      }

      T_BOOL     L_DEBUG_DFA_existTransition 
      ( 
        IN     t_dfa    *dfaType,
        IN     T_CHAR   *state_orig,
        IN     T_CHAR   *state_dest 
      )
      {
        T_U_LONG  i ;

        /* 
         *  search  
         */
        for (i=0; (dfaType->transitions)[i].state_orig != NULL; i++)
            {
              if (
                   (! strcmp((dfaType->transitions)[i].state_orig,state_orig))
                                            &&
                   (! strcmp((dfaType->transitions)[i].state_dest,state_dest))
                 )
                 {
                   return TRUE ;
                 }
            }

        /* 
         *  return 
         */
        return FALSE ;
      }


      /*  Basic functions  *
       * ----------------- */
      T_CHAR    *L_DEBUG_DFA_getName       
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        static  T_CHAR  L_DEBUG_DFA_name[1024] ;

        /* 
         *  identification + ident. space 
         */
#if defined(HAVE_PTHREAD_H)
        sprintf(L_DEBUG_DFA_name,
                "%s.%p.%li.%li",
                dfaType->name,
                dfaId,
                (long)getpid(),
                (long)pthread_self()) ;
#else
        sprintf(L_DEBUG_DFA_name,
                "%s.%p.%li",
                dfaType->name,
                dfaId,
                (long)getpid()) ;
#endif

        /* 
         *  return 
         */
        return L_DEBUG_DFA_name ;
      }

      int        L_DEBUG_DFA_open          
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        T_CHAR  *dfaName ;
        int      ret ;

        /* 
         *  open 
         */
        dfaName = L_DEBUG_DFA_getName(dfaType,dfaId,file,line) ;
        ret = X_FILE_open(dfaName,O_RDWR) ;

        /* 
         *  return 
         */
        return ret ;
      }

      void       L_DEBUG_DFA_close         
      ( 
        INOUT  int        dfa 
      )
      {
        /* 
         *  close 
         */
        X_FILE_close(dfa) ;
      }

      void       L_DEBUG_DFA_creat         
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        T_CHAR  *dfaName ;
        int      ret ;

        dfaName = L_DEBUG_DFA_getName(dfaType,dfaId,file,line) ;

        ret = X_FILE_creat(dfaName,S_IRWXU) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_perror
             ( 
               DBG_INFO,
               FALSE,
               "I can NOT creat dfa file\n"
             ) ;
             exit(1) ; /* die hard */
           }

        L_DEBUG_DFA_writeState(ret,"begin",file,line) ;
        close(ret) ;
      }

      void       L_DEBUG_DFA_remove        
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        T_CHAR  *dfaName ;
        int      ret ;

        dfaName = L_DEBUG_DFA_getName(dfaType,dfaId,file,line) ;

        ret = unlink(dfaName) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_PrintF
             ( 
               DBG_INFO,
               FALSE,
               "debug_dfa(%s,%li,\"unknow reference to %s\")\n",
               file,line,
               dfaName 
             ) ;
           }
      }

      void       L_DEBUG_DFA_rename        
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *olddfaId,
        IN     void      *newdfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        if ( olddfaId != newdfaId )
           {
             T_CHAR  *olddfaName ;
             T_CHAR  *newdfaName ;
             int      ret ;

             olddfaName = L_DEBUG_DFA_getName(dfaType,olddfaId,file,line) ;
             newdfaName = L_DEBUG_DFA_getName(dfaType,newdfaId,file,line) ;

             ret = rename(olddfaName,newdfaName) ;
             if (ret < 0)
                {
                  L_DEBUG_MSG_PrintF
                  ( 
                    DBG_INFO,
                    FALSE,
                    "debug_dfa(%s,%li,\"unknow reference to %s\")\n",
                    file,line,
                    olddfaName 
                  ) ;
                }
           }
      }

      T_BOOL     L_DEBUG_DFA_exist         
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        T_CHAR  *dfaName ;
        int      ret ;

        dfaName = L_DEBUG_DFA_getName(dfaType,dfaId,file,line) ;

        ret = X_FILE_access(dfaName,F_OK) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_PrintF
             ( 
               DBG_INFO,
               FALSE,
               "debug_dfa(%s,%li,\"unknow reference to %s\")\n",
               file,line,
               dfaName 
             ) ;
             return FALSE ;
           }

        return TRUE ;
      }


      /*  Moving dfa  *
       * ------------ */
      T_BOOL     L_DEBUG_DFA_doTransition  
      ( 
        IN     t_dfa     *dfaType,
        IN     void      *dfaId,
        IN     T_CHAR    *newState,
        IN     T_CHAR    *file,
        IN     T_U_LONG   line 
      )
      {
        T_BOOL     ok ;
        T_CHAR    *dfaName ;
        int        ret ;
        T_CHAR     oldState[1024] ;
        T_CHAR     oldFile[1024] ;
        T_U_LONG   oldLine ;

        /* 
         *  check if exist dfa 
         */
        dfaName = L_DEBUG_DFA_getName(dfaType,dfaId,file,line) ;
        ret = access(dfaName,F_OK) ;
        if (ret < 0)
           {
             L_DEBUG_DFA_creat(dfaType,dfaId,file,line) ;
           }

        /* 
         *  check newState is valid
         */
        oldState[0] = '\0' ;
        ret = open(dfaName,O_RDWR) ;
        if (ret < 0)
           {
             L_DEBUG_MSG_PrintF
             ( 
               DBG_INFO,
               FALSE,
               "debug_dfa(%s,%li,\"unknow reference to %s\")\n",
               file,line,
               dfaName 
             ) ;
             return FALSE ;
           }

        ok  = L_DEBUG_DFA_readState(ret,oldState,oldFile,&oldLine) ;
        if (ok == FALSE)
           {
             L_DEBUG_MSG_PrintF
             ( 
               DBG_INFO,
               FALSE,
               "debug_dfa(%s,%li,\"invalid reference to %s\")\n",
               file,line,
               dfaName 
             ) ;
             return FALSE ;
           }

        ok  = L_DEBUG_DFA_existTransition(dfaType,oldState,newState) ;
        if (ok == FALSE)
           {
             L_DEBUG_MSG_PrintF
             ( 
               DBG_INFO,
               FALSE,
               "debug_dfa(%s,%li,\"invalid transition in %s, from %s to %s\")\n",
               file,line,
               dfaName,
               oldState,
               newState
             ) ;
             return FALSE ;
           }

        /* 
         *  update new state
         */
        L_DEBUG_DFA_writeState(ret,newState,file,line) ;
        close(ret) ;

        /* 
         *  check final state
         */
        ok  = L_DEBUG_DFA_existTransition(dfaType,newState,"end") ;
        if (ok == TRUE)
           {
             L_DEBUG_DFA_remove(dfaType,dfaId,file,line) ;
           }

        /* 
         *  return 
         */
        return TRUE ;
      }


   /* ................................................................... */

