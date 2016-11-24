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

      #include "mp/mpi/mpi_reduce/mpi_reduce_list.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_REDUCE_LIST
      ( 
        INOUT  void         *sendbuf, 
        INOUT  void         *recvbuf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           op, 
        IN     int           root, 
        IN     MPI_Comm      comm,
		IN     int           reduce_exec
      )
      {
        T_BOOL           ok ;
        int              ret, rank, bcount ;
        void           **barray[MAX_SOCKS] ;
		t_req_param      reduce_param ;

        /*
         *  get some comm info
         */
        ret = MPI_Comm_rank(comm,&rank) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;

        /*
         *  bytes to send/recv
         */
        bcount = count * L_DATATYPE_size(datatype) ;

        /*
         *  hand on
         */
        if (root == rank)
           {
             int  i, node ;

             /* 
              * lauch receive threads
              */
             L_MULTI_REQUEST_init(reduce_exec,&(reduce_param)) ;

             reduce_param.req.data_size = bcount ;
             reduce_param.nodeli        = MPI_COMM_commNodeLi(comm) ;
             reduce_param.tagY          = NR_REDUCE ;
             reduce_param.filter        = FILTER_DEFAULT ;

             for (i=0; i<MAX_SOCKS; i++)
             {
               barray[i] = NULL ;
               node = MPI_COMM_translate_rank(comm,i) ;
               if (
                    (node != -1)
                         &&
                    (node != NODE_node_id())
                  )
                  {
                    barray[i] = X_ALLOC_Malloc(bcount) ;
                    reduce_param.req.data_buff = (char *)(barray[i]) ;
                    reduce_param.req.from      = node ;
                    ok = L_MULTI_REQUEST_recv(&(reduce_param)) ;
                    if (ok == FALSE)    
                        return MPI_ERR ;
                  }
             }
             L_MULTI_REQUEST_finalize(&(reduce_param)) ;

             /* 
              *  reducing ...
              */
             X_ALLOC_MemMove(recvbuf,sendbuf,bcount) ;
             for (i=0; i<MAX_SOCKS; i++)
             {
               if (barray[i] != NULL)
                  {
                    ok = MPI_REDUCE_OP_ApplyReduce(op,datatype,count,
                                                 recvbuf,barray[i]) ;
                    if (ok == FALSE)    
                        return MPI_ERR ;
                    X_ALLOC_Free((void **)&(barray[i])) ;
                  }
             }

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
                 NR_REDUCE,
                 FILTER_DEFAULT,
                 sendbuf,
                 bcount,
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

