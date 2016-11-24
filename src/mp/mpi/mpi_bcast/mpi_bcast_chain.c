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

      #include "mp/mpi/mpi_bcast/mpi_bcast_chain.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_BCAST_CHAIN
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
        int            ret ;
        int            size, rank, bRank, nRank, bRRank, nRRank ;
        int            bcount ;
        t_req_param    bcast_param ;

 
        /*
         *  comm stuff
         */
        ret = MPI_Comm_size(comm,&size) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;
        ret = MPI_Comm_rank(comm,&rank) ; 
        if (ret == MPI_ERR) 
            return MPI_ERR ;

        /*
         *  next-back rank  
         */
        bRank  = MPI_COMM_back_rank(comm,rank) ; 
        nRank  = MPI_COMM_next_rank(comm,rank) ; 
        bRRank = MPI_COMM_back_rank(comm,root) ; 
        nRRank = MPI_COMM_next_rank(comm,root) ; 

        /*
         *  knowing size
         */
        bcount = count * L_DATATYPE_size(datatype) ;

        /*
         *  setup params  
         */
        L_MULTI_REQUEST_init(bcast_exec,&(bcast_param)) ;

        /*
         *  1.- root send data
         */
        if (rank == root)
           { 
             bcast_param.req.data_size = bcount ;
             bcast_param.req.data_buff = buf ;
             bcast_param.filter        = FILTER_DEFAULT ;
             bcast_param.req.to = nRRank ;
             bcast_param.nodeli = MPI_COMM_commNodeLi(comm) ;
             bcast_param.tagY   = NR_BCAST ;
             ok = L_MULTI_REQUEST_send(&(bcast_param)) ;
             if (ok == FALSE)    
                 return MPI_ERR ;
           } 
       
        /*
         *  2.- last receive data
         */
        if (rank == bRRank)
           { 
             bcast_param.req.data_size = bcount ;
             bcast_param.req.data_buff = buf ;
             bcast_param.filter        = FILTER_DEFAULT ;
             bcast_param.req.from = bRank ;
             bcast_param.nodeli   = MPI_COMM_commNodeLi(comm) ;
             bcast_param.tagY     = NR_BCAST ;
             ok = L_MULTI_REQUEST_recv(&(bcast_param)) ;
             if (ok == FALSE)    
                 return MPI_ERR ;
           } 

        /*
         *  3.- inter-nodes
         */
        if (
             (rank != root)
                   &&
             (rank != bRRank)
           )
           { 
             /*
              *  receive back
              */
             bcast_param.req.data_size = bcount ;
             bcast_param.req.data_buff = buf ;
             bcast_param.filter        = FILTER_DEFAULT ;
             bcast_param.req.from = bRank ;
             bcast_param.nodeli   = MPI_COMM_commNodeLi(comm) ;
             bcast_param.tagY     = NR_BCAST ;
             ok = L_MULTI_REQUEST_recv(&(bcast_param)) ;
             if (ok == FALSE)    
                 return MPI_ERR ;

             /*
              *  send back
              */
             bcast_param.req.data_size = bcount ;
             bcast_param.req.data_buff = buf ;
             bcast_param.filter        = FILTER_DEFAULT ;
             bcast_param.req.to = nRank ;
             bcast_param.nodeli = MPI_COMM_commNodeLi(comm) ;
             bcast_param.tagY   = NR_BCAST ;
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

