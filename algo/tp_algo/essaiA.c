# include <stdio.h>
# include <string.h>
# define const 10 		/*declaration des constantes*/
int var;
char c;

/* fonction qui liste tous mestriplets d'entiers positifs(a,b,c) inferieurs a n, n lu au clavier, verifiant a2+b2+c2*/
int main()
{
int i,j,k, n;
printf("entrez un entier superieur a 2: ");
scanf("%d",&n);
if (n<=2) return 1;
for(i=0;i<n-2;i++)
	for (j=i+1;j<n-1;j++)
		for(k=n;k>j;k--)
		{
		if ((i*i)+(j*j)==(k*k))
		printf("%d \t %d \t %d \n",i,j,k);	
		}
	
return 0;
}

