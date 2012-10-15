# include <stdio.h>
int nb, temp, premier;
void main() {
printf ("donner un nombre :\n");
scanf ("%d", &nb);
if (nb==1)
 printf("le nombre %d est premier \n", nb);
else
	{
	temp=2;
	premier=0; 
	while ((temp!=nb)&&(premier == 0))
		{
		if (nb%temp==0)
		premier = 1;
		else
		temp++;
		}
	if (premier== 0)
	printf ("le nombre %d est  premier \n", nb);
	else
	printf ("le nombre %d n'est  pas premier car il est divisible par %d \n", nb, temp);

	}
}

