#include <stdio.h>

int main()
{
  int n, i=1, s=0 ;

  printf("entrer un entier >1 : ") ;
  scanf("%d",&n) ;

  while (s<n && i<n) 
  {
    if (n%i==0) s+=i ; 
    i++ ;
  }

  if (s==n) 
    printf("%d est parfait\n",n) ;
  else
    printf("%d n'est pas parfait\n",n) ;
  
  return 0 ;
}

