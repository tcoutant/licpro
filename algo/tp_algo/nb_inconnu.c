# include <stdio.h>
# include <math.h>

/*l'ordi choisit aleatoirement un nombre entre 1 et 1000, saisir une proposition et repondre "trop petit" ou "trop grand". La partie dure 10 essais.*/

int size,rep, coup,nb;

void main()  
{
coup=1;size=3;
srandom(getpid());
nb=(random()%size)+1;
printf ("donner un nombre :  ");
scanf("%d",&rep);
while ((rep!=nb)&&(coup<10))
{
	if
	(rep<nb)
	printf("   trop petit. \n" );
	else
	printf("   trop grand. \n");
	
	coup++;
	scanf("%d",&rep);
}
if(coup==10)
printf("vous avez perdu, le nombre était %d \n",nb);
else
printf("vous avez gagné en %d coups. \n",coup);
}
