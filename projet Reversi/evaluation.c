/****************************************************************
 *
 *     author : Vincent Spiewak & Allaedine Elbanna
 *      login : 2351994
 *     groupe :  6 
 * last modif : 09/03/2005 19h00        
 *           
 *
 *****************************************************************/

#include "stdio.h"
#include "othello.h"
#include "representation.h"
#include "regles.h"



char adversaire(char camp)
{   
   if(camp=='o')
      return 'x'; 
   else 
      return 'o';
}


/*****************************************************************
 *                                                         
 *    Nom : char donneContenuDeCase(  char * +grille,
 *                                    int +NumLigne, int
 *                                    +NumColonne
 *                                 )
 * Entrée : pointeur representant la grille du jeu, 
 *           indice ligne, indice colonne (commencent a 0)
 * Sortie : char de la case 
 *
 *          donne le contenu de la case (NumLigne,NumColonne)
 *  
 ***************************************************************/

char donneContenuDeCase(char * grille, int NumLigne, int NumColonne)
{
  
  return *(grille+(NumLigne*DIMENSION_MAX)+NumColonne);
}






/*****************************************************************
 *                                                  
 *    Nom : int caseVide(  char * +grille,
 *                         int +NumLigne, 
 *                         int +NumColonne
 *                       )
 *
 * Entrée : pointeur representant la grille du jeu, 
 *           indice ligne, indice colonne (commencent a 0)
 * Sortie : entier valant 0 ou 1
 *
 *          rend vrai si la case est vide, faux sinon
 *  
 ***************************************************************/

int caseVide(char * grille, int NumLigne, int NumColonne)
{
   return *(grille+(NumLigne*DIMENSION_MAX)+NumColonne)=='-';
}




/*******************************************************************
 *                                                       
 *    Nom : comptePions(   
 *                        char +grille,
 *                        int +NbPionsX, 
 *                        int +NbPionsO
 *                     )
 *
 * Entrée : char * grille
 *          nb de pions X, 
 *          nb de pions O
 *
 * Sortie : void
 *
 *          Modifie les valeurs NbPionsX et NbPionsO
 *        
 ******************************************************************/

void comptePions(char * grille, int *NbPionsX, int *NbPionsO)
{
   int i,j;
   char tmp;

   for(i=0;i<DIMENSION_MAX;i++)
   {
      for(j=0;j<DIMENSION_MAX;j++)
      {
         tmp=donneContenuDeCase(grille,i,j);
         if(tmp=='x') (*NbPionsX)++;
         if(tmp=='o') (*NbPionsO)++;
      }
   }


}







/*******************************************************************
 *                                                      
 *    Nom : int existeCoupPourCamp( 
 *                                   char -grille,
 *                                   char +camp
 *                                )  
 *
 * Entrée : char * grille
 *          camp
 *
 * Sortie : 0 ou 1
 *
 *          rend vrai si le camp peut jouer, 0 sinon
 *        
 ******************************************************************/

int existeCoupPourCamp(char * grille,char camp)
{
   int i,j;
  /* int tmp=0; */

   
 

   for(i=0;i<DIMENSION_MAX;i++)
   {
      for(j=0;j<DIMENSION_MAX;j++)
      {
 
         if(coupValide(camp,grille,i,j))
         { 
 
             return 1;
         }
       
      }
   }

   return 0;

}




/*******************************************************************
 *                                                     
 *    Nom : void joueLeCoup(
 *                           char -grille,
 *                           int +NumLigne, 
 *                           int +NumColonne, 
 *                           char +camp
 *                         )
 * Entrée : char * grille
 *          indice de la ligne et de la colonne
 *          char du joueur
 *
 * Sortie : void
 *
 *          joue le coup a la position donnée,
 *          retourne les pion(s) 
 *          et affiche le nouvel othellier 
 *        
 ******************************************************************/

void joueLeCoup(char * grille, int NumLigne, int NumColonne, char camp)
{
      *(grille+(NumLigne*DIMENSION_MAX)+NumColonne)=camp;
      retournePions(camp,grille,NumLigne,NumColonne);
      afficheOthellier(grille);
}





/*******************************************************************
 *                                                   
 *    Nom : int partieTerminee(char -grille)  
 *
 * Entrée : char * grille
 *
 * Sortie : 0 ou 1
 *
 *          rend vrai si la partie est terminée
 *        
 ******************************************************************/

int partieTerminee(char * grille) 
{
   return !existeCoupPourCamp(grille,'x') && !existeCoupPourCamp(grille,'o'); 
}







/*******************************************************************
 *                                                   
 *    Nom : int valeurQuantitative(char -grille)  
 *
 * Entrée : char * grille
 *
 * Sortie : 0 ou 1
 *
 *          rend la différence du nombre de pions noir 
 *          moins le nombre de pions blancs
 *        
 ******************************************************************/

int valeurQuantitative(char * grille) 
{
   int px,po;
   px=po=1;
   comptePions(grille,&px,&po);
   printf("Nombre Pions x:%i o:%i\n",px,po);
   return (px-po);
  
}



/*******************************************************************
 *                                                   
 *    Nom : int evalue(char -grille)  
 *
 * Entrée : char * grille
 *
 * Sortie : 0 ou 1
 *
 *          Rend l'évaluation de la grille
 *        
 ******************************************************************/

float evalue(char * grille)
{
  
  return (float) valeurQuantitative(grille);
  
}



