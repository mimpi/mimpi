

#ifndef L_DATATYPE_BYTE_H
#define L_DATATYPE_BYTE_H

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
      void   L_DATATYPE_BYTE_MAX       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_MIN       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_SUM       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_PROD      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_LAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_BAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_LOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_BOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_LXOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  functions  
       **/
      void   L_DATATYPE_BYTE_MAX       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_MIN       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_SUM       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_PROD      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_LAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_BAND      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_LOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_BOR       ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_BYTE_LXOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  in threads  
       **/
      void  *L_DATATYPE_BYTE_tMAX      ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tMIN      ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tSUM      ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tPROD     ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tLAND     ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tBAND     ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tLOR      ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tBOR      ( INOUT void          *param ) ;
      void  *L_DATATYPE_BYTE_tLXOR     ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_BYTE_MAX(count,result,oper1,oper2)      \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_MIN(count,result,oper1,oper2)      \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_SUM(count,result,oper1,oper2)      \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_PROD(count,result,oper1,oper2)     \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_LAND(count,result,oper1,oper2)     \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 && op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_BAND(count,result,oper1,oper2)     \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 & op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_LOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 || op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_BOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 | op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_BYTE_LXOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_BYTE  op1, op2 ;                      \
                 register T_BYTE *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_BYTE *)oper1)[i]) ;            \
                       op2 =  (((T_BYTE *)oper2)[i]) ;            \
                       res = &(((T_BYTE *)result)[i]) ;           \
                       (*res) = op1 ^ op2 ;                       \
                     }                                            \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_BYTE_H */


