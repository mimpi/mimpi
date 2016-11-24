

#ifndef L_DATATYPE_DOUBLE_H
#define L_DATATYPE_DOUBLE_H

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
      void   L_DATATYPE_DOUBLE_MAX    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_MIN    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_SUM    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_PROD   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_LAND   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_BAND   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_LOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_BOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_LXOR   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  functions  
       **/
      void   L_DATATYPE_DOUBLE_MAX    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_MIN    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_SUM    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_PROD   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_LAND   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_BAND   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_LOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_BOR    ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_DOUBLE_LXOR   ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  in threads  
       **/
      void  *L_DATATYPE_DOUBLE_tMAX   ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tMIN   ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tSUM   ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tPROD  ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tLAND  ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tBAND  ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tLOR   ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tBOR   ( INOUT void          *param ) ;
      void  *L_DATATYPE_DOUBLE_tLXOR  ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_DOUBLE_MAX(count,result,oper1,oper2)    \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_MIN(count,result,oper1,oper2)    \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_SUM(count,result,oper1,oper2)    \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_PROD(count,result,oper1,oper2)   \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_LAND(count,result,oper1,oper2)   \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = op1 && op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_BAND(count,result,oper1,oper2)   \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = (long)op1 & (long)op2 ;           \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_LOR(count,result,oper1,oper2)    \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = op1 || op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_BOR(count,result,oper1,oper2)    \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = (long)op1 | (long)op2 ;           \
                     }                                            \
               }

      #define  L_DATATYPE_DOUBLE_LXOR(count,result,oper1,oper2)   \
               {                                                  \
                 register T_DOUBLE  op1, op2 ;                    \
                 register T_DOUBLE *res ;                         \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_DOUBLE *)oper1)[i]) ;          \
                       op2 =  (((T_DOUBLE *)oper2)[i]) ;          \
                       res = &(((T_DOUBLE *)result)[i]) ;         \
                       (*res) = (long)op1 ^ (long)op2 ;           \
                     }                                            \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_DOUBLE_H */


