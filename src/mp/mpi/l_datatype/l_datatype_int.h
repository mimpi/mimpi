

#ifndef L_DATATYPE_INT_H
#define L_DATATYPE_INT_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "mp/mpi/l_datatype/l_datatype_op.h"


   /* ... Functions / Funciones ....................................... */

      /* ... macros ... */
      void   L_DATATYPE_INT_MAX       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_MIN       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_SUM       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_PROD      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_LAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_BAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_LOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_BOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_LXOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /* ... functions ... */
      void   L_DATATYPE_INT_MAX       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_MIN       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_SUM       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_PROD      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_LAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_BAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_LOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_BOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_INT_LXOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /* ... in threads ... */
      void  *L_DATATYPE_INT_tMAX      ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tMIN      ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tSUM      ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tPROD     ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tLAND     ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tBAND     ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tLOR      ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tBOR      ( INOUT void          *param ) ;
      void  *L_DATATYPE_INT_tLXOR     ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_INT_MAX(count,result,oper1,oper2)       \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_INT_MIN(count,result,oper1,oper2)       \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_INT_SUM(count,result,oper1,oper2)       \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_INT_PROD(count,result,oper1,oper2)      \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_INT_LAND(count,result,oper1,oper2)      \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 && op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_INT_BAND(count,result,oper1,oper2)      \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 & op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_INT_LOR(count,result,oper1,oper2)       \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 || op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_INT_BOR(count,result,oper1,oper2)       \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 | op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_INT_LXOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_INT  op1, op2 ;                       \
                 register T_INT *res ;                            \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_INT *)oper1)[i]) ;             \
                       op2 =  (((T_INT *)oper2)[i]) ;             \
                       res = &(((T_INT *)result)[i]) ;            \
                       (*res) = op1 ^ op2 ;                       \
                     }                                            \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_INT_H */


