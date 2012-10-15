#include <stdio.h>
#include <stdlib.h>

const int N = 100 ;
typedef short T ;

int compare(const void *a, const void *b)
{
  return *(T *)a - *(T *)b ;
}

int main()
{
  T t[N] ;
  int i ;

  qsort(t,N,sizeof(T),compare) ;

  for (i=0 ; i<N ; i++) printf("%d ",t[i]) ;

  return 0 ;
}
