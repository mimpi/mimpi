/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Include / Inclusiones ....................................... */

      #include "mp/xmp/map/node/l_nodes/l_nodei.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL   L_NODEI_writeSendReq
      (
        INOUT  t_sb                 *sb,
        INOUT  int                   sock,
        IN     t_nodeHeader         *outHeader,
        INOUT  t_nodeReq            *psend
      )
      {
        T_BOOL ok ;

        /*
         *  set values
         */
        (outHeader)->id   = NH_DATA ;
        (outHeader)->size = (psend)->data_size ;
        (outHeader)->tagX = (psend)->tagX ;
        (outHeader)->tagY = (psend)->tagY ;

        /* 
         *  send header and data
         */
		if ((psend)->data_size <= NH_IDATA)
		{ 
          /*
           *  add data to header
           */
		  X_ALLOC_MemMove((outHeader)->idata,
			              (psend)->data_buff,
			              (psend)->data_size) ;

          /*
           *  write header
           */
          ok = L_NODEHEADER_writeHeader ( sb,
                                          sock,
                                          (outHeader) ) ;
          if (ok == FALSE)
		  {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                "ERROR: fail when try writeHeader...") ;
             return FALSE ;
          }
		}
		else
		{ 
          /*
           *  add data to header
           */
	      X_ALLOC_MemMove((outHeader)->idata,
			              (psend)->data_buff,
			              NH_IDATA) ;

		  /*
           *  write header
           */
          ok = L_NODEHEADER_writeHeader ( sb,
                                          sock,
                                          (outHeader) ) ;
          if (ok == FALSE)
		  {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                "ERROR: fail when try writeHeader...") ;
             return FALSE ;
          }

          /*
           *  write data 
           */
          ok = L_NODEDATA_writeData ( sb,
                                      sock,
                                      (psend)->data_buff+NH_IDATA,
                                      (psend)->data_size-NH_IDATA) ;
          if (ok == FALSE)
		  {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: fail when try writeData...") ;
             return FALSE ;
          }
		}

        /*
         *  return ok 
         */
        return TRUE ;
      }

      T_BOOL   L_NODEI_recvConnect
      (
        INOUT  t_sb                 *sb,
        OUT    int                  *sock,
        OUT    int                  *who
      )
      {
        T_BOOL  ok ;
        int     ret ;

        /*
         *  try accept
         */
        ok = L_SB_accept(sb,sock) ;
        if (ok == FALSE)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: fail when try L_SB_accept...") ;
             return FALSE ;
           }

        /*
         *  receive its identity
         */
        ret = L_SB_read( sb,
                         (*sock),
                         (char *) who,
                         c_INT ) ;
        if (ret <= 0)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: fail when try read node' I.D.") ;
             return FALSE ;
           }

        /*
         *  return ok 
         */
        return TRUE ;
      }

      T_BOOL   L_NODEI_sendConnect
      (
        INOUT  t_sb                 *sb,
        IN     T_INT                *nodeid,
        IN     struct sockaddr_in   *sa,
        OUT    int                  *sock
      )
      {
        T_BOOL  ok ;
        int     ret ;

        /*
         *  try connect
         */
        ok = L_SB_connectTo(sb,sock,sa) ;
        if (ok == FALSE)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: fail when try L_SB_connectTo") ;
             return FALSE ;
           }

        /*
         *  send my identity
         */
        ret = L_SB_write ( sb,
                           (*sock),
                           (char *) (nodeid),
                           c_INT ) ;
        if (ret < 0)
           {
             L_TRACE_MSG_PrintF(DEFCON_1,
                                 "ERROR: fail when try write node' I.D.") ;
             return FALSE ;
           }

        /*
         *  return ok 
         */
        return TRUE ;
      }


  /* .................................................................... */

