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
#include "HumainVsCPUMaxValeurCase.h"

void tourCPUMaxValeurCase(plateau p,plateau val, int joueur)
{
	


	int nbCoupsPossibles;
	int nbAleatoireChoisi;
	int test=0;
	int LvalMax=0;
	int CvalMax=0;
	int valeurMax= -1000;

	Maillon *teteMaillon;  //Il sera alloué dans donneTousLesCoupsValides
 	Maillon *courantMaillon; //Sert a parcourir teteMaillon, pas besoin d'etre alloué
	Maillon *temp;
	Maillon *temp1=NULL;
	srand(time(NULL));
	
		if(!existeCoupPourJoueur(p, joueur)) 
		printf(" Le joueur numero %d doit passer son tour !  \n",joueur); 
	else
	{
        /*remplit la liste des coups jouables et retourne le nb de coups possibles*/

	nbCoupsPossibles=donneTousLesCoupsValides(p,joueur,&teteMaillon);
	//printf("nb de Cases Possibles = %d\n",nbCoupsPossibles);

	courantMaillon = teteMaillon;   //Pour parcourir teteMaillon
	temp = teteMaillon;
	//initialisation du meilleur coup (valeurMax) au premier coup possible de la liste
		LvalMax=courantMaillon->coup.ligne;
		CvalMax=courantMaillon->coup.colonne;
		valeurMax=val[CvalMax][LvalMax];

		
	/* comparaison avec les autres coups jouables s'ils existent pour ne garder
		dans la liste que le ou les meilleurs coups s'ils sont identiques. */
		while ((courantMaillon->suivant!=NULL)||(test!=0))
		{
		if (test==1) // on revient au premier coup pour recomparer le premier apres modif 
		{
			courantMaillon =teteMaillon;
			temp=courantMaillon;
			test=0;
		}

	/* si le coup analyse est meilleur, on supprime le maillon moins interessant */	
			if (val[courantMaillon->suivant->coup.colonne][courantMaillon->suivant->coup.ligne]>valeurMax)
			{
		/* si c'est le premier à supprimer, on modifie aussi teteMaillon */	
				if (teteMaillon==courantMaillon) 
				{
				LvalMax=courantMaillon->suivant->coup.ligne;
				CvalMax=courantMaillon->suivant->coup.colonne;
				valeurMax=val[CvalMax][LvalMax];
				teteMaillon=courantMaillon->suivant;
				free(temp);
				courantMaillon=teteMaillon;
				temp=courantMaillon;
				nbCoupsPossibles--;
								}

		/* cas où l'element a supprimer n'est pas le premier de la liste */
				else
				{
				LvalMax=courantMaillon->suivant->coup.ligne;
				CvalMax=courantMaillon->suivant->coup.colonne;
				valeurMax=val[CvalMax][LvalMax];
				temp1=courantMaillon;
				courantMaillon=courantMaillon->suivant;
				temp->suivant=courantMaillon;
				free(temp1);
				nbCoupsPossibles--;
				test=1; // pour revenir tester l'element d'avant dans la liste
								}
			}	
			else

	/* si le coup analyse est de meme valeur que celui deja retenu, on le garde */
			{
				if (val[courantMaillon->suivant->coup.colonne][courantMaillon->suivant->coup.ligne]==valeurMax) 
				{
		/* si le coup analyse est identique et pas le premier, on avance temp et 				courantMaillon */
					if (courantMaillon!=temp) 
					{
						courantMaillon=courantMaillon->suivant;
						temp=temp->suivant;
											}
		/* sinon on avance que courantMaillon */
					else 
					{
						courantMaillon=courantMaillon->suivant;
											}
				}
	
				else 
	/* dans ce cas, le coup analyse est moins interressant, on supprime ce coup */
				{
					temp1=courantMaillon->suivant;
					courantMaillon->suivant=courantMaillon->suivant->suivant;
					free(temp1);
					nbCoupsPossibles--;
				}
			}
		}
		
	printf("nb de meilleurs coups equivalents = %d\n",nbCoupsPossibles);
	nbAleatoireChoisi = (random()%nbCoupsPossibles+1);
	printf("Coup valorisé Choisi au hasard = %d(er eme)\n",nbAleatoireChoisi);
	courantMaillon = teteMaillon;   //Pour parcourir teteMaillon

	/* retrouver dans la liste le meilleur coup choisi aleatoirement */

	while (test<nbAleatoireChoisi-1)
	{
	courantMaillon = courantMaillon->suivant;
	test++;
	}
	
	/* joue le coup choisi aleatoirement parmi les meilleurs coups equivalents */
	
	printf("Coup joué par l'ordi%d parmi les meilleurs coups : (%c %d)\n",joueur, 'a'+courantMaillon->coup.colonne, courantMaillon->coup.ligne+1);
	  
	printf("Ce coup equivaut dans le tableau de valeur des cases a : %d points\n",val[courantMaillon->coup.colonne][courantMaillon->coup.ligne]);

	joueLeCoup(p,courantMaillon->coup.ligne,courantMaillon->coup.colonne,joueur);
	free_Maillons(teteMaillon);//Libération de tout les maillons   
	}
			
}

