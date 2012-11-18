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
#include "HumainVsCPUMinMaxCases.h"
#include "HumainVsCPUMinMax.h"


/*	Libère une liste chainée */
void free_Maillons(Maillon * teteMaillon)//OK
{
	Maillon * suivantMaillon;
	Maillon * courantMaillon;
	courantMaillon=teteMaillon;
   
	if(!courantMaillon) return;

	while(courantMaillon) 
	{
		suivantMaillon=courantMaillon->suivant;
		free(courantMaillon);
		courantMaillon=suivantMaillon;    
     
	}
}


/*	Compte le nombre de pions pour chacun des joueurs étant donné un plateau p */
int ecartPions(plateau p) 
{
	int pion1,pion2;
	pion2=0;
	pion1=0;

	comptePions(p,&pion1,&pion2);

	printf(" Nb de pions :\tJoueur1: %d\tJoueur2: %d\n",pion1,pion2);
	
	return (pion1-pion2);  
}


int ecartPionsSansAffiche(plateau p) 
{
	int pion1,pion2;
	pion2=0;
	pion1=0;

	comptePions(p,&pion1,&pion2);
	
	return (pion1-pion2);  
}


/*
	On initialise la variable ecart à -70 (valeur impossible)
	On alloue une liste chainée qui contient la liste des coups valides sur le plateau passé en paramètre.
	On teste chaque coup possible, et on compte le nombre de pions que l'on prendra à l'adversaire si l'on joue ce coup (avec la fonction ecartPions ), que l'on stocke dans ecart_tmp.
	Si ce nombre est supérieur au nombre stocké dans la variable ecart, on change la valeur.
	A la fin de la liste chainée, on retourne ecart.
*/
int trouveCoupMaxPions(plateau p, StrCoup * Coup,int joueur)
{
	int ecart_tmp,ecart=-1;
	int Ligne,Colonne;
	int i=0, nbAleatoireChoisi=0, nbCoupsPossibles=0;

	plateau tmp;//Plateau temporaire pour tester les differents coups

	Maillon * teteMaillon=NULL;//Maillon pour avoir les coupsValides
	Maillon * parcoursMaillon=NULL;//Maillon pour parcourir les coupsValides
	Maillon * meilleurMaillon=NULL;
	Maillon * supprimeMaillon=NULL;
  
	Coup->joueur=joueur;

	teteMaillon=NULL; 

	nbCoupsPossibles = donneTousLesCoupsValides(p,joueur,&teteMaillon);//Rentre tout les coup valides dans la liste chainée
	parcoursMaillon=teteMaillon;//Pour pouvoir parcourir la chaine
	meilleurMaillon=teteMaillon;
	 //________________________________
   	//|   Parcours de la liste chainée   |
	//__________________________________
   
//PREMIER MAILLON
// Duplication du Plateau
		dupliPlateau(p,&tmp);

		Ligne = parcoursMaillon->coup.ligne;
		Colonne = parcoursMaillon->coup.colonne;         
 
		printf(" Test de la position (%c %d) : ",Colonne+'a',Ligne+1);
       
		//On simule le coup sur le plateau dupliqué
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,tmp,Ligne,Colonne);

		if(joueur==1)
			{
			ecart = ecartPions(tmp);
			}
		else
			{
			ecart = -ecartPions(tmp);
			}


//RESTE DE LA CHAINE
	//Tant que le maillon est pas null 
	while((parcoursMaillon!=NULL)&&(parcoursMaillon->suivant!=NULL)) 
	{
       // Duplication du Plateau
		dupliPlateau(p,&tmp);

		Ligne = parcoursMaillon->suivant->coup.ligne;
		Colonne = parcoursMaillon->suivant->coup.colonne;         
 
		printf(" Test de la position (%c %d) : ",Colonne+'a',Ligne+1);
       
		//On simule le coup sur le plateau dupliqué
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,tmp,Ligne,Colonne);
       
		if(joueur==1)
			{
			ecart_tmp=ecartPions(tmp);
			}
		else
			{
			ecart_tmp = -ecartPions(tmp);
			}
		//On teste laquelle des deux variables est la plus petite
		if(ecart_tmp > ecart)
		{
			meilleurMaillon=parcoursMaillon->suivant;
			ecart=ecart_tmp;
			while(teteMaillon!=meilleurMaillon)
			{
				supprimeMaillon=teteMaillon;
				teteMaillon=teteMaillon->suivant;
				free(supprimeMaillon);
				parcoursMaillon=teteMaillon;
				nbCoupsPossibles--;
			}
						
		}
		else if(ecart_tmp < ecart)
		{
			supprimeMaillon=parcoursMaillon->suivant;
			parcoursMaillon->suivant=parcoursMaillon->suivant->suivant;
			free(supprimeMaillon);
			nbCoupsPossibles--;
		}
			
		else
			parcoursMaillon=parcoursMaillon->suivant;

	}

	printf(" nb de meilleurs coups maxpions équivalents : %d\n",nbCoupsPossibles);
	nbAleatoireChoisi = (random()%nbCoupsPossibles+1);
	printf(" Coup maxPions Choisi : %der eme\n",nbAleatoireChoisi);
	parcoursMaillon = teteMaillon;   //Pour parcourir teteMaillon

	/* retrouver dans la liste le meilleur coup choisi aleatoirement */
	
	while (i<nbAleatoireChoisi-1)
	{
	//printf(" valeur : %d %d\n", parcoursMaillon->coup.ligne, parcoursMaillon->coup.colonne);
	parcoursMaillon = parcoursMaillon->suivant;
	i++;
	}
	
	Coup->ligne=parcoursMaillon->coup.ligne;
	Coup->colonne=parcoursMaillon->coup.colonne;
	
	return ecart;   //renvoie le plus petit nombre de possibilités pour l'adversaire
}




/*	Si l'ordinateur a la possibilité de jouer, on appelle la fonction qui cherche le coup prenant le plus de pions à son adversaire, puis on joue ce coup.	*/
void tourCPUMaxPions(plateau p, int joueur)
{
	StrCoup * Coup;   

	if(existeCoupPourJoueur(p, joueur) == 0) 
		printf(" Vous devez passer, joueur numero %d ! \n",joueur);
	else
	{
		Coup=(StrCoup *) malloc(sizeof(StrCoup)); //Allocation liste chainé

		if(Coup == NULL)
			printf(" Allocation de memoire dans tourCPU impossible\n"); 

	/* Retient le meilleur coup possible dans la variable Coup */

	printf(" Ecart retenu apres coup: %d\n",trouveCoupMaxPions(p,Coup,joueur));

	printf(" Coup maxPions joué par l'ordi %d : (%c %d)\n\n",joueur, 'a'+Coup->colonne, Coup->ligne+1);
	joueLeCoup(p,(Coup->ligne),(Coup->colonne),joueur);
	
	free(Coup); //Liberation de la structure Coup
	}      
}
