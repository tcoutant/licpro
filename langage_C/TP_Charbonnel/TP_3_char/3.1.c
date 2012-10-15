#include <stdio.h>

#define N 10
#define VRAI 1
#define FAUX 0

void tri(float t[])
{
	int i,permut ;
	float x ;

	do {
	  permut = FAUX ;
	  for (i=0 ; i<N-1 ; i++)
	    if (t[i]>t[i+1])
	    {
	      x = t[i] ;
	      t[i] = t[i+1] ;
	      t[i+1] = x ;
	      permut = VRAI ;
	    }
	} while (permut) ;
}
/* sous-programme test*/
int main()
{
	int i ;
	float tab[N] ;

	for (i=0 ; i<N ; i++) scanf("%f",&tab[i]) ;
	tri(tab) ;
	for (i=0 ; i<N ; i++) printf("%.0f ",tab[i]) ;
	printf("\n") ;

	return 0 ;
}

