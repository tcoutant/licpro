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
#include "HumainVsCPUMinMax.h"
#include "HumainVsCPUMinMaxCases.h"
#include "HumainVsCPUMinOptions.h"
#include "HumainVsCPUMaxValeurCase.h"

/*
	Compte, à partir d'un plateau et d'un joueur passé en paramètre, le nombre de coups possible pour ce joueur sur le plateau
*/
int nbCoupsValides(plateau p, int joueur)
{
   int i,j,cpt=0;

   for(i=0;i<DIM_MAX;i++)
       for(j=0;j<DIM_MAX;j++)
              if(coupValide(joueur,p,i,j)==1)
                 cpt++;
   return cpt;
}




/*
	On initialise la variable minOptions à 65 (supérieur aux possibilités maximum, car il n'y a que 64 cases)
	On alloue une liste chainée qui contient la liste des coups valides sur le plateau passé en paramètre.
	On teste chaque coup possible, et on compte le nombre de possibilités qu'aura l'adversaire si l'on joue ce coup (avec la fonction nbCoupsValides), ue l'on stocke dans minOptions_tmp.
	Si ce nombre est inférieur au nombre stocké dans la variable minOptions, on change la valeur.
	A la fin de la liste chainée, on retourne minOptions.
*/
int trouveCoupMinOptions(plateau p, StrCoup * Coup,int joueur)
{
	int minOptions_tmp, minOptions=30, nbCoupsPossibles=0;
	int Ligne,Colonne;
	int i=0, nbAleatoireChoisi=0;

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
 
		printf(" Test de la position: (%c %d) : ",Colonne+'a',Ligne+1);
       
		//On simule le coup sur le plateau dupliqué
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,tmp,Ligne,Colonne);
       
		if(joueur==1)
			{
			minOptions=nbCoupsValides(tmp, 2);
			printf("\t nb coups possibles ensuite : %d\n",minOptions);
			}
		else
			{
			minOptions=nbCoupsValides(tmp, 1);
			printf("\t nb coups possibles ensuite : %d\n",minOptions);
			}

//RESTE DE LA CHAINE
	//Tant que le maillon est pas null 
	while((parcoursMaillon!=NULL)&&(parcoursMaillon->suivant!=NULL)) 
	{
       // Duplication du Plateau
		dupliPlateau(p,&tmp);

		Ligne = parcoursMaillon->suivant->coup.ligne;
		Colonne = parcoursMaillon->suivant->coup.colonne;         
 
		printf(" Test de la position: (%c %d) : ",Colonne+'a',Ligne+1);
       
		//On simule le coup sur le plateau dupliqué
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,tmp,Ligne,Colonne);
       
		if(joueur==1)
			{
			minOptions_tmp=nbCoupsValides(tmp, 2);
			printf("\t nb coups possibles ensuite : %d\n",minOptions_tmp);
			}
		else
			{
			minOptions_tmp=nbCoupsValides(tmp, 1);
			printf("\t nb coups possibles ensuite : %d\n",minOptions_tmp);
			}

		//On teste laquelle des deux variables est la plus petite
		if(minOptions_tmp < minOptions)
		{
			meilleurMaillon=parcoursMaillon->suivant;
			minOptions=minOptions_tmp;
			while(teteMaillon!=meilleurMaillon)
			{
				supprimeMaillon=teteMaillon;
				teteMaillon=teteMaillon->suivant;
				free(supprimeMaillon);
				parcoursMaillon=teteMaillon;
				nbCoupsPossibles--;
			}
			
		}
		else if(minOptions_tmp > minOptions)
			{
			supprimeMaillon=parcoursMaillon->suivant;
			parcoursMaillon->suivant=parcoursMaillon->suivant->suivant;
			free(supprimeMaillon);
			nbCoupsPossibles--;
			}
			else
				parcoursMaillon=parcoursMaillon->suivant;

	}

	printf(" nb de meilleurs coups minOptions équivalents : %d\n",nbCoupsPossibles);
	nbAleatoireChoisi = (random()%nbCoupsPossibles+1);
	printf(" Coup minOption Choisi : %der eme\n",nbAleatoireChoisi);
	parcoursMaillon = teteMaillon;   //Pour parcourir teteMaillon

	/* retrouver dans la liste le meilleur coup choisi aleatoirement */
	
	while (i<nbAleatoireChoisi-1)
	{
	//printf("valeur : %d %d\n", parcoursMaillon->coup.ligne, parcoursMaillon->coup.colonne);
	parcoursMaillon = parcoursMaillon->suivant;
	i++;
	}
	
	Coup->ligne=parcoursMaillon->coup.ligne;
	Coup->colonne=parcoursMaillon->coup.colonne;
	
	return minOptions;   //renvoie le plus petit nombre de possibilités pour l'adversaire
}





/*
	Si l'ordinateur a la possibilité de jouer, on appelle la fonction qui cherche le coup laissant le moins de possibilités à son adversaire, puis on joue ce coup.	
*/
void tourCPUMinOptions(plateau p, int joueur)
{
	StrCoup * Coup;   

	if(existeCoupPourJoueur(p, joueur) == 0) 
		printf(" Vous devez passer, joueur numero %d ! \n",joueur);
	else
	{
		Coup=(StrCoup *) malloc(sizeof(StrCoup)); //Allocation liste chainé

		if(Coup == NULL)
			printf(" Allocation de memoire dans tourCPU impossible\n"); 

	// Retient le meilleur coup possible dans la variable Coup

	printf(" Nombre de possibilité pour l'adversaire retenu : %d\n",trouveCoupMinOptions(p,Coup,joueur));
	printf(" Coup minOptions joué par l'ordi %d : (%c %d)\n\n",joueur, 'a'+Coup->colonne, Coup->ligne+1);
	joueLeCoup(p,(Coup->ligne),(Coup->colonne),joueur);
	
	free(Coup); //Liberation de la structure Coup
	}      
}

