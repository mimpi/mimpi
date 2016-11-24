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

      #include "mp/mpi/mpi_allgather/mpi_allgather_dp.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_ALLGATHER_DP
      ( 
        INOUT  void         *sendbuf,
        IN     int           sendcount,
        IN     MPI_Datatype  senddatatype,
        INOUT  void         *recvbuf,
        IN     int           recvcount,
        IN     MPI_Datatype  recvdatatype,
        IN     MPI_Comm      comm
      )
      {
        int         ret ;
        int         rank, dest_rank, p_block_rank ;
        int         comm_size, bcount, count_block ;
        int         pow2p, ln2p, p ;
        MPI_Status  status ;


        /*
         *  console  
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_ALLGATHER_DP,%p,%p,%i,%p,%i,%i,%p",
                             sendbuf,
                             recvbuf,
                             count,
                             datatype,
                             op,
                             comm) ;
        #endif

        /*
	 *  get some comm info
	 */
        ret    = MPI_Comm_rank(comm,&rank) ; 
        if (MPI_ERR == ret)
           goto LABEL_MPI_ALLGATHER_ERROR ;

        ret    = MPI_Comm_size(comm, &comm_size);
        if (MPI_ERR == ret)
           goto LABEL_MPI_ALLGATHER_ERROR ;

        /*
	 *  get self data
	 */
        bcount = recvcount * L_DATATYPE_size(recvdatatype) ;
        X_ALLOC_MemMove( recvbuf+bcount*rank, /* recvbuf[rank] */
                         sendbuf,
                         bcount ) ;

        /*
	 *  Dancing Pattners
	 */
        pow2p = 1 ;
        ln2p  = MPIX_MATH_log_x_2(comm_size) ;
	for (p = 0; p < ln2p; p++)
	{
          p_block_rank = rank % (pow2p << 1) ;
          dest_rank    = pow2p + rank ;
          count_block  = recvcount * pow2p ;

          if (p_block_rank < pow2p)
             {
               ret = MPI_Send ( recvbuf + bcount*rank, count_block, recvdatatype, 
                                dest_rank, NR_ALLTOALL, comm ) ;
               if (FALSE == ret)
                  goto LABEL_MPI_ALLGATHER_ERROR ;

               ret = MPI_Recv ( recvbuf + bcount*dest_rank, count_block, recvdatatype, 
                                dest_rank, NR_ALLTOALL, comm, &status ) ;
               if (FALSE == ret)
                  goto LABEL_MPI_ALLGATHER_ERROR ;
             }
          else 
             {
               ret = MPI_Recv ( recvbuf + bcount*dest_rank, count_block, recvdatatype, 
                                dest_rank, NR_ALLTOALL, comm, &status ) ;
               if (FALSE == ret)
                  goto LABEL_MPI_ALLGATHER_ERROR ;

               ret = MPI_Send ( recvbuf + bcount*rank, count_block, recvdatatype, 
                                dest_rank, NR_ALLTOALL, comm ) ;
               if (FALSE == ret)
                  goto LABEL_MPI_ALLGATHER_ERROR ;
             }

          pow2p = pow2p << 1 ; /* <-> pow2p = pow2p * 2 ; */
	}
        goto LABEL_MPI_ALLGATHER_OK ;


        /*
         *  Return
         */
        LABEL_MPI_ALLGATHER_OK :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_ALLGATHER_DP,%p,%p,%i,%p,%i,%i,%p",
                               sendbuf,
                               recvbuf,
                               count,
                               datatype,
                               op,
                               root,
                               comm) ;
           #endif

           return MPI_SUCCESS ;

        LABEL_MPI_ALLGATHER_ERROR :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_ALLGATHER_DP,%p,%p,%i,%p,%i,%i,%p",
                               sendbuf,
                               recvbuf,
                               count,
                               datatype,
                               op,
                               root,
                               comm) ;
           #endif

           return MPI_ERR ;
      }


   /* ................................................................. */


