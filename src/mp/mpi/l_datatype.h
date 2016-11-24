

#ifndef L_DATATYPE_H
#define L_DATATYPE_H

 #ifdef  __cplusplus
    extern "C" {
 #endif
 

  /* ... Includes / Inclusiones ....................................... */

     #include "mp/mpi/c_base.h"
     #include "base/l_alloc/x_alloc.h"
     #include "mp/mpi/l_datatype/l_datatype_byte.h"
     #include "mp/mpi/l_datatype/l_datatype_char.h"
     #include "mp/mpi/l_datatype/l_datatype_short.h"
     #include "mp/mpi/l_datatype/l_datatype_int.h"
     #include "mp/mpi/l_datatype/l_datatype_long.h"
     #include "mp/mpi/l_datatype/l_datatype_float.h"
     #include "mp/mpi/l_datatype/l_datatype_double.h"


   /* ... Types / Tipos ............................................... */

      typedef 
      struct 
      {
        int     type_id ;
        void   *type_userId ;
        long    type_offset ;
      } t_datatypeElement ;

      typedef 
      struct
      {
        t_datatypeElement   *eltos ;
        long                 neltos ;
        long                 size ;
      } t_datatype ;

      typedef 
      t_datatype  *MPI_Datatype ;


   /* ... Const. / Constantes ......................................... */

      #define   c_MPI_DATATYPE     (sizeof(MPI_Datatype))

      #define   MPI_CHAR       L_DATATYPE_MPI_CHAR
      #define   MPI_BYTE       L_DATATYPE_MPI_BYTE
      #define   MPI_SHORT      L_DATATYPE_MPI_SHORT
      #define   MPI_INT        L_DATATYPE_MPI_INT
      #define   MPI_LONG       L_DATATYPE_MPI_LONG
      #define   MPI_FLOAT      L_DATATYPE_MPI_FLOAT
      #define   MPI_DOUBLE     L_DATATYPE_MPI_DOUBLE


   /* ... Operations / Operaciones .................................... */

      void   L_DATATYPE_MAX         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_MIN         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_SUM         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_PROD        
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_LAND        
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_BAND        
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_LOR         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_BOR         
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;

      void   L_DATATYPE_LXOR        
      ( 
        IN    MPI_Datatype   dt,
        IN    int            count,
        OUT   void          *result,
        IN    void          *oper1,
        IN    void          *oper2
      ) ;


   /* ... Const. / Constantes ......................................... */

      #define   c_DATATYPE         (sizeof(t_datatype))
      #define   c_DATATYPEELEMENT  (sizeof(t_datatypeElement))

      #define   id_unknow      0
      #define   id_userType    1
      #define   id_char        2
      #define   id_byte        3
      #define   id_short       4
      #define   id_int         5
      #define   id_long        6
      #define   id_float       7
      #define   id_double      8

      extern t_datatype    L_DATATYPE_MPI_CHAR[] ;
      extern t_datatype    L_DATATYPE_MPI_BYTE[] ;
      extern t_datatype    L_DATATYPE_MPI_SHORT[] ;
      extern t_datatype    L_DATATYPE_MPI_INT[] ;
      extern t_datatype    L_DATATYPE_MPI_LONG[] ;
      extern t_datatype    L_DATATYPE_MPI_FLOAT[] ;
      extern t_datatype    L_DATATYPE_MPI_DOUBLE[] ;


   /* ... Building / Construccion ..................................... */

      /*
       *  init/finalize  
       */
      MPI_Datatype   L_DATATYPE_creat       
      ( 
        void 
      ) ;

      T_BOOL         L_DATATYPE_destroy     
      ( 
        IN    MPI_Datatype  *dt 
      ) ;

      int            MPI_Type_dup         
      ( 
        IN    MPI_Datatype   dt,
        OUT   MPI_Datatype  *ndt 
      ) ;

      /*
       *  update  
       */
      T_LONG         L_DATATYPE_size        
      ( 
        IN    MPI_Datatype   dt 
      ) ;

      T_BOOL         L_DATATYPE_add         
      ( 
        IN    MPI_Datatype   dt,
        IN    T_INT          type_id,
        IN    void          *type_uid,
        IN    T_INT          type_offset,
        IN    T_INT          type_size 
      ) ;


   /* ................................................................. */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_DATATYPE_H */


