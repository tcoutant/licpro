#include <stdlib.h>
#include <stdio.h>

struct noeud
{
	 int val;
	 struct noeud * gauche;
	 struct noeud * droit;
};
typedef struct noeud * arbre;

 /* taille de l'arbre */
int taille(arbre a)
{
	if (a == NULL) 
		return 0;
	else
		return 1 + taille(a->gauche) + taille(a->droit);
}

 /* hauteur de l'arbre */
int hauteur(arbre a,int n)
{
int ht=0;
if (a==NULL) return -1;
if (a->val==n) return 0;
ht= hauteur (a->gauche,n)+1;
if(ht==0)
	{
	ht=hauteur(a->droit,n)+1;
	if (ht==0) return -1;
	else return ht;
	}
else
return ht;
}

 /* inserer une valeur */
void inserer(arbre *a,int x)
{

if (*a==NULL)
	{
	*a =malloc(sizeof(struct noeud));
	(*a)->val=x;
	(*a)->gauche=NULL;
	(*a)->droit=NULL;
	}
else
	{
	if (x <= (*a)->val)
		 inserer (&(*a)->gauche,x);
	else
		 inserer (&(*a)->droit,x);
	}
}
 /* rechercher une valeur */
int rechercher (arbre a, int x)
{
if (a==NULL) return 1;
else
	if (a->val== x) return 0; // la valeur appartient à l'arbre
	else
		if (x< a->val) return rechercher(a->gauche,x);
		else rechercher(a->droit,x);	
}

/* affichage differentes manieres */
void prefixe(arbre a)
{
if (a!=NULL) 
	{
	printf("%d",a->val);
	prefixe(a->gauche);
	prefixe(a->droit);
	}
}

void infixe(arbre a)
{
if (a!=NULL)
	{
	infixe(a->gauche);
	printf("%d",a->val);
	infixe(a->droit);
	}
}

void suffixe(arbre a)
{
if (a!=NULL)
	{
	suffixe(a->gauche);
	suffixe(a->droit);
	printf("%d",a->val);	
	}
}



 /* programme principal */
int main()
{
	arbre a,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9;
	tmp1 = (arbre)malloc(sizeof(struct noeud));
	tmp1->val = 1;
	tmp1->gauche = NULL;
	tmp1->droit = NULL;
	tmp2 = (arbre)malloc(sizeof(struct noeud));
	tmp2->val = 3;
	tmp2->gauche = NULL;
	tmp2->droit = NULL;
	tmp3 = (arbre)malloc(sizeof(struct noeud));
	tmp3->val = 7;
	tmp3->gauche = NULL;
	tmp3->droit = NULL;
	tmp4 = (arbre)malloc(sizeof(struct noeud));
	tmp4->val = 9;
	tmp4->gauche = NULL;
	tmp4->droit = NULL;
	tmp5 = (arbre)malloc(sizeof(struct noeud));
	tmp5->val = 2;
	tmp5->gauche = tmp1;
	tmp5->droit = tmp2;
	tmp6 = (arbre)malloc(sizeof(struct noeud));
	tmp6->val = 6;
	tmp6->gauche = NULL;
	tmp6->droit = tmp3;
	tmp7 = (arbre)malloc(sizeof(struct noeud));
	tmp7->val = 10;
	tmp7->gauche = tmp4;
	tmp7->droit = NULL;
	tmp8 = (arbre)malloc(sizeof(struct noeud));
	tmp8->val = 4;
	tmp8->gauche = tmp5;
	tmp8->droit = NULL;
	tmp9 = (arbre)malloc(sizeof(struct noeud));
	tmp9->val = 8;
	tmp9->gauche = tmp6;
	tmp9->droit = tmp7;
	a = (arbre)malloc(sizeof(struct noeud));
	a->val = 5;
	a->gauche = tmp8;
	a->droit = tmp9;
	printf("hauteur 10 = %d\n",hauteur(a,10));
	printf("Taille de a = %d\n",taille(a));
	prefixe(a);
printf("\n");
	infixe(a);
printf("\n");
	suffixe(a);
printf("\n");
	inserer(&a,6);
	infixe(a);
printf("\n");
printf("%d\n", rechercher(a,12));
 	}