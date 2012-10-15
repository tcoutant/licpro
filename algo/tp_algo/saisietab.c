# include <stdio.h>
#define size 30
int tabmax, i,tab[size];
void main(){
printf(" Combien de valeurs voulez-vous saisir? \n");
scanf("%d",&tabmax);
for(i=0;i<tabmax;i++)////
{
printf("donner la %dème valeur du tableau : \t",i+1);
scanf("%d",&tab[i]);
}
}
