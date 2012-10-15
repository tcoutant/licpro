#include <stdio.h>
#include <math.h>

int racines(float s,float p,float *a,float *b)
{
  float delta = s*s - 4*p ;

  if (delta<0) return 0 ;

  *a = (s - sqrt(delta))/2 ;
  *b = (s + sqrt(delta))/2 ;

  return 1 ;
}

int main()
{
  float a,b,som,prod ;

  printf("entrer la somme : ") ; scanf("%f",&som) ;
  printf("entrer le produit : ") ; scanf("%f",&prod) ;
  if (racines(som,prod,&a,&b))
    printf("les 2 nombres sont %f et %f\n",a,b) ;
  else
    printf("il n'y a pas de solutions\n") ;

  return 0 ;
}
