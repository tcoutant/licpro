#include <stdio.h>

int c(int n,int p)
{
  return n==p || p==0 ? 1 : c(n-1,p)+c(n-1,p-1) ;
}

int main()
{
  int i,j,n ;

  printf("entrer un entier: ") ;
  scanf("%d",&n) ;
  for (i=0 ; i<n ; i++)
  {
    for (j=0 ; j<=i ; j++) printf("%5d",c(i,j)) ;
    printf("\n") ;
  }
    
  return 0 ;
}

