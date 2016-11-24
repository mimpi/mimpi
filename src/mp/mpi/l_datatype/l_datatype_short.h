

#ifndef L_DATATYPE_SHORT_H
#define L_DATATYPE_SHORT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype/l_datatype_op.h"


   /* ... Functions / Funciones ....................................... */

      /* ... macros ... */
      void   L_DATATYPE_SHORT_MAX     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_MIN     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_SUM     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_PROD    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_LAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_BAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_LOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_BOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_LXOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /* ... functions ... */
      void   L_DATATYPE_SHORT_MAX     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_MIN     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_SUM     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_PROD    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_LAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_BAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_LOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_BOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_SHORT_LXOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /* ... in threads ... */
      void  *L_DATATYPE_SHORT_tMAX      ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tMIN      ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tSUM      ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tPROD     ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tLAND     ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tBAND     ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tLOR      ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tBOR      ( INOUT void          *param ) ;
      void  *L_DATATYPE_SHORT_tLXOR     ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_SHORT_MAX(count,result,oper1,oper2)     \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_MIN(count,result,oper1,oper2)     \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_SUM(count,result,oper1,oper2)     \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_PROD(count,result,oper1,oper2)    \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_LAND(count,result,oper1,oper2)    \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 && op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_BAND(count,result,oper1,oper2)    \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 & op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_LOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 || op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_BOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 | op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_SHORT_LXOR(count,result,oper1,oper2)    \
               {                                                  \
                 register T_SHORT  op1, op2 ;                     \
                 register T_SHORT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_SHORT *)oper1)[i]) ;           \
                       op2 =  (((T_SHORT *)oper2)[i]) ;           \
                       res = &(((T_SHORT *)result)[i]) ;          \
                       (*res) = op1 ^ op2 ;                       \
                     }                                            \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_SHORT_H */


