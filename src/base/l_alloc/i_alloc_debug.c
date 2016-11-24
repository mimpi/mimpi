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

      #include "base/l_alloc/i_alloc_debug.h"


   /* ... Functions / Funciones ......................................... */

      t_dfaTransition I_ALLOC_DEBUG_memTRANSITIONS[] =
                      {
                        { "begin", "malloc" },
                        { "begin", "realloc" },
                        { "malloc", "realloc" },
                        { "realloc", "realloc" },
                        { "malloc", "free" },
                        { "realloc", "free" },
                        { "free", "end" },
                        { NULL, NULL }
                      } ;

      t_dfa  I_ALLOC_DEBUG_memDFA =
             {
               "DBG_memory",
               I_ALLOC_DEBUG_memTRANSITIONS
             } ;


      /*  Standard Memory Functions  *
       * --------------------------- */
      T_POINTER  I_ALLOC_DEBUG_Malloc   ( IN     T_U_INT    size,
                                          IN     T_CHAR    *file,
                                          IN     T_INT      line )
      {
        T_POINTER  pvoid ;

        /*
         *  action
         */
        pvoid = L_ALLOC_Malloc(size) ;

        /*
         *  debug
         */
        L_DEBUG_MSG_PrintF( DBG_INFO,
                            FALSE,
                            "alloc(%s,%li,%li,%i,\"Malloc\")",
                            file,line,
                            pvoid,
                            size ) ;
        L_DEBUG_DFA_doTransition( &I_ALLOC_DEBUG_memDFA,
                                  pvoid,
                                  "malloc",
                                  file,
                                  line ) ;

        /*
         *  return
         */
        return pvoid ;
      }

      void       I_ALLOC_DEBUG_Free     ( INOUT  T_POINTER *ptr,
                                          IN     T_CHAR    *file,
                                          IN     T_INT      line )
      {
        /*
         *  debug
         */
        L_DEBUG_MSG_PrintF( DBG_INFO,
                            FALSE,
                            "alloc(%s,%li,%li,\"Free\")",
                            file,line,
                            ptr ) ;
        L_DEBUG_DFA_doTransition( &I_ALLOC_DEBUG_memDFA,
                                  (*ptr),
                                  "free",
                                  file,
                                  line ) ;

        /*
         *  action
         */
        L_ALLOC_Free(ptr) ;
      }

      T_POINTER  I_ALLOC_DEBUG_Realloc  ( IN     T_POINTER  block, 
                                          IN     T_U_INT    size,
                                          IN     T_CHAR    *file,
                                          IN     T_INT      line )
      {
        T_POINTER  pvoid ;

        /*
         *  action
         */
        pvoid = L_ALLOC_Realloc(block,size) ;

        /*
         *  debug
         */
        L_DEBUG_MSG_PrintF( DBG_INFO,
                            FALSE,
                            "alloc(%s,%li,%li,%i,\"Realloc\")",
                            file,line,
                            block,
                            size ) ;
        L_DEBUG_DFA_rename( &I_ALLOC_DEBUG_memDFA,
                            block,
                            pvoid,
                            file,
                            line ) ;
        L_DEBUG_DFA_doTransition( &I_ALLOC_DEBUG_memDFA,
                                  pvoid,
                                  "realloc",
                                  file,
                                  line ) ;

        /*
         *  return
         */
        return pvoid ;
      }
      

      /*  Advanced Memory Functions  *
       * --------------------------- */
      T_POINTER  I_ALLOC_DEBUG_MemMove  ( IN     T_POINTER  dest,
                                          IN     T_POINTER  src,
                                          IN     T_U_INT    count,
                                          IN     T_CHAR    *file,
                                          IN     T_INT      line )
      {
        /*
         *  debug
         */
        L_DEBUG_MSG_PrintF(DBG_INFO,
                           FALSE,
                           "alloc(%s,%li,%li,\"MemMove\")",
                           file,line,
                           dest,
                           src,
                           count) ;

        /*
         *  action
         */
        if (dest != NULL)
            L_ALLOC_MemMove(dest,src,count) ;

        /*
         *  return
         */
        return dest ;
      }

      T_POINTER  I_ALLOC_DEBUG_MemSet   ( IN     T_POINTER  dest,
                                          IN     T_BYTE     byte,
                                          IN     T_U_INT    count,
                                          IN     T_CHAR    *file,
                                          IN     T_INT      line )
      {
        /*
         *  debug
         */
        L_DEBUG_MSG_PrintF(DBG_INFO,
                           FALSE,
                           "alloc(%s,%li,%li,\"MemSet\")",
                           file,line,
                           dest,
                           byte,
                           count) ;

        /*
         *  action
         */
        if (dest != NULL)
            L_ALLOC_MemSet(dest,byte,count) ;

        /*
         *  return
         */
        return dest ;
      }


      /*  Control Memory Functions  *
       * -------------------------- */
      T_POINTER  I_ALLOC_DEBUG_ChkPtr  ( IN     T_POINTER   b,
                                         IN     T_CHAR     *file,
                                         IN     T_INT       line )
      {
        /*
         *  action
         */
        L_DEBUG_MSG_PrintF( DBG_INFO,
                            FALSE,
                            "alloc(%s,%li,%li,\"ChkPtr\")",
                            file,line,
                            b ) ;
        L_DEBUG_DFA_exist( &I_ALLOC_DEBUG_memDFA,
                            b,
                            file,
                            line ) ;

        /*
         *  return
         */
        return b ;
      }


   /* ................................................................... */

