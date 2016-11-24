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

      #include "mp/mpi/l_datatype/l_datatype_byte.h"


   /* ... Functions / Funciones ....................................... */

      /*  thread  *
       * -------- */
      void *L_DATATYPE_BYTE_tMAX ( void *param )
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
        L_DATATYPE_BYTE_MAX(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tMIN ( void *param )
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
        L_DATATYPE_BYTE_MIN(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tSUM ( void *param )
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
        L_DATATYPE_BYTE_SUM(((t_op_param *)param)->count,
                           ((t_op_param *)param)->result,
                           ((t_op_param *)param)->oper1,
                           ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tPROD ( void *param )
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
        L_DATATYPE_BYTE_PROD(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tLAND ( void *param )
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
        L_DATATYPE_BYTE_LAND(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tBAND ( void *param )
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
        L_DATATYPE_BYTE_BAND(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tLOR  ( void *param )
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
        L_DATATYPE_BYTE_LOR (((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tBOR  ( void *param )
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
        L_DATATYPE_BYTE_BOR (((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }

      void *L_DATATYPE_BYTE_tLXOR ( void *param )
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
        L_DATATYPE_BYTE_LXOR(((t_op_param *)param)->count,
                            ((t_op_param *)param)->result,
                            ((t_op_param *)param)->oper1,
                            ((t_op_param *)param)->oper2) ;

        /* ... the end ... */
        return (void *)(long)(ok) ;
      }



      /*  functions  *
       * ----------- */
      void   L_DATATYPE_BYTE_fMAX      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              if (op1 > op2)
                       (*res) = op1 ;
                  else (*res) = op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fMIN      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              if (op1 < op2)
                       (*res) = op1 ;
                  else (*res) = op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fSUM      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 + op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fPROD     ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 * op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fLAND     ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 && op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fBAND     ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 & op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fLOR      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 || op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fBOR      ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 | op2 ;
            }
      }

      void   L_DATATYPE_BYTE_fLXOR     ( IN    T_LONG         count,
                                         OUT   void          *result,
                                         IN    void          *oper1,
                                         IN    void          *oper2 )
      {
        register T_BYTE  op1, op2 ;
        register T_BYTE *res ;
        register T_LONG  i ;

        for (i=0; i<count; i++)
            {
              op1 =  (((T_BYTE *)oper1)[i]) ;
              op2 =  (((T_BYTE *)oper2)[i]) ;
              res = &(((T_BYTE *)result)[i]) ;
              (*res) = op1 ^ op2 ;
            }
      }


   /* ................................................................. */

