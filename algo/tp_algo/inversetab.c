# include <stdio.h>
#define size 6

/* saisir les valeurs d'un tableau à 1 dimension puis inverser le tableau avant d'afficher ses valeurs*/

int temp,i, tab[size];
void main() {
for(i=0;i<size;i++)
{
printf ("donner un nombre :\n");
scanf ("%d", &tab[i]);
}
temp=tab[6];	
for(i=0;i<=(size-1)/2;i++)
{
temp=tab[i];	
tab[i]=tab[size-1-i];
tab[size-1-i]=temp;
}

for(i=0;i<size;i++)
{
printf ("%d \t",tab[i]);	
}
printf ("\n");
}
