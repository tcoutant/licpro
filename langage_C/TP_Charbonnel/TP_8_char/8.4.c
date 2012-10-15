#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 31
const char dico[] = "/usr/share/dict/words" ;

struct maillon ;
struct maillon { char *mot ; struct maillon *suiv ; } ;

struct maillon *charger() ;
void trier(struct maillon *tete) ;
void lister(struct maillon *tete) ;
void liberer(struct maillon *tete) ;

int main()
{
  struct maillon *tete ;
  
  tete = charger() ;
  trier(tete) ;
  lister(tete) ;
  liberer(tete) ;
  
  return 0 ;
}

struct maillon *charger()
{
  FILE *f ;
  struct maillon *nouv, *cour=NULL ;
  char s[L] ;
  
  f = fopen(dico,"r") ;
  if (f==NULL) { perror("in function charger") ; exit(1) ; }
  
  while (fgets(s,L-1,f)!=NULL) 
  { 
    nouv = malloc(sizeof(struct maillon)) ;
    if (nouv==NULL) { perror("in function charger") ; exit(3) ; }
    nouv->mot = malloc((strlen(s)+1)*sizeof(char)) ;
    if (nouv->mot==NULL) { perror("in function charger") ; exit(2) ; }
    strcpy(nouv->mot,s) ;
    nouv->suiv = cour ;
    cour = nouv ;
  }
  return cour ;
}

void trier(struct maillon *tete)
{
}

void lister(struct maillon *tete)
{
  struct maillon *cour = tete ;
  
  while (cour!=NULL)
  {
    printf("%s",cour->mot) ;
    cour = cour->suiv ;
  }
}

void liberer(struct maillon *tete)
{
  struct maillon *tmp,*cour = tete ;

  while (cour!=NULL)
  {
    free(cour->mot) ;
    tmp = cour ;
    cour = cour->suiv ;
    free(tmp) ;
  }
}

