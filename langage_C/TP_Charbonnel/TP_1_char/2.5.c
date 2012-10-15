#include <stdio.h>

int fib(int n)
{
	return n==0 || n==1 ? 1 : fib(n-1)+fib(n-2) ;
}

int main()
{
	int f=1, i=1, n ;

	printf("entrez un entier : ") ;
	scanf("%d",&n) ;
	while (f<=n)
	{
	  printf("%d ",f) ;
	  f = fib(i) ;
	  i++ ;
	}
	printf("\n") ;
 
	return 0 ;
}

