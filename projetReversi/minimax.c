/******************************************************************************
 *     name:  minimax.c
 *   author:  Vincent Spiewak & Allaedine Elbanna    
 *    login:  2351994 
 *   groupe:  6
 *   last modif : 18/03/2005 18:07 
 *   
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include <limits.h>
#include "evaluation.h"
#include "regles.h"
#include "othello.h"
#include "representation.h"


char * mystrdup(char * s, int taille)
{  
   int i;
   char * c;

   c=(char *)malloc(sizeof(char)*taille);

   for(i=0;i<taille;i++)
      *(c+i)=*(s+i);
  
   return c;  
} 




/*******************************************************************
 *                                                 
 *    Nom : trouveCoupQuiMaximise(char -grille, StrCoup +coup)
 *                          
 * Entrée : char -grille, 
 *          StrCoup +coup
 *
 * Sortie : rend l'evaluation de la position
 *
 *          Modifie la variable coup pour donné les coordonnées 
 *          de la case où noirs doit jouer pour maximiser la fonction
 *          d'evaluation evalue(char -grille)
 *        
 ******************************************************************/

float trouveCoupQuiMaximise(char * grille, StrCoup * Coup)
{
   float eval_tmp,eval;
   int i,j;
   char Camp;
   char * tmp_grille;
   Maillon * teteMaillon;
   Maillon * courantMaillon;
   
  
   eval=-FLT_MAX; 
   Camp='x'; 
   Coup->camp=Camp;

   teteMaillon=NULL; 


   donneTousLesCoupsValides(grille,Camp,&teteMaillon);
   courantMaillon=teteMaillon;

    

   /************************************
    *  
    *   Parcours de la liste chainée
    *
    ************************************/
   
   
   /* Tant que le maillon a un suivant */
   while(courantMaillon) 
   {                 
       
       
       /* Duplicata de la grille */
       tmp_grille = mystrdup(grille,DIMENSION_MAX*DIMENSION_MAX);
       
       if(!tmp_grille) 
       {
          printf("malloc null: tmp_grille, trouveCoupQuiMaximise\n"); 
          exit(1);
       }

       i=courantMaillon->coup.ligne; 
       j=courantMaillon->coup.colonne;         
 
       
       printf("Maximise: Evaluation de la position: (%c %i)\n",
       j+'a',i+1);      
       
       *(tmp_grille+(i*DIMENSION_MAX)+j)=Camp;
       retournePions(Camp,tmp_grille,i,j);
         
       /* afficheOthellier(tmp_grille); */
       

       eval_tmp=evalue(tmp_grille);
       printf("Maximise: Resultat: eval:%f eval_tmp:%f\n",eval,eval_tmp);

       if(eval<eval_tmp)
       {
          printf("Maximise: Ce coup est meilleur\n");
          eval=eval_tmp;
          Coup->ligne=i;
          Coup->colonne=j;
          printf("\n");
       } else printf("\n");

       /* Suppression du duplicata */
       free(tmp_grille);

       /* on passe au maillon suivant */
       courantMaillon=courantMaillon->suivant;

   }; 

   free_Maillons(teteMaillon);
   
   return eval;    

}







/*******************************************************************
 *                                                 
 *    Nom : trouveCoupQuiMinimise(char -grille, StrCoup +coup)
 *                          
 * Entrée : char -grille, 
 *          StrCoup +coup
 *
 * Sortie : rend l'evaluation de la position
 *
 *          Modifie la variable coup pour donné les coordonnées 
 *          de la case où blanc doit jouer pour minimiser la fonction
 *          d'evaluation evalue(char -grille)
 *        
 ******************************************************************/

float trouveCoupQuiMinimise(char * grille, StrCoup * Coup)
{
   float eval_tmp,eval;
   int i,j;
   char Camp;
   char * tmp_grille;
   Maillon * teteMaillon;
   Maillon * courantMaillon;
   
  
   eval=FLT_MAX; 
   Camp='o'; 
   Coup->camp=Camp;

   teteMaillon=NULL; 

   donneTousLesCoupsValides(grille,Camp,&teteMaillon);
   courantMaillon=teteMaillon;

   

   /*****************************************
    *  
    *   Parcours de la liste chainée
    *
    *****************************************/

   
   
   /* Tant que le maillon a un suivant */
   while(courantMaillon) 
   {                 
      
       
       /* Duplicata de la grille */
       tmp_grille = mystrdup(grille,DIMENSION_MAX*DIMENSION_MAX);
       
       if(!tmp_grille){ 
          printf("malloc null: tmp_grille,trouveCoupQuiMaximise\n"); 
          exit(1);
       }

       
       i=courantMaillon->coup.ligne; 
       j=courantMaillon->coup.colonne;         
       
       
       *(tmp_grille+(i*DIMENSION_MAX)+j)=Camp;
       retournePions(Camp,tmp_grille,i,j);
          
       printf("Minimise: Evaluation de la position: (%c %i)\n",
                                               j+'a',
                                               i+1);
              
       /* afficheOthellier(tmp_grille); */
       
       eval_tmp=evalue(tmp_grille);
       printf("Minimise: Resultat: eval:%f eval_tmp:%f\n",eval,eval_tmp);

       if(eval>eval_tmp)
       {
          printf("Minimise: Ce coup est meilleur\n");
          eval=eval_tmp;
          Coup->ligne=i;
          Coup->colonne=j;
          printf("\n");

       } else printf("\n");

       /* Suppression du duplicata */
       free(tmp_grille);

       /* on passe au maillon suivant */
       courantMaillon=courantMaillon->suivant;

   }; 

   free_Maillons(teteMaillon);
   return eval;    

}






float trouveCoupMinimax(char * grille, char camp, int prof, StrCoup * coup)
{
   float evalMeilleur;
   float eval_tmp;
   int i,j;
   char * tmp_grille;
   Maillon * teteMaillon;
   Maillon * courantMaillon;

   StrCoup * tmp_coup;

   if(camp=='x') 
      evalMeilleur=-FLT_MAX;
   else 
      evalMeilleur=FLT_MAX; 


   if(prof==1)
   {
            
      if(camp=='o')
         evalMeilleur=trouveCoupQuiMinimise(grille,coup);
      else
         evalMeilleur=trouveCoupQuiMaximise(grille,coup);

      printf("MiniMax: eval Meilleur: %f\n",evalMeilleur); 
           
   }
   /* Si la profondeur est != a 1 */
   else
   {
         
         teteMaillon=NULL; 
         donneTousLesCoupsValides(grille,camp,&teteMaillon);
         courantMaillon=teteMaillon;

         while(courantMaillon) 
         {
       
          tmp_coup=(StrCoup*)malloc(sizeof(StrCoup));

          /* Duplicata de la grille */
          tmp_grille = mystrdup(grille,DIMENSION_MAX*DIMENSION_MAX);

          if(!tmp_grille) 
          {
             printf("malloc null: tmp_grille, trouveCoupMinimax\n"); 
             exit(1);
          }  


          i=courantMaillon->coup.ligne; 
          j=courantMaillon->coup.colonne;                    
                                              
          /* Je joue le Coup donner en entree i,j dans tmp_grille */
          *(tmp_grille+(i*DIMENSION_MAX)+j)=camp;
          retournePions(camp,tmp_grille,i,j); 

          printf("\n\n\n\n");
          printf("MiniMax: (prof:%i)",prof);
          printf("MiniMax: Evaluation de la position: (%c %i)\n",
                                                  j+'a',
                                                  i+1);

          /* Si le l'adversaire ne peux pas jouer */
          if(!existeCoupPourCamp(tmp_grille,adversaire(camp))) 
          {
             printf("MiniMax: %c ne peux pas jouer\n",adversaire(camp));
             eval_tmp=evalue(tmp_grille); 
             printf("MiniMax: eval_tmp: %f\n",eval_tmp);
          }
          else
          {
             
             eval_tmp=trouveCoupMinimax(tmp_grille,
                                        adversaire(camp),
                                        prof-1,
                                        tmp_coup);

             printf("MiniMax: eval_tmp: %f\n",eval_tmp);
          } 

          if(camp=='x')
          {
             if(eval_tmp>evalMeilleur)
             {   
                evalMeilleur=eval_tmp;
                coup->ligne=i;
                coup->colonne=j;
                printf("MiniMax: Ce coup maximise + que le precedent\n");
             }
          }
          else
          {
             if(eval_tmp<evalMeilleur)
             {
                evalMeilleur=eval_tmp;
                coup->ligne=i;
                coup->colonne=j;
                printf("MiniMax: -->Ce coup minimise + que le precedent\n");
             }
          }

          /* Suppression du duplicata */
          free(tmp_grille);
          free(tmp_coup);
          
          /* on passe au maillon suivant */
          courantMaillon=courantMaillon->suivant;  
         

       } /* fin while */     
      
      free_Maillons(teteMaillon);

   } /* fin if */


   return evalMeilleur;    
   
}
