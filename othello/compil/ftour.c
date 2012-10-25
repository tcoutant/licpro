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
	Regarde si le joueur a la possibilité de jouer, en appelant la fonction "coupValide"
*/
int existeCoupPourJoueur(plateau p,int joueur)
{
   int i,j;  
 
   for(i=0;i<DIM_MAX;i++)
   {
      for(j=0;j<DIM_MAX;j++)
      {
         if(coupValide(joueur,p,i,j)==1)
             return 1;
      }
   }
   return 0;
}
/*___________________________________________________________________________________*/


/*
	Regarde si l'un des deux joueurs peut jouer. Si aucun ne peut jouer, la partie est finie
	Utilise existeCoupPourJoueur
*/
int partieTerminee(plateau p)
{
   if ((existeCoupPourJoueur(p,1) == 0) && (existeCoupPourJoueur(p,2) == 0)) 
		return 1;
	else
		return 0;
}
/*____________________________________________________________________________________*/


/*
	Une fois le plateau rempli de pions, on le parcourt et incrémente le "NbPions" du bon joueur en fonction de la couleur de chaque case
*/
void comptePions(plateau p, int *NbPions1, int *NbPions2)
{
   int i,j;

   for(i=0;i<DIM_MAX;i++)
   {
      for(j=0;j<DIM_MAX;j++)
      {
         if(p[i][j]==1)
			(*NbPions1)++;
		else
			if(p[i][j] ==2)
				(*NbPions2)++;
      }
   }
}
/*____________________________________________________________________________*/


/*
	On pose la pièce sur le plateau (la case passe de vide à couleur).
	On appelle ensuite la fonction retournePions, qui retourne les pion qui sont prit lors du coup
	On affiche le nouveau plateau de jeu, avec les modifications
*/
void joueLeCoup(plateau p, int NumLigne, int NumColonne, int joueur)//Joue un coup
{
      p[NumLigne][NumColonne]=joueur;								//Retourne le pion avec la couleur du joueur

      retournePions(joueur,p,NumLigne,NumColonne);					//Appel de la fonction retournePions

      afficherPlateau(p);											//Affichage du plateau
}
/*________________________________________________________________________________*/


/*
	On regarde si le pion est posé sur une case vide ou non, et si oui, si la pose fait une prise.
	Si les deux conditions son OK, on retourne 1
	Sinon, on retourne 2
*/
int coupValide(int joueur, plateau p, int NumLigne, int NumColonne)
{
   
   if((faitPrise(joueur,p,NumLigne,NumColonne)==1) && (renvoieContenuCase(p,NumLigne,NumColonne)==0))
		return 1;
	else
		return 0;
}
/*__________________________________________________________________________________*/




/*
	On teste toutes les cases du tableau, et si un coup est valide, il crée un nouveau maillon dans une liste chainée, qui contient toutes les cases où l'on peut jouer
*/
int donneTousLesCoupsValides(plateau p, int joueur, Maillon ** teteMaillon)
{
   int i,j,cpt;
   Maillon * courantMaillon;
   Maillon * newMaillon;

   courantMaillon=NULL;
   cpt=0;


   for(i=0;i<DIM_MAX;i++)
       for(j=0;j<DIM_MAX;j++)
              if(coupValide(joueur,p,i,j)==1)
              {                   

                 newMaillon=(Maillon *)malloc(sizeof(Maillon));
                 
                 if(!newMaillon)
                 { 
                    printf("Allocation impossible de 'newMaillon' dans 'donneTousLesCoupsValides'\n");
                    exit(1);              
                 }
                 
                 newMaillon->coup.ligne=i;
                 newMaillon->coup.colonne=j;
                 newMaillon->coup.joueur=joueur;

                 newMaillon->suivant=courantMaillon;             
                 courantMaillon=newMaillon;
                  
                 cpt++;

              }       

         *teteMaillon=courantMaillon;
	printf("Il y a %d coups valides : ", cpt);
   return cpt;
}
/*______________________________________________________________________________*/




/*
	On demande à l'utilisateur de rentrer un coup, que l'on stocke dans les deux entiers passés en paramètre
*/
void saisiUnCoup(int joueur, int * NumLigne, int * NumColonne)
{
      char tmp[4];

	printf(" Saisissez une case pour le joueur numero %d (au format 'a 1')\n puis appuyez sur Entrée\n",joueur);
	fgets(tmp, sizeof tmp, stdin);

	*NumLigne=tmp[2]-'0'-1;
	*NumColonne=tmp[0]-'a';
}
/*____________________________________________________________________________*/



/*
	
*/
char * donneStringCoupsValides(plateau p, int joueur)
{
   
   Maillon * teteMaillon;
   Maillon * courantMaillon;
   char * coups;
   int index;


   teteMaillon=NULL;

   coups=(char *)malloc(sizeof(char)*1000);
   if(!coups)
   {
      printf("Allocation impossible de 'coups' dans 'donneStringCoupsValides'\n"); 
      exit(1);
   }
   
   index=0;
   
	donneTousLesCoupsValides(p,joueur,&teteMaillon);
   
   courantMaillon=teteMaillon;

      
   while(courantMaillon) 
   { 
                     
      *(coups+index)='(';   
		index++;
      *(coups+index)=courantMaillon->coup.colonne+'a'; index++;  
      *(coups+index)=' ';   
		index++; 
      *(coups+index)=(courantMaillon->coup.ligne)+'1'; index++;
      *(coups+index)=')';  
		index++;  
      *(coups+index)=' ';   
		index++;

      courantMaillon=courantMaillon->suivant;

   } 

   *(coups+index)='\0';

   return coups; 
  
}

/*______________________________________________________________________*/


/*
	Déroulement du tour d'un joueur
	On regarde si le joueur peut jouer, avec la fonction existeCoupPourJoueur
	Si oui, on liste tous les coups qu'il peut jouer
	On lui demande de saisir des coordonées
	On teste si les valeurs données sont correctes et si le coup est valide
	On joue le coup (retourne les pions qu'il faut....)
*/
void tourJoueur(plateau p, int joueur)
{
   int testL=-1;
   int testC=-1;
   
   if(!existeCoupPourJoueur(p,joueur)) 
      printf(" Le joueur numéro %d doit passer son tour !\n",joueur);
   else
   {
		while(((testL >= DIM_MAX )
			|| ( testC >= DIM_MAX )            
			|| ( testL < 0 )   
			|| ( testC < 0 ) ) 
			|| ( coupValide(joueur, p,testL,testC)==0 ) 
			) 
		{  
			testL=DIM_MAX;
			testC=DIM_MAX;
			printf("%s\n",donneStringCoupsValides(p, joueur)); 
			videStdin();
			saisiUnCoup(joueur,&testL,&testC);
		} 
		joueLeCoup(p,testL,testC,joueur);    
	}      
}
/*__________________________________________________________________________*/



/*
	Fonction ui dupliue un plateau, pour pouvoir tester des coups.
*/
void dupliPlateau(plateau p, plateau * dupli)//OK
{  
	int i,j;
	
	for(i=0;i<DIM_MAX;i++)
		for(j=0;j<DIM_MAX;j++)
      (*dupli)[i][j]=p[i][j];  
}
