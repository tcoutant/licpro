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
	int minOptions_tmp, minOptions;
	int Ligne,Colonne;


	plateau tmp;//Plateau temporaire pour tester les differents coups

	Maillon * teteMaillon;//Maillon pour avoir les coupsValides
	Maillon * tmpMaillon;//Maillon pour parcourir les coupsValides
   
  
	minOptions=65;
	Coup->joueur=joueur;

	teteMaillon=NULL; 

	donneTousLesCoupsValides(p,joueur,&teteMaillon);//Rentre tout les coup valides dans la liste chainée
	tmpMaillon=teteMaillon;//Pour pouvoir parcourir la chaine

	 //________________________________
   	//|   Parcours de la liste chainée   |
	//__________________________________
   
	//Tant que le maillon est pas null 
	while(tmpMaillon!=NULL) 
	{
       // Duplication du Plateau
		dupliPlateau(p,&tmp);

		Ligne = tmpMaillon->coup.ligne;
		Colonne = tmpMaillon->coup.colonne;         
 
		printf("Test de la position: (%c %d)\n",Colonne+'a',Ligne+1);
       
		//On simule le coup sur le plateau dupliqué
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,tmp,Ligne,Colonne);
       
		if(joueur==1)
			minOptions_tmp=nbCoupsValides(tmp, 2);
		else
			minOptions_tmp=nbCoupsValides(tmp, 1);

		//On teste laquelle des deux variables est la plus petite
		if(minOptions_tmp < minOptions)
		{
			printf("Ce coup implique un plus faible nombre de possibilité pour l'adversaire : %d vs %d\n", minOptions, minOptions_tmp);
			minOptions=minOptions_tmp;
			Coup->ligne=Ligne;
			Coup->colonne=Colonne;
			printf("\n");
		}
		else
			printf("Ce coup implique un plus grand nombre de possibilité pour l'adversaire : %d vs %d\n", minOptions, minOptions_tmp);

		// Passage du maillon suivant 
		tmpMaillon = tmpMaillon->suivant;
	}; 

   free_Maillons(teteMaillon); //Liberation de tout les maillons
	
	return minOptions;   //renvoie le plus petit nombre de possibilités pour l'adversaire
}





/*
	Si l'ordinateur a la possibilité de jouer, on appelle la fonction qui cherche le coup laissant le moins de possibilités à son adversaire, puis on joue ce coup.	
*/
void tourCPUMinOptions(plateau p, int joueur)
{
	StrCoup * Coup;   

	if(existeCoupPourJoueur(p, joueur) == 0) 
		printf("Vous devez passer, joueur numero %d ! \nAppuyer sur une touche pour continuer\n",joueur);
	else
	{
		Coup=(StrCoup *) malloc(sizeof(StrCoup)); //Allocation liste chainé

		if(Coup == NULL)
			printf("Allocation de memoire dans tourCPU impossible\n"); 

	// Retient le meilleur coup possible dans la variable Coup

	printf("Nombre de possibilité pour l'adversaire retenu : %d\n",trouveCoupMinOptions(p,Coup,joueur));

	joueLeCoup(p,(Coup->ligne),(Coup->colonne),joueur);
	printf("Coup joué par l'ordi : (%c %d)\n", 'a'+Coup->colonne, Coup->ligne+1);
	free(Coup); //Liberation de la structure Coup
	}      
}

