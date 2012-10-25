#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"


/*
	Initialise toutes les cases tu tableau à 0, sauf les quatre du centre
*/
void initialiserPlateau(plateau p)
{
	int i, j;

	for(i=0;i<DIM_MAX; i++)
		for(j=0;j<DIM_MAX;j++)
			p[i][j]=0;

	p[(DIM_MAX/2)-1][(DIM_MAX/2)-1]	= 1;
	p[(DIM_MAX/2)-1][(DIM_MAX/2)]	= 2;
	p[(DIM_MAX/2)][(DIM_MAX/2)-1]	= 2;
	p[(DIM_MAX/2)][(DIM_MAX/2)]		= 1;
}
/*/____________________________________________________________________________\\



	Affichage du plateau de jeu
*/
void afficherPlateau(plateau p)
{
	int i,j,k;

	printf("\t");
	for(i=0;i<DIM_MAX;i++)
	printf("  %2c",'a'+i);
	printf("\n");
	
	for(i=0;i<DIM_MAX;i++)
	{
		printf("\t  ");
		for(k=0;k<DIM_MAX;k++)
		{
			printf("+---");
		}
		
		printf("+\n\t%d |",i+1);
		
		for(j=0;j<DIM_MAX;j++)
		{
			if(p[i][j]==0)
				printf("   |");
			else if (p[i][j]==1)
					printf(" 1 |");
				else
					printf(" 2 |");
		}
		printf("\n");
	}
	printf("\t  ");

	for(k=0;k<DIM_MAX;k++)
	{
		printf("+---");
	}
	printf("+\n\n\n");
}
/*/________________________________________________________________\\




*/
void videStdin()
{

     char c;
     c = getchar();

     if (c != '\n')
       while ( (getchar()) != '\n');
 
}
