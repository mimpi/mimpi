/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-1999)
 * <acaldero@laurel.datsi.fi.upm.es>
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */


/*
 *
 *  prove mpi.c
 *
 */

	#include "base/l_basic/c_basic.h"
    #include "mpi.h"


	int main  
    (
      int   	argc,
	  char	   *argv[]	
    )
	{
		T_INT       i ;
		double      t1 ;
		double      t2 ;
		double      outdiff ;

		/*
         */
		printf("\n") ;
		printf("%s\n",argv[0]) ;
		printf("begin\n") ;

		/*
         *  MPI_Wtime
         */
        printf("\tdo 1000:\n") ;
        printf("\t\tt1 = MPI_Wtime()\n") ;
        printf("\t\tt2 = MPI_Wtime()\n") ;
        printf("\t\t( (t2-t1) > 0 ) ?\n") ;

		for (i=0; i< 1000; i++)
		    {
		      t1 = MPI_Wtime() ;
		      t2 = MPI_Wtime() ;
		      outdiff = t2 - t1 ;
                      if (outdiff < 0)
                          printf("t2-t1 <  0 -> ERROR\n") ;
                      if (outdiff == 0)
                          printf("t2-t1 == 0 -> WARNING\n") ;
		    }
		printf("\n") ;


		/*
         *  MPI_Wtime
         */
        printf("\tt1 = MPI_Wtime()\n") ;
        printf("\tdo 1000000:\n") ;
        printf("\t\tMPI_Wtime()\n") ;
        printf("\tt2 = MPI_Wtime()\n") ;

		t1 = MPI_Wtime() ;
		for (i=0; i< 1000000; i++)
		     MPI_Wtime() ;
		t2 = MPI_Wtime() ;
		outdiff = (t2 - t1) / 1000000 ;

        printf("\tcall time: %f sec.\n",outdiff) ;
		printf("\n") ;


		/*
         *  MPI_Wtime
         */
        printf("\tt1 = MPI_Wtime()\n") ;
        printf("\tsleep 1 seg.\n") ;
        printf("\tt2 = MPI_Wtime()\n") ;
        t1 = MPI_Wtime() ;
#if defined(HAVE_WINDOWS_H)
		Sleep(1000) ;
#else
		sleep(1) ;
#endif
        t2 = MPI_Wtime() ;
        outdiff = t2 - t1 ;
        printf("\toutdiff: %e sec.\n",outdiff) ;
        printf("\terror:   %f sec.\n",outdiff-1.0) ;


		/*
         */
		printf("end\n") ;
		return 1 ;
	}


