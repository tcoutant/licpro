#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"
#include "modeDeJeu.h"
#include "HumainVsCPURandom.h"
#include "HumainVsCPUMaxPions.h"
#include "HumainVsCPUMinOptions.h"
#include "HumainVsCPUMaxValeurCase.h"

/*
	Les définitions des structures sont dans le fichier "definitions.h"
*/

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
/*_______________________________________________________________________________*/


/*
	Initialise toutes les cases avec des valeurs selon leurs places sur le plateau
			+-----+-----+-----+-----+-----+-----+-----+-----+
			| 800 |-500 | 300 | 300 | 300 | 300 |-500 | 800 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			|-500 |-500 | 200 | -50 | -50 | 200 |-500 |-500 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			| 300 | 200 | 100 | 100 | 100 | 100 | 200 | 300 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			| 300 | -50 | 100 |  0  |  0  | 100 | -50 | 300 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			| 300 | -50 | 100 |  0  |  0  | 100 | -50 | 300 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			| 300 | 200 | 100 | 100 | 100 | 100 | 200 | 300 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			|-500 |-500 | 200 | -50 | -50 | 200 |-500 |-500 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
			| 800 |-500 | 300 | 300 | 300 | 300 |-500 | 800 |
			+-----+-----+-----+-----+-----+-----+-----+-----+
*/  
void initialiserPlateauCoef(plateau p)
{
	p[0][0]=p[0][DIM_MAX-1]=p[DIM_MAX-1][0]=p[DIM_MAX-1][DIM_MAX-1]=800;

	p[0][1]=p[1][0]=p[1][1]=p[0][6]=p[1][6]=p[1][7]=p[6][0]=p[6][1]=p[7][1]=p[6][6]=p[6][7]=p[7][6]=-500;

	p[0][2]=p[0][3]=p[0][4]=p[0][5]=p[2][0]=p[2][7]=p[3][0]=p[3][7]=p[4][0]=p[4][7]=p[5][0]=p[5][7]=p[7][2]=p[7][3]=p[7][4]=p[7][5]=300;

	p[1][2]=p[1][5]=p[2][1]=p[2][6]=p[5][2]=p[5][6]=p[6][2]=p[6][5]=p[5][1]=200;

	p[2][2]=p[2][3]=p[2][4]=p[2][5]=p[3][2]=p[3][5]=p[4][2]=p[4][5]=p[5][2]=p[5][3]=p[5][4]=p[5][5]=100;

	p[1][3]=p[1][4]=p[3][1]=p[3][6]=p[4][1]=p[4][6]=p[6][3]=p[6][4]=-50;

	p[3][3]=p[3][4]=p[4][3]=p[4][4]=0;
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
