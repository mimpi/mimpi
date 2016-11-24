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

      #include "mp/mpi/mpi_init.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_Init 
      ( 
        int      *p_argc, 
        char   ***p_argv 
      )
      {
        int    j, nnodes ;
        T_BOOL ok ;

        /*
         *  console info
         */
        #if defined(__DEBUG__)
            L_STACK_MSG_Push("MPI_Init,%i,%p",
                                (*argc),
                                (*argv)) ;
        #endif

        /*
         *  check NODE_initialized
         */
        if (NODE_initialized() == TRUE)
            goto LABEL_MPI_INIT_OK ;

        /*
         *  init params
         */
        ok = PARAMS_MPI_put((*p_argc),(*p_argv)) ;
        if (ok == FALSE)
            goto LABEL_MPI_RECV_ERROR ;

        /*
         *  init node
         */
        ok = NODE_init(p_argc,p_argv) ;
        if (ok == FALSE)
            goto LABEL_MPI_RECV_ERROR ;

        /*
         *  init comm
         */
        MPI_COMM_init() ;
        nnodes = NODE_n_nodes() ;
        for (j=0; j< nnodes; j++)
            {
              MPI_COMM_insert(MPI_COMM_WORLD,j) ;
            }


        /*
         *  Return
         */
        LABEL_MPI_INIT_OK :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_Init,%i,%p",
                                (*argc),
                                (*argv)) ;
           #endif

           return (MPI_SUCCESS) ;


        LABEL_MPI_RECV_ERROR :

           #if defined(__DEBUG__)
               L_STACK_MSG_Pop("MPI_Init,%i,%p",
                                (*argc),
                                (*argv)) ;
           #endif

           return (MPI_ERR) ;

      }


   /* ................................................................. */


