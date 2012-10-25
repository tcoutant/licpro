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

	printf("Nombre de pions\nJoueur1: %d\nJoueur2: %d\n",pion1,pion2);
	
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
	int ecart_tmp,ecart;
	int Ligne,Colonne;


	plateau tmp;//Plateau temporaire pour tester les differents coups

	Maillon * teteMaillon;//Maillon pour avoir les coupsValides
	Maillon * tmpMaillon;//Maillon pour parcourir les coupsValides
   
  
	ecart=-70;
	Coup->joueur=joueur;

	teteMaillon=NULL; 

	donneTousLesCoupsValides(p,joueur,&teteMaillon);//Rentre tout les coup valides dans la liste chainée
	tmpMaillon=teteMaillon;//Pour pouvoir parcourir la chaine

	 /*********************************\
   	|   Parcours de la liste chainée   |
	\*********************************/
   
	/* Tant que le maillon est pas null */
	while(tmpMaillon!=NULL) 
	{
       /* Duplication du Plateau*/
		dupliPlateau(p,&tmp);

		Ligne = tmpMaillon->coup.ligne;
		Colonne = tmpMaillon->coup.colonne;         
 
		printf("Test de la position: (%c;%d)\n",Colonne+'a',Ligne+1);
       
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,tmp,Ligne,Colonne);
         
       // afficherPlateau(tmp);
       

		ecart_tmp=ecartPions(tmp);

		printf("résultat: écart:%d écart_tmp:%d\n",ecart,ecart_tmp);

		if(ecart < ecart_tmp)
		{
			printf("Ce coup implique un plus gros écart\n");
			ecart=ecart_tmp;
			Coup->ligne=Ligne;
			Coup->colonne=Colonne;
			printf("\n");
		}
		else 
			printf("\n");

		/* Passage du maillon suivant */
		tmpMaillon = tmpMaillon->suivant;
	}; 

   free_Maillons(teteMaillon); //Liberation de tout les maillons
	
	return ecart;   //renvoie le plus grand nombre d'ecart de point possible entre les deux joueurs
}


/*	Si l'ordinateur a la possibilité de jouer, on appelle la fonction qui cherche le coup prenant le plus de pions à son adversaire, puis on joue ce coup.	*/
void tourCPUMaxPions(plateau p, int joueur)
{
	StrCoup * Coup;   

	if(existeCoupPourJoueur(p, joueur) == 0) 
		printf("Vous devez passer, joueur numero %d ! \n",joueur);
	else
	{
		Coup=(StrCoup *) malloc(sizeof(StrCoup)); //Allocation liste chainé

		if(Coup == NULL)
			printf("Allocation de memoire dans tourCPU impossible\n"); 

	/* Retient le meilleur coup possible dans la variable Coup */

	printf("Ecart retenu apres coup: %d\n",trouveCoupMaxPions(p,Coup,joueur));

	joueLeCoup(p,(Coup->ligne),(Coup->colonne),joueur);
	printf("Coup aléatoire joué par l'ordi : (%c %d)\n", 'a'+Coup->colonne, Coup->ligne+1);

	free(Coup); //Liberation de la structure Coup
	}      
}
