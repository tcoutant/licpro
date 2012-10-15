#include <stdio.h>

int main()
{
  int i=1 ;
  float s1=0,s2 ;

  do {
    s2 = s1 ;
    s1 += 1./(i*i) ;
    i++ ;
  } while (s1!=s2) ;
  printf("somme: %.12f, iteration: %d\n",s1,i) ;

  return 0 ;
}


