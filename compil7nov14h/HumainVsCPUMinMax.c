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
#include "HumainVsCPUMinOptions.h"
#include "HumainVsCPUMaxValeurCase.h"

/*

*/
void tourCPUMinMax(plateau p, int joueur)
{
	if(existeCoupPourJoueur(p, joueur)) 
		trouveCoupMinMax(p, joueur);  
	else
		printf("Vous devez passer, joueur numero %d ! \n",joueur);
}
/*________________________________________________________________________________________*/

/*

*/
int minVal (plateau p,int prof, int joueur)
{
	int min_val = -500;
	int val,nb;
	int coups_possibles;
	plateau tmp;
							
	Maillon *liste_coups = NULL;
	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	if (prof == 1)
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			if(nb > min_val)
			{
				min_val = nb;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(liste_coups);
		return min_val;
	}
	else
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			val = (-nb) + maxVal(tmp,prof-1,adversaire(joueur));
			if(val > min_val)
			{
				min_val = val;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(liste_coups);
		return min_val;
	}
}
/*________________________________________________________________________________________________*/

/*

*/
int maxVal (plateau p,int prof,int joueur)
{
	int max_val = -500;
	int val, nb;
	int coups_possibles;
	plateau tmp;
	Maillon * liste_coups = NULL;

	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	if (prof == 1)
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			if(nb > max_val)
			{
				max_val = nb;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(liste_coups);
		return max_val;
	}
	else
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			val = nb + minVal(tmp,prof-1,adversaire(joueur));
			if(val > max_val)
			{
				max_val = val;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(liste_coups);
		return max_val;
	}
}
/*_________________________________________________________________________________________________*/


/*

*/
void trouveCoupMinMax(plateau p, int joueur)
{
	int prof = PROFONDEUR;
	int max_val = -500,nb;
	int val,coups_possibles;
	plateau tmp;

	Maillon *liste_coups = NULL;
	StrCoup *meilleur_coup = NULL;

	meilleur_coup = malloc(sizeof(StrCoup));
	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	if(coups_possibles == 1)
	{
		joueLeCoup(p,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);	//On joue le meilleur coup
		free_Maillons(liste_coups);											//Liberation de la liste
		free(meilleur_coup);												//Libération du meilleur coup
	}
	else
	{
		while(coups_possibles != 0)
		{	
			dupliPlateau(p, &tmp);											//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			val = nb + minVal(tmp,prof-1,adversaire(joueur));
			if(val > max_val)
			{
				max_val = val;	
				*meilleur_coup = liste_coups->coup;
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;										//Decrementation
		}
		joueLeCoup(p,meilleur_coup->ligne,meilleur_coup->colonne,joueur);
		free_Maillons(liste_coups);
		free(meilleur_coup);
	}
	printf("Meilleur coup joué par l'Ordi %d (MinMax) : (%c %d)\n\n",joueur,'a'+meilleur_coup->colonne,meilleur_coup->ligne+1);
}
/*________________________________________________________________________________________________________*/
