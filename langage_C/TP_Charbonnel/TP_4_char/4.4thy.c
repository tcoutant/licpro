# include <stdio.h>
# include <string.h>
# include <math.h>

# define const 10 		/*declaration des constantes*/

/*commentaire*/
float fonctionF(float S,float P,float *a,float *b)
{
float discrim;
discrim=(S*S)-(4*P);
	if (discrim<0)
	{
	printf("il n'y a pas de solution \n");
	return 0;
	}
	else
	{
	*a=-(-S + sqrt(discrim))/2;	//compiler avec l'option -lm pour sqrt
	*b=-(-S - sqrt(discrim))/2;	// avec gcc 4.4thy -lm
	printf("la solution est le couple de nombres %.2f %.2f \n",*a,*b);
	return 1;
	}
}
void main ()
{
printf("donner 2 nombres : \n");
float prod,som;
float aa, bb;
scanf("%f",&som);
scanf("%f",&prod);
fonctionF(som,prod,&aa,&bb);		


}
