# include <stdio.h>
# define const 10 		//declaration des constantes//
int i, indice,temp, tab[10];	//declaration des variables//

/*saisir les valeurs d'un taleau et trier ces valeurs dans l'ordre croissant, puis afficher ce tableau.*/

void main()			//programme principal//
{

///saisie des valeurs du tableau//
for(i=0;i<10;i++)
{
printf("Donner la %deme valeur du tableau :\n",i+1);
scanf("%d",&tab[i]);
}
/// tri bulles du tableau
indice=0;
while(indice!=8)

{
	for(i=0;i<9-indice;i++)
	{
	if (tab[i]>tab[i+1])
		{
		temp=tab[i];
		tab[i]=tab[i+1];
		tab[i+1]=temp;
		}
	}
	indice++;
}
///ecriture du tableau
for(i=0;i<10;i++)
printf(" %d \t",tab[i]);
}

