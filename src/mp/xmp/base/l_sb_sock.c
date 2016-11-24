/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes .................................................... */

      #include "mp/xmp/base/l_sb_sock.h"


   /* ... Funciones ................................................... */

      /*          
       *   Creat/Destroy
       *  ---------------   
       */

      t_sb_sock      *L_SB_SOCK_Creat 
      ( 
        void 
      )
      {
        t_sb_sock  *sbs ;

        /*
         *  check params  
         */
        sbs = X_ALLOC_Malloc(c_SB_SOCK) ;
        NULL_RET_NULL(sbs) ;

        /*
         *  setup fields  
         */
        sbs->fd = NULL_SOCKET ;
        X_THREAD_init( (&(sbs->read_mutex)) ) ;
        X_THREAD_init( (&(sbs->write_mutex)) ) ;

        /*
         *  return descriptor
         */
        return sbs ;
      }

      T_BOOL          L_SB_SOCK_Destroy  
      ( 
        INOUT  t_sb_sock  **sbs 
      )
      {
        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sbs) ;
        NULL_RET_TRUE((*sbs)) ;

        /*
         *  destroy  
         */
        X_SOCKET_unplug (   (*sbs)->fd ) ;
        X_THREAD_destroy( &((*sbs)->read_mutex) ) ;
        X_THREAD_destroy( &((*sbs)->write_mutex) ) ;
        X_ALLOC_Free( (void **)(sbs) ) ;

        /*
         *  return ok
         */
        return TRUE ;
      }


      /*          
       *   Setup 
       *  -------   
       */

      T_BOOL  L_SB_SOCK_beeper    
      ( 
        IN     T_SOCKADDR_IN       *sa,
        INOUT  t_sb_sock          **sbs 
      )
      {
        T_BOOL ok ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sa) ;
        NULL__SET_ERROR__RET_FALSE(sbs) ;

        /*
         *  build a beeper  
         */
        (*sbs) = L_SB_SOCK_Creat() ;
        NULL_RET_FALSE((*sbs)) ;
        (*sbs)->fdaddr = *sa ;
		ok = X_SOCKET_beeper( &((*sbs)->fd),
                              &((*sbs)->fdaddr) ) ;
        FALSE_RET_FALSE(ok) ;

        /*
         *  return ok
         */
        return TRUE ;
      }

      T_BOOL  L_SB_SOCK_accept      
      ( 
        INOUT  t_sb_sock    *sbs,
        OUT    t_sb_sock   **sret 
      )
      {
        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sbs) ;
        NULL__SET_ERROR__RET_FALSE(sret) ;

        /*
         *  accept  
         */
        (*sret) = L_SB_SOCK_Creat() ;
        NULL_RET_FALSE((*sret)) ;
        X_SOCKET_accept( &((*sret)->fd),
                         &((*sret)->fdaddr),
                         (sbs->fd) ) ;

        /*
         *  return ok 
         */
        return TRUE ;
      }

      T_BOOL  L_SB_SOCK_connect     
      ( 
        INOUT  T_SOCKADDR_IN       *fdaddr,
        OUT    t_sb_sock          **sret 
      )
      {
        T_BOOL ok ;
        T_INT  i ;

        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(fdaddr) ;
        NULL__SET_ERROR__RET_FALSE(sret) ;

        /*
         *  try connect  
         */
        (*sret) = L_SB_SOCK_Creat() ;
        NULL_RET_FALSE((*sret)) ;
        (*sret)->fdaddr = (*fdaddr) ;
        ok = FALSE ;
        while (ok == FALSE)
        {
          for (i=0; (i<3); i++)
              {
                ok = X_SOCKET_connect( &((*sret)->fd),
                                       &((*sret)->fdaddr) ) ;
                TRUE_RET_TRUE(ok) ;
              }
          X_PROCESS_sleep(1) ;
        }

        /*
         *  return error 
         */
        return FALSE ;
      }


      /*          
       *   fields   
       *  --------   
       */

      T_SOCKET              L_SB_SOCK_getFd        
      ( 
        INOUT  t_sb_sock    *sbs 
      )
      {
        /*
         *  check params  
         */
        if (sbs == NULL)
		{
            L_DEBUG_MSG_Write(DBG_ERROR,FALSE,"(sbs==NULL)") ;
            return NULL_SOCKET ;
		}

        /*
         *  return fd 
         */
        return (sbs->fd) ;
      }

      T_SOCKADDR_IN        *L_SB_SOCK_getFdAddress 
      ( 
        INOUT  t_sb_sock    *sbs 
      )
      {
        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_NULL(sbs) ;

        /*
         *  return address 
         */
        return &(sbs->fdaddr) ;
      }

      T_BOOL                L_SB_SOCK_alive        
      ( 
        INOUT  t_sb_sock    *sbs 
      )
      {
        /*
         *  check params  
         */
        NULL__SET_ERROR__RET_FALSE(sbs) ;

        /*
         *  check alives 
         */
        if ( (sbs->fd) != NULL_SOCKET )
              return TRUE ;

        return FALSE ;
      }


  /* .................................................................... */

