#include <stdlib.h>
#include <stdio.h>

struct noeud
{
	int valeur;
	struct noeud * gauche;
	struct noeud * droit;
};
typedef struct noeud * Arbre;
#define max 10
typedef int TAB[max];

void insererABR(Arbre *a,int x)
{
	if (*a == NULL)
		{
			*a = (Arbre) malloc(sizeof(struct noeud));
			(*a)->gauche = NULL;
			(*a)->droit = NULL;
			(*a)->valeur = x;
		}
	else
		if ((*a)->valeur < x)
			insererABR(&(*a)->droit,x);
		else
			insererABR(&(*a)->gauche,x);
}

void infixe(Arbre a)
{
	if (a != NULL)
		{
			infixe(a->gauche);
			printf("%d ",a->valeur);
			infixe(a->droit);
		}
}

void remplitableau(Arbre a,TAB t,int *j)
{
	if (a != NULL)
		{
			remplitableau(a->gauche,t,&(*j));
			t[*j]=a->valeur;
			(*j)++;
			remplitableau(a->droit,t,&(*j));
		}
}

void tritableau(TAB tab, int n)
{
	int j = 0;
	Arbre abr = NULL;
	int i;
	for(i=0;i<n;i++)
		insererABR(&abr,tab[i]);
	remplitableau(abr,tab,&j);
}

int main()
{
	int i;
	TAB t={9,1,2,3,5,4,3,2,1,0};
	for(i=0;i<10;i++)
		printf("%d ",t[i]);
	printf("\n");
	tritableau(t,10);
	for(i=0;i<10;i++)
		printf("%d ",t[i]);
	printf("\n");
	return 0;
}
