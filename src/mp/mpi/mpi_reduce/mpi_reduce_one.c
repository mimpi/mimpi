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

      #include "mp/mpi/mpi_reduce/mpi_reduce_one.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_REDUCE_ONE_sync_function
      ( 
        INOUT  void         *sendbuf, 
        INOUT  void         *recvbuf, 
        IN     int           count, 
        IN     MPI_Datatype  datatype, 
        IN     int           op, 
        IN     int           root, 
        IN     MPI_Comm      comm 
      )
      {
        T_BOOL           ok ;
        int              ret, rank, bcount ;
        void            *barray ;

        bcount = count * L_DATATYPE_size(datatype) ;
        ret = MPI_Comm_rank(comm,&rank) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;

        if (root == rank)
           {
             int        i, node ;
             t_nodeReq  receive ;

             X_ALLOC_MemMove(recvbuf,sendbuf,bcount) ;
             barray = X_ALLOC_Malloc(bcount) ;
             if (barray == NULL)
                {
                  return MPI_ERR ;
                }

             /* ... recolecting ... */
             for (i=0; i<MAX_SOCKS; i++)
             {
               node = MPI_COMM_translate_rank(comm,i) ;
               if (
                    (node != -1)
                         &&
                    (node != NODE_node_id())
                  )
                  {
                    /* 
                     *  receiving 
                     */
                    L_FILTER_REQUEST_recv_and_unpack
                    (
                      &ok,
                      &(receive),
                      MPI_COMM_commNodeLi(comm),
                      REQ_RECEIVE_X_SYNC,
                      0,
                      NR_REDUCE,
                      FILTER_DEFAULT,
                      (char *)(barray),
                      bcount,
                      node,
                      NODE_node_id()
                    ) ;

                    /* 
                     *  reducing ... 
                     */
                    ok = MPI_REDUCE_OP_ApplyReduce(op,
                                                 datatype,
                                                 count,
                                                 recvbuf,
                                                 barray) ;
                    if (ok == FALSE)    
                        return MPI_ERR ;
                  }
             }
             X_ALLOC_Free((void **)&(barray)) ;
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

