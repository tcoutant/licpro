#include <stdlib.h>
#include <stdio.h>

#define n 6


int M[n];
/* structure graphe par matrice d'adjacence */
struct Element
{
	 int val;
	 struct Element * suivant;
};
typedef struct Element * File;

/* structure graphe par liste d'adjacence */
struct cellule
{
int noeud;
struct cellule *suivant;
};
typedef struct cellule *GRAPHE[n];
typedef int GRAPHE[n][n];

void prof(int s,int g[n][n], int M[n])
{
int i;
printf("%d ",s);
M[s-1]=1;
	for (i=1;i<=n;i++)
		if ((M[i-1]==0) && (g[s-1][i-1]==1))
			prof(i,g,M);
}

/* creer graphe en matrice d'adja */
void creerGrapheM(graphe

/* creer graphe par liste d'adja */


void afficheGrapheM(GRAPHE g)
{
int i,j;
for(i=0;i<N;i++)
	printf("%d",g[i][j]);
printf("\n");
}

void afficheGrapheL(GRAPHE g)
{
int i;
struct cellule *tmp;
for(i=0;i<N;i++)
tmp= g[i];
while (tmp!=NULL)
	{
	printf("%d->%d\n",i+1,tmp->noeud+1);
	tmp=tmp->suivant;
	}
}










/* ajouter un arc ente 2 sommets pour matrice */
void ajouterM_arc(int i,intj)
{
GRAPHE[i][j] = 1;
}

/* ajouter arc entre 2 sommets pour liste d'adja */
void ajouterL_arcint i, int j)
{

}




int main()
{
/* creation d'un graphe sans arc*/
int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			GRAPHE[i][j] = 0;
}
