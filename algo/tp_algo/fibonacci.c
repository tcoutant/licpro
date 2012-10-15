# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/
int nb;
/*prototype de la fonction fibonacci*/
int fibonacci(int);

/*definition de la fonction*/
int fibonacci(int n)
{
int som;
if ((n==1)||(n==2))
	return 1;
else
	return fibonacci(n-1)+fibonacci(n-2);

}

/*programme principal*/	
void main()
{
printf(" donner un nombre pour calculer cette ènième valeur dans la suite de fobonacci:  ");
scanf("%d",&nb);
printf("la %dème valeur dans la suite de fibonacci est : %d \t",nb,fibonacci(nb));
printf("\n");


/*commentaire*/


}
