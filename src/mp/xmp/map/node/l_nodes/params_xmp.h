

#ifndef PARAMS_XMP_H
#define PARAMS_XMP_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Includes / Inclusiones ...............................*/
 
      #include "base/l_basic/c_basic.h"
      #include "mp/xmp/map/node/l_nodes/l_params_xmp.h"
 
 
   /* ... Functions / Funciones ................................*/

      /**
       *
       *  Set default params values,
       *  getting values from enviroment.
       *
       *     @params 'argc' from main function.
       *     @params 'argv' from main function.
       *     @params 'envv' from main function.
       *     @return TRUE if allright.
       *
       */
      T_BOOL         PARAMS_XMP_put
      ( 
         IN     int             argc,
         IN     char          **argv,
         IN     char          **envv 
      ) ;

      /**
       *
       *  Return params values.
       *
       *     @params nothing
       *     @return table with params.
       *
       */
      t_params_xmp  *PARAMS_XMP_getParams 
      ( 
        void 
      ) ;


   /* ..........................................................*/


 #ifdef  __cplusplus
    }
 #endif

#endif /* PARAMS_XMP_H */

