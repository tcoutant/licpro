# include <stdio.h>

/* saisir les valeurs d'un tableau à 2 dimensons puis afficher ce tableau*/

# define nbc 5
# define nbl 3
int i, j, tab[nbl][nbc];
void main()
{
for(i=0;i<nbl;i++)
{
	for(j=0;j<nbc;j++)
	{
	printf("sur la %dème ligne, case %d donner la valeur:\n",i+1,j+1);
	scanf("%d",&tab[i][j]);
	}
}
/// affichage
printf("voici le tableau saisi :\n");
for(i=0;i<nbl;i++)
{
	for(j=0;j<nbc;j++)
	{
	printf("%d \t",tab[i][j]);
	}
	printf("\n");
}
}
