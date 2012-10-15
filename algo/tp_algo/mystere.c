# include <stdio.h>
# include <string.h>
	
int n, nb;	/*declaration des variables*/

/*fonction qui calcule le carre d'un nombre +1 */
int mystere(int n)
{
if (n==0)
return 1;
else
return mystere(n-1) +2*(n-1)+1;
}

/*sous programme test*/
int main ()			
{
printf(" donner un nombre entier \n");
scanf("%d",&nb);
printf("le nombre mystere est %d .\n",mystere(nb));
return 0;
}
/*commentaire*/

	


