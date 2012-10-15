# include <stdio.h>
# include <math.h>
# define MAX 3 
typedef int TAB[MAX];	/*declaration des constantes*/

TAB A,B,C;		/*declaration des variables */
int gagne; int coup;
		
/*creation de la table aleatoire B */
/*int choix ()
{
srandom(getpid());
do
{B[1]=random()%9;} 
while(B[1]==B[0]);
do 
{B[2]=random()%9;}
while ((B[2]==B[1])||(B[0]));
return 0;
}*/
TAB B={2,4,6};
/*procedure de saisie de la table A*/
void saisie_tab(TAB *x)
{
int temp=0; int i=0;
while(i<MAX)
	{
	printf("donner la %d valeur : \n",i+1);
	scanf("%d",&temp);
		if ((temp>0)&&(temp<10))
		(*x)[i]=temp;
		i++;
	}
while(i<MAX) printf("choix propose : %d  ",(*x)[i]);
printf("\n");
}


/*affichage de la table proposée*/
void affiche_tab(TAB z)
{
int i=0;
printf("table  ");
while (i<MAX)
	{
	printf( "%d  ",z[i]);
	i++;
	}
printf("");
}

/* fonction qui teste si x appartient a la table*/
int appartient(TAB y,int x)
{
int i=0;
while (i<MAX)
	{
	if (y[i]==x)
	return 1;
	i++;
	}
return 0;
}

/*procedure qui compare 2 tables pour ecrire l'analyse dans une 3eme*/
void compare_tab(TAB x,TAB y)
{
int i=0;
while (i<MAX)
	{
	if(x[i]==y[i]) C[i]=x[i];
	else 
		if (appartient(y,x[i])==1 ) C[i]=-x[i];
		else C[i]=0;
i++; 
		
	}
}
/* fonction gagne*/
int gagne_partie()
{
int i, test=0;
for(i=0;i<MAX;i++)
{	if (C[i]==B[i]) test++;
}
if (test==3) gagne=1;
return gagne;
}



/*programme principal*/			
void main()			
{
TAB T;
while((gagne==0)&&(coup<8))
{
saisie_tab(&T);
printf(" la table ");
affiche_tab(T);
compare_tab (T,B);
printf(" donne ");
affiche_tab(C);
coup++;

printf(" \n");
gagne = gagne_partie();
}
if (gagne==1) printf("Bravo !! Vous avez gagné. \n");
else printf(" Vous avez perdu. Essaie encore !!  \n");
} 
