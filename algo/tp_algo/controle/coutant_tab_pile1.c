# include <stdio.h>
# include <stdlib.h>
# define N 10 	/* declaration d'une constante pour la dimension du tableau */

	/* definition d'une structure */
struct Piletab
{
int tab_pile[N];	
int nbval;		//nombre de valeur rentrée dans la Pile
};
	/* definition d'un type Pile */
typedef struct Piletab Piletab;


	/* definition des fonctions et procedures */

	/* fonction qui retourne si la pile est pleine */
int est_pleine(Piletab *pile)
{
	if (pile->nbval==N)
 	return 1; // valeur 1 pour la pile est pleine
	else        
	return 0; 
}

	/* fonction qui retourne si la pile est vide */
int est_vide(Piletab *pile)
{
	if (pile->nbval==0)
  	return 1; // 1 pour la pile est vide
	else   
        return 0;
}

	/* empiler un élément dans la pile */ 
void empiler(Piletab *pile,int nb)
{
if (est_pleine(pile)==1)	 // test si la pile est pleine
	printf("La pile est pleine, il n'est pas possible d'y placer %d.\n",nb);
else
	
	{ // place le nouvel element à la suite dans le tableau
	pile->tab_pile[pile->nbval] = nb; 
	pile->nbval++;
	}
}

	/* depiler la pile */ 
void depiler(Piletab *pile)
{
if (est_vide(pile)==1) 	// test si la pile est deja vide avant d'enlever le dernier element
	printf("La pile est déjà vide, aucun element ne peut etre enlever.\n");
else
	{
	pile->tab_pile[pile->nbval-1]=0;	 // enleve le dernier element de la pile
	pile->nbval--;
	}
}

	/* affiche la file */
void affiche(Piletab *pile)
{
int i;
if (est_vide(pile)==1) 
	printf("Aucun element à afficher, la pile est vide.\n");
else
	{
	for(i=0;i<pile->nbval;i++) 
	printf("%d  ",pile->tab_pile[i]);
	printf("\n");
	}

}

	/* programme principal */	
int main ()			
{
	/* initialisation d'une structure Pile */
Piletab *pile = malloc(sizeof(*pile)); 
pile->tab_pile[N];	
pile->nbval=0;		//nombre de valeur dans le tableau

printf("\n");
affiche(pile);

empiler(pile,1);
empiler(pile,2);
empiler(pile,3);
empiler(pile,4);
empiler(pile,5);
empiler(pile,6);
empiler(pile,7);
empiler(pile,8);
empiler(pile,9);
empiler(pile,10);

affiche(pile);

	/* test empiler la pile pleine */
empiler(pile,11);

depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);

affiche(pile);

empiler(pile,12);
empiler(pile,13);
empiler(pile,14);
empiler(pile,15);
empiler(pile,16);

affiche(pile);

depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);
depiler(pile);

affiche(pile);

	/* test depiler la pile vide */
depiler(pile);
printf("\n");

return 0;
}
