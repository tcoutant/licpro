#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"
#include "modeDeJeu.h"
#include "HumainVsCPURandom.h"
#include "HumainVsCPUMaxPions.h"
#include "HumainVsCPUMinOptions.h"


void tourCPURandom(plateau p, int joueur)
{
	int nbCoupsPossibles;
	int nbAleatoireChoisi;
	int test=0;//->initialisation test a zero

	Maillon *teteMaillon;  //Il sera alloué dans donneTousLesCoupsValides
	Maillon *courantMaillon;//Sert a parcourir teteMaillon, pas besoin d'etre alloué
	
	srand(time(NULL)); //inclu time.h pour avoir une valeur au hasard par rapport a l'heure de l'ordi

	if(!existeCoupPourJoueur(p, joueur)) 
		printf(" Le joueur numero %d doit passer son tour !  \n",joueur); 
	else
	{
        /*remplit la liste des coups jouables et retourne le nb de coups possibles*/

	nbCoupsPossibles=donneTousLesCoupsValides(p,joueur,&teteMaillon);
	printf("nb de Cases Possibles = %d\n",nbCoupsPossibles);

	/* effectue un random sur le nombre de valeurs possibles*/

	nbAleatoireChoisi = (random()%nbCoupsPossibles)+1;
	printf("Case Aleatoire Choisi = %d\n",nbAleatoireChoisi);
	courantMaillon = teteMaillon;   //Pour parcourire teteMaillon

	/* retrouver dans la liste le coup choisi aleatoirement */

	while (test<(nbAleatoireChoisi-1))//-1 pour aller un cran moins loin dans le liste
	{
		courantMaillon = courantMaillon->suivant;
		test++;
	}
	
	/* joue le coup choisi aleatoirement */
	joueLeCoup(p,courantMaillon->coup.ligne,courantMaillon->coup.colonne,joueur);
	printf("Coup aléatoire joué par l'ordi : (%c %d)\n", 'a'+courantMaillon->coup.colonne, courantMaillon->coup.ligne+1);
	free_Maillons(teteMaillon);//Libération de tout les maillons     
	}    
}

