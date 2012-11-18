# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct noeud {
	int val;
	struct noeud *gauche;
	struct noeud *droite;	
}; 
typedef struct noeud * Arbre;

int tailleArbre(Arbre f)
{	
	if (f==NULL)
		return 0;
	else
		return  1+ tailleArbre(f->gauche) + tailleArbre(f->droite);
}

int hauteur(Arbre f, int nb)
{
	int ht;
	if (f==NULL) return -1;
	if (f->val==nb) return 0;
	ht = hauteur(f->gauche,nb)+1;
	if (ht==0)
	{
		ht=hauteur(f->droite,nb)+1;
		if(ht==0)
			return-1;
		else 
			return ht;
	}
	else return ht;	
}

void insererABR(Arbre *f, int nb)
{
	if (*f==NULL)
	{
	(*f)=malloc(sizeof(struct noeud));
	(*f)->val=nb;
	(*f)->gauche=NULL;
	(*f)->droite=NULL;
	}
	else
		if(nb>(*f)->val)
			insererABR(&(*f)->droite,nb);
		else
			insererABR(&(*f)->gauche,nb);
}

int appartientABR(Arbre f,int nb)
{
	if(f==NULL) return 1;
	else
	{
		if(f->val==nb) return 0;
		else
		{
		 if(nb>f->val)
			return appartientABR(f->droite,nb);
		else
			return appartientABR(f->gauche,nb);	
		}
	}
}

void prefixe(Arbre f)
{
	if (f!=NULL)
	{
	printf("%d -> ",f->val);
	prefixe(f->gauche);
	prefixe(f->droite);
	}
}

void infixe(Arbre f)
{
	if (f!=NULL)
	{
	infixe(f->gauche);
	printf("%d -> ",f->val);
	infixe(f->droite);
	}
}

void suffixe(Arbre f)
{
	if(f!=NULL)
	{
	suffixe(f->gauche);
	suffixe(f->droite);
	printf("%d -> ",f->val);
	}
}

int main ()
{
return 0;
}