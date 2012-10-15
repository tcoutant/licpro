#include <stdio.h>

void swap(int *a, int *b)
{
  int c ;

  c = *a ;
  *a = *b ;
  *b = c ;
}

int main()
{
  int x=2, y=3 ;

  swap(&x,&y) ;
  printf("x=%d, y=%d\n",x,y) ;

  return 0 ;
}
