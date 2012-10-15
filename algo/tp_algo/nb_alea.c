# include <stdio.h>
# include <math.h>
# define MAX 3 
typedef int TAB[MAX];	/*declaration des constantes*/

TAB A,B,C;		/*declaration des variables */
int gagne; int coup;
		
/*creation de la table aleatoire B */

void main()
{
srandom(getpid());
B[0]=random()%9;
printf("la valeur aleatoire est: %d \n",B[0]);
do
{B[1]=random()%9;} 
while(B[1]==B[0]);
printf("la valeur aleatoire est: %d \n",B[1]);
do 
{B[2]=random()%9;}
while ((B[2]==B[1])||(B[2]==B[0]));
printf("la valeur aleatoire est: %d \n",B[2]);
}

/*

