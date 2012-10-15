# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/


/*prototype de la fonction F (declaration)*/
int F(int);

/*definition de la fonction*/			
 int F(int k)			
{
int f;
for(f=1;k>0;k--)
	f=f*k;
return f;
}

/*programme principal*/
void main()
{
printf("la factorielle de 5 est %d . \n",F(5));

} 
