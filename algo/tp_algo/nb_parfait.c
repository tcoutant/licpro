# include <stdio.h>
int nb, somme,temp;
void main() {
printf ("donner un nombre :\n");
scanf ("%d", &nb);
somme=1;
temp=2;
while (temp <= nb/2)
{
	if (nb%temp==0)
	{
	somme=somme+temp;
	}
	temp++;	
}
 	if (nb==somme)
	{
	printf("le nombre %d est un nombre parfait\n",nb);
	}
	else
	{
	printf("le nombre %d n'est pas un nombre parfait.\n", nb);
	}
}
