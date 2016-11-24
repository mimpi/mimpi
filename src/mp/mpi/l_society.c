/* ....................................................................
 *
 * Copyright Alejandro Calderon (1997-2000)
 * <fgarcia,acaldero@laurel.datsi.fi.upm.es>
 * See documentation for more information.
 *
 * permission is hereby granted to copy, modify and redistribute this code
 * in terms of the GNU Library General Public License, Version 2 or later,
 * at your option.
 *
 * .................................................................... */



   /* ... Includes / Inclusiones ...................................... */

      #include "mp/mpi/l_society.h"


   /* ... Glob. var / Var. globales ................................... */

      long         L_SOCIETY_last_society ;
      t_societies  L_SOCIETY_societies ;


   /* ... Functions / Funciones ....................................... */

      T_BOOL         L_SOCIETY_empty           
      ( 
        IN    t_society   s 
      )
      {
        long  k ;

        L_SOCIETY_setNMembers(s,0L) ;
        for(k=0; k< MAX_SOCKS; k++)
           {
             L_SOCIETY_setMemberInfo(s,k,-1) ;
           }

        return TRUE ;
      }

      t_member       L_SOCIETY_getMember       
      ( 
        IN    t_society    s,
        IN    t_memberInfo myNID 
      )
      {
        int j ;
        t_member myRANK ;

        myRANK = -1 ;
        for (j=0; j < MAX_SOCKS; j++)
            {
              if ((L_SOCIETY_societies[s]).members[j] == myNID)
                 {
                   myRANK = j ;
                 }
            }

        return myRANK ; 
      }


   /* ................................................................. */

