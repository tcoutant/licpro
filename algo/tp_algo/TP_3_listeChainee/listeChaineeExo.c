#include <stdio.h>
#include <stdlib.h>

typedef struct element Element;

struct element
{	int nombre;
	Element *suivant;
};


typedef struct liste
{
	Element *premier;
} Liste;

/* initialisation d'ube liste */
Liste * initialisationListe()
{
Liste *listeNum=malloc(sizeof(*listeNum));
Element *element = malloc(sizeof(*element));
element->nombre=0;
element->suivant=NULL;
listeNum->premier=element;
return listeNum;
}

/* insertion en début de liste chainee */
void insertionDebut (Liste *liste,int nb)
{
// si la liste n'a pas encore d'element insere, on remplace le zero de l'initialisation
if ((liste->premier->nombre==0)&&(liste->premier->suivant==NULL))
	liste->premier->nombre=nb;
else
{
	// creation d'un nouvel element
	Element *nouveauElement=malloc(sizeof(*nouveauElement));
	// affectation de la valeur à ce nouveau element
	nouveauElement->nombre=nb;
	// pointage de ce nouvel element vers debut de liste deja creee
	nouveauElement->suivant=liste->premier;
	// attribution de ce nouveau element comme premier de la liste
	liste->premier=nouveauElement;
}
}
/* insertion à la fin de la liste*/
void insertionFin(Liste *liste, int nb)
{
if (liste!=NULL)
// si la liste n'a pas encore d'element insere, on remplace le zero de l'initialisation
if ((liste->premier->nombre==0)&&(liste->premier->suivant==NULL))
	liste->premier->nombre=nb;
else
{
	Element *tmp=liste->premier;
	while (tmp->suivant!=NULL)
		tmp= tmp->suivant;
	Element *nouveau =malloc(sizeof(*nouveau));
	nouveau->nombre=nb;
	nouveau->suivant=NULL;
	tmp->suivant=nouveau;
}
}

/* suppression du premier element */
void suppressionDebut(Liste *liste)
{
if (liste==NULL) exit(EXIT_FAILURE);
if (liste->premier!=NULL)
	{
	Element *tmp=liste->premier;
	liste->premier=liste->premier->suivant;
	free(tmp);
	}
}

/* suppression du dernier element */
void supprimerFin(Liste *liste)
{
	if (liste==NULL) exit(EXIT_FAILURE);
	if (liste->premier!=NULL)
	{
		Element *tmp=liste->premier;
		Element *tmp1=liste ->premier->suivant;
		while (tmp1->suivant!=NULL)
		{
			tmp=tmp->suivant;
			tmp1=tmp1->suivant;
		}
	tmp->suivant=NULL;
	free(tmp1);
	}
}

/* fonction qui verifie si un nombre appartient à la liste */
int appartientListe(Liste *liste, int nb)
{
if (liste==NULL) exit(EXIT_FAILURE);
Element *tmp =liste->premier;
int test=0;
while ((tmp->suivant!=NULL)&&test==0)
{
	if (tmp->nombre==nb) test=1;
	tmp=tmp->suivant;
}
printf("resultat appartenance de %d à la liste: %d\n",nb,test);
return test;
}

/* suppression de la liste les elements d'une certaine valeur 
void SuppressionElements(Liste *liste,int nombre)
{
if(liste==NULL) exit(EXIT_FAILURE);
if (liste->premier!=NULL)
{
	Element *tmp=liste->premier;
	Element *tmp1= liste->premier->suivant;
	if ((tmp->nombre==nb)&&(tmp1==NULL))
	{
		liste->premier=tmp1;
		free(tmp);
		free(tmp1);
	}
	else
	{
		if ((tmp->nombre==nb)&&(tmp1!=NULL))
		{
			liste->premier=tmp1;
			free(tmp);
			tmp=tmp1;
			tmp1=tmp->suivant;
			suppressionElements(liste,nombre);
		}
	}
	while (
}
}*/

/* affichage de la liste */
void affichage(Liste *liste)
{
if (liste==NULL) exit(EXIT_FAILURE);
Element *courant= liste->premier;
	while (courant!=NULL)
	{
	printf("->%d",courant->nombre);
	courant=courant->suivant;
	}
	printf("\n");
}

int main()
{
Liste *maListe=initialisationListe();
insertionFin(maListe,2);
insertionDebut(maListe,4);
insertionDebut(maListe,8);
insertionDebut(maListe,6);
insertionDebut(maListe,0);
insertionDebut(maListe,5);
affichage(maListe);
suppressionDebut(maListe);
affichage(maListe);
insertionFin(maListe,10);
insertionFin(maListe,12);
affichage(maListe);
supprimerFin(maListe);
supprimerFin(maListe);
affichage(maListe);
appartientListe(maListe,6);
appartientListe(maListe,14);
return 0;
}