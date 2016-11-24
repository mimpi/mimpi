

#ifndef L_DATATYPE_LONG_H
#define L_DATATYPE_LONG_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype/l_datatype_op.h"


   /* ... Functions / Funciones ....................................... */

      /* ... macros ... */
      void   L_DATATYPE_LONG_MAX      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_MIN      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_SUM      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_PROD     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_LAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_BAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_LOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_BOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_LXOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /* ... functions ... */
      void   L_DATATYPE_LONG_MAX      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_MIN      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_SUM      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_PROD     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_LAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_BAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_LOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_BOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_LONG_LXOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /* ... in threads ... */
      void  *L_DATATYPE_LONG_tMAX     ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tMIN     ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tSUM     ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tPROD    ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tLAND    ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tBAND    ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tLOR     ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tBOR     ( INOUT void          *param ) ;
      void  *L_DATATYPE_LONG_tLXOR    ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_LONG_MAX(count,result,oper1,oper2)      \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_MIN(count,result,oper1,oper2)      \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_SUM(count,result,oper1,oper2)      \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_PROD(count,result,oper1,oper2)     \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_LAND(count,result,oper1,oper2)     \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 && op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_BAND(count,result,oper1,oper2)     \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 & op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_LOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 || op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_BOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 | op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_LONG_LXOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_LONG  op1, op2 ;                      \
                 register T_LONG *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_LONG *)oper1)[i]) ;            \
                       op2 =  (((T_LONG *)oper2)[i]) ;            \
                       res = &(((T_LONG *)result)[i]) ;           \
                       (*res) = op1 ^ op2 ;                       \
                     }                                            \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_LONG_H */


