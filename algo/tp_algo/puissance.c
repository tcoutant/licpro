# include <stdio.h>
# include <string.h>
#
int n, tour ,tourV;
float nb;


/* fonction puissance*/

float puissance(float x, int a)
{
if (a==0) return 1;
else
		{
		tour++;
		if(a>0) 
		return (x * puissance(x,a-1));
		else 
		return (1/ puissance(x,-a));
		}
}

/*une autre fonction avec une autre methode pour calculer la puissance*/
float puissanceV(float x,int a)
{
if(a==0) return 1;
else	
	{
	tourV++;
	if (a<0) return (1/ puissance(x,-a));
	else
		if(a%2!=0)
		return (x*puissance(x,a-1));
		else 
		return puissance(puissance(x,2),(n/2));
	}	
}

/*programme principal*/	
void main()
{
printf("donner un nombre reel : \n");
scanf("%f",&nb);
printf("donner un nombre entier : \n");
scanf("%d",&n);
printf(" %.0f puissance %d est egale à %.0f avec %d tours. \n",nb,n,puissance(nb,n),tour);
printf("%d \n",tour);
printf(" %.0f puissance %d est egale à %.0f avec %d tours.\n",nb,n,puissanceV(nb,n),tourV);
}
