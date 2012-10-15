#include <stdio.h>

int premier(int n)
{
	int i=2 ;

	while (n%i!=0 && i*i<=n) i++ ;
	return n==2 || n%i!=0 ;
}

/* sous-programme test */
int main()
{
	int i, n ;

	printf("entrez un entier >2 : ") ;
	scanf("%d",&n) ;
	for (i=2 ; i<=n ; i++)
	  if (premier(i)) printf("%d ",i) ;
	printf("\n") ;
 
	return 0 ;
}

