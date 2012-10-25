#include <stdio.h>
#include <stdlib.h>



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
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("______________________________________________________\n"); 
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
      printf("Faite votre choix puis appuyer sur Entrée...\n");
      scanf("%i",&choix);
      //videStdin();
   } 
   while(choix<1 || choix>4);
   
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
      printf("|              Menu choix du type de jeu             |\n");
      printf("______________________________________________________\n");
      printf("\n");
      printf("         1 - à 2 joueurs \n");
      printf("\n");
      printf("         2 - un joueur contre l'ordinateur \n");
      printf("\n");
      printf("         3 - Retour au Menu Principal\n");
      printf("\n\n\n\n\n\n"); 
      printf("Faite votre choix puis appuyer sur Entrée...\n");
      scanf("%i",&mode);
      //videStdin();
   } 
   while(mode<1 || mode>3);
   
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
      printf("______________________________________________________\n"); 
      printf("|             Menu choix du niveau de jeu            |\n");
      printf("______________________________________________________\n");
      printf("\n");
      printf("         1 - Niveau débutant, facile \n");
      printf("\n");
      printf("         2 - Niveau moyen \n");
      printf("\n");
      printf("         3 - Niveau expérimenté\n");
      printf("\n");
      printf("         4 - Niveau expert\n");
      printf("\n\n\n\n\n\n"); 
      printf("Faite votre choix puis appuyer sur Entrée...\n");
      scanf("%i",&niveau);
      //videStdin();

   } while(niveau<1 || niveau>4);
   
   return niveau;
}

/*void videStdin()
{

     char c;
     c = getchar();

     if (c != '\n')
       while ( (getchar()) != '\n'); 
 
}
*/

/*/////////////////////////////////
 /                                              
 /    Programme Principal
 /        
 /////////////////////////////////*/


int main(void)
{ 
   
   int menu;
   int c;

   menu=proposeEtChoixMenu();   
     
    switch(menu) {

       case 1: // menu jouer a été choisi
         
           menu=proposeEtChoixModeDeJeu();
           
              switch(menu) 
              { 
		 
                  case 1: // mode à 2 joueurs a été choisi
                     //joueHumainHumain();
                  break;

                  case 2: // mode 1 joueur contre l'ordi a été choisi
                     menu=proposeEtChoixNiveauDeJeu();

			switch(menu)
			{
			   case 1: // niveau debutant
				//joueHumainVsCPU('o');

			   break;

			   case 2: // niveau moyen
			   break;

			   case 3: // niveau experimenté
			   break;

			   case 4: // niveau expert
			   break;
			}
		   main();
                  break;
  
                  case 3: // retour au menu principal
			main();
		  
                  break;

               }

           main();
           
           break;
  
       case 2: // menu affichage des regles a été choisi
	   printf("\n\n\n");
	   printf("     bientot ou plus tard les regles seront écrites\n");
           printf("\n\n\n");
	   printf("taper 1 puis Entrée pour revenir au menu...\n");

           scanf("%d",&c);
	   while(c!=1)
	   	scanf("%d",&c);
           main();
           break;

       case 3: // menu affichage des auteurs a été choisi

           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
           printf("______________________________________________________\n"); 
     	   printf("|     stage tutoré dans le cadre de la licence pro    |\n");
     	   printf("______________________________________________________\n");
           printf("\n\n\n");
           printf("                   Jeux d'othello\n\n");
	   printf("   Origines Sources: Vincent Spiewak et Allaedine Elbanna\n");
	   printf("\n");
           printf("   repris par: Thomas Fraquet, Florent Guibert, Thierry Coutant\n");
           printf("\n\n\n\n\n\n\n");
           printf("taper 1 puis Entrée pour revenir au menu...\n");
	   
	   scanf("%d",&c);
	   while(c!=1)
	   	scanf("%d",&c);
           main();

           break;

       case 4: //menu quitter le jeu a été choisi
	   
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
           printf("Au revoir ...\n");
	   printf("\n\n\n");
           break;
 
      
   }
   return 0; 

}
