
      #include <stdio.h>
      #include <stdlib.h>


      int log2 
      ( 
        int n
      )
      {      
        int ln2p, i ;

        ln2p = 1 ;
        for (i=0; i <= n; i++)
        {
	  /*deb*/printf("(ln2p=%d)",ln2p) ;

          if (ln2p >= n)
              return i ;
          ln2p = ln2p << 1 ;
        }

	return i ;
      }
 

      int main
      (
      )
      {
        int ln, n ;

        printf("intro number: ") ;
        scanf("%d",&n) ;
        while(n != -1)
	{
          ln = log2(n) ;
          printf(" --> log2(%d) = %d\n",n,ln) ;

          printf("intro number: ") ;
          scanf("%d",&n) ;
	}
      }

