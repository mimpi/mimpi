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

      #include "mp/xmp/base/l_sb/l_sb_select.h"


   /* ... Funciones ................................................... */

#if ( defined(__LINUX__) || defined(__SUNOS__) || defined(HAVE_WINDOWS_H) )
      T_BOOL  L_SB_select    
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *fd 
      )
      {
        int    ch, i ;
        int    ret_select ;
        int    fdtmp, fdaux ;
        fd_set readfds ;

        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(fd) ;

        /* 
         *  wait any event
         */
        do
        {
           while (TRUE)
           {
              /*
               *  setup '_sock_set' 
               */
              FD_ZERO(&readfds) ;
              for (i=0; i<sb->last; i++)
                  {
                    if (
                         ( i != sb->ns )
                                &&
                         ( L_SB_alive(sb,i) == TRUE )
                       )
                       {
                         fdtmp = L_SB_getFd(sb,i) ;
                         FD_SET(fdtmp,&readfds) ;
                       }
                  }

              /*
               *  select 
               */
              ret_select = select(MAX_SOCKS,&readfds,NULL,NULL,NULL) ;
              if (ret_select >= 0)
                  break;
              switch (errno)
              {
                case EINTR:
                     ret_select = 0;
                     continue;
                default:
                     L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At select...") ;
                     return FALSE ;
              }
           }

           (*fd) = -1 ;
           if ( FD_ISSET(L_SB_getFd(sb,sb->my),&readfds) )
              {
                /* accept */
                L_SB_accept(sb,&fdaux) ;
                continue ;   /* play it again, ... */
              }
           for (ch=0; ch < sb->last; ch++)
           {
              if (
                   ( ch != sb->ns )
                          &&
                   ( ch != sb->my )
                          &&
                   ( L_SB_alive(sb,ch) == TRUE )
                 )
                 {
                   fdtmp = L_SB_getFd(sb,ch) ;
                   if ( FD_ISSET(fdtmp,&readfds) )
                      {
                        if (fdtmp != -1)
                           {
                             (*fd) = ch ;
                             return TRUE ;
                           }
                      }  /* if */
                 }  /* if */
            }  /* for */
        } while ((*fd) < 0) ;

        /*
         *  return
         */
        return TRUE ;
      }
#endif

#if defined(__SP2__)
      T_BOOL  L_SB_select    
      ( 
        INOUT  t_sb    *sb,
        INOUT  int     *fd 
      )
      {
        struct pollfd       *_sock_set ;
        struct sockaddr_in   sa;
        int     i, _sock_set_size ;
        int     ret_poll, ch ;
        int     fdtmp, fdaux ;
        T_BOOL  ok ;

        /* 
         *  check params 
         */
        NULL__SET_ERROR__RET_FALSE(sb) ;
        NULL__SET_ERROR__RET_FALSE(fd) ;

        /*
         *  select 
         */
        _sock_set_size = MAX_SOCKS * sizeof(struct pollfd) ;
        _sock_set = X_ALLOC_Malloc(_sock_set_size) ;
        NULL_RET_FALSE(_sock_set) ;
        (*fd) = -1 ;
        do
        {
           while (TRUE)
           {
              /*
               *  setup '_sock_set' 
               */
              X_ALLOC_MemSet(_sock_set,0,_sock_set_size) ;
              for (i=0; i<MAX_SOCKS; i++)
                  {
                    if (
                         ( i != sb->ns )
                                &&
                         ( L_SB_alive(sb,i) == TRUE )
                       )
                       {
                         (_sock_set[i]).fd     = L_SB_getFd(sb,i) ;
                         (_sock_set[i]).events = POLLIN ;
                       }
                  }

              /*
               *  poll 
               */
              ret_poll = poll(_sock_set,MAX_SOCKS,-1) ;
              if (ret_poll >= 0)
                  break;
              switch (errno)
              {
                case EINTR  :
                case EAGAIN :
                     ret_poll = 0;
                     continue ;
                default:
                     L_DEBUG_MSG_perror(DBG_ERROR,TRUE,"At poll...") ;
                     X_ALLOC_Free( (void **)&(_sock_set) ) ;
                     return FALSE ;
              }
           }

           ch = 0 ;
           while (ret_poll > 0)
           {
             switch (_sock_set[ch].revents)
             {
               case 0 :
                    break ;
               case POLLHUP :
               case POLLHUP | POLLIN :
                    ret_poll-- ;
                    ok = L_SB_unplug(sb,ch) ;
                    break ;
               case POLLERR :
                    ret_poll-- ;
                    ok = L_SB_unplug(sb,ch) ;
                    break ;
               case POLLNVAL :
                    ret_poll-- ;
                    (_sock_set[ch]).fd = -1 ;
                    break ;
               case POLLIN :
                    ret_poll-- ;
                    if ( (_sock_set[ch]).fd == L_SB_getFd(sb,sb->my) )
                       { /* accept */
                         L_SB_accept(sb,&fdaux) ;
                       }
                    else
                       { /* data!!! */
                         if ( (_sock_set[ch]).fd != -1 )
                            {
                              (*fd) = ch ;
                              return TRUE ;
                            }
                       }
                    break ;
               default :
                    break ;
             }
             ch++ ;
           }

        } while ((*fd) < 0) ;

        X_ALLOC_Free( (void **)&(_sock_set) ) ;

        /*
         *  return
         */
        return TRUE ;
      }
#endif


  /* .................................................................... */

