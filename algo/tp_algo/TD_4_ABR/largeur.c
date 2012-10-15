#include <stdlib.h>
#include <stdio.h>


struct noeud
{
	int valeur;
	struct noeud * gauche;
	struct noeud * droit;
};
typedef struct noeud * Arbre;


struct Element
{
	struct noeud * valeur;
	struct Element * suivant;
};
typedef struct Element * File;

void enfiler(File *mafile, Arbre val)
{
	File tmp;
	tmp = (File)malloc(sizeof(struct Element));
	tmp->valeur = val;
	tmp->suivant = *mafile;
	*mafile=tmp;
}

File defiler(File *mafile)
{
	File tmp,tmp2;
	if (*mafile == NULL)
		return NULL;
	else
		{
			tmp = *mafile;
			if ((*mafile)->suivant == NULL)
				{
					(*mafile) = NULL;
					return tmp;
				}
			else
				{
					while(tmp->suivant->suivant != NULL)
						tmp=tmp->suivant;
					tmp2 = tmp->suivant;
					tmp->suivant = NULL;
					return tmp2;
				}
		}
}


int estvide(File f)
{
	if (f == NULL) 
		return 0;
	else
		return 1;
}


void largeur (Arbre a, File * f)
{
  Arbre tmp;
  File tmpf;
  if (a != NULL)
	{
	  printf("%d ",a->valeur);
	  if (a->gauche != NULL)
		  enfiler(&(*f),a->gauche);
	  if (a->droit != NULL)	
		  enfiler(&(*f),a->droit);
	  if (estvide(*f) != 0)
		{
		tmpf = defiler(&(*f));
		tmp = tmpf->valeur;
		free(tmpf);
		largeur(tmp,&(*f));
		}
	}
}






void larg(Arbre a)
{
	Arbre v;
	File f,tmp; 
	f = NULL;
	if (a != NULL)
		{
			enfiler(&f, a);
			while (estvide(f) == 1)
				{ 
					tmp = defiler(&f);
					v = tmp->valeur;
					free(tmp);
					printf("%d ",v->valeur);
					if (v->gauche != NULL)
						{
							enfiler(&f,v->gauche);
						}
					if (v->droit != NULL)
						{
							enfiler(&f,v->droit);
						}
				}
		}
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


int main()
{
	File f = NULL;
	Arbre ab;
	Arbre tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9;

	ab = NULL;

	tmp1 = (Arbre)malloc(sizeof(struct noeud));
	tmp1->valeur = 1;
	tmp1->gauche = NULL;
	tmp1->droit = NULL;
	tmp2 = (Arbre)malloc(sizeof(struct noeud));
	tmp2->valeur = 3;
	tmp2->gauche = NULL;
	tmp2->droit = NULL;
	tmp3 = (Arbre)malloc(sizeof(struct noeud));
	tmp3->valeur = 7;
	tmp3->gauche = NULL;
	tmp3->droit = NULL;
	tmp4 = (Arbre)malloc(sizeof(struct noeud));
	tmp4->valeur = 2;
	tmp4->gauche = NULL;
	tmp4->droit = NULL;
	tmp5 = (Arbre)malloc(sizeof(struct noeud));
	tmp5->valeur = 9;
	tmp5->gauche = tmp1;
	tmp5->droit = tmp2;
	tmp6 = (Arbre)malloc(sizeof(struct noeud));
	tmp6->valeur = 10;
	tmp6->gauche = NULL;
	tmp6->droit = tmp3;
	tmp7 = (Arbre)malloc(sizeof(struct noeud));
	tmp7->valeur = 6;
	tmp7->gauche = tmp4;
	tmp7->droit = NULL;
	tmp8 = (Arbre)malloc(sizeof(struct noeud));
	tmp8->valeur = 4;
	tmp8->gauche = tmp5;
	tmp8->droit = NULL;
	tmp9 = (Arbre)malloc(sizeof(struct noeud));
	tmp9->valeur = 8;
	tmp9->gauche = tmp6;
	tmp9->droit = tmp7;
	ab = (Arbre)malloc(sizeof(struct noeud));
	ab->valeur = 5;
	ab->gauche = tmp8;
	ab->droit = tmp9;

	printf("ABR\n");
//	larg(ab);
//	printf("\nV2\n");
	largeur(ab,&f);
	printf("\n");

	return 0;
}

