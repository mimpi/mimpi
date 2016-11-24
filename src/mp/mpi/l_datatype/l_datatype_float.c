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

      #include "mp/mpi/l_datatype/l_datatype_float.h"


   /* ... Functions / Funciones ....................................... */

      /*  thread  *
       * -------- */
      void *L_DATATYPE_FLOAT_tMAX ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_MAX(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tMIN ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_MIN(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tSUM ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

		ok = TRUE ;
        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_SUM(((t_op_param *)param)->count,
                           ((t_op_param *)param)->result,
                           ((t_op_param *)param)->oper1,
                           ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tPROD ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_PROD(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tLAND ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_LAND(((t_op_param *)param)->count,
                              ((t_op_param *)param)->result,
                              ((t_op_param *)param)->oper1,
                              ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tBAND ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_BAND(((t_op_param *)param)->count,
                              ((t_op_param *)param)->result,
                              ((t_op_param *)param)->oper1,
                              ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tLOR  ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_LOR (((t_op_param *)param)->count,
                              ((t_op_param *)param)->result,
                              ((t_op_param *)param)->oper1,
                              ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tBOR  ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_BOR (((t_op_param *)param)->count,
                              ((t_op_param *)param)->result,
                              ((t_op_param *)param)->oper1,
                              ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_FLOAT_tLXOR ( void *param )
      {
        T_BOOL        ok ;
        t_op_param    op_param ;

        /* ... copy params ... */
        X_THREAD_lock         ( &(((t_op_param *)param)->boot) ) ;
        X_ALLOC_MemMove(
                         &op_param,
                         (t_op_param *)param,
                         c_OP_PARAM
                       ) ;
        X_THREAD_signalReady  ( &(((t_op_param *)param)->boot) ) ;
        X_THREAD_unlock       ( &(((t_op_param *)param)->boot) ) ;

        /* ... do operation ... */
		ok = TRUE ;
        L_DATATYPE_FLOAT_LXOR(((t_op_param *)param)->count,
                              ((t_op_param *)param)->result,
                              ((t_op_param *)param)->oper1,
                              ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }



      /*  functions  *
       * ----------- */
      void   L_DATATYPE_FLOAT_fMAX    ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              if (op1 > op2)
                       (*res) = op1 ;
                  else (*res) = op2 ;
            }
      }

      void   L_DATATYPE_FLOAT_fMIN    ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              if (op1 < op2)
                       (*res) = op1 ;
                  else (*res) = op2 ;
            }
      }

      void   L_DATATYPE_FLOAT_fSUM    ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) (op1 + op2) ;
            }
      }

      void   L_DATATYPE_FLOAT_fPROD   ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) (op1 * op2) ;
            }
      }

      void   L_DATATYPE_FLOAT_fLAND   ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) (op1 && op2) ;
            }
      }

      void   L_DATATYPE_FLOAT_fBAND   ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) ((long)op1 & (long)op2) ;
            }
      }

      void   L_DATATYPE_FLOAT_fLOR    ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) (op1 || op2) ;
            }
      }

      void   L_DATATYPE_FLOAT_fBOR    ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) ((long)op1 | (long)op2) ;
            }
      }

      void   L_DATATYPE_FLOAT_fLXOR   ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_FLOAT  op1, op2 ;
        register T_FLOAT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_FLOAT *)oper1)[i]) ;
              op2 =  (((T_FLOAT *)oper2)[i]) ;
              res = &(((T_FLOAT *)result)[i]) ;
              (*res) = (T_FLOAT) ((long)op1 ^ (long)op2) ;
            }
      }


   /* ................................................................. */

