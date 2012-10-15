# include <stdio.h>
int nb;	//declaration des variables//

/* fonction calculant la factorielle */
float factorielle(int a)
{
	if (a==0)
	return 1;
	else
	return a*factorielle(a-1);
}

void main()			//programme principal//
{
printf("donner un nombre entier pour calculer sa factorielle: \n");
scanf("%d",&nb);
printf("la factorielle de %d est égale à %.0f :\n",nb,factorielle(nb));
}
