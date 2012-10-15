# include <stdio.h>
# include <math.h>
# define MAX 3 
typedef int TAB[MAX];	/*declaration des constantes*/

TAB A,B,C;		/*declaration des variables */
int gagne; int coup;
		
/*creation de la table aleatoire B */
int tab_alea ()

{
srandom(getpid());
B[0]=random()%8+1;
do
{B[1]=random()%8+1;} 
while(B[1]==B[0]);
do 
{B[2]=random()%8+1;}
while ((B[2]==B[1])||(B[2]==B[0]));
return 0;
}


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
		else i--;
		i++;
	}
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
void compare_tab(TAB x,TAB y,TAB *C)
{
int i=0;
while (i<MAX)
	{
	if(x[i]==y[i]) (*C)[i]=x[i];
	else 
		if (appartient(y,x[i])==1 ) (*C)[i]=-x[i];
		else (*C)[i]=0;
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
tab_alea();
TAB T;
while((gagne==0)&&(coup<8))
{
saisie_tab(&T);
printf(" la ");
affiche_tab(T);
compare_tab (T,B,&C);
printf(" donne ");
affiche_tab(C);
coup++;

printf(" \n");
gagne = gagne_partie();
}
if (gagne==1) printf("Bravo !! Vous avez gagné. \n");
else printf(" Vous avez perdu. Essaie encore !!  \n");
} 
