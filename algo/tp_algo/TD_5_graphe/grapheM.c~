#include <stdlib.h>
#include <stdio.h>

#define n 6

int GRAPHE[n][n];
int M[n];

struct Element
{
	 int val;
	 struct Element * suivant;
};
typedef struct Element * File;

void prof(int s,int g[n][n], int M[n])
{
}

int main()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			GRAPHE[i][j] = 0;
	GRAPHE[0][0] = 1;
	GRAPHE[0][1] = 1;
	GRAPHE[0][2] = 1;
	GRAPHE[1][3] = 1;
	GRAPHE[2][0] = 1;
	GRAPHE[2][1] = 1;
	GRAPHE[2][4] = 1;
	GRAPHE[3][2] = 1;
	GRAPHE[3][4] = 1;
	GRAPHE[4][1] = 1;
	
	for(i=0;i<n;i++)
		M[i] = 0;
	printf("->1\n");
	prof(1,GRAPHE,M);
	for(i=0;i<n;i++)
		M[i] = 0;
	printf("\n->2\n");
	prof(2,GRAPHE,M);
	for(i=0;i<n;i++)
		M[i] = 0;
	printf("\n->3\n");
	prof(3,GRAPHE,M);
	for(i=0;i<n;i++)
		M[i] = 0;
	printf("\n->4\n");
	prof(4,GRAPHE,M);
	for(i=0;i<n;i++)
		M[i] = 0;
	printf("\n->5\n");
	prof(5,GRAPHE,M);
	for(i=0;i<n;i++)
		M[i] = 0;
	printf("\n->6\n");
	prof(6,GRAPHE,M);
	printf("\n");

	return 0;
}
