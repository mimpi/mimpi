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

      #include "mp/mpi/mpi_bcast/mpi_bcast_tree.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_BCAST_calcularPadre  
      ( 
        IN    int  nodeId,  
        IN    int  nivel 
      )
      {
        int m1, m2;

        /* posibles padres */
        m1 = nodeId - MPIX_MATH_pow_x_2 (nivel-1);
        m2 = nodeId - MPIX_MATH_pow_x_2 (nivel);

        if (MPIX_MATH_log_x_2_le(m1+1) == nivel-1)
                return m1 ;
        else
                return m2 ;     

      }


      int MPI_BCAST_TREE
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
        int            mylevel, dest1, dest2, node1, node2 ;
        t_nodeReq      receive ;
        int            node_papa ;
        t_req_param    bcast_param ;

 
        bcount = count * L_DATATYPE_size(datatype) ;
        ret    = MPI_Comm_rank(comm,&rank) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;

        mylevel = MPIX_MATH_log_x_2_le(NODE_node_id()+1) ;

        /*
         *  setup params  
         */
        L_MULTI_REQUEST_init(bcast_exec,&(bcast_param)) ;
        bcast_param.tagY          = NR_BCAST ;
        bcast_param.nodeli        = MPI_COMM_commNodeLi(comm) ;

        /*
         *  send data  
         */
        if (root != rank)
           { 
             node_papa = MPI_BCAST_calcularPadre(NODE_node_id(), mylevel);

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
                node_papa,
                NODE_node_id()
             ) ;
           }
       
        dest1 = NODE_node_id() + MPIX_MATH_pow_x_2(mylevel) ;
        node1 = MPI_COMM_translate_rank(comm,dest1) ;
        if (node1 != -1)
           {
             bcast_param.req.data_size = bcount ;
             bcast_param.req.data_buff = buf ;
             bcast_param.filter        = FILTER_DEFAULT ;
             bcast_param.req.to = node1 ;
             ok = L_MULTI_REQUEST_send(&(bcast_param)) ;
             if (ok == FALSE)    
                 return MPI_ERR ;
           }

        dest2 = NODE_node_id() + 2 * MPIX_MATH_pow_x_2(mylevel) ;
        node2 = MPI_COMM_translate_rank(comm,dest2) ;
        if (node2 != -1)
           {
             bcast_param.req.data_size = bcount ;
             bcast_param.req.data_buff = buf ;
             bcast_param.filter        = FILTER_DEFAULT ;
             bcast_param.req.to = node2 ;
             ok = L_MULTI_REQUEST_send(&(bcast_param)) ;
             if (ok == FALSE)    
                 return MPI_ERR ;
           }

        /*
         *  the end  
         */
        L_MULTI_REQUEST_finalize(&(bcast_param)) ;
        return MPI_SUCCESS ;
      }


   /* ................................................................. */

