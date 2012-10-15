# include <stdio.h>
/*ecrire une fonction qui pour un nombre n renvoit la meilleure valeur approchée de 1+1/4+1/9+1/16+1/25+1/n2*/

int nb;	//declaration des variables//
int iteration;
float fonction2(int a)
{
	if (a==0)
	return 0;
	else
	{
	iteration++;
	return ((1/(double)(a*a)) + fonction2(a-1));
	}	
}

void main()			//programme principal//
{
printf("Donner une valeur entiere pour calculer son image par la fonction2 :  \n");
scanf("%d",&nb);
printf("l'image de %d par la fonction2 est égale à %f .\n",nb,fonction2(nb));
printf("%d \n",iteration);

}
