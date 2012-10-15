/* Cribble d'Erathostene */

#include <stdio.h>

#define N 100

int main()
{
  int tab[N], i, j ;

  for (i=2 ; i<N ; i++) tab[i]=i ;

  for (i=2 ; i<N ; i++)
    if (tab[i]!=0)
      for (j=2*i ; j<N ; j+=i) tab[j]=0 ;

  for (i=2 ; i<N ; i++)
   if (tab[i]!=0) printf("%d ",tab[i]) ;

  return 0 ;
}

