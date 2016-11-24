

#ifndef L_NSI_H
#define L_NSI_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


  /* ... Includes / Inclusiones ...............................*/

     #include "base/l_basic/c_basic.h"
     #include "base/l_string/x_string.h"
     #include "base/l_process/x_process.h"
     #include "mp/xmp/base/l_sb.h"


  /* ... Const / Constantes ...................................*/

     #define MAX_NODE_NAME        128

     #define NS_MATCH             1
     #define NS_CREAT             2
     #define NS_OPEN              3
     #define NS_UNLINK            4
     #define NS_DISC              5
     #define NS_FINALIZE          6
     #define NS_DUMP              7
     #define NS_TRACE_ON          8
     #define NS_TRACE_OFF         9
     #define NS_TRACE            10

     #define c_NODE2NSHEADER       (sizeof(struct node2nsHeader))
     #define c_NSHEADER            (sizeof(t_nsHeader))


  /* ... Type / Tipos .........................................*/

     struct node2nsHeader 
     {
        int    code ;
        char   name[MAX_NODE_NAME] ;
        struct sockaddr_in sa ;
        int    ret_code ;
        int    data_size ;
     } ;

     typedef
     union
     {
        struct node2nsHeader n2nH ;
        T_CHAR               b2nH [c_NODE2NSHEADER] ;
     } t_nsHeader ;


  /* ... Functions / Funciones ................................*/

     /**
      **  read/write
      ** ------------ 
      **/

      T_INT    L_NSI_read             
      ( 
        INOUT    t_sb        *sb,
        INOUT    int          nsfd,
        OUT      t_nsHeader  *msg 
      ) ;

      T_INT    L_NSI_readAvailable    
      ( 
        INOUT    t_sb        *sb,
        INOUT    int          nsfd,
        OUT      t_nsHeader  *msg 
      ) ;

      T_INT    L_NSI_write            
      ( 
        INOUT    t_sb        *sb,
        INOUT    int          nsfd,
        IN       t_nsHeader  *msg 
      ) ;


     /**
      **  write command
      ** --------------- 
      **/

      T_BOOL   L_NSI_writeInsert      
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        IN       char               *name,
        IN       struct sockaddr_in *sa,
        OUT      int                *code 
      ) ;

      T_BOOL   L_NSI_writeOpen        
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        IN       char               *name,
        OUT      struct sockaddr_in *sa,
        OUT      int                *code 
      ) ;

      T_BOOL   L_NSI_writeDisconnect  
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        OUT      int                *code 
      ) ;

      T_INT    L_NSI_writeDump        
      ( 
        INOUT    t_sb               *sb,
        INOUT    int                 nsfd,
        IN       int                 nodeid,
        IN       char               *format, 
        ... 
      ) ;

      T_INT    L_NSI_writeTrace       
      ( 
        INOUT    t_sb               *sb,
        IN       int                 nsfd,
        IN       int                 nodeid,
        IN       char               *str 
      ) ;


  /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NSI_H */

