// triangle de Pascal

#include <stdio.h>

#define N 12

int main()
{
  int i, j, tab[N][N] ;

  for (i=0 ; i<N ; i++) tab[i][0]=tab[i][i]=1 ;

  for (i=1 ; i<N ; i++)
    for (j=1 ; j<i ; j++)
      tab[i][j] = tab[i-1][j-1]+tab[i-1][j] ;

  for (i=0 ; i<N ; i++)
  {
    for (j=0 ; j<=i ; j++)
      printf("%4d ",tab[i][j]) ;
    printf("\n") ;
  }

  return 0 ;
}
  
