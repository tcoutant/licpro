# include <stdio.h>
# define N 10 		/*declaration des constantes*/




/* declaration des fonctions et procedures */

/* fonction qui retoune si la pile est pleine*/
int est_pleine(int x[N])
{
int i;
int test=0;
	for(i=0;i<N;i++)
		if (x[i]=="\0") test++;
	if (test==1) 	return 1; //la pile est pleine
	else            return 0;  // la pile n'est pas pleine
}

/* fonction qui retourne si la file est vide*/
int est_vide(int x[N])
{
int i;
int test=0;
	for(i=0;i<N;i++)
		if (x[i]=="\0") test++;
	if (test==N)  	return 1; //la pile est vide
	else            return 0;  // la pile n'est pas vide
}

/* empiler un élément dans la pile*/ 
/*void empiler(int x[N], int nb,int *fin)
{
if (est_pleine(x,fin)==1) 
	printf("La pile est pleine, il n'est pas possible d'y placer %d.\n",nb);
else
	{
	x[*fin]=nb; 
	*fin++;
	}
}
*/
/* depiler la pile*/ 
/*void depiler(int x[N],int *fin)
{
if (est_vide(x,fin)==1)
	printf("La pile est déjà vide, aucun element ne peut etre enlever.\n");
else
	{
	x[*fin]=0;
	*fin--;
	}
}
*/
/* affiche la pile*/
void affiche_pile(int tab_pile[N])
{
int i;
if (est_vide(tab_pile)==1) printf("Aucun element dans la pile.");
else
	{
	for(i=0;i<N;i++) printf("%d  ",tab_pile[i]);
	}
printf("\n");
}

/*programme principal*/	
int main ()			
{
/*initialisation du tableau*/
/*declaration des variables*/
 int *tab_pile[N];
*tab_pile[N]=malloc(sizeof(tab_pile[N]));
int i;
for(i=0;i<N;i++) tab_pile[i]=="\0";	//initialisation de la pile vide

printf("\n");
/* affichage*/
affiche_pile(tab_pile);

/*empiler(tab_pile,1,fin);
empiler(tab_pile,2,fin);
empiler(tab_pile,3,fin);
empiler(tab_pile,4,fin);
empiler(tab_pile,5,fin);
empiler(tab_pile,6,fin);
empiler(tab_pile,7,fin);
empiler(tab_pile,8,fin);
empiler(tab_pile,9,fin);
empiler(tab_pile,10,fin);
*/
/* affichage*/
affiche_pile(tab_pile);


/* test empiler la pile pleine*/
//empiler(tab_pile,11,fin);

/* affichage*/
affiche_pile(tab_pile);
/*
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
*/
/* affichage*/
affiche_pile(tab_pile);

/*
empiler(tab_pile,12,fin);
empiler(tab_pile,13,fin);
empiler(tab_pile,14,fin);
empiler(tab_pile,15,fin);
*/
/* affichage*/
affiche_pile(tab_pile);
/*
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
depiler(tab_pile, fin);
*/
/* affichage*/
affiche_pile(tab_pile);

/*test depiler la pile vide*/
//depiler(tab_pile, fin);

/* affichage*/
affiche_pile(tab_pile);

return 0;
}
