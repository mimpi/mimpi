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

      #include "mp/mpi/mpi_bcast/mpi_bcast_list.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_BCAST_LIST
      ( 
        INOUT  void         *buf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           root, 
        IN     MPI_Comm      comm,
        IN     int           bcast_exec
      )
      {
        T_BOOL         ok ;
        int            ret, rank, bcount ;
        t_req_param    bcast_param ;

        /*
         *  get some comm info
         */
        ret    = MPI_Comm_rank(comm,&rank) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;

	/*
	 *  know byte count
	 */
        bcount = count * L_DATATYPE_size(datatype) ;

	/*
	 *  hand on
	 */
        if (root == rank)
           {
             int  i, node ;

             L_MULTI_REQUEST_init(bcast_exec,&(bcast_param)) ;
             for (i=0; i<MAX_SOCKS; i++)
             {
               node = MPI_COMM_translate_rank(comm,i) ;
               if (
                    (node != -1)
                         &&
                    (node != NODE_node_id())
                  )
                  {
                    bcast_param.req.data_buff = buf ;
                    bcast_param.req.data_size = bcount ;
                    bcast_param.filter        = FILTER_DEFAULT ;
                    bcast_param.tagY   = NR_BCAST ;
                    bcast_param.nodeli = MPI_COMM_commNodeLi(comm) ;
                    bcast_param.req.to = node ;

                    ok = L_MULTI_REQUEST_send(&(bcast_param)) ;
                    if (ok == FALSE)    
                        return MPI_ERR ;
                  }
             }
             L_MULTI_REQUEST_finalize(&(bcast_param)) ;
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
                 NR_BCAST,
                 FILTER_DEFAULT,
                 buf,
                 bcount,
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



