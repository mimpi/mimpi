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

      #include "mp/mpi/mpi_scatter/mpi_scatter_list.h"


   /* ... Functions / Funciones ....................................... */

      int   MPI_SCATTER_LIST
      ( 
        INOUT  void         *sendbuf, 
        IN     int           sendcount, 
        IN     MPI_Datatype  senddatatype, 
        INOUT  void         *recvbuf, 
        IN     int           recvcount, 
        IN     MPI_Datatype  recvdatatype, 
        IN     int           root, 
        IN     MPI_Comm      comm,
		IN     int           scatter_exec
      )
      {
        T_BOOL           ok ;
        int              ret, rank ;
        int              bscount, brcount ;
	t_req_param      scatter_param ;

        /*
         *  get some comm info
         */
        ret     = MPI_Comm_rank(comm,&rank) ; 
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
              * Offset Index => second 'bscount' block 
              */
             oi = 1 ;

             L_MULTI_REQUEST_init(MR_JOIN_THREAD,&(scatter_param)) ;
             scatter_param.nodeli         = MPI_COMM_commNodeLi(comm) ;
             scatter_param.tagY           = NR_SCATTER ;

             for (i=0; i<MAX_SOCKS; i++)
             {
               node = MPI_COMM_translate_rank(comm,i) ;
               if (
                    (node != -1)
                         &&
                    (node == NODE_node_id())
                  )
                  {
                    X_ALLOC_MemMove(recvbuf,sendbuf,bscount) ;
                    continue ;
                  }
               if (
                    (node != -1)
                         &&
                    (node != NODE_node_id())
                  )
                  {
                    scatter_param.req.data_size = bscount ;
                    scatter_param.filter        = FILTER_DEFAULT ;
                    scatter_param.req.to        = node ;
                    scatter_param.req.data_buff = (char *)sendbuf + oi*bscount ;
                    oi ++ ;
                    ok = L_MULTI_REQUEST_send(&(scatter_param)) ;
                    if (ok == FALSE)    
                        return MPI_ERR ;
                  }
             }
             L_MULTI_REQUEST_finalize(&(scatter_param)) ;
             ret = MPI_SUCCESS ;
           }
        else { 
               t_nodeReq  receive ;
       
               L_FILTER_REQUEST_recv_and_unpack
               (
                 &ok,
                 &receive,
                 MPI_COMM_commNodeLi(comm),
                 REQ_RECEIVE_X_SYNC,
                 0,
                 NR_SCATTER,
                 FILTER_DEFAULT,
                 recvbuf,
                 brcount,
                 MPI_COMM_translate_rank(comm,root),
                 NODE_node_id()
               ) ;

               ret = ( (ok == TRUE) ? MPI_SUCCESS : MPI_ERR ) ;
             } 

        /*
         *  return 'ret'
         */
        return ret ;
      }


   /* ................................................................. */


