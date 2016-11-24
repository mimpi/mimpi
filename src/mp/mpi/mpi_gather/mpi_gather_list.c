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



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/mpi/mpi_gather/mpi_gather_list.h"


   /* ... Functions / Funciones ....................................... */

      int   MPI_GATHER_LIST
      ( 
        INOUT  void         *sendbuf, 
        IN     int           sendcount, 
        IN     MPI_Datatype  senddatatype, 
        INOUT  void         *recvbuf, 
        IN     int           recvcount, 
        IN     MPI_Datatype  recvdatatype, 
        IN     int           root, 
        IN     MPI_Comm      comm,
        IN     int           gather_exec
      )
      {
        T_BOOL           ok ;
        int              ret ;
        int              rank, np ;
        int              bscount, brcount ;
        t_req_param      gather_param ;

        /*
         *  get some comm info
         */
        ret     = MPI_Comm_rank(comm,&rank) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;
        ret     = MPI_Comm_size(comm,&np) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;

        /*
         *  bytes to send/recv
         */
        bscount = sendcount * L_DATATYPE_size(senddatatype) ;
        brcount = recvcount * L_DATATYPE_size(recvdatatype) ;

        /*
         *  hand on
         */
        if (root == rank)
           {
             int  i, node, oi ;

             /* 
              * oi (Offset Index) = 1 ==> second 'bscount' block 
              */
             oi = 1 ;
             L_MULTI_REQUEST_init(gather_exec,&(gather_param)) ;
             gather_param.req.data_size = brcount ;
             gather_param.nodeli        = MPI_COMM_commNodeLi(comm) ;
             gather_param.tagY          = NR_GATHER ;
             gather_param.filter        = FILTER_DEFAULT ;

             for (i=0; i<MAX_SOCKS; i++)
             {
               node = MPI_COMM_translate_rank(comm,i) ;
               if (
                    (node != -1)
                         &&
                    (node == NODE_node_id())
                  )
                  {
                    X_ALLOC_MemMove(recvbuf,sendbuf,brcount) ;
                    continue ;
                  }
               if (
                    (node != -1)
                         &&
                    (node != NODE_node_id())
                  )
                  {
                    gather_param.req.from      = node ;
                    gather_param.req.data_buff = (char *)recvbuf + oi*brcount ;
                    oi ++ ;
                    ok = L_MULTI_REQUEST_recv(&(gather_param)) ;
                    if (ok == FALSE)    
                        return MPI_ERR ;
                  }
             }
             L_MULTI_REQUEST_finalize(&(gather_param)) ;
             ret = MPI_SUCCESS ;
           }
        else { 
               t_nodeReq  send ;
       
               L_FILTER_REQUEST_pack_and_send
               (
                 &ok,
                 &send,
                 MPI_COMM_commNodeLi(comm),
                 REQ_SEND_X_SYNC,
                 0,
                 NR_GATHER,
                 FILTER_DEFAULT,
                 sendbuf,
                 bscount,
                 NODE_node_id(),
                 MPI_COMM_translate_rank(comm,root)
               ) ;
               ret = ( (ok == TRUE) ? MPI_SUCCESS : MPI_ERR ) ;
             } 

        /*
         *  return 'ret'
         */
        return ret ;
      }


   /* ................................................................. */


