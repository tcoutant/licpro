#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct function
{
  char *name ;
  double (*func)(double) ;
} ;

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

int main(int argc, char **argv)
{
  struct function tab[] = { { "cos", cos }
                            , { "sin", sin }
                            , { "tan", tan }
                            , { "e", exp }
                            , { "ln", log }
                            , { "v", sqrt }
                          } ;

  if (argc!=3)
  { 
    printf("usage: %s fonction num\n",argv[0]) ;
    return 1 ;
  }
  float x = conv(argv[2]) ;
  int i, nb = sizeof(tab)/sizeof(tab[0]) ;

  for (i=0 ; i<nb && strcmp(argv[1],tab[i].name) ; i++) ;
  if (i==nb) { printf("fonction %s inconnue !\n",argv[1]) ; return 3 ; }
  printf("%s(%s) = %f\n",argv[1],argv[2],tab[i].func(x)) ;

  return 0 ;  
}
