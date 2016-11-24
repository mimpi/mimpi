
/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@hinojo.datsi.fi.upm.es>
 * <fgarcia@hinojo.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"


	int
	main
	(
	  int   argc,
	  char *argv[]
	)
	{
	  /*
	   *  para MPI
	   */
  	  int rank ;
	  MPI_Status status ;

	  /*
	   *  para mensaje
	   */
	  char mensaje[20] ;


	  /*
	   *  inicializar MPI
	   */
	  MPI_Init(&argc,&argv) ;

	  /*
	   *  saber mi identificador en el supergrupo
	   */
	  MPI_Comm_rank(MPI_COMM_WORLD,&rank) ;

	  /*
	   *  ejecutar cada uno su codigo
	   */
	  switch(rank)
	  {
	    case 0 :
		 strcpy(mensaje,"hola mundo") ;
		 MPI_Send(mensaje,
			  20,              /* numero elementos */
			  MPI_CHAR,        /* tipo de dato de un elemento */
			  1,               /* origen */
			  99,              /* etiqueta */
			  MPI_COMM_WORLD) ;
                 break ;
	    case 1 :
		 MPI_Recv(mensaje,
			  20,              /* numero elementos */
			  MPI_CHAR,        /* tipo de dato de un elemento */
			  0,               /* origen */
			  99,              /* etiqueta */
			  MPI_COMM_WORLD,
			  &status) ;
		 printf("%s\n",mensaje) ;
                 break ;
            default :
                 printf("%s", "Rank not valid...\n") ;
                 break ;
	  }

	  /*
	   *  finalizar MPI
	   */
	  MPI_Finalize() ;

          /*
           *  exit (0)
           */
          return 0 ;
	}



