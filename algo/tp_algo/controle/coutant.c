# include <stdio.h>
# define N 10 		/*declaration des constantes*/

/*declaration des variables*/
int tab_pile[N];	
int fin;		//indice de la fin de la pile
int i;

/* declaration des fonctions et procedures */

/* fonction qui retoune si la pile est pleine*/
int est_pleine(int x[N])
{
	if (fin==N) 	return 1; //la pile est pleine
	else            return 0;  // la pile n'est pas pleine
}

/* fonction qui retourne si la file est vide*/
int est_vide(int x[N])
{
	if (fin==0)  	return 1; //la pile est vide
	else            return 0;  // la pile n'est pas vide
}

/* empiler un élément dans la pile*/ 
void empiler(int x[N], int nb)
{
if (est_pleine(x)==1) 
	printf("La pile est pleine, il n'est pas possible d'y placer %d.\n",nb);
else
	{
	x[fin]=nb; 
	fin++;
	}
}

/* depiler la pile*/ 
void depiler(int x[N])
{
if (est_vide(x)==1)
	printf("La pile est déjà vide, aucun element ne peut etre enlever.\n");
else
	{
	x[fin]=0;
	fin--;
	}
}

/* affiche la pile*/
void affiche_pile()
{
if (est_vide(tab_pile)==1) printf("Aucun element dans la pile.");
else
	{
	for(i=0;i<fin;i++) printf("%d  ",tab_pile[i]);
	}
printf("\n");
}

/*programme principal*/	
int main ()			
{
/*initialisation du tableau*/
for (i=0;i<N;i++) tab_pile[i]=0;
fin=0;
printf("\n");
empiler(tab_pile,1);
empiler(tab_pile,2);
empiler(tab_pile,3);
empiler(tab_pile,4);
empiler(tab_pile,5);
empiler(tab_pile,6);
empiler(tab_pile,7);
empiler(tab_pile,8);
empiler(tab_pile,9);
empiler(tab_pile,10);

/* affichage*/
affiche_pile(tab_pile);

depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
/* affichage*/
affiche_pile(tab_pile);

empiler(tab_pile,11);
empiler(tab_pile,12);
empiler(tab_pile,13);
empiler(tab_pile,14);
empiler(tab_pile,15);

/* test empiler la pile pleine*/
empiler(tab_pile,16);

/* affichage*/
affiche_pile(tab_pile);

depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);
depiler(tab_pile);

/* affichage*/
affiche_pile(tab_pile);

/*test depiler la pile vide*/
depiler(tab_pile);

return 0;
}
