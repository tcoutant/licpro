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


int victoire(plateau p, int joueur)
{
	int NbPions1=0,NbPions2=0;
	if(partieTerminee(p))
	{
		comptePions(p,&NbPions1,&NbPions2);
		if(NbPions1 == NbPions2)
			return 2;
		else 
		{
			if(joueur == 1)
			{
				if(NbPions1 > NbPions2)
					return 1;
				else
					return 0;
			}
			else
			{
				if(NbPions2 > NbPions1)
					return 1;
				else
					return 0;
			}
		}
	}
	else
		return -1;
}
/*

*/
void tourCPUMinMax(plateau p, int joueur)
{ 
	if(!existeCoupPourJoueur(p, joueur)) 
		printf(" Le joueur numero %d doit passer son tour !  \n",joueur);
	else
		trouveCoupMinMax(p, joueur); 
}
/*________________________________________________________________________________________*/

/*

*/
int minVal (plateau p,int prof, int joueur)
{
	int min_val = -5000;
	int val,nb;
	int coups_possibles;
	plateau tmp;
							
	Maillon *liste_coups = NULL;
	Maillon *tete_Maillon = NULL;
	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	tete_Maillon = liste_coups;

	if(coups_possibles < 1)
		return 1;
	if (prof == 0)
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			//printf("Min: nombre pions = %d, prof = %d, (%c,%d)\n\n",nb,prof,'a'+liste_coups->coup.colonne,liste_coups->coup.ligne+1);
			if(victoire(tmp,joueur)==1)
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
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			//printf("Min: nombre pions = %d, prof = %d, (%c,%d)\n\n",nb,prof,'a'+liste_coups->coup.colonne,liste_coups->coup.ligne+1);
			if(victoire(tmp,joueur)==1)
				nb += 1000;

			val = nb - maxVal(tmp,prof-1,adversaire(joueur));
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
int maxVal (plateau p,int prof,int joueur)
{
	int max_val = -5000;
	int val, nb;
	int coups_possibles;
	plateau tmp;
	Maillon *tete_Maillon = NULL;
	Maillon * liste_coups = NULL;

	
	coups_possibles = donneTousLesCoupsValidesSansAffiche(p,joueur,&liste_coups);
	tete_Maillon = liste_coups;

	if(coups_possibles < 1)
		return 0;	
	if (prof == 1)
	{
		while(coups_possibles != 0)
		{
			dupliPlateau(p, &tmp);									//Duplication plateau
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			//printf("Max: nombre pions = %d, prof = %d, (%c,%d)\n\n",nb,prof,'a'+liste_coups->coup.colonne,liste_coups->coup.ligne+1);
			if(victoire(tmp,joueur)==1)
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
			nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
			//printf("Max: nombre pions = %d, prof = %d, (%c,%d)\n\n",nb,prof,'a'+liste_coups->coup.colonne,liste_coups->coup.ligne+1);
			if(victoire(tmp,joueur)==1)
				nb += 1000;

			val = nb - minVal(tmp,prof-1,adversaire(joueur));
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
void trouveCoupMinMax(plateau p, int joueur)
{
	int prof = PROFONDEUR;
	int max_val = -5000,nb;
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
				nb = joueLeCoupSansAffiche(tmp,liste_coups->coup.ligne,liste_coups->coup.colonne,joueur);
				//printf("MinMax: nombre pions = %d, prof = %d, (%c,%d)\n\n",nb,prof,'a'+liste_coups->coup.colonne,liste_coups->coup.ligne+1);
				val = nb - minVal(tmp,prof-1,adversaire(joueur));
				if(val > max_val)
				{
					max_val = val;	
					*meilleur_coup = liste_coups->coup;
				}
				coups_possibles--;

			liste_coups = liste_coups->suivant;
		}
		printf(" Meilleur coup joué par l'Ordi %d (MinMaxPions) : (%c %d)\n\n",joueur,'a'+meilleur_coup->colonne,meilleur_coup->ligne+1);
		joueLeCoup(p,meilleur_coup->ligne,meilleur_coup->colonne,joueur);
	}

	free_Maillons(tete_Maillon);
	free(meilleur_coup);
}
/*________________________________________________________________________________________________________*/
