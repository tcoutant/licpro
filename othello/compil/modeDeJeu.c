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
		//free(plateauValeur);
}


/*____________________________________________________________________________*/

void CPUVsCPU(int niveauOrdi1, int niveauOrdi2)
{
	plateau p;  
	int Point1=0,Point2=0;
	char *niveau1, *niveau2;

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
		}
	do
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
		}
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
		}
      
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nOrdinateur 1 (%s) : %d\nOrdinateur 2 (%s) :  %d\n", niveau1, Point1, niveau2, Point2);
		//free(plateauValeur);
}
