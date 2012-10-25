#include <stdio.h>
#include <stdlib.h>

#include "HumainVsHumain.h"
#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"


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

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score final est Joueur 1: %i  et Joueur 2: %i\n",Point1,Point2);
		videStdin();
}

void JoueurvsCPUMaxPions()
{
	plateau p;
	int tour=2,Point1=0,Point2=0; 

	//demandeDIM_MAX();
   
	initialiserPlateau(p);
	afficherPlateau(p); 

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPU(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est : Joueur %d - CPU %d\n",Point1,Point2);
		videStdin();
}
