# include <stdio.h>

/*supprimer d'un tableau les nombres qui ont un diviseur place avant (algorythme erathostene)*/
int nb;


int main ()
{
printf("donner un nombre entier pour rechercher tous les nb premiers jusqu'à ce nb: \n");
scanf("%d",&nb);
int tab[nb+2];
/* ecriture des nombres dans le tableau*/
int i, j;
tab[0]=0;tab[1]=1;
for (i=2;i<nb;i++) tab[i]=i;


/* algorythme d'erathostene*/
i=2;
while (i<nb)
{
if (tab[i]==0) i++;
else
{
	{	
	for(j=i+1;j<nb;j++)
		if(tab[j]%tab[i]==0) tab[j]=0;	
	}
i++;
}
}
/* affichage des nombres premiers du tableau*/
for (i=0;i<nb;i++)
	if (tab[i]!=0) printf(" %d ",i);
printf("\n");
return 0;
}
