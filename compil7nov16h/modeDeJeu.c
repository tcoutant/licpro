#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"
#include "modeDeJeu.h"
#include "HumainVsCPURandom.h"
#include "HumainVsCPUMaxPions.h"
#include "HumainVsCPUMinMax.h"
#include "HumainVsCPUMinMaxCases.h"
#include "HumainVsCPUMinOptions.h"
#include "HumainVsCPUMaxValeurCase.h"



void HumainVsHumain()
{
	plateau p;  
	int tour=2,Point1=0,Point2=0; 
   
	//demandeDIM_MAX(&DIM_MAX);

	initialiserPlateau(p);
	afficherPlateau(p);

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);    
		else 
			tourJoueur(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminée !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score final est :\nJoueur 1 : %d\nJoueur 2 : %i\n",Point1,Point2);
}
/*_________________________________________________________________________________*/
void HumainVsCPUMaxPions()
{
	plateau p;
	int tour=2,Point1=0,Point2=0; 
   
	initialiserPlateau(p);
	afficherPlateau(p); 

	while(!partieTerminee(p))
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPUMaxPions(p,2);
		tour++;
	}

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est : Joueur %d - Ordi %d\n",Point1,Point2);
}
/*_________________________________________________________________________*/
void HumainVsCPUMinOptions()
{
	plateau p;
	int tour=2,Point1=0,Point2=0; 
  
	initialiserPlateau(p);
	afficherPlateau(p); 

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPUMinOptions(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);
}
/*_________________________________________________________________________*/
void HumainVsCPURandom()
{
   plateau p;  
   int tour=2,Point1=0,Point2=0; 

   initialiserPlateau(p);
   afficherPlateau(p); 
         
	do
	{ 
		if( (tour%2)==0 )
			tourJoueur(p,1);
		else
			tourCPURandom(p,2);
		tour++;
      
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);

}
/*____________________________________________________________________________*/
void HumainVsCPUMaxValeurCase()
{
   plateau p;  
   int tour=2,Point1=0,Point2=0; 

   initialiserPlateau(p);
   afficherPlateau(p);

	/* initialisation du tableau des valeurs des cases */
	plateau plateauValeur;
	initialiserPlateauCoef(plateauValeur); 
         
	do
	{ 
		if( (tour%2)==0 )
			tourJoueur(p,1);
		else
			tourCPUMaxValeurCase(p,plateauValeur,2);
		tour++;
      
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);
}


/*____________________________________________________________________________*/

void CPUVsCPU(int niveauOrdi1, int niveauOrdi2)
{
	plateau p;
	int i,P1=0,P2=0;
	int compte = 0;
	int Point1=0,Point2=0;
	char *niveau1=NULL, *niveau2=NULL;

	initialiserPlateau(p);
	afficherPlateau(p); 
	/* initialisation du tableau des valeurs des cases */
	plateau plateauValeur;
	initialiserPlateauCoef(plateauValeur); 

	switch(niveauOrdi1)
		{
			case 1:
				niveau1="Random";
				break;
			case 2:
				niveau1="MaxPions";
				break;
			case 3:
				niveau1="MinOptions";
				break;
			case 4:
				niveau1="MaxValeurCase";
				break;
			case 5:
				niveau1="MinMaxPions";
				break;
			case 6:
				niveau1="MinMaxCases";
				break;
		}
		switch(niveauOrdi2)
		{
			case 1:
				niveau2="Random";
				break;
			case 2:
				niveau2="MaxPions";
				break;
			case 3:
				niveau2="MinOptions";
				break;
			case 4:
				niveau2="MaxValeurCase";
				break;
			case 5:
				niveau2="MinMaxPions";
				break;
			case 6:
				niveau2="MinMaxCases";
				break;
		}
	for(i=0;i<100;i++)
	{
	do
	{
		if((compte%2)==0)
		{
			switch(niveauOrdi1)
			{
				case 1:
					tourCPURandom(p, 1);
					break;
				case 2:
					tourCPUMaxPions(p, 1);
					break;
				case 3:
					tourCPUMinOptions(p, 1);
					break;
				case 4:
					tourCPUMaxValeurCase(p,plateauValeur, 1);
					break;
				case 5:
					tourCPUMinMax(p, 1);
					break;
				case 6:
					tourCPUMinMaxCases(p,1,plateauValeur);
					break;
			}
		}
		else
		{
			switch(niveauOrdi2)
			{
				case 1:
					tourCPURandom(p, 2);
					break;
				case 2:
					tourCPUMaxPions(p, 2);
					break;
				case 3:
					tourCPUMinOptions(p, 2);
					break;
				case 4:
					tourCPUMaxValeurCase(p,plateauValeur, 2);
					break;
				case 5:
					tourCPUMinMax(p, 2);
					break;
				case 6:
					tourCPUMinMaxCases(p,2,plateauValeur);
					break;
			}
		}
		compte ++;     
	}while(!partieTerminee(p));

	printf("\n\n\n\n La Partie est terminee !\n");
	comptePions(p,&Point1,&Point2);
	if(Point1>Point2)
		P1++;
	else if(Point2>Point1)
		P2++;
	printf("Le score est :\nOrdinateur 1 (%s) : %d\nOrdinateur 2 (%s) :  %d\n", niveau1, Point1, niveau2, Point2);
	Point1=0;
	Point2=0;
	initialiserPlateau(p);
	}
	printf("joueur 1:%d joueur 2:%d\n",P1,P2);
}
/*_________________________________________________________________________*/
void HumainVsCPUMinMax()
{
	plateau p;
	int tour=2,Point1=0,Point2=0; 
  
	initialiserPlateau(p);
	afficherPlateau(p); 

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPUMinMax(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);
}

void HumainVsCPUMinMaxCases()
{
	plateau p,pV;
	int tour=2,Point1=0,Point2=0; 
  
	initialiserPlateau(p);
	initialiserPlateauCoef(pV);
	afficherPlateau(p); 

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPUMinMaxCases(p,2,pV);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);
}

