

 #ifndef X_STRING_H
 #define X_STRING_H

 #ifdef  __cplusplus
    extern "C" {
 #endif


   /* ... Include / Inclusion ........................................... */

      #include "base/l_basic/c_basic.h"
      #include "base/l_alloc/x_alloc.h"
      #include "base/l_file/x_file.h"
      #include "base/l_string/l_string.h"


   /* ... Functions / Funciones ......................................... */

      /*
       *  String Length
       * --------------- 
       */

      /**  
       *
       *  Return string length.
       *   (if ('str'==NULL) --> ret 0L) 
       *
       *     @params string
       *     @return string legth
       *
       */
       T_U_LONG  X_STRING_StrLen       
       ( 
         IN  T_CHAR  *str 
       ) ;

      /**  
       *
       *  Like 'X_STRING_StrLen' but also accept
       *   a string with format. 
       *
       *     @params string format
       *     @params format params
       *     @return string legth
       *
       */
      T_U_INT  X_STRING_StrLenF       
      ( 
        IN  T_CHAR   *format,
        IN  va_list   argl 
      ) ;


      /*
       *  Char's string functions
       * ------------------------- 
       */

      /**  
       *
       *  Return times 'ch' char is in 'str'. 
       *
       *     @params string
       *     @params caracter
       *     @return times ch in str
       *
       */
      T_U_LONG  X_STRING_StrChrNumber 
      ( 
        IN  T_CHAR  *str,
        IN  T_CHAR   ch 
      ) ;

      /**  
       *
       *  Change 'cho' char with 'chd' in 'str'. 
       *
       *     @params string
       *     @params caracter to del
       *     @params caracter to put
       *     @return string with changes
       *
       */
      T_CHAR   *X_STRING_StrChrCh     
      ( 
        INOUT  T_CHAR  *str,
        IN     T_CHAR   cho,
        IN     T_CHAR   chd 
      ) ;

      /**  
       *
       *  Return a pointer to first position where is 'ch' 
       *
       *     @params string
       *     @params caracter
       *     @return pointer to position
       *
       */
      T_CHAR   *X_STRING_StrChr       
      ( 
        IN     T_CHAR  *str,
	IN     T_CHAR   ch 
      ) ;

      /**  
       *
       *  Retorna un puntero a la primera posicion en str 
       *  con ocurrencia de ch 
       *
       *     @params string
       *     @params caracter
       *     @params case sensitive
       *     @return pointer to position
       *
       */
      T_CHAR   *X_STRING_CaseStrChr   
      ( 
        IN     T_CHAR  *str,
        IN     T_CHAR   ch,
        IN     T_BOOL   cs 
      ) ;

      /**  
       *
       *  Retorna el caracter que ocupa la ultima
       *  posicion en el string 'str' 
       *
       *     @params string
       *     @return pointer to position
       *
       */
      T_CHAR    X_STRING_LastChar     
      ( 
        IN     T_CHAR  *str 
      ) ;

      /**  
       *
       *  Retorna el caracter que ocupa la primera
       *  posicion en el string 'str' 
       *
       *     @params string
       *     @return pointer to position
       *
       */
      T_CHAR    X_STRING_FirstChar    
      ( 
        IN     T_CHAR  *str 
      ) ;

      /**  
       *
       *  Retorna el caracter que ocupa la posicion
       *  'index' en el string (0 .. strlen(str)-1) 
       *
       *
       *     @params string
       *     @return caracter at position
       *
       */
      T_CHAR    X_STRING_CharIn       
      ( 
        IN     T_CHAR  *str,
        IN     T_INT    index 
      ) ; 


     /*
      *  String compare
      * ---------------- 
      */

      /**  
       *
       *  Retorna si el string 'str' es 'model'. 
       *
       */
      T_BOOL    X_STRING_Equal        
      ( 
         IN  T_CHAR  *str1,
 	 IN  T_CHAR  *str2 
      ) ;

      /**  
       *
       *  Retorna si el string 'str' es 'model'. 
       *
       */
      T_BOOL    X_STRING_NEqual       
      ( 
        IN  T_CHAR  *str1,
        IN  T_CHAR  *str2,
        IN  T_INT    nchar 
      ) ;

      /**  
       *
       *  Retorna si el string 'str' es 'model'. 
       *
       */
      T_BOOL    X_STRING_CaseEqual    
      ( 
         IN  T_CHAR  *str ,
	 IN  T_CHAR  *model,
	 IN  T_BOOL   CSense 
      ) ;

      /**  
       *
       *  Retorna si el string 'str' es 'model'. 
       *
       */
      T_BOOL    X_STRING_CaseNEqual   
      ( 
         IN  T_CHAR  *str ,
	 IN  T_CHAR  *model,
	 IN  T_INT    nchar,
         IN  T_BOOL   CSense 
      ) ;

      /**  
       *
       *  Como 'strcmp' pero accepta parametros
       *  que valgan NULL. 
       *
       */
      T_INT     X_STRING_StrCmp       
      ( 
         IN  T_CHAR  *str1 ,
	 IN  T_CHAR  *str2 
      ) ;

      /**  
       *
       *  Como 'X_STRING_StrCmp' pero no importa  
       *  mayusculas/minusculas. 
       *
       */
      T_INT     X_STRING_CaseStrCmp   
      ( 
         IN  T_CHAR  *str1 ,
         IN  T_CHAR  *str2 ,
	 IN  T_BOOL   CSense 
      ) ;

      /**  
       *
       *  Retorna si el string 'model' modela a 'str'.
       *  En model SI vale wildcards como '*', '?'. 
       *  Segun 'CSense' la comparacion diferencia entre 
       *  mayusculas (TRUE) o no (FALSE) 
       *
       */
      T_BOOL    X_STRING_Match        
      ( 
        IN  T_CHAR  *str ,
        IN  T_CHAR  *model,
        IN  T_BOOL   CSense 
      ) ;


     /*
      *  String operations
      * ------------------- 
      */

      /**  
       *
       *  Convert string 'str' to upper case. 
       *
       *     @params string
       *     @return string with changes
       *
       */
      T_CHAR   *X_STRING_StrUpr       
      ( 
        IN  T_CHAR  *str 
      ) ;

      /**  
       *
       *  Convert string 'str' to lower case. 
       *
       *     @params string
       *     @return string with changes
       *
       */
      T_CHAR   *X_STRING_StrLwr       
      ( 
        IN  T_CHAR  *str 
      ) ;


     /*
      *  String MEMORY management functions
      * ------------------------------------ 
      */

      /**  
       *
       *  Alloc memory and uset it to concat 
       *  'str1'+'str2'+'str3'. 
       *
       */
      T_CHAR *X_STRING_ConcatInStr 
      ( 
         IN  T_CHAR  *str1,
         IN  T_CHAR  *str2,
	 IN  T_CHAR  *str3 
      ) ;

      /**  
       *
       *  Realloc memory used by (*strd), and uset it to 
       *  concat to (*strd) 'str1'. 
       *
       */
      T_BOOL  X_STRING_AddStrToStr 
      ( 
        INOUT  T_CHAR  **strd,
        IN     T_CHAR   *str1,
        ... 
      ) ;

      /**  
       *
       *  Pide memoria para concatenar a 'strd', 'str1'+'str2'
       *  Retorna TRUE si todo fue bien 
       *
       */
      T_BOOL  X_STRING_Add2StrToStr 
      ( 
        INOUT  T_CHAR  **strd,
        IN     T_CHAR   *str1,
        IN     T_CHAR   *str2 
      ) ;

      /**  
       *
       *  Retorna zona de memoria de memoria con una copia del
       *  string 'str'. Ret. NULL si hubo problemas 
       *
       */
      T_CHAR *X_STRING_StrDup   
      ( 
        IN  T_CHAR  *str 
      ) ;

      /**  
       *
       *  El espacio de memo asignado al string 'str', 
       *  sera su longitud util para quitar la memoria de 
       *  mas que no se utiliza.
       *  Siempre ret. TRUE 
       *
       */
      T_BOOL  X_STRING_StrAjust 
      ( 
        INOUT  T_CHAR  **str 
      ) ;

      /**  
       *
       *  Actual igual que vsprintf, pero pide memoria 
       *  dinamica para el string donde se imprime.
       *  Retorna NULL si no pudo.  
       *
       */
      T_CHAR *X_STRING_Dvsprintf 
      ( 
        IN  T_CHAR   *format,
        IN  va_list   argl 
      ) ;

      /**  
       *
       *  Igual que la anterior, solo varia los argumentos 
       *
       */
      T_CHAR *X_STRING_Dsprintf 
      ( 
        IN  T_CHAR   *format, ... 
      ) ;


   /* ... Inline / Macros ............................................... */

      #include "base/l_string/x_string.m"


   /* ................................................................... */


 #ifdef  __cplusplus
    }
 #endif

 #endif

