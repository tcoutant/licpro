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


/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixMenu()
 /                           
 /    retourne le choix du menu principal
 /        
 /////////////////////////////////*/

int proposeEtChoixMenu()
{
   int choix;
   choix=-1;
   do
   {
      printf("\n\n\n");
      printf("______________________________________________________\n"); 
      printf("|                                                     |\n");
      printf("|            Menu Principal du jeu othello            |\n");
      printf("______________________________________________________\n");
      printf("\n");
      printf("         1 - Jouer\n");
      printf("\n");
      printf("         2 - Règles\n");
      printf("\n");
      printf("         3 - Auteurs\n");
      printf("\n");
      printf("         4 - Quitter\n");
      printf("\n\n\n"); 
      printf("   Faites votre choix puis appuyez sur Entrée...\n");
      scanf(" %i",&choix);
   }      while(choix<1 || choix>4);
   
   return choix;
}



/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixModeDeJeu()
 /                           
 /    retourne le choix du mode de jeux
 /        
 /////////////////////////////////*/

int proposeEtChoixModeDeJeu()
{
   int mode;
   mode=-1;
   do
   {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("______________________________________________________\n"); 
		printf("|                                                     |\n");
	 	printf("|              Menu choix du type de jeu             |\n");
		printf("______________________________________________________\n");
		printf("\n");
		printf("         1 - à 2 joueurs \n");
	 	printf("\n");
		printf("         2 - un joueur contre l'ordinateur \n");
		printf("\n");
		printf("         3 - Ordinateur contre Ordinateur\n");
		printf("\n");
		printf("         4 - Retour au Menu Principal \n");
		printf("\n");	
		printf("\n\n\n\n\n\n"); 
		printf("   Faites votre choix puis appuyez sur Entrée...\n");
		scanf("%i",&mode);
    }while(mode<1 || mode>3);
   
   return mode;
}


/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixNiveauDeJeu()                          
 / 
 /    retourne le niveau de jeux choisi
 /        
 /////////////////////////////////*/

int proposeEtChoixNiveauDeJeu()
{
   int niveau;
   niveau=-1;
   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("\t______________________________________________________\n"); 
      printf("\t|                                                     |\n");
      printf("\t|             Menu choix du niveau de jeu             |\n");
      printf("\t______________________________________________________\n");
      printf("\n");
      printf("\t1 - Niveau 'Random', réponse aléatoire de l'ordinateur \n");
      printf("\n");
      printf("\t2 - Niveau 'MaxPions',\nl'ordinateur joue le coup qui maximise le nombre de pièces prises à l'adversaire\n");
      printf("\n");
      printf("\t3 - Niveau 'MinOptions,\nl'ordinateur joue le coup qui minimise le nombre de possibilités de l'adversaire\n");
      printf("\n");
      printf("\t4 - Niveau expert, (en projet! l'ordi utilise minimax)\n");
      printf("\n\n\n\n\n\n"); 
      printf("   Faites votre choix puis appuyez sur Entrée...\n");
      scanf("%i",&niveau);
    } 	  while(niveau<1 || niveau>4);
   
   return niveau;
}




/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixNiveauDeJeu()                          
 / 
 /    retourne le niveau de jeux choisi
 /        
 /////////////////////////////////*/

int proposeEtChoixNiveauDeJeuCPUVsCPU(int num)
{
   int niveau;
   niveau=-1;
   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("\t______________________________________________________\n"); 
      printf("\t|                                                     |\n");
      printf("\t|             choix du niveau de l'Ordinateur %d       |\n", num);
      printf("\t______________________________________________________\n");
      printf("\n");
      printf("\t1 - Niveau 'Random', réponse aléatoire de l'ordinateur \n");
      printf("\n");
      printf("\t2 - Niveau 'MaxPions',\nl'ordinateur joue le coup qui maximise le nombre de pièces prises à l'adversaire\n");
      printf("\n");
      printf("\t3 - Niveau 'MinOptions,\nl'ordinateur joue le coup qui minimise le nombre de possibilités de l'adversaire\n");
      printf("\n");
      printf("\t4 - Niveau expert, (en projet! l'ordi utilise minimax)\n");
      printf("\n\n\n\n\n\n"); 
      printf("   Faites votre choix puis appuyez sur Entrée...\n");
      scanf(" %i",&niveau);
    } 	  while(niveau<1 || niveau>4);
   
   return niveau;
}

