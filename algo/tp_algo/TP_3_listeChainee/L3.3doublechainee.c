#include <stdio.h>
#include <stdlib.h>

struct maillon
{
  int val;
  struct maillon * succ;
  struct maillon * pred;
};

typedef struct maillon * Listed;



void inserer(Listed *maliste, int val)
{
	Listed tmp,l;
	tmp = (Listed)malloc(sizeof(struct maillon));
	tmp->val = val;
	l = *maliste;
	if ((*maliste == NULL) || (val <= (*maliste)->val)) // NULL ou premier a inserer
		{
			tmp->succ = (*maliste);
			tmp->pred = NULL;
			if (*maliste != NULL)
				(*maliste)->pred = tmp;
			*maliste=tmp;
		}
	else //Non null et pas le premier
		{
			while ((l->succ != NULL) && (l->val < val)) 
				l = l->succ;
			if (l->val >= val) //Cas general
				{				 				
					tmp->succ = l;
					tmp->pred = l->pred;
					l->pred->succ = tmp;
					l->pred = tmp;
				}
			else  //dernier element a inserer
					{
						tmp->pred = l;
						tmp->succ = NULL;
						l->succ = tmp;
					}
		}
}

void afficher(Listed p)
{
	while(p!=NULL)
		{
			if (p->pred != NULL)
				if (p->succ != NULL)
					printf("%d(%d,%d) ",p->val,p->pred->val,p->succ->val);
				else
					printf("%d(%d,NULL) ",p->val,p->pred->val);
			else
				if (p->succ != NULL)
					printf("%d(NULL,%d) ",p->val,p->succ->val);
				else
					printf("%d(NULL,NULL) ",p->val);
					
			p=p->succ;
		}
	printf("\n");
}

int main()
{
	Listed liste = NULL;
	inserer(&liste,9);
	afficher(liste);
	inserer(&liste,5);
	afficher(liste);
	inserer(&liste,14);
	afficher(liste);
	inserer(&liste,12);
	inserer(&liste,2);
	afficher(liste);
	supprimer(&liste,12);
	afficher(liste);
	supprimer(&liste,5);
	afficher(liste);
	supprimer(&liste,14);
	afficher(liste);

	
	return 1;
}
