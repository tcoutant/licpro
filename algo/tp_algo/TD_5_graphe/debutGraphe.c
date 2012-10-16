#include <stdlib.h>
#include <stdio.h>

#define N 6
// liste d'adjacence
struct cellule
{
 	int noeud;
 	struct cellule * suivant;
};

typedef struct cellule * GRAPHEL[N];

// matrice d'adjacence
typedef int GRAPHEM[N][N];

/* creer graphe par listed 'adja */
void creerGrapheL(GRAPHEL g)
{
int i;
for(i=0;i<N;i++)
	g[i] = NULL;
}
/* creer graphe par matrice d'adj */
void creerGrapheM(GRAPHEM g)
{
int i,j;
for(i=0;i<N;i++)
	for(j=0;j<N;j++)
		g[i][j] = 0;
}

/* affiche graphe par matrice d'adja */
void afficheGrapheM(GRAPHEM g){
int i,j;
for(i=0;i<N;i++){
	for(j=0;j<N;j++)
		printf("%d ",g[i][j]);
	printf("\n");
	}
printf("\n");
}
/* affiche graphe par liste d'adja */
void afficheGrapheL(GRAPHEL g){
int i;
struct cellule * tmp;
for(i=0;i<N;i++){
	tmp = g[i];
	while (tmp != NULL)
		{
			printf("%d->%d\n",i+1,tmp->noeud+1);
			tmp = tmp->suivant;
		}
}

/* ajouter arc par marice d'adja */
void ajouterArcM(GRAPHEM g, int i, int j)
{
g[i-1][j-1]=1;
}

/* supprimer un arc par matrice d'adja */
void supprimerArcM(GRAPHEM g,int i, int j)
{

}

/* supprimer un arc par liste d'adja */
void supprimerArcL(GRAPHEL g,int i, int j)
{

}


/* ajouter arc par liste d'adja */
void ajouterArcL(GRAPHEL g, int i, int j)
{
struct cellule *tmp;
tmp=malloc(sizeof(struct cellule));
tmp->noeud=j-1;
tmp->suivant=g[i-1];
g[i-1]=tmp;
}

/* tester un arc par matrice d'adja */
void testerArcM(GRAPHEM g, int i, nt j)
{
return g[i-1][j-1];
}

/* tester arc par liste d'adja */
void testerArcLGRAPHEL g, int i, int j)
{
struct cellule *tmp=g[i-1];
while ((tmp!=NULL) && (tmp->noeud !=j-1)
	tmp =tmp->suivant;
if (tmp==NULL) return 0;
else return 1;
}

/* afficher la liste des successeurs d'un sommet par matrice d'adja */
void succM(GRAPHEM g, int i)
{
int j;
printf("%d -> ",i);
for (j=0;j<N;J++)
	{
	if (testArc(g,i,j==1)
		{
		printf("%d ,",j);
		}
	}
}

/* affiche la liste des successeurs d'un sommet par liste d'adja */
void succL(GRAPHEL g, int i)
{
struct cellule *tmp=g[i-1];
while((tmp;!NULL) && (tmp->noeud!=
}

// Programme Principal
int main()
{
GRAPHEL gl;
GRAPHEM gm;

printf("CREATION\n");
creerGrapheM(gm);
creerGrapheL(gl);

printf("GM\n");
afficheGrapheM(gm);
printf("GL\n");
afficheGrapheL(gl);

printf("AJOUT\n");
ajoutArcL(gl,1,2);
ajoutArcM(gm,1,2);

printf("GM\n");
afficheGrapheM(gm);
printf("GL\n");
afficheGrapheL(gl);

printf("TESTS\n");
printf("M arc entre 1 et 2 : %d \n",testarcM(gm,1,2));
printf("L arc entre 1 et 2 : %d \n",testarcL(gl,1,2));

printf("SUCCESSEURS\n");
succM(gm,1);
succL(gl,1);
succL2(gl,1);
printf("PREDECESSEURS\n");
predM(gm,2);
predL(gl,2);

printf("SUPPRESSION\n");
supprimeArcL(gl,1,2);
supprimeArcM(gm,1,2);

printf("GM\n");
afficheGrapheM(gm);
printf("GL\n");
afficheGrapheL(gl);

printf("TESTS\n");
printf("M arc entre 1 et 2 : %d \n",testarcM(gm,1,2));
printf("L arc entre 1 et 2 : %d \n",testarcL(gl,1,2));

return 0;
}