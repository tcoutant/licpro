#include <stdio.h>
#include <stdlib.h>

#include "HumainVsHumain.h"
#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"





/*/////////////////////////////////
 /                                              
 /    Programme Principal
 /        
 /////////////////////////////////*/


int main()
{
	   
   int menu;
   int c;

   menu=proposeEtChoixMenu();   
     
    switch(menu)
	{
       case 1: // Le menu jouer a été choisi
         
           menu=proposeEtChoixModeDeJeu();
           
              switch(menu) 
              { 
                  case 1: // Le mode à 2 joueurs a été choisi
                     	HumainVsHumain();
<<<<<<< HEAD
						main();
=======
			main();
>>>>>>> 395ea5cb379e2cd17ab7ce560c6d66f2c0884593
                  break;

                  case 2: // mode 1 joueur contre l'ordi a été choisi
                     	menu=proposeEtChoixNiveauDeJeu();
						switch(menu)
						{
						   case 1: // niveau debutant, ordi random

						   break;

						   case 2: // niveau moyen
									JoueurvsCPUMaxPions();//-------------------->Thomas
						   break;

						   case 3: // niveau experimenté
						   break;

						   case 4: // niveau expert
						   break;
						}

<<<<<<< HEAD
=======
			   case 4: // niveau expert
			   break;
			}
		   
>>>>>>> 395ea5cb379e2cd17ab7ce560c6d66f2c0884593
                  break;
  
                  case 3: // retour au menu principal
						main();
		  
                  break;
		
               }
           
           break;
  
<<<<<<< HEAD
		case 2: // menu affichage des regles a été choisi
			printf("\n\n\n");
			printf(" But du jeu :\n");
			printf("\n");
			printf(" Avoir plus de pions de sa couleur que l'adversaire à la fin de la partie. \n");
			printf(" Celle-ci s'achève lorsque aucun des joueurs ne peut plus jouer de coup légal.\n");
			printf(" Cela intervient généralement lorsque les 64 cases sont occupées.\n");
			printf("\n");
			printf(" La pose d'un pion :\n");
			printf("\n");
			printf(" A son tour de jeu, le joueur doit poser un pion de sa couleur \n");
			printf(" sur une case vide de l'othellier, adjacente à un pion adverse.\n");
			printf(" Il doit également, en posant son pion, encadrer un ou plusieurs pions adverses\n");
			printf(" entre le pion qu'il pose et un autre pion de sa couleur déjà placé sur l'othellier.\n");
			printf(" Il retourne alors de sa couleur le ou les pions qu'il vient d'encadrer.\n");
			printf(" Les pions ne sont ni retirés de l'othellier, ni déplacés d'une case à l'autre.\n");
			printf("\n\n\n");
			printf(" tapez 1 puis Entrée pour revenir au menu...\n");

		       scanf("%d",&c);
			while(c!=1)
				scanf("%d",&c);
			main();
			break;

		case 3: // menu affichage des auteurs a été choisi

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t______________________________________________________\n");
			printf("\t|                                                    |\n");
			printf("\t|   stage tutoré dans le cadre de la licence pro     |\n");
			printf("\t|       université d'Angers    octobre 2012          |\n");
			printf("\t______________________________________________________\n");
			printf("\n\n\n");
			printf("\t---------------------Jeu othello----------------------\n\n");
			printf("\tSources d'appui de: Vincent Spiewak et Allaedine Elbanna\n");
			printf("\n");
			printf("\treprit par: Thomas Fraquet, Florent Guibert, Thierry Coutant\n");
			printf("\n\n\n\n\n\n\n");
			printf("\ttapez 1 puis Entrée pour revenir au menu...\n");
=======
       case 2: // menu affichage des regles a été choisi
printf("\n\n\n");
printf("   But du jeu :\n");
printf("\n");
printf(" Avoir plus de pions de sa couleur que l'adversaire à la fin de la partie.   \n");
printf(" Celle-ci s'achève lorsque aucun des joueurs ne peut plus jouer de coup légal.\n");
printf(" Cela intervient généralement lorsque les 64 cases sont occupées.\n");
printf("\n");
printf("   La pose d'un pion :\n");
printf("\n");
printf(" A son tour de jeu, le joueur doit poser un pion de sa couleur \n");
printf(" sur une case vide de l'othellier, adjacente à un pion adverse.\n");
printf(" Il doit également, en posant son pion, encadrer un ou plusieurs pions adverses\n");
printf(" entre le pion qu'il pose et un autre pion de sa couleur déjà placé sur l'othellier.\n");
printf(" Il retourne alors de sa couleur le ou les pions qu'il vient d'encadrer.\n");
printf(" Les pions ne sont ni retirés de l'othellier, ni déplacés d'une case à l'autre.\n");
printf("\n\n\n");
printf("   tapez 1 puis Entrée pour revenir au menu...\n");

           scanf("%d",&c);
	   while(c!=1)
	   	scanf("%d",&c);
  	   main();
           break;

       case 3: // menu affichage des auteurs a été choisi

           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
           printf("______________________________________________________\n"); 
     	   printf("|     stage tutoré dans le cadre de la licence pro    |\n");
	   printf("|          université d'Angers    octobre 2012        |\n");
     	   printf("______________________________________________________\n");
           printf("\n\n\n");
           printf("                      Jeu othello\n\n");
	   printf("   Sources d'appui de: Vincent Spiewak et Allaedine Elbanna\n");
	   printf("\n");
           printf("   reprit par: Thomas Fraquet, Florent Guibert, Thierry Coutant\n");
           printf("\n\n\n\n\n\n\n");
           printf("tapez 1 puis Entrée pour revenir au menu...\n");
	   
	   scanf("%d",&c);
	   while(c!=1)
	   	scanf("%d",&c);
           main();

           break;
main();
       case 4: //menu quitter le jeu a été choisi
>>>>>>> 395ea5cb379e2cd17ab7ce560c6d66f2c0884593
	   
	   		scanf("%d",&c);
			while(c!=1)
				scanf("%d",&c);
			main();
		break;
	main();

		case 4: //menu quitter le jeu a été choisi	   
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Au revoir ...\n");
			printf("\n\n\n");
		break;
   }
<<<<<<< HEAD
=======
	
>>>>>>> 395ea5cb379e2cd17ab7ce560c6d66f2c0884593
	return 0;
}
