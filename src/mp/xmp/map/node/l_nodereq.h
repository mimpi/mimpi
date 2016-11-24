

#ifndef L_NODEREQ_H
#define L_NODEREQ_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones .............................. */
 
      #include "base/l_basic/c_basic.h"
      #include "base/l_string/x_dtd.h"
      #include "base/l_thread/x_thread.h"
      #include "mp/xmp/base/l_sb.h"
      #include "mp/xmp/map/node_server/l_nsi.h"
 
 
   /* ... Types / Tipos ....................................... */
  
      typedef 
      struct nreq
      {
 
        /** 
         *  Request info
         */
        T_INT         requestId ;
        int           to ;
        int           from ;
        int           tagX ;
        int           tagY ;
        int           data_size ;
        char         *data_buff ;
        int           code ;
        int           ret_size ;
 
        /**
         *  Transmission info
         */
        int           ch ;
 
        /**
         *  Memory control info
         */
        T_BOOL        isMalloc ;
        T_BOOL        isServed ;
        T_LONG        nlinks ;
        struct nreq  *reqptr ;
 
        /**
         *  Access control info
         */
        t_mtsda       mtsda ;
 
      } t_nodeReq ;
 
 
   /* ... Const / Constantes .................................. */
  
      /**
       *  funtion
       */
      #define   REQ_SEND_X_SYNC           10
      #define   REQ_SEND_X_ASYNC          15
      #define   REQ_RECEIVE_X_SYNC        20
      #define   REQ_RECEIVE_X_ASYNC       25
      #define   REQ_RECEIVE_ANY_SYNC      30
      #define   REQ_RECEIVE_ANY_ASYNC     35
      #define   REQ_WAIT                  40
 
      /**
       *  special tags
       */
      #define   ANY_TAG            -100
      #define   ANY_NODE           -200
 
      /**
       *  data type size
       */
      #define c_NODEREQ             (sizeof(t_nodeReq))
 
 
   /* ... Functions / Funciones ............................... */
 
      /** 
       *
       *  Set with default values.
       *  It is supposed 'nodereq' is NOT dynamic memory
       *
       *     @params node request to init
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_NODEREQ_init
      ( 
        INOUT    t_nodeReq  *nodereq 
      ) ;
 
      /** 
       *
       *  Set with values passed as function params.
       *  It is supposed 'nodereq' is NOT dynamic memory
       *
       *     @params node request to init
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_NODEREQ_init_2
      (
        INOUT    t_nodeReq  *nodereq,
        IN       T_INT       reqid,
        IN       int         tx,
        IN       int         ty,
        IN       char       *data_buff,
        IN       int         data_size,
        IN       int         from,
        IN       int         to
      ) ;

      /** 
       *
       *  Set with default values a 'nodereq' that 
       *  is dynamic memory
       *
       *     @params nothing
       *     @return TRUE if allright.
       *
       */
      t_nodeReq  *L_NODEREQ_new
      ( 
        void
      ) ;
 
      /** 
       *
       *  Creat a 'bizarre' ( a duplicate using dinamic memory )
       *  From this bizarre, we can access to original.
       *
       *     @params node request to dup
       *     @return a dup request if allright 
       *             or null if problems.
       *
       */
      t_nodeReq  *L_NODEREQ_dup
      ( 
        INOUT    t_nodeReq  *nodereq 
      ) ;
 
      /** 
       *
       *  'nodrereq' information is respresented
       *  as string.
       *
       *     @params node request to inspect
       *     @return node information as string
       *
       */
      T_CHAR  *L_NODEREQ_nodereqToString   
      ( 
        IN       t_nodeReq  *nodereq 
      ) ;
 
      /** 
       *
       *  Incr. reference number.
       *
       *     @params node request to add one link
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_NODEREQ_addLink
      ( 
        INOUT    t_nodeReq  *nodereq 
      ) ;
 
      /** 
       *
       *  Decr. references number.
       *  When it reachs zero, if 'nodereq' is a dynamic
       *  memory, it will be freed.
       *
       *     @params node request to unlink
       *     @return TRUE if allright.
       *
       */
      T_BOOL      L_NODEREQ_subLink
      ( 
        INOUT    t_nodeReq  **nodereq
      ) ;
 
 
   /* ......................................................... */


 #ifdef  __cplusplus
    }
 #endif

#endif  /* L_NODEREQ_H */

