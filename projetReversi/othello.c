/******************************************************************************
 *     name:  othello.c
 *   author:  Vincent Spiewak & Allaedine Elbanna    
 *    login:  2351994 
 *   groupe:  6
 *   last modif : 09/03/2005 16:31 
 *   
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "representation.h"
#include "evaluation.h"
#include "regles.h"
#include "othello.h"
#include "sauvegarde.h"
#include "minimax.h"



  int DIMENSION_MAX;  /* dimension de l'othellier égale à 4,6 ou 8
                         variable globale définie par l'utilisateur*/



void demandeDIMENSION_MAX()
{
   DIMENSION_MAX=0;

   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Entrez la dimension de l'othellier (4,6 ou 8)\n");
      scanf("%i",&DIMENSION_MAX);
      videStdin();

   } while(DIMENSION_MAX!=4 && DIMENSION_MAX!=6 && DIMENSION_MAX!=8);
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/*******************************************************************
 *                                                    othello
 *    Nom : void moteur(char -grille, char +camp)
 *                          
 * Entrée : char -grille, 
 *          char +camp
 *
 * Sortie : void
 *
 *          fait jouer un tour a un joueur
 *        
 ******************************************************************/

void moteur(char * grille, char camp,FeuillePartie * feuillepartie)
{
   int testL;
   int testC;
   char c;
   
   

   if(!existeCoupPourCamp(grille,camp)) 
   {
      printf("Vous devez passer %c ! :( \nAppuyer sur une touche pour continuer\n",camp);
      
      fgets(&c,1,stdin);
      

      videStdin();
    
      *(feuillepartie->lignes+feuillepartie->nbCoups)=-1;
      *(feuillepartie->colonnes+feuillepartie->nbCoups)=25;
      feuillepartie->nbCoups++;
     
   } 
   else
   {
      

      do 
      {  
         testL=DIMENSION_MAX;
         testC=DIMENSION_MAX;
         
         /* printf("avant appel L:%i, C:%i\n",testL,testC); */
   
         printf("CoupsValides: %s\n",donneStringCoupsValides(grille,camp)); 
         
         saisiUnCoup(camp,&testL,&testC);
        
         /* printf("apres appel L:%i, C:%i\n",testL,testC); */

      

      } while( 
                (   ( testL >= DIMENSION_MAX )
                 || ( testC >= DIMENSION_MAX )            
                 || ( testL < 0 )   
                 || ( testC < 0 ) 
                ) 
              || ( !coupValide(camp,grille,testL,testC) ) 
             );
         
        joueLeCoup(grille,testL,testC,camp);

        *(feuillepartie->lignes+feuillepartie->nbCoups)=testL;
        *(feuillepartie->colonnes+feuillepartie->nbCoups)=testC;
        feuillepartie->nbCoups++;
 
     

   }      
}



/*******************************************************************
 *                                                    othello
 *    Nom : void moteur(char -grille, char +camp)
 *                          
 * Entrée : char -grille, 
 *          char +camp
 *
 * Sortie : void
 *
 *          fait jouer un tour a un joueur
 *        
 ******************************************************************/

void moteurCPU(char * grille, char camp,FeuillePartie * feuillepartie)
{

   char c;
   StrCoup * Coup;   


   if(!existeCoupPourCamp(grille,camp)) 
   {
      printf("Vous devez passer %c ! :( \nAppuyer sur une touche pour continuer\n",camp);
      
      fgets(&c,1,stdin);
      videStdin();
    
      *(feuillepartie->lignes+feuillepartie->nbCoups)=-1;
      *(feuillepartie->colonnes+feuillepartie->nbCoups)=25;
      feuillepartie->nbCoups++;
     
   } 
   else
   {


        Coup=(StrCoup *) malloc(sizeof(StrCoup)); 
  
        if(Coup==NULL)
           printf("Allocation dans moteurCPU impossible\n"); 

        printf("Evaluation Retenue(max): %f\n",trouveCoupMinimax(grille,camp,3,Coup));

        joueLeCoup(grille,Coup->ligne,Coup->colonne,camp);

        *(feuillepartie->lignes+feuillepartie->nbCoups)=Coup->ligne;
        *(feuillepartie->colonnes+feuillepartie->nbCoups)=Coup->colonne;
        feuillepartie->nbCoups++;

        free(Coup);
        
   }      
}






/*******************************************************************
 *                                              
 *    Nom : void rejouePartie(
 *                              FeuillePartie +fp,
 *                              int +tailleOthellier
 *                           )
 *                          
 * Entrée : FeuillePartie +fp,
 *          int +tailleOthellier
 *
 * Sortie : void
 *
 *          rejoue la partie selon FeuillePartie
 *        
 ******************************************************************/

void rejouePartie(FeuillePartie fp,int tailleOthellier)
{

   char * GRILLE,
          camp,c;

   int po=0,
       px=0, 
       tmp_l,
       tmp_c,
       cpt=0;

   DIMENSION_MAX = tailleOthellier;


   GRILLE = (char *) malloc(DIMENSION_MAX*DIMENSION_MAX);

   initialiseGrilleDepart(GRILLE);
   afficheOthellier(GRILLE);



      printf("Appuyer sur Entrée pour lancer le replay...\n");
         fgets(&c,1,stdin);
         videStdin();

    do
    {
         


      if( (cpt%2)==0 )
         camp='x';
      else camp='o';
 
      tmp_l=*(fp.lignes+cpt);
      tmp_c=*(fp.colonnes+cpt);  
      
      if(tmp_l==-1 && tmp_c==25)
      {
         printf("%c passe son tour :(\n",camp);
         afficheOthellier(GRILLE);
      }
      else
      {
         printf("%c joue son le coup  %c %i\n",
               camp,tmp_c+'a',tmp_l+1);
         
         joueLeCoup(GRILLE,tmp_l,tmp_c,camp);
         
      }

    if(partieTerminee(GRILLE)) break;

         printf("Appuyer sur Entrée pour continuer...\n");
         fgets(&c,1,stdin);
         videStdin();

      cpt++;

   } while(!partieTerminee(GRILLE));

   printf("\n\n\n\n La Partie est terminée !\n");
   comptePions(GRILLE,&px,&po);
   printf("Le score est (o - x):  %i - %i\n\n\n",po,px);
 
   printf("Appuyer sur Entrée pour revenir au menu...\n");
   fgets(&c,1,stdin);
   videStdin();
 
   free(GRILLE);

}






/*******************************************************************
 *                                              
 *    Nom : void joueHumainHumain()
 *                          
 * Entrée : void
 *
 * Sortie : void
 *
 *          lance le mode Humain vs Humain
 *        
 ******************************************************************/

void joueHumainHumain()
{
   char *GRILLE;  
   int cpt_joueur=2,Px=0,Po=0; 
   FeuillePartie fp;

   demandeDIMENSION_MAX();

   fp.nbCoups=0;
   fp.lignes=(int *) malloc(sizeof(int)*((DIMENSION_MAX*DIMENSION_MAX)-4)); 
   fp.colonnes=(int *) malloc(sizeof(int)*((DIMENSION_MAX*DIMENSION_MAX)-4));
   

   GRILLE = (char *) malloc(DIMENSION_MAX*DIMENSION_MAX);
   initialiseGrilleDepart(GRILLE);
   afficheOthellier(GRILLE); 
 

                  
       do
       { 
          if( (cpt_joueur%2)==0 )
          moteur(GRILLE,'x',&fp);    
          else moteur(GRILLE,'o',&fp);
          cpt_joueur++;      

       } 
        while(!partieTerminee(GRILLE));
     


        printf("\n\n\n\n La Partie est terminée !\n");
        comptePions(GRILLE,&Px,&Po);
        printf("Le score est (o - x):  %i - %i\n",Po,Px);
 

       /* printf("Voulez-vous sauvegarder? (y/n)\n"); */



       /*
        * Test Sur la sauvegarde
        */
 
        sauvegardePartie(&fp,DIMENSION_MAX);
        /* rejouePartie(fp,DIMENSION_MAX); */

        /*
        * Fin test saauvegarde
        */  
        free(fp.lignes);
        free(fp.colonnes);
        free(GRILLE);

}





/*******************************************************************
 *                                              
 *    Nom : void joueHumainVsCPU()
 *                          
 * Entrée : void
 *
 * Sortie : void
 *
 *          lance le mode Humain vs CPU
 *        
 ******************************************************************/

void joueHumainVsCPU(char camp)
{
   char *GRILLE;  
   int cpt_joueur=2,Px=0,Po=0; 
   FeuillePartie fp;

   demandeDIMENSION_MAX();

   fp.nbCoups=0;
   fp.lignes=(int *) malloc(sizeof(int)*((DIMENSION_MAX*DIMENSION_MAX)-4)); 
   fp.colonnes=(int *) malloc(sizeof(int)*((DIMENSION_MAX*DIMENSION_MAX)-4));
   

   GRILLE = (char *) malloc(DIMENSION_MAX*DIMENSION_MAX);
   initialiseGrilleDepart(GRILLE);
   afficheOthellier(GRILLE); 
 

                  
       do
       { 
          if( (cpt_joueur%2)==0 )
          {
             if(camp=='x')
             moteurCPU(GRILLE,'x',&fp);    
             else moteur(GRILLE,'x',&fp);
          }
          else
          {
             if(camp=='o')
             moteurCPU(GRILLE,'o',&fp);    
             else moteur(GRILLE,'o',&fp);
          }
          
          cpt_joueur++;      

       } 
        while(!partieTerminee(GRILLE));
     


        printf("\n\n\n\n La Partie est terminée !\n");
        comptePions(GRILLE,&Px,&Po);
        printf("Le score est (o - x):  %i - %i\n",Po,Px);
 

       /* printf("Voulez-vous sauvegarder? (y/n)\n"); */



       /*
        * Test Sur la sauvegarde
        */
 
        sauvegardePartie(&fp,DIMENSION_MAX);
        /* rejouePartie(fp,DIMENSION_MAX); */



        free(fp.lignes);
        free(fp.colonnes);
        free(GRILLE);

        /*
        * Fin test saauvegarde
        */  

}





/*******************************************************************
 *                                              
 *    Nom : void joueCPUVsCPU()
 *                          
 * Entrée : void
 *
 * Sortie : void
 *
 *          lance le mode Humain vs CPU
 *        
 ******************************************************************/

void joueCPUVsCPU()
{
   char *GRILLE;  
   int cpt_joueur=2,Px=0,Po=0; 
   FeuillePartie fp;

   demandeDIMENSION_MAX();

   fp.nbCoups=0;
   fp.lignes=(int *) malloc(sizeof(int)*((DIMENSION_MAX*DIMENSION_MAX)-4)); 
   fp.colonnes=(int *) malloc(sizeof(int)*((DIMENSION_MAX*DIMENSION_MAX)-4));
   

   GRILLE = (char *) malloc(DIMENSION_MAX*DIMENSION_MAX);
   initialiseGrilleDepart(GRILLE);
   afficheOthellier(GRILLE); 
 

                  
       do
       { 
          if( (cpt_joueur%2)==0 )
          {
             
             moteurCPU(GRILLE,'x',&fp);    
         
          }
          else
          {
         
             moteurCPU(GRILLE,'o',&fp);    
         
          }
          
          cpt_joueur++;      

       } 
        while(!partieTerminee(GRILLE));
     


        printf("\n\n\n\n La Partie est terminée !\n");
        comptePions(GRILLE,&Px,&Po);
        printf("Le score est (o - x):  %i - %i\n",Po,Px);
 

       /* printf("Voulez-vous sauvegarder? (y/n)\n"); */



       /*
        * Test Sur la sauvegarde
        */
 
        sauvegardePartie(&fp,DIMENSION_MAX);
        /* rejouePartie(fp,DIMENSION_MAX); */

        /*
        * Fin test saauvegarde
        */  

        free(fp.lignes);
        free(fp.colonnes);
        free(GRILLE);

}



/*******************************************************************
 *                                              
 *    Nom : void rejouer()
 *                          
 * Entrée : void
 *
 * Sortie : void
 *
 *          lance le mode replay
 *        
 ******************************************************************/

void rejouer()
{
      int dimension;
      char nomfichier[100];
      FILE * fichier;    
      FeuillePartie fp;
       
      printf("Veuillez entrez le nom du fichier de sauvegarde à ouvrir\npuis appuyer sur Entrée\n");
  
      scanf("%s",nomfichier);
      videStdin();
     
      fichier=ouvreFichierLecture(nomfichier); 
      printf("Ouverture du fichier en lecture\n");


      fp.nbCoups=0;
      fp.lignes=(int *) malloc(sizeof(int)*60); 
      fp.colonnes=(int *) malloc(sizeof(int)*60);


      printf("Résultat de la lecture: %i\n",lecturePartie(fichier,&fp,&dimension));
      
      rejouePartie(fp,dimension);
     
      free(fp.lignes);
      free(fp.colonnes);
      
}





/*******************************************************************
 *                                              
 *    Nom : int choixMenu()
 *                          
 * Entrée : void
 *
 * Sortie : void
 *
 *          retourne le choix dans le menu principal
 *        
 ******************************************************************/

int choixMenu()
{
   int mode;
   mode=-1;
   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("######################################################\n"); 
      printf("################### Menu Principal ###################\n");
      printf("######################################################\n");
      printf("\n");
      printf("         1 - Jouer\n");
      printf("\n");
      printf("         2 - Replay\n");
      printf("\n");
      printf("         3 - A propos\n");
      printf("\n");
      printf("         4 - Quitter\n");
      printf("\n\n\n\n\n\n\n\n\n"); 
      printf("Faite votre choix puis appuyer sur Entrée...\n");
      scanf("%i",&mode);
      videStdin();

   } while(mode<1 || mode>4);
   
   return mode;
}






/*******************************************************************
 *                                              
 *    Nom : int choixMode()
 *                          
 * Entrée : void
 *
 * Sortie : void
 *
 *          retourne le choix du mode de jeux
 *        
 ******************************************************************/

int choixMode()
{
   int mode;
   mode=-1;
   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("######################################################\n"); 
      printf("#################### Choix du Mode ###################\n");
      printf("######################################################\n");
      printf("\n");
      printf("         1 - Humain Vs Humain \n");
      printf("\n");
      printf("         2 - Humain Vs CPU \n");
      printf("\n");
      printf("         3 - CPU Vs Humain\n");
      printf("\n");
      printf("         4 - CPU Vs CPU\n");
      printf("\n");
      printf("\n");
      printf("         5 - Retour au Menu Principal\n");
      printf("\n\n\n\n\n\n"); 
      printf("Faite votre choix puis appuyer sur Entrée...\n");
      scanf("%i",&mode);
      videStdin();

   } while(mode<1 || mode>5);
   
   return mode;
}





/*************************************************************
 *
 *   Fonction Principale du programme de Superviseur
 *
 *************************************************************/

int main(void)
{ 
   
   int menu;
   char c;
/*
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
   printf("                          ,%%%%%%%%%%%%%%,             \n");
   printf("                        ,%%%%/\\%%%%%%%%/\\%%,           \n");
   printf("                       ,%%%%%%\\c \"\" J/%%%%,          \n");
   printf("  %%.                   %%%%%%%%/ d  b \\%%%%%%          \n");
   printf("  `%%%%.         __      %%%%%%%%    _  |%%%%%%          \n");
   printf("   `%%%%      .-'  `\"~--\"`%%%%%%%%(=_Y_=)%%%%'          \n");
   printf("    //    .'     `.     `%%%%%%%%`\7/%%%%%%'____       \n");
   printf("   ((    /         ;      `%%%%%%%%%%%%%%'____)))      \n");
   printf("   `.`--'         ,'   _,`-._____`-,            \n");
   printf("     `\"\"\"`._____  `--,`  +-------`)))------+    \n");
   printf("                `~\"-)))  |                 |    \n");
   printf("                         |   Othello v1.0  |           \n");
   printf("                         |                 |           \n"); 
   printf("                         +-----------------+           \n"); 

   printf("\n\n\n\n\n\n\n");
   printf("Appuyer sur Entrée\n");
   fgets(&c,1,stdin);
   videStdin();
*/



   menu=choixMenu();   
     
    switch(menu) {

       case 1:
         /* test joueHumainVsCPU('o'); */

         /*  joueHumainHumain(); */
           menu=choixMode();
           
              switch(menu) 
              { 
                  case 1:
                     joueHumainHumain();
                  break;

                  case 2:
                     joueHumainVsCPU('o');
                  break;
  
                  case 3:
                     joueHumainVsCPU('x');
                  break;

                  case 4:
                     joueCPUVsCPU();
                     main(); 
                  break;

                  case 5:
                     main();
                  break; 
              }

           main();
           
           break;
  
       case 2:
           rejouer();
           main();
           
           break;

       case 3:

           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
           printf("######################################################\n"); 
           printf("###################### A propos ######################\n");
           printf("######################################################\n");
           printf("\n\n\n");
           printf("                   Jeux d'othello\n\n");
           printf("   Auteurs: Vincent Spiewak et Allaedine Elbanna\n");
           printf("   Version Optimisée pour un affichage 67x24 :)\n");
           printf("                   Copyright 2005\n");

           printf("\n\n\n\n\n\n\n\n\n");
           printf("Appuyer sur Entrée pour revenir au menu...\n");

           fgets(&c,1,stdin);
           videStdin();
          
           main();

           break;

       case 4:
           printf("Bye :) ...\n");
           break;
     
   }
   return 0;

}
