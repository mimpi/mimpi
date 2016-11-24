

 #ifndef C_STATUS_H
 #define C_STATUS_H


  /* ... Types / Tipos ........................................ */

     #define T_STATUS       int


  /* ... Consts / Constantes .................................. */

     /*
      *  datatype size
      */
     #define c_STATUS       sizeof(int)

     /*
      *  basic values
      */
     #define STATUS_ERROR      -1
     #define STATUS_OK          0
     #define STATUS_WARNING    +1

     /**
      **  each library define its own 'STATUS_ERROR' and
      **  'STATUS_WARNING'. As example :
      **   
      **  x_file.h :
      **   
      **  ... 
      **     #define STATUS_ERROR_INVALID_PARAM    -2
      **     #define STATUS_ERROR_DEVICE_NOT_READY -3
      **  ... 
      **     #define STATUS_WARNING_TOO_MANY_OPEN_FILES   2
      **  ... 
      **   
      **/

  /* .......................................................... */


#endif

