# include <stdio.h>
# include <math.h>

/*l'ordi choisit aleatoirement un nombre entre 1 et 1000, saisir une proposition et repondre "trop petit" ou "trop grand". La partie dure 10 essais.*/

int size,rep, coup,nb;

void main()  
{
coup=0;size=1000;
srandom(getpid());
nb=random()%size;
printf ("donner un nombre :  ");

while ((rep!=nb)&&(coup<10))
{
	scanf("%d",&rep);
	if
	(rep<nb)
	printf("   trop petit. \n" );
	else
	printf("   trop grand. \n");
	
	coup++;
	
}
if(coup==10)
printf("vous avez perdu, le nombre était %d \n",nb);
else
printf("vous avez gagné en %d coups. \n",coup);
}