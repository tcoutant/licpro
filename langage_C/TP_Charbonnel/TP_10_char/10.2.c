#include <stdio.h>

int main(int nbarg, char *arg[])
{
  char **ptr = arg ;

  printf("%d argument(s)\n",nbarg) ;
  while (*ptr) { printf("arg[%d] = %s\n",ptr-arg,*ptr) ; ptr++ ; }

  return 0 ;
}
