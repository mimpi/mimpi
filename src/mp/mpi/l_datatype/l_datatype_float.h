

#ifndef L_DATATYPE_FLOAT_H
#define L_DATATYPE_FLOAT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype/l_datatype_op.h"


   /* ... Functions / Funciones ....................................... */

      /**
       **  macros  
       **/
      void   L_DATATYPE_FLOAT_MAX     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_MIN     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_SUM     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_PROD    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_LAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_BAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_LOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_BOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_LXOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  functions  
       **/
      void   L_DATATYPE_FLOAT_MAX     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_MIN     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_SUM     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_PROD    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_LAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_BAND    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_LOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_BOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_FLOAT_LXOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  in threads  
       **/
      void  *L_DATATYPE_FLOAT_tMAX    ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tMIN    ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tSUM    ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tPROD   ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tLAND   ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tBAND   ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tLOR    ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tBOR    ( INOUT void          *param ) ;
      void  *L_DATATYPE_FLOAT_tLXOR   ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_FLOAT_MAX(count,result,oper1,oper2)     \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;           \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;           \
                       res = &(((T_FLOAT *)result)[i]) ;          \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_FLOAT_MIN(count,result,oper1,oper2)     \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;           \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;           \
                       res = &(((T_FLOAT *)result)[i]) ;          \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_FLOAT_SUM(count,result,oper1,oper2)     \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;           \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;           \
                       res = &(((T_FLOAT *)result)[i]) ;          \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_FLOAT_PROD(count,result,oper1,oper2)    \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;           \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;           \
                       res = &(((T_FLOAT *)result)[i]) ;          \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_FLOAT_LAND(count,result,oper1,oper2)    \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                               \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;              \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;              \
                       res = &(((T_FLOAT *)result)[i]) ;             \
                       (*res) = (T_FLOAT) ((long)op1 && (long)op2) ; \
                     }                                               \
               }

      #define  L_DATATYPE_FLOAT_BAND(count,result,oper1,oper2)    \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                              \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;             \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;             \
                       res = &(((T_FLOAT *)result)[i]) ;            \
                       (*res) = (T_FLOAT) ((long)op1 & (long)op2) ; \
                     }                                              \
               }

      #define  L_DATATYPE_FLOAT_LOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                               \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;              \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;              \
                       res = &(((T_FLOAT *)result)[i]) ;             \
                       (*res) = (T_FLOAT) ((long)op1 || (long)op2) ; \
                     }                                               \
               }

      #define  L_DATATYPE_FLOAT_BOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                              \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;             \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;             \
                       res = &(((T_FLOAT *)result)[i]) ;            \
                       (*res) = (T_FLOAT) ((long)op1 | (long)op2) ; \
                     }                                              \
               }

      #define  L_DATATYPE_FLOAT_LXOR(count,result,oper1,oper2)    \
               {                                                  \
                 register T_FLOAT  op1, op2 ;                     \
                 register T_FLOAT *res ;                          \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                              \
                       op1 =  (((T_FLOAT *)oper1)[i]) ;             \
                       op2 =  (((T_FLOAT *)oper2)[i]) ;             \
                       res = &(((T_FLOAT *)result)[i]) ;            \
                       (*res) = (T_FLOAT) ((long)op1 ^ (long)op2) ; \
                     }                                              \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_FLOAT_H */


