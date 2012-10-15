#include <stdio.h>
#include <stdlib.h>
	/* definition de la structure element et creation d'un type correspondant*/
typedef struct Element Element;
struct Element
{
    	int nombre;
    	struct Element *suivant;
	struct Element *precedent;
};
	/* creation d'un pointeur d'une structure liste qui contient des elements*/
typedef Element *Listed;

/* procedure qui affiche une liste*/
void afficherListe(Listed list)
{
Listed liste=list;
       while (liste != NULL)
    {
	if (liste->precedent!=NULL)
		if (liste->suivant!=NULL)
        printf("%d (%d,%d) ", liste->nombre,liste->precedent->nombre,liste->suivant->nombre);
		else printf("%d(%d,NULL) ",liste->nombre,liste->precedent->nombre);
	else 	if (liste->precedent!=NULL)
	printf("%d(NULL,%d) ",liste->nombre,liste->suivant->nombre);
		else printf("%d(NULL,NULL) ",liste->nombre);
	liste= liste->suivant;
    }
    printf("NULL\n");
}









	/*fonction pour inserer un element en debut de liste*/
Listed insertionD(Listed liste, int valeur)
{
 /*fonction pour inserer un element en debut de liste*/
Listed insertionD(Listed liste, int valeur)
{
 /* Création du nouvel élément */
Element *nouveau = malloc(sizeof(Element));
nouveau->nombre=valeur;
nouveau->suivant=liste;

  /*on retourne cette nouvelle liste modifiée avec le nouvel elemet en tete*/
return nouveau;
}

int main()
{
return 0;
}

