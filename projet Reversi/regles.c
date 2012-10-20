/*****************************************************************************
 *       name :  othello.c
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 
 *   
 *****************************************************************************/


/*****************************************************************
 *                                                                                        
 *    Nom : faitPriseDansDirection(  int +dir,
 *                                   char +camp,
 *                                   char * +grille,  
 *                                   int +NumLigne, 
 *                                   int +NumColonne )
 *
 * Entrée : entier direction (de 0 a 7)
 *          char camp 
 *          pointeur representant la grille du jeu, 
 *          indice ligne, indice colonne (commencent a 0)
 * Sortie : entier valant 0 ou 1
 *
 *          rend vrai si fait une prise avec la position,
 *          le camp, et la direction donnée
 *  
 ***************************************************************/
 
#include <stdio.h>
#include "othello.h"
#include "evaluation.h"

int faitPriseDansDirection(int dir, char camp, char * grille, int NumLigne, int
NumColonne)
{

   int dL=0;
   int dC=0;
   
   switch(dir) {

     case 0:
        dL=-1;
     break;

     case 1:
        dL=-1;
        dC=1;
     break;

     case 2:
        dC=1;
     break;

     case 3:
        dL=1;
        dC=1;
     break;
  
     case 4:
        dL=1;
     break;

     case 5:
        dL=1;
        dC=-1; 
     break;

     case 6:
        dC=-1;
     break;

     case 7:
        dL=-1;
        dC=-1;
     break;

   }

    /*
     printf("faitPriseDansDirection-> dir:%i, L:%i, C:%i dL:%i dC:%i\n",dir,NumLigne,NumColonne,dL,dC);
   */

       NumLigne+=dL; 
       NumColonne+=dC;

    /*
       Si le pion accoler au coup n'est pas du camp adverse on arrete
    */

    if(
           NumLigne>=DIMENSION_MAX 
        || NumColonne>=DIMENSION_MAX          
        || NumLigne<0 
        || NumColonne<0
        || donneContenuDeCase(grille,NumLigne,NumColonne)==camp 
        || donneContenuDeCase(grille,NumLigne,NumColonne)=='-'
      )
       {

    /*
     printf("Sortie avant le while\n");
    */
         return 0;  
       }
   else
   {

       
       while( NumLigne<DIMENSION_MAX 
              && NumColonne<DIMENSION_MAX 
              && NumLigne>=0 
              && NumColonne>=0 
              && donneContenuDeCase(grille,NumLigne,NumColonne)!=camp 
              && donneContenuDeCase(grille,NumLigne,NumColonne)!='-'   
              
            )
        {

          NumLigne+=dL; 
          NumColonne+=dC;
         /* printf("1 pions ... "); */

       }

    /*
     printf("faitPriseDansDirection-> dir: %i, Case d'arret: (%i,%i), valeur: %i\n",
      dir,
      NumLigne,
      NumColonne,
      donneContenuDeCase(grille,NumLigne,NumColonne)==camp
          );
     */

       if(
              NumLigne>=DIMENSION_MAX
           || NumColonne>=DIMENSION_MAX  
           || NumLigne<0 
           || NumColonne<0
         )
          {  /* printf("Sorti\n");  */
            
            return 0;

          } else  
          {  
              /* printf("dans le test contenu case\n");  */
            
            return (donneContenuDeCase(grille,NumLigne,NumColonne)==camp);
          }

   }

}






/*******************************************************************
 *                                                    
 *    Nom : faitPrise(  char +camp,
 *                      char * +grille,  
 *                      int +NumLigne, 
 *                      int +NumColonne )
 *
 * Entrée : char camp 
 *          pointeur representant la grille du jeu, 
 *          indice ligne, indice colonne (commencent a 0)
 * Sortie : entier valant 0 ou 1
 *
 *          rend vrai si fait au moins une prise avec la position
 *          et le camp donné dans toutes les directions
 *  
 ******************************************************************/

int faitPrise(char camp, char * grille, int NumLigne, int NumColonne)
{
    int i,cpt_tmp; 
    int cpt=0;

    for(i=0;i<8;i++)
    {

        cpt_tmp=faitPriseDansDirection(i,camp,grille,NumLigne,NumColonne);
        cpt+=cpt_tmp;
    }

    return (cpt!=0);
   
}





/*******************************************************************
 *                                                      regles
 *    Nom : int coupValide(   char +camp, 
                              char * +grille, 
                              int +NumLigne, 
                              int +NumColonne)
 *
 * Entrée : char camp 
 *          pointeur representant la grille du jeu, 
 *          indice ligne, indice colonne (commencent a 0)
 * Sortie : entier valant 0 ou 1
 *
 *          rend vrai si le joueur peut joueur sur la case
 *         
 *  
 ******************************************************************/

int coupValide(char camp, char * grille, int NumLigne, int NumColonne)
{
   
   return (   faitPrise(camp,grille,NumLigne,NumColonne)
            && (donneContenuDeCase(grille,NumLigne,NumColonne)=='-')
          );
}






/*******************************************************************
 *                                                        regles
 *    Nom : int retournePionsDansDirection(   int +dir,
 *                                            char +camp, 
 *                                            char * +grille, 
 *                                            int +NumLigne, 
 *                                            int +NumColonne
 *                                        )
 *
 * Entrée : int dir (de 0 a 7) 
 *          char camp 
 *          pointeur representant la grille du jeu, 
 *          indice ligne, indice colonne (commencent a 0)
 * Sortie : entier valant 0 ou 1
 *
 *          modifie grille en retournant les pions pour un
 *          coup joué dans une direction donnée et 
 *          renvoi le nombre de pions retournés.
 *        
 ******************************************************************/

int retournePionsDansDirection(int dir, char camp, char * grille, int NumLigne, int NumColonne)
{
   int cpt=0;
   int dL=0;
   int dC=0;
   
   switch(dir) {

     case 0:
        dL=-1;
     break;

     case 1:
        dL=-1;
        dC=1;
     break;

     case 2:
        dC=1;
     break;

     case 3:
        dL=1;
        dC=1;
     break;
  
     case 4:
        dL=1;
     break;

     case 5:
        dL=1;
        dC=-1; 
     break;

     case 6:
        dC=-1;
     break;

     case 7:
        dL=-1;
        dC=-1;
     break;

   }  
    /*
    printf("retournePionsDansDirection(dir:%i,L:%i,C:%i,dL:%i,dC:%i)\n",dir,NumLigne,NumColonne,dL,dC);
   */

    if( !faitPriseDansDirection(dir,camp,grille,NumLigne,NumColonne) ) 
    return 0;
     

       NumLigne+=dL; 
       NumColonne+=dC;


    while(    donneContenuDeCase(grille,NumLigne,NumColonne)!=camp 
           && donneContenuDeCase(grille,NumLigne,NumColonne)!='-'   
           && NumLigne<DIMENSION_MAX
           && NumColonne<DIMENSION_MAX           
           && NumLigne>=0   
           && NumColonne>=0 
         )
     {

       *(grille+(NumLigne*DIMENSION_MAX)+NumColonne)=camp;
       cpt++;

       NumLigne+=dL; 
       NumColonne+=dC;

    }


    return cpt--; 

}








/*******************************************************************
 *                                                           regles
 *    Nom : int retournePions( 
 *                              char +camp, 
 *                              char * +grille, 
 *                              int +NumLigne, 
 *                              int +NumColonne
 *                           )
 *
 * Entrée : char camp 
 *          pointeur representant la grille du jeu, 
 *          indice ligne, indice colonne (commencent a 0)
 *
 * Sortie : entier valant 0 ou 1
 *
 *          modifie grille en retournant les pions pour un
 *          coup joué dans toutes les directions et
 *          renvoi le nombre de pions retournés.
 *        
 ******************************************************************/

int retournePions(char camp, char * grille, int NumLigne, int NumColonne)
{
    int i; 
    int cpt=0;
    int cpt_tmp;
    
    for(i=0;i<8;i++)
    {
      /*
       printf("retournePions(dir:%i,%c,L:%i,C:%i)\n",i,camp,NumLigne,NumColonne);
      */
      cpt_tmp=retournePionsDansDirection(i,camp,grille,NumLigne,NumColonne);
      cpt+=cpt_tmp;
    }
    return cpt;
   
}






