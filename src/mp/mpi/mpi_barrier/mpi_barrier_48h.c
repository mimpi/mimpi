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

      #include "mp/mpi/mpi_barrier/mpi_barrier_48h.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_BARRIER_48H_Barrier 
      ( 
        MPI_Comm comm 
      )
      {
        int        np ;
        int        me ;
        char       c ;
        T_BOOL     ok ;
        t_nodeReq  send_recv ;


        /*
         *  console info
         */
        L_STACK_MSG_PopPush("MPI_BARRIER_48H_Barrier,%p",
                             comm) ;
 
        /*
         *  barrier
         */
        np = MPI_COMM_commSize(comm) ;
        if (np == 1)
            return (MPI_SUCCESS) ;

        me = MPI_COMM_translate_nodeid(comm,NODE_node_id()) ;
        if (me == 0)
           {
               L_FILTER_REQUEST_pack_and_send  (&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_SEND_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 NODE_node_id(),me + 1) ;
               L_FILTER_REQUEST_recv_and_unpack(&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_RECEIVE_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 me + 1,NODE_node_id()) ;
           }
        else if (me == (np -1))
             {
               L_FILTER_REQUEST_recv_and_unpack(&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_RECEIVE_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 me - 1,NODE_node_id()) ;
               L_FILTER_REQUEST_pack_and_send  (&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_SEND_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 NODE_node_id(),me - 1) ;
             }
             else
             {
               L_FILTER_REQUEST_recv_and_unpack(&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_RECEIVE_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 me - 1,NODE_node_id()) ;
               L_FILTER_REQUEST_pack_and_send  (&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_SEND_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 NODE_node_id(),me + 1) ;
               L_FILTER_REQUEST_recv_and_unpack(&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_RECEIVE_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 me + 1,NODE_node_id()) ;
               L_FILTER_REQUEST_pack_and_send  (&ok,&send_recv,MPI_COMM_commNodeLi(comm),
                                                 REQ_SEND_X_SYNC,-1000,NR_BARRIER,
                                                 FILTER_NULL,(&c),1,
                                                 NODE_node_id(),me - 1) ;
             }
                        
        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }


   /* ................................................................. */


