#include <stdio.h>
#include <stdlib.h>
	/* definition de la structure element et creation d'un type correspondant*/
typedef struct Element Element;
struct Element
{
    int nombre;
    struct Element *suivant;
};
	/* creation d'un type pointeur Liste  qui pointe vers une structure elements*/
typedef Element *Liste;

	/*fonction pour inserer un element en debut de liste*/
Liste insertionD(Liste liste, int valeur)
{
  /* Création du nouvel élément */
Element *nouveau = malloc(sizeof(Element));
nouveau->nombre=valeur;
nouveau->suivant=liste;
  /*on retourne cette nouvelle liste modifiée avec le nouvel elemet en tete*/
return nouveau; /* c'est le pointeur du debut dela liste chainée*/
}

	/*fonction pour inserer un element en fin de liste*/
Liste insertionF(Liste liste, int valeur)
{
  /* creation du nouvel element*/
Element *nouveau = malloc(sizeof(Element));
nouveau->nombre = valeur;
nouveau->suivant =NULL;
if (liste==NULL) return nouveau; //si la liste est vide retourne l'element inserer
else
{
Element *temp=liste;
while (temp->suivant !=NULL)
	{
	temp = temp->suivant;
	}
	temp->suivant = nouveau;
return liste;
}
}
/* procedure qui affiche une liste*/
void afficherListe(Liste liste)
{
    Element *temp = liste;

    while (temp != NULL)
    {
        printf("%d - ", temp->nombre);
        temp = temp->suivant;
    }
    printf("NULL\n");
}
/* fonction qui recherche la derniere occurence dans une liste d'une valeur donnée*/
Liste rechercherD (Liste liste, int valeur)
{
if (liste==NULL) return NULL;
Element *temp = liste;
Element *temp1=NULL;
while (temp!=NULL)
	{
	if (temp->nombre==valeur)
		{
		/*creation d'un autre pointeur pour memoriser avant de continuer la verification*/
		temp1=temp;
		}
	temp=temp->suivant;
	}
return temp1;
}

/* fonction qui enleve tous les elements de la liste ayant une valeur donnée et la retourne*/
Liste supprimerE(Liste liste,int valeur)
{
if (liste==NULL) return NULL;//si la liste est nulle retourne NULL
if (liste->nombre==valeur)
	{
	Element *temp =liste->suivant;
	free(liste);
	temp =supprimerE (temp,valeur);
	return temp;
	}
else
	{
	liste->suivant = supprimerE(liste->suivant,valeur);//en recursif
	return liste;
	}
}	
/* fonction qui supprime le premier element d'une liste et la retourne*/
Liste supprimerD (Liste liste)
{
if (liste==NULL) exit;
Element *temp = liste->suivant;
free(liste);
return temp;
}
/* fonction qui supprime le dernier element d'une liste et la retourne */
Liste supprimerF(Liste liste)
{
if(liste==NULL) return NULL;
if (liste->suivant==NULL)
	{
	free(liste);
	return NULL;
	}
Element *temp=liste;
Element *temp1=liste; /*on garde le pointeur liste pour le renvoyerà la fin*/
while(temp->suivant!=NULL)
	{
	temp1=temp;
	temp=temp->suivant;
	}
temp1->suivant=NULL;
free(temp);
return liste;
}

int main()
{
/* creation tout d'abord d'une liste vide*/ 
Liste listeB = NULL;
/*utilisation des fonctions pour remplir la liste*/
listeB = insertionD(listeB,2);
listeB = insertionD(listeB,10);
listeB = insertionF(listeB,7);
listeB = insertionF(listeB,5);
listeB = insertionF(listeB,2);
listeB = insertionF(listeB,10);
afficherListe(listeB);
listeB = supprimerE(listeB,10);
listeB = supprimerD(listeB);
listeB = supprimerF(listeB);
afficherListe(listeB);
return 0;
}












