

#ifndef L_DATATYPE_CHAR_H
#define L_DATATYPE_CHAR_H

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
      void   L_DATATYPE_CHAR_MAX      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_MIN      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_SUM      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_PROD     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_LAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_BAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_LOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_BOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_LXOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  functions  
       **/
      void   L_DATATYPE_CHAR_MAX      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_MIN      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_SUM      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_PROD     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_LAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_BAND     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_LOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_BOR      ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;
      void   L_DATATYPE_CHAR_LXOR     ( IN    T_LONG         count,
                                        OUT   void          *result,
                                        IN    void          *oper1,
                                        IN    void          *oper2 ) ;

      /**
       **  in threads  
       **/
      void  *L_DATATYPE_CHAR_tMAX     ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tMIN     ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tSUM     ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tPROD    ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tLAND    ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tBAND    ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tLOR     ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tBOR     ( INOUT void          *param ) ;
      void  *L_DATATYPE_CHAR_tLXOR    ( INOUT void          *param ) ;



   /* ... Inline / Macros ............................................. */

      #define  L_DATATYPE_CHAR_MAX(count,result,oper1,oper2)      \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       if (op1 > op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_MIN(count,result,oper1,oper2)      \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       if (op1 < op2)                             \
                                (*res) = op1 ;                    \
                           else (*res) = op2 ;                    \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_SUM(count,result,oper1,oper2)      \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 + op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_PROD(count,result,oper1,oper2)     \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 * op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_LAND(count,result,oper1,oper2)     \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 && op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_BAND(count,result,oper1,oper2)     \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 & op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_LOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 || op2 ;                      \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_BOR(count,result,oper1,oper2)      \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 | op2 ;                       \
                     }                                            \
               }

      #define  L_DATATYPE_CHAR_LXOR(count,result,oper1,oper2)     \
               {                                                  \
                 register T_CHAR  op1, op2 ;                      \
                 register T_CHAR *res ;                           \
                 register T_LONG i ;                              \
                                                                  \
                 for (i=0; i<count; i++)                          \
                     {                                            \
                       op1 =  (((T_CHAR *)oper1)[i]) ;            \
                       op2 =  (((T_CHAR *)oper2)[i]) ;            \
                       res = &(((T_CHAR *)result)[i]) ;           \
                       (*res) = op1 ^ op2 ;                       \
                     }                                            \
               }


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_CHAR_H */


