#include <stdio.h>
#include <stdlib.h>

float conv(char *s)
{
  char *end ;
  float x = strtod(s,&end) ;
  if (end==s)
  {
    printf("argument '%s' incorrect\n",s) ;
    exit(2) ;
  }
  return x ;
}

void errop()
{
  printf("erreur: argument 2 doit être +, - ou x\n") ;
  exit(3) ;
}

int main(int nbarg, char **arg)
{
  if (nbarg!=4)
  { 
    printf("usage: %s num op num\n",arg[0]) ;
    return 1 ;
  }

  float a = conv(arg[1]) ;
  float b = conv(arg[3]) ;
  float r ;
  if (arg[2][1]) errop() ;

  switch(arg[2][0])
  {
    case '+' : r=a+b ; break ;
    case '-' : r=a-b ; break ;
    case 'x' : r=a*b ; break ;
    default : errop() ;
  }
  printf("%s %c %s = %f\n",arg[1],arg[2][0],arg[3],r) ;

  return 0 ;
}
