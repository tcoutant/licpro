# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/
int maxi;

/*declaration fonction booleenne estnbpemier*/			
int estnbpremier (int);
			
/*definition de la fonction*/
int estnbpremier(int N)
{
int i=2;
while((N%i!=0)&&(i<N))
	i++;
if (i==(N))
	return 1;
else 
	return 0;
}


/*programme principal*/
void main()
{

printf("donner un nombre pour chercher les nombres premiers compris entre 1 et ce nombre : \n");
scanf("%d",&maxi);
int i;
printf(" %d \t",1);
for(i=2;i<=maxi;i++)
{
	if (estnbpremier(i)!=0)
		printf(" %d \t",i);
}
printf("  \n");
}



