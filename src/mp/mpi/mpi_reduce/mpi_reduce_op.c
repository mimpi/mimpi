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

      #include "mp/mpi/mpi_reduce/mpi_reduce_op.h"


   /* ... Functions / Funciones ....................................... */

      T_BOOL MPI_REDUCE_OP_ApplyReduce   
      ( 
        IN     int           op, 
        IN     MPI_Datatype  datatype, 
        IN     int           count, 
        INOUT  void         *op1res, 
        INOUT  void         *op2 
      )
      {
        switch (op)
        {
          case MPI_MAX :
               L_DATATYPE_MAX(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_MIN :
               L_DATATYPE_MIN(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_SUM :
               L_DATATYPE_SUM(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_PROD :
               L_DATATYPE_PROD(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_LAND :
               L_DATATYPE_LAND(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_BAND :
               L_DATATYPE_BAND(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_LOR  :
               L_DATATYPE_LOR(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_BOR  :
               L_DATATYPE_BOR(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_LXOR :
               L_DATATYPE_LXOR(datatype,count,op1res,op1res,op2) ;
               break ;
          case MPI_NOP :
               break ;
          default :
               return FALSE ;
        }
        return TRUE ;
      }


   /* ................................................................. */


