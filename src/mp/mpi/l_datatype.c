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

      #include "mp/mpi/l_datatype.h"


   /* ... Glob. var / Variables Globales .............................. */

      t_datatypeElement L_DATATYPE_CHAR_dte[] =
                        { { id_char, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_CHAR[] =
                        { { L_DATATYPE_CHAR_dte, 1, sizeof(char) } } ;

      t_datatypeElement L_DATATYPE_BYTE_dte[] =
                        { { id_byte, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_BYTE[] =
                        { { L_DATATYPE_BYTE_dte, 1, sizeof(unsigned char) } } ;

      t_datatypeElement L_DATATYPE_SHORT_dte[] =
                        { { id_short, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_SHORT[] =
                        { { L_DATATYPE_SHORT_dte , 1, sizeof(short) } } ;

      t_datatypeElement L_DATATYPE_INT_dte[] =
                        { { id_int, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_INT[] =
                        { { L_DATATYPE_INT_dte , 1, sizeof(int) } } ;

      t_datatypeElement L_DATATYPE_LONG_dte[] =
                        { { id_long, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_LONG[] =
                        { { L_DATATYPE_LONG_dte , 1, sizeof(long) } } ;

      t_datatypeElement L_DATATYPE_FLOAT_dte[] =
                        { { id_float, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_FLOAT[] =
                        { { L_DATATYPE_FLOAT_dte , 1, sizeof(float) } } ;

      t_datatypeElement L_DATATYPE_DOUBLE_dte[] =
                        { { id_double, NULL, 0 } } ;
      t_datatype        L_DATATYPE_MPI_DOUBLE[] =
                        { { L_DATATYPE_DOUBLE_dte , 1, sizeof(double) } } ;


   /* ... Operations / Operaciones .................................... */

      void   L_DATATYPE_MAX         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_MAX(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_MAX(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_MAX(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_MAX(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_MAX(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_MAX(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_MAX(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_MIN         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_MIN(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_MIN(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_MIN(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_MIN(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_MIN(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_MIN(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_MIN(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_SUM         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_SUM(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_SUM(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_SUM(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_SUM(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_SUM(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_SUM(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_SUM(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_PROD         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_PROD(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_PROD(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_PROD(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_PROD(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_PROD(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_PROD(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_PROD(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_LAND         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_LAND(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_LAND(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_LAND(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_LAND(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_LAND(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_LAND(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_LAND(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_BAND         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_BAND(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_BAND(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_BAND(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_BAND(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_BAND(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_BAND(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_BAND(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_LOR         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_LOR(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_LOR(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_LOR(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_LOR(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_LOR(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_LOR(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_LOR(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_BOR         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_BOR(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_BOR(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_BOR(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_BOR(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_BOR(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_BOR(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_BOR(count,result,oper1,oper2) ;
      }

      void   L_DATATYPE_LXOR         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2 
      )
      {
          if (dt == MPI_BYTE)
               L_DATATYPE_BYTE_LXOR(count,result,oper1,oper2) ;
          if (dt == MPI_CHAR)
               L_DATATYPE_CHAR_LXOR(count,result,oper1,oper2) ;
          if (dt == MPI_SHORT)
               L_DATATYPE_SHORT_LXOR(count,result,oper1,oper2) ;
          if (dt == MPI_INT)
               L_DATATYPE_INT_LXOR(count,result,oper1,oper2) ;
          if (dt == MPI_LONG)
               L_DATATYPE_LONG_LXOR(count,result,oper1,oper2) ;
          if (dt == MPI_FLOAT)
               L_DATATYPE_FLOAT_LXOR(count,result,oper1,oper2) ;
          if (dt == MPI_DOUBLE)
               L_DATATYPE_DOUBLE_LXOR(count,result,oper1,oper2) ;
      }

   /* ... Building / Construccion ..................................... */

      /*
       *  init/finalize  
       */
      MPI_Datatype   L_DATATYPE_creat       
      ( 
        void 
      )
      {
        t_datatype   *dtAux ;

        dtAux = X_ALLOC_Malloc(c_DATATYPE) ;
        NULL_RET_NULL(dtAux) ;
        dtAux->eltos  = NULL ;
        dtAux->neltos = 0L ;
        dtAux->size   = 0L ;
        return dtAux ;
      }

      T_BOOL         L_DATATYPE_destroy     
      ( 
        IN    MPI_Datatype  *dt 
      )
      {
        NULL_RET_TRUE(dt) ;
        NULL_RET_TRUE((*dt)) ;
        X_ALLOC_Free( (void **) &((*dt)->eltos) ) ;
        X_ALLOC_Free( (void **) dt ) ;
        return TRUE ;
      }

      int            MPI_Type_dup         
      ( 
        IN    MPI_Datatype   dt,
        OUT   MPI_Datatype  *ndt 
      )
      {
        t_datatype   *dtAux ;

        (*ndt) = NULL ;
        if (dt == NULL)
            return (MPI_SUCCESS) ;
        dtAux = X_ALLOC_Malloc(c_DATATYPE) ;
        if (dtAux == NULL)
            return (MPI_ERR) ;
        dtAux->eltos  = X_ALLOC_MemDup ( dt->eltos,
                                         (dt->neltos) * c_DATATYPEELEMENT ) ;
        if ( 
             ((dt->eltos) != NULL)
                      &&
             ((dtAux->eltos) == NULL)
           )
           {
             return (MPI_ERR) ;
           }

        dtAux->neltos = dt->neltos ;
        dtAux->size   = dt->size ;
        (*ndt) = dtAux ;
        return (MPI_SUCCESS) ;
      }


      /**
       **  update  
       **/
      T_BOOL         L_DATATYPE_add         
      ( 
        IN    MPI_Datatype   dt,
        IN    T_INT          type_id,
        IN    void          *type_uid,
        IN    T_INT          type_offset,
        IN    T_INT          type_size 
      )
      {
        NULL_RET_FALSE(dt) ;

        /*
         *  update datatype  
         */
        dt->eltos = X_ALLOC_Realloc( dt->eltos,
                                     (dt->neltos + 1) * c_DATATYPEELEMENT ) ;
        NULL_RET_FALSE(dt->eltos) ;
        dt->neltos = dt->neltos + 1 ;
        dt->size   = MAX(dt->size, type_offset + type_size) ;

        /*
         *  update element  
         */
        ((dt->eltos)[dt->neltos]).type_id     = type_id ;
        ((dt->eltos)[dt->neltos]).type_userId = type_uid ;
        ((dt->eltos)[dt->neltos]).type_offset = type_offset ;

        return TRUE ;
      }

      T_LONG         L_DATATYPE_size        
      ( 
        IN    MPI_Datatype   dt 
      )
      {
        if (dt == NULL)
            return 0 ;
        return dt->size ;
      }


   /* ................................................................. */


