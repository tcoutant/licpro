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


void creerGrapheL(GRAPHEL g)
{
int i;
for(i=0;i<N;i++)
	g[i] = NULL;
}

void creerGrapheM(GRAPHEM g)
{
int i,j;
for(i=0;i<N;i++)
	for(j=0;j<N;j++)
		g[i][j] = 0;
}


void afficheGrapheM(GRAPHEM g){
int i,j;
for(i=0;i<N;i++){
	for(j=0;j<N;j++)
		printf("%d ",g[i][j]);
	printf("\n");
	}
printf("\n");
}

void afficheGrapheL(GRAPHEL g){
int i;
struct cellule * tmp;
for(i=0;i<N;i++){
	tmp = g[i];
	while (tmp != NULL){
			printf("%d->%d\n",i+1,tmp->noeud+1);
			tmp = tmp->suivant;
		}
	}
}


void ajoutArcM(GRAPHEM g, int i, int j)
{
	g[i-1][j-1] = 1;
}

void ajoutArcL(GRAPHEL g, int i, int j)
{
	struct cellule *tmp;
	tmp = malloc(sizeof(struct cellule));
	tmp->noeud = j-1;
	tmp->suivant = g[i-1];
	g[i-1] = tmp;
}

void supprimeArcM(GRAPHEM g, int i, int j)
{
	g[i-1][j-1] = 0;
}

void supprimeArcL(GRAPHEL g, int i, int j)
{
	struct cellule * sup,* tmp = g[i-1];
	if (g[i-1] != NULL)
		{
		if ((g[i-1])->noeud == j-1)
			{
			sup = g[i-1];
			g[i-1] = g[i-1]->suivant;
			free(sup);
			}
		else
			{
			while ((tmp->suivant != NULL) && (tmp->suivant->noeud != j-1))
				tmp=tmp->suivant;
			if (tmp->suivant != NULL)
				{
				sup = tmp->suivant;
				tmp->suivant=tmp->suivant->suivant;
				free(sup);
				}
			}
		}
}

int testarcM(GRAPHEM g, int i, int j)
{
	return g[i-1][j-1];
}

int testarcL(GRAPHEL g, int i, int j)
{
	struct cellule * tmp = g[i-1];
	while ((tmp != NULL) && (tmp->noeud != j-1))
		tmp = tmp->suivant;
	if (tmp == NULL)
		return 0;
	else
		return 1;
}

void succM(GRAPHEM g, int i)
{
	int j;
	printf("%d -> ",i);
	for (j=1;j<=N;j++)
		if (testarcM(g,i,j) == 1) //if (g[i][j] == 1)
			printf("%d ",j);
	printf("\n");
}

void succL(GRAPHEL g, int i) //très facile mais peu efficace
{
	int j;
	printf("%d -> ",i);
	for (j=1;j<=N;j++)
		if (testarcL(g,i,j) == 1)
			printf("%d ",j);
	printf("\n");
}

void succL2(GRAPHEL g, int i) // facile ET efficace
{
	struct cellule * tmp = g[i-1];
	printf("%d -> ",i);
	while(tmp != NULL)
	{
		printf("%d ",tmp->noeud+1);
		tmp = tmp->suivant;	
	}
	printf("\n");
}

void predM(GRAPHEM g, int j)
{
	int i;
	printf("%d -> ",j);
	for (i=1;i<=N;i++)
		if (testarcM(g,i,j) == 1)
			printf("%d ",i);
	printf("\n");
}

void predL(GRAPHEL g, int j) //très facile
{
	int i;
	printf("%d -> ",j);
	for (i=1;i<=N;i++)
		if (testarcL(g,i,j) == 1)
			printf("%d ",i);
	printf("\n");
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
