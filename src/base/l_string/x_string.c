/* ........................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * ........................................................................ */
 
 
 
   /* ... Include / Inclusion ........................................... */
 
      #include "base/l_string/x_string.h"
 
 
   /* ... Funtions / Funciones .......................................... */
 
     /*  String Length  *
      * --------------- */
      T_U_INT  X_STRING_StrLenF       
      ( 
        IN  T_CHAR   *format,
        IN  va_list   argl 
      )
      {
              T_U_INT   ineed ;
       static FILE     *nullfd = NULL ;

       if (nullfd == NULL)
          {
            nullfd = fopen (NULL_DEVICE_PATH,"w") ;
            /*
             *   we will lost one file descriptor, 
             *   because we never "fclose(nullfd)", 
             *   but it improves perfomance (i hope).
             */
          }

       if (X_STRING_StrChr(format,'%') != NULL)
            {
              ineed = vfprintf(nullfd,format,argl) ;
            } 
       else /* only a string, not format */
            {
              ineed = strlen(format) ;
            }

       return ineed ;
     }


     /*  Char's string functions  *
      * ------------------------- */
      T_CHAR    X_STRING_LastChar     
      ( 
        IN     T_CHAR  *str 
      )
      {
        if (
             (str == NULL)
                  || 
             (X_STRING_StrLen(str) == 0)
           )
           {
             return '\0' ;
           }

        return (str)[X_STRING_StrLen(str)-1] ;
      }

      T_CHAR    X_STRING_FirstChar    
      ( 
        IN     T_CHAR  *str 
      )
      {
        if (
             (str == NULL)
                  || 
             (X_STRING_StrLen(str) == 0)
           )
           {
             return '\0' ;
           }

        return (str)[0] ;
      }

      T_CHAR    X_STRING_CharIn       
      ( 
        IN     T_CHAR  *str,
        IN     T_INT    index 
      )
      {
        if (
             (str == NULL)
                  || 
             ((T_INT)X_STRING_StrLen(str) >= (index))
           )
           {
             return '\0' ;
           }

        return (str)[index] ;
      }

      T_U_LONG X_STRING_StrChrNumber 
      ( 
        IN  T_CHAR  *str,
        IN  T_CHAR   ch 
      )
      {
        T_U_LONG n, i ;

        n=0 ;
        if (str!=NULL)
           {
             for (i=0; str[i]!='\0'; i++)
              {
                if (str[i]==ch) 
                       n++ ;
              }
           }

        return n ;
      }

      T_CHAR  *X_STRING_StrChrCh     
      ( 
        INOUT  T_CHAR  *str,
        IN     T_CHAR   cho,
        IN     T_CHAR   chd 
      )
      {
        if (str!=NULL)
           {
             T_U_LONG i ;

             for (i=0; str[i]!='\0'; i++)
              {
                if (str[i]==cho)  
                       str[i]=chd ;
              }
           }

        return str ;
      }

      T_CHAR  *X_STRING_CaseStrChr   
      ( 
        IN  T_CHAR  *str,
        IN  T_CHAR   ch,
        IN  T_BOOL   cs 
      )
      {
        T_CHAR *p1, *p2 ;

        p1 = X_STRING_StrChr(str,ch) ;
        p2 = X_STRING_StrChr(str,(T_CHAR)toupper(ch)) ;
        if (p1 == NULL)
            return p2 ;
        if (p2 == NULL)
            return p1 ;
        if (p1 < p2) 
            return p1 ;

        return p2 ;
      }


     /*  String compare  *
      * ---------------- */
      T_BOOL    X_STRING_Equal        
      ( 
        IN  T_CHAR  *str1,
        IN  T_CHAR  *str2 
      )
      {
        if ( (str1 == str2) )
              return TRUE ;
        if ( (str1 == NULL) || (str2 == NULL) )
              return FALSE ;
        if ( (strcmp(str1,str2) == 0) )
              return TRUE ;

        return FALSE ;
      }

      T_BOOL    X_STRING_NEqual       
      ( 
        IN  T_CHAR  *str1,
        IN  T_CHAR  *str2,
        IN  T_INT    nchar 
      )
      {
        if ( (str1 == str2) )
              return TRUE ;
        if ( (str1 == NULL) || (str2 == NULL) )
              return FALSE ;
        if ( (strncmp(str1,str2,nchar) == 0) )
              return TRUE ;

        return FALSE ;
      }

      T_BOOL    X_STRING_CaseNEqual   
      ( 
        IN  T_CHAR  *str ,
        IN  T_CHAR  *model,
        IN  T_INT    nchar,
        IN  T_BOOL   CSense 
      )
      {
        register int i ;

        if (CSense == TRUE)
           {
             for (i=0; i<nchar; i++)
             {
               if (str[i] != model[i])
                   return FALSE ;
             }
           }
        else /* (CSense == FALSE) */
           {
             for (i=0; i<nchar; i++)
             {
               if ( toupper(str[i]) != toupper(model[i]) )
                   return FALSE ;
             }
           }

        return TRUE ;
      }

      T_INT     X_STRING_CaseStrCmp   
      ( 
        IN  T_CHAR  *model,
        IN  T_CHAR  *str,
        IN  T_BOOL   CSense 
      )
      {
        register int i ;
        register int nchar ;

        nchar = MAX(X_STRING_StrLen(model),X_STRING_StrLen(str)) ;
        if (CSense == TRUE)
           {
             for (i=0; i<nchar; i++)
             {
               if (model[i] != str[i])
                   return (model[i] - str[i]) ;
             }
           }
        else /* (CSense == FALSE) */
           {
             for (i=0; i<nchar; i++)
             {
               if ( toupper(model[i]) !=  toupper(str[i]) )
                    return ( toupper(model[i]) !=  toupper(str[i]) ) ;
             }
           }

        return 0 ;
      }

      T_BOOL    X_STRING_CaseEqual    
      ( 
        IN  T_CHAR  *str ,
        IN  T_CHAR  *model,
        IN  T_BOOL   CSense 
      )
      {
        register int i ;
        register int nchar, mchar ;

        mchar = X_STRING_StrLen(str) ;
        nchar = X_STRING_StrLen(model) ;
        if (mchar != nchar)
           {
             return FALSE ;
           }
        if (CSense == TRUE)
           {
             for (i=0; i<nchar; i++)
             {
               if (str[i] != model[i])
                   return FALSE ;
             }
           }
        else /* (CSense == FALSE) */
           {
             for (i=0; i<nchar; i++)
             {
               if ( toupper(str[i]) != toupper(model[i]) )
                   return FALSE ;
             }
           }

        return TRUE ;
      }

      T_BOOL X_STRING_Match 
      ( 
        IN  T_CHAR  *str ,
        IN  T_CHAR  *model,
        IN  T_BOOL   CSense 
      )
      {
        T_U_INT   pp, pf ;
        T_U_INT   lp, lf, pnwc ;
        T_CHAR   *fuente, *patron ;
        T_CHAR   *pch1, *pch2, *pch3, *nwc ;
        T_BOOL    iguales ;

        /* ... simples cases ... */
        lf = X_STRING_StrLen(str) ;
        lp = X_STRING_StrLen(model) ;
        if ( (lp == 0) && (lf == 0) )
             return TRUE ;  /* 1.- EQUAL */

        if ( (lp == 0) && (lf != 0) )
             return FALSE ; /* 2.- FALSE , DIFERENT */

        if ( strcmp(model,str) == 0 )
             return TRUE ;  /* 3.- EQUAL */

        /* ... see casesense ... */
        fuente = X_STRING_StrDup(str) ;
        patron = X_STRING_StrDup(model) ;
        if (CSense==FALSE)
           {
             fuente = X_STRING_StrUpr ( fuente ) ;
             patron = X_STRING_StrUpr ( patron ) ;
           }

        /* ... compararemos INCLUYENDO el fin de string ('\0') ... */
        pp = 0 ;
        pf = 0 ;
        iguales = TRUE ;
        while ( (lp>=pp) && (iguales) )
        {
          switch (patron[pp])
          {
            case '?' :
                 pp++ ;
                 pf++ ;
                 break ;
            case '*' :
                 while (patron[pp] == '*')
                        pp++ ;
                 if (lp == pp)
                    {
                      X_ALLOC_Free((void **)&(fuente)) ;
                      X_ALLOC_Free((void **)&(patron)) ;
                      return TRUE ;
                    }

                 /* next segment */
                 nwc = patron + lp ;
                 pch1 = X_STRING_StrChr(patron+pp,'?') ;
                 if (pch1 != NULL)
                     nwc = MIN(nwc,pch1) ;
                 pch2 = X_STRING_StrChr(patron+pp,'*') ;
                 if (pch2 != NULL)
                     nwc = MIN(nwc,pch2) ;
                 pnwc = abs(nwc - (patron+pp)) ;

                 /* next source point */
                 do
                 {
                   pch3 = X_STRING_StrChr(fuente+pf,patron[pp]) ;
                   if (pch3 == NULL)
                      {
                        X_ALLOC_Free((void **)&(fuente)) ;
                        X_ALLOC_Free((void **)&(patron)) ;
                        return FALSE ;
                      }
                    pf = pch3 + 1 - fuente ;
                 } while ( 
                           strncmp(pch3,patron+pp,pnwc-1) != 0 
                         ) ;

                 /* update */
                 pp = pp     + pnwc ;
                 pf = pf - 1 + pnwc ;
                 break ;
            default : 
                 iguales = ( (patron[pp]) == (fuente[pf]) ) ;
                 pf++ ; 
                 pp++ ;
                 break ;
           }
        }
        X_ALLOC_Free((void **)&(fuente)) ;
        X_ALLOC_Free((void **)&(patron)) ;

        return iguales ;
      }


     /*  String operations  *
      * ------------------- */
      T_CHAR   *X_STRING_StrDup       
      ( 
        IN  T_CHAR  *str 
      )
      {
        T_U_INT  lenstr ;
        T_CHAR  *pch ;

        NULL_RET_NULL(str) ;
        lenstr = strlen(str) + 1 ;
        pch    = (T_CHAR *)X_ALLOC_MemDup(str,lenstr) ;

        return pch ;
      }

      T_CHAR *X_STRING_StrUpr 
      ( 
        IN  T_CHAR  *str 
      )
      {
        T_U_INT i ;

        if (str)
        {
          for(i=0; str[i]!='\0'; i++)
              str[i]=toupper(str[i]) ;
        }

        return str ;
      }

      T_CHAR *X_STRING_StrLwr 
      ( 
        IN  T_CHAR  *str 
      )
      {
        T_U_INT i ;

        if (str)
        {
          for(i=0; str[i]!='\0'; i++)
              str[i]=tolower(str[i]) ;
        }

        return str ;
      }


     /*  Memory Manager  *
      * ---------------- */
      T_BOOL   X_STRING_StrAjust      
      ( 
        INOUT  T_CHAR  **str 
      )
      {
        T_U_INT  lenstr ;

        lenstr = X_STRING_StrLen(*(str)) ;
        str = X_ALLOC_Realloc((void *)(str),lenstr) ;

        return TRUE ;
      }

      T_CHAR *X_STRING_ConcatInStr 
      ( 
        IN    T_CHAR *str1,
        IN    T_CHAR *str2,
        IN    T_CHAR *str3 
      )
      {
        T_CHAR *astr ;

        astr=X_ALLOC_Malloc(X_STRING_StrLen(str1)+
                            X_STRING_StrLen(str2)+
                            X_STRING_StrLen(str3)+1) ;
        NULL_RET_NULL(astr) ;

        astr[0] ='\0' ;
        strcat(astr,str1) ;
        strcat(astr,str2) ;
        strcat(astr,str3) ;

        return astr ;
      }

      T_BOOL  X_STRING_AddStrToStr  
      ( 
        INOUT  T_CHAR  **strd,
        IN     T_CHAR   *format,
        ... 
      )
      {
        T_CHAR   *baux ;
        T_U_INT   ineed1, ineed2 ;
        va_list   varg ;
  
        va_start(varg,format) ;
        /* ... how i need ? ... */
        ineed1 = X_STRING_StrLen((*strd)) ;
        ineed2 = X_STRING_StrLenF(format,varg) ;

        /* ... hand on ? ... */
        baux = X_ALLOC_Realloc((*strd),ineed1+ineed2+1) ;
        NULL_RET_FALSE(baux) ;
        vsprintf((char *)(baux+ineed1),format,varg) ;
        (*strd) = baux ;
        va_end(varg) ;

        return TRUE ;
      }

      T_BOOL  X_STRING_Add2StrToStr 
      ( 
        INOUT T_CHAR **strd,
        IN    T_CHAR *str1,
        IN    T_CHAR *str2 
      )
      {
        T_CHAR *astr ;

        astr=X_ALLOC_Realloc((*strd),X_STRING_StrLen(*strd)+
                                     X_STRING_StrLen(str1)+
                                     X_STRING_StrLen(str2)+1) ;
        NULL_RET_FALSE(astr) ;

        if ((*strd) == NULL)
             astr[0] = '\0' ;
        strcat(astr,str1) ;
        strcat(astr,str2) ;
        (*strd)=astr ;

        return TRUE ;
      }

      T_CHAR *X_STRING_Dvsprintf 
      ( 
        IN  T_CHAR   *format,
        IN  va_list   argl 
      )
      {
        T_CHAR   *baux ;
        T_U_INT   ineed ;

        ineed = X_STRING_StrLenF(format,argl) ;
        baux  = X_ALLOC_Malloc(ineed+1) ;
        NULL_RET_NULL(baux) ;
        vsprintf(baux,format,argl) ;

        return baux ;
      }

      T_CHAR *X_STRING_Dsprintf 
      ( 
        IN  T_CHAR   *format, 
        ... 
      )
      {
        T_CHAR *saux ;
        va_list varg ;

        va_start(varg,format) ;
        saux = X_STRING_Dvsprintf(format,varg) ;
        va_end(varg) ;

        return saux ;
      }
 
 
   /* ................................................................... */
 
 
