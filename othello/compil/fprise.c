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
	Renvoie le contenu de la case (0, 1 ou 2)
*/
int renvoieContenuCase(plateau p, int NumLigne, int NumColonne)
{
	return (p[NumLigne][NumColonne]);
}
/*_______________________________________________________________________________*/


/*
	On regarde dans la direction passée en paramètre, si la case adjacente est vide ou contient une pièce de la même couleur que celle du joueur => pas de prise, retourne 0
	sinon, on se décale dans la direction tant qu'on ne tombe pas sur la fin du tableau, ou sur une case vide ou occupée par une pièce du joueur.
	Si on est en fin de tableau, on renvoie 0
	Si la case est vide, on renvoie 0
	Si la case contient une pièce du joueur, on renvoie 1 => on fait une prise dans la direction.
*/
int faitPriseDansDirection(int direction, int joueur, plateau p, int NumLigne, int NumColonne)
{
   int dirLigne=0;
   int dirColonne=0;
   
	switch(direction) 
	{
		case 0:			//Case au Nord
			dirLigne=-1;
		break;
	
		case 1:			//Case Nord-Est
			dirLigne=-1;
			dirColonne=1;
		break;

		case 2:			//Case Est
			dirColonne=1;
		break;

		case 3:			//Case Sud-Est
			dirLigne=1;
			dirColonne=1;
		break;
	  
		case 4:			//Case Sud
			dirLigne=1;
		break;

		case 5:			//Case Sud-Ouest
			dirLigne=1;
			dirColonne=-1; 
		break;

		case 6:			//Case Ouest
			dirColonne=-1;
		break;

		case 7:			//Case Nord-Ouest
			dirLigne=-1;
			dirColonne=-1;
		break;
	}
       NumLigne+=dirLigne;
       NumColonne+=dirColonne;

    if(NumLigne>=DIM_MAX 
		|| NumColonne>=DIM_MAX          
		|| NumLigne<0 
		|| NumColonne<0
		|| renvoieContenuCase(p,NumLigne,NumColonne)==joueur
		|| renvoieContenuCase(p,NumLigne,NumColonne)==0)
	{
		return 0;  
	}
	else
	{
		while(NumLigne<DIM_MAX 
              && NumColonne<DIM_MAX 
              && NumLigne>=0 
              && NumColonne>=0 
              && renvoieContenuCase(p,NumLigne,NumColonne)!=joueur 
              && renvoieContenuCase(p,NumLigne,NumColonne)!=0)
		{
			NumLigne+=dirLigne; 
			NumColonne+=dirColonne;
		}
		if(NumLigne>=DIM_MAX
			|| NumColonne>=DIM_MAX  
			|| NumLigne<0 
			|| NumColonne<0)
		{ 
			return 0;
		}
		else  
		{              
			if(renvoieContenuCase(p,NumLigne,NumColonne)==joueur)
				return 1;
			else
				return 0;
		}
   }
}
/*____________________________________________________________________________*/






/*
	On regarde dans la direction passée en paramètre si on fait une prise avec la fonction faitPriseDansDirection
	Si non, on retourne 0
	Si oui, on se décale dans la direction jusqu'à rencontrer un pion de la couleur du joueur passé en paramètre, en changeant la couleur des cases que l'on rencontre.
		====> On teste aussi si la case est non nulle et si on est pas au bord ???? utile ? testé dans faitPriseDansDirection
	On incrémente "compte" a chaque fois qu'on change une case.
	On retourne "compte", pour savoir le nombre de pion prit
*/

int retournePionsDansDirection(int direction, int joueur, plateau p, int NumLigne, int NumColonne)
{
   int compte=0;
   int dirLigne=0;
   int dirColonne=0;
   
	switch(direction)
	{
    	case 0:			//Case au Nord
			dirLigne=-1;
		break;
	
		case 1:			//Case Nord-Est
			dirLigne=-1;
			dirColonne=1;
		break;

		case 2:			//Case Est
			dirColonne=1;
		break;

		case 3:			//Case Sud-Est
			dirLigne=1;
			dirColonne=1;
		break;
	  
		case 4:			//Case Sud
			dirLigne=1;
		break;

		case 5:			//Case Sud-Ouest
			dirLigne=1;
			dirColonne=-1; 
		break;

		case 6:			//Case Ouest
			dirColonne=-1;
		break;

		case 7:			//Case Nord-Ouest
			dirLigne=-1;
			dirColonne=-1;
		break;
	}  

     if(faitPriseDansDirection(direction,joueur,p,NumLigne,NumColonne)==0) 
    	return 0;

       NumLigne+=dirLigne; 
       NumColonne+=dirColonne;

    while(renvoieContenuCase(p,NumLigne,NumColonne)!=joueur
           && renvoieContenuCase(p,NumLigne,NumColonne)!=0   
           && NumLigne<DIM_MAX
           && NumColonne<DIM_MAX           
           && NumLigne>=0   
           && NumColonne>=0)
	{
       p[NumLigne][NumColonne]=joueur;
       compte++;

       NumLigne+=dirLigne; 
       NumColonne+=dirColonne;
	}
    return compte--; 
}
//___________________________________________________________________________________________________________________________________________________





/*
	On compte le nombre de pions retournés dans chacune des 8 directions, et on fait le total dans la boucle.
	On retourne le nombre total de pions prit grâce au coup joué
*/

int retournePions(int joueur, plateau p, int NumLigne, int NumColonne)
{
    int i,compte=0,compte_tmp;
    
    for(i=0;i<8;i++)
    {
      compte_tmp=retournePionsDansDirection(i,joueur,p,NumLigne,NumColonne);
      compte+=compte_tmp;
    }
    return compte;  
}
/*______________________________________________________________________________*/

/*
	Retourne 1 si le nombre de pions prit est supérieur à 0 ==> on fait une prise
	Retourne 0 si le nombre de pions prit est égal à 0 ==> on ne fait pas de prise 
*/

int faitPrise(int joueur,plateau p, int NumLigne, int NumColonne)
{
    int i,compte_tmp,compte=0;

    for(i=0;i<8;i++)
    {
		compte_tmp = faitPriseDansDirection(i,joueur,p,NumLigne,NumColonne);
		compte+=compte_tmp;
    }

    if (compte!=0)
		return 1;
	else 
		return 0;
}
/*___________________________________________________________________________________*/




