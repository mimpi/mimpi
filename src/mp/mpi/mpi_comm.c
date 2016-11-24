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

      #include "mp/mpi/mpi_comm.h"


   /* ... Functions / Funciones ....................................... */

      int MPI_COMM_init           
      ( 
        void 
      )
      {
        long j ;

        /*
         *  set default values
         */
        L_SOCIETY_last_society = MPI_COMM_WORLD ;
        for (j=0; j < MPI_MAX_COMM; j++)
            {
              L_SOCIETY_empty(j) ;
            }

        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }

      int MPI_COMM_finalize       
      ( 
        void 
      )
      {
        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }

      int MPI_COMM_insert         
      ( 
        IN    MPI_Comm    comm,
        IN    int         rank 
      )
      {
        /*
         *  add to 'comm' communicator
         */
        (L_SOCIETY_societies[MPI_COMM_WORLD].nmembers) ++ ;
        L_SOCIETY_setMemberInfo(MPI_COMM_WORLD,rank,rank) ;

        /*
         *  add to MPI_COMM_WORLD communicator
         */
        if (comm != MPI_COMM_WORLD)
           {
             (L_SOCIETY_societies[comm].nmembers) ++ ;
             L_SOCIETY_setMemberInfo(comm,rank,rank) ;
           }

        /*
         *  return ok
         */
        return (MPI_SUCCESS) ;
      }

      int MPI_COMM_back_rank
      (   
        IN    MPI_Comm    comm,
        IN    int         rank
      )
      {
        int   ret, size ;

        /*
         *  get size
         */
        size = L_SOCIETY_getNMembers(comm) ;

        /*
         *  get next rank
         */
        ret = (rank + size - 1) % size ;

        /*
         *  return it
         */
        return (ret) ;
      }

      int MPI_COMM_next_rank    
      ( 
        IN    MPI_Comm    comm,
        IN    int         rank
      )
      {
        int   ret, size ;

        /*
         *  get size
         */
        size = L_SOCIETY_getNMembers(comm) ;

        /*
         *  get next rank
         */
        ret = (rank + 1) % size ;

        /*
         *  return it
         */
        return (ret) ;
      }


   /* ................................................................. */


