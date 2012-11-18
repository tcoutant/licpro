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
#include "HumainVsCPUMinMaxCases.h"


void tourCPUMinMaxCases(plateau p, int joueur,plateau plateauValeur)
{
	if(!existeCoupPourJoueur(p, joueur))
		printf(" Le joueur numero %d doit passer son tour !  \n",joueur);
	else
		trouveCoupMinMaxCases(p, joueur,plateauValeur); 
}
/*________________________________________________________________________________________*/

/*

*/
int minValCases (plateau p,int prof, int joueur,plateau plateauValeur)
{
	int min_val = -5000;
	int val,nb;
	int coups_possibles;
	plateau tmp;
							
	Maillon *liste_coups = NULL;
	Maillon *tete_Maillon = NULL;

	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	tete_Maillon = liste_coups;
	if (prof == 1)
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			nb = plateauValeur[liste_coups->coup.ligne][liste_coups->coup.colonne];
			if(victoire(tmp,joueur) || (nb == -800))
				nb += 1000;

			if(nb > min_val)
			{
				min_val = nb;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(tete_Maillon);
		return min_val;
	}
	else
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			nb = plateauValeur[liste_coups->coup.ligne][liste_coups->coup.colonne];
			if(victoire(tmp,joueur) || (nb == -800))
				nb += 1000;

			val = nb - maxValCases(tmp,prof-1,adversaire(joueur),plateauValeur);
			if(val > min_val)
			{
				min_val = val;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(tete_Maillon);
		return min_val;
	}
}
/*________________________________________________________________________________________________*/

/*

*/
int maxValCases (plateau p,int prof,int joueur,plateau plateauValeur)
{
	int max_val = -5000;
	int val, nb;
	int coups_possibles;
	plateau tmp;
	Maillon *tete_Maillon = NULL;
	Maillon * liste_coups = NULL;

	
	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	tete_Maillon = liste_coups;	
	if (prof == 1)
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);

			nb = plateauValeur[liste_coups->coup.ligne][liste_coups->coup.colonne];
			if(victoire(tmp,joueur))
				nb += 1000;

			if(nb > max_val)
			{
				max_val = nb;
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(tete_Maillon);
		return max_val;
	}
	else
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			nb = plateauValeur[liste_coups->coup.ligne][liste_coups->coup.colonne];
			if(victoire(tmp,joueur))
				nb += 1000;

			val = nb - minValCases(tmp,prof-1,adversaire(joueur),plateauValeur);
			if(val > max_val)
			{
				max_val = val;	
			}
			liste_coups = liste_coups->suivant;
			coups_possibles--;
		}
		free_Maillons(tete_Maillon);
		return max_val;
	}
}
/*_________________________________________________________________________________________________*/


/*

*/
void trouveCoupMinMaxCases(plateau p, int joueur,plateau plateauValeur)
{
	int prof = PROFONDEUR;
	int max_val = -50000,nb;
	int val,coups_possibles;
	plateau tmp;

	Maillon *liste_coups = NULL;
	Maillon *tete_Maillon = NULL;
	StrCoup *meilleur_coup = NULL;

	meilleur_coup = malloc(sizeof(StrCoup));

	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	tete_Maillon = liste_coups;

	if(coups_possibles == 1)
	{
		joueLeCoup(p,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
	}
	else
	{	
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);
			joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			nb = plateauValeur[liste_coups->coup.ligne][liste_coups->coup.colonne];
			val = nb - minValCases(tmp,prof-1,adversaire(joueur),plateauValeur);
			if(val > max_val)
			{
				max_val = val;	
				*meilleur_coup = liste_coups->coup;
			}
			coups_possibles--;
			liste_coups = liste_coups->suivant;
		}
		printf(" Meilleur coup joué par l'Ordi %d (MinMaxCase) : (%c %d)\n\n",joueur,'a'+meilleur_coup->colonne,meilleur_coup->ligne+1);
		joueLeCoup(p,meilleur_coup->ligne,meilleur_coup->colonne,joueur);
	}

	free_Maillons(tete_Maillon);
	free(meilleur_coup);
}
/*________________________________________________________________________________________________________*/
