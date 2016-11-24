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

      #include "mp/mpi/l_datatype/l_datatype_int.h"


   /* ... Functions / Funciones ....................................... */

      /*  thread  *
       * -------- */
      void *L_DATATYPE_INT_tMAX ( void *param )
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
        L_DATATYPE_INT_MAX(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tMIN ( void *param )
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
        L_DATATYPE_INT_MIN(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tSUM ( void *param )
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
        L_DATATYPE_INT_SUM(((t_op_param *)param)->count,
                           ((t_op_param *)param)->result,
                           ((t_op_param *)param)->oper1,
                           ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tPROD ( void *param )
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
        L_DATATYPE_INT_PROD(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tLAND ( void *param )
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
        L_DATATYPE_INT_LAND(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tBAND ( void *param )
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
        L_DATATYPE_INT_BAND(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tLOR  ( void *param )
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
        L_DATATYPE_INT_LOR (((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tBOR  ( void *param )
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
        L_DATATYPE_INT_BOR (((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_INT_tLXOR ( void *param )
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
        L_DATATYPE_INT_LXOR(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }



      /*  functions  *
       * ----------- */
      void   L_DATATYPE_INT_fMAX       ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              if (op1 > op2)
                       (*res) = op1 ;
                  else (*res) = op2 ;
            }
      }

      void   L_DATATYPE_INT_fMIN       ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              if (op1 < op2)
                       (*res) = op1 ;
                  else (*res) = op2 ;
            }
      }

      void   L_DATATYPE_INT_fSUM       ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 + op2 ;
            }
      }

      void   L_DATATYPE_INT_fPROD      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 * op2 ;
            }
      }

      void   L_DATATYPE_INT_fLAND      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 && op2 ;
            }
      }

      void   L_DATATYPE_INT_fBAND      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 & op2 ;
            }
      }

      void   L_DATATYPE_INT_fLOR       ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 || op2 ;
            }
      }

      void   L_DATATYPE_INT_fBOR       ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 | op2 ;
            }
      }

      void   L_DATATYPE_INT_fLXOR      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_INT  op1, op2 ;
        register T_INT *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_INT *)oper1)[i]) ;
              op2 =  (((T_INT *)oper2)[i]) ;
              res = &(((T_INT *)result)[i]) ;
              (*res) = op1 ^ op2 ;
            }
      }


   /* ................................................................. */

