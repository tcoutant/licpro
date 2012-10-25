/* cat toto | ./othello | cat > tutu */


/*****************************************************************************
 *       name :  representation.c
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 
 *   
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "othello.h"
#include "representation.h" 
#include "regles.h" 




void free_Maillons(Maillon * teteMaillon)
{
   Maillon * suivantMaillon;
   Maillon * courantMaillon;
   courantMaillon=teteMaillon;
   
   if(!courantMaillon) return;

   while(courantMaillon) 
   { 
     printf("free maillon: %p\n",courantMaillon);

     suivantMaillon=courantMaillon->suivant;
     free(courantMaillon);
     courantMaillon=suivantMaillon;    
     
   } 
 
}


void videStdin()
{

     char c;
     c = getchar();

     if (c != '\n')
       while ( (getchar()) != '\n'); 
 
}



/***************************************************************************
 *                                                          representation
 *    Nom : void initialiseGrilleDepart(int +taille)
 * Entrée : taille de la grille
 * Sortie : aucune
 *        
 *          Définit la grille de départ du jeu en fonction
 *          de la taille demandée et positionne les pions sur la grille
 *  
 ***************************************************************************/

void initialiseGrilleDepart(char * grille)
{
  
   int i,j;
   
   for(i=0;i<DIMENSION_MAX;i++)
      for(j=0;j<DIMENSION_MAX;j++)
          *(grille+(i*DIMENSION_MAX)+j)='-';
         
   *(grille+(((DIMENSION_MAX/2)-1)*DIMENSION_MAX)+((DIMENSION_MAX/2)-1))='o';
   *(grille+((DIMENSION_MAX/2)*DIMENSION_MAX)+(DIMENSION_MAX/2))='o';
   *(grille+(((DIMENSION_MAX/2)-1)*DIMENSION_MAX)+(DIMENSION_MAX/2))='x';
   *(grille+((DIMENSION_MAX/2)*DIMENSION_MAX)+((DIMENSION_MAX/2)-1))='x';
}






/*****************************************************************
 *
 *    Nom : void afficheOthellier(char +grille)   (representation)
 * Entrée : pointeur representant la grille du jeu
 * Sortie : aucune
 *
 *          Affichage de l'Othellier 
 *  
 ***************************************************************/

void afficheOthellier(char * grille)
{

   int i,j;
   
   printf("\n");
   
   printf("      ");

   for(i=0; i<DIMENSION_MAX ;i++)     
       printf("  %c ",i+'a');
   printf("\n");

   for(i=0;i<DIMENSION_MAX;i++)
   {
      
      printf("      ");
      
      for(j=0; j<DIMENSION_MAX ;j++)     
        printf("+---");
      printf("+\n");      

      printf("    %i ",i+1);
      
      for(j=0;j<DIMENSION_MAX;j++)
        if(*(grille+(i*DIMENSION_MAX)+j)!='-')
           printf("| %c ", *(grille+(i*DIMENSION_MAX)+j));    
        else printf("|   ");    
      printf("|\n");  

   }

      printf("      ");
      for(j=0; j<DIMENSION_MAX ;j++)     
        printf("+---");
      printf("+\n");   
   
      printf("\n");
}






/*******************************************************************
 *                                                      representation
 *    Nom : void saisiUnCoup(
 *                            char +camp, 
 *                            int -NumLigne,
 *                            int -NumColonne
 *                          )
 *                          
 * Entrée : char +camp, 
 *          int -NumLigne,
 *          int -NumColonne
 *
 * Sortie : void
 *
 *          Saisie un coup, valide ou pas  
 *        
 ******************************************************************/

void saisiUnCoup(char camp, int * NumLigne, int * NumColonne)
{

      char tmp[4];

      printf("Veuillez entrez un coup %c (format: a 1,...,h 8)\npuis appuyer sur Entrée\n",camp);

      fgets(tmp, sizeof tmp, stdin);

      *NumLigne=tmp[2]-'0'-1;
      *NumColonne=tmp[0]-'a';
      
      videStdin();

}







/*******************************************************************
 *                                                    
 *    Nom : int donneTousLesCoupsValides(
 *                                          char * grille, 
 *                                          char camp,
 *                                          Maillon * teteMaillon
 *                                      )
 *                          
 * Entrée : char * grille,
 *          char camp,
 *          Maillon * teteMaillon
 *
 * Sortie : nombre de coups valides pour camp
 *
 *          Liste tous les coups valides pour camp 
 *          et les enregistrent dans la liste chainée
 *        
 ******************************************************************/

int donneTousLesCoupsValides(char * grille, char camp, Maillon ** teteMaillon)
{
   int i,j,cpt;
   Maillon * courantMaillon;
   Maillon * newMaillon;

   courantMaillon=NULL;
   cpt=0;


   for(i=0;i<DIMENSION_MAX;i++)
       for(j=0;j<DIMENSION_MAX;j++)
              if(coupValide(camp,grille,i,j))
              {                   

                 newMaillon=(Maillon *)malloc(sizeof(Maillon));
                 
                 if(!newMaillon)
                 { 
                    printf("malloc null: newMaillon,donneTousLesCoupsValides \n");
                    exit(1);              
                 }
                 
                 newMaillon->coup.ligne=i;
                 newMaillon->coup.colonne=j;
                 newMaillon->coup.camp=camp;

                 newMaillon->suivant=courantMaillon;             
                 courantMaillon=newMaillon;
                  
                 cpt++;

              }       

         *teteMaillon=courantMaillon;

   return cpt;
}
 
 




/*******************************************************************
 *                                                    
 *    Nom : char * donneStringCoupsValides(char -grille, char +camp)
 *                          
 * Entrée : char * grille, char camp
 *
 * Sortie : char * representant la liste des coups suivit de \0
 *
 *          Liste tous les coups valides pour camp 
 *          et les retournes dans un char *
 *        
 ******************************************************************/


char * donneStringCoupsValides(char * grille, char camp)
{
   
   Maillon * teteMaillon;
   Maillon * courantMaillon;
   char * coups;
   int index;


   teteMaillon=NULL;

   coups=(char *)malloc(sizeof(char)*1000);
   if(!coups)
   {
      printf("Alloc:null coups donneStringCoupsValides\n"); 
      exit(1);
   }
   
   index=0;
   
   
   printf("Il y a %i ",
   donneTousLesCoupsValides(grille,camp,&teteMaillon));
   
   courantMaillon=teteMaillon;

      
   while(courantMaillon) 
   { 
                     
      *(coups+index)='(';   index++;
      *(coups+index)=courantMaillon->coup.colonne+'a'; index++;  
      *(coups+index)=' ';   index++; 
      *(coups+index)=(courantMaillon->coup.ligne)+'1'; index++;
      *(coups+index)=')';   index++;  
      *(coups+index)=' ';   index++;

      courantMaillon=courantMaillon->suivant;

   } 

   *(coups+index)='\0';

   return coups; 
  
}





