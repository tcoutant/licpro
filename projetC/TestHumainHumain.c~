#include<stdio.h>
#include<stdlib.h>
#define DIM_MAX 8

typedef int plateau[DIM_MAX][DIM_MAX];

typedef struct _StrCoup {
                     
                           int ligne;
                           int colonne;
                           int joueur;   
 
                        } StrCoup;

typedef struct _Maillon { 
                        
                          StrCoup coup;
                          struct _Maillon * suivant;
 
                        } Maillon;

int coupValide(int joueur, plateau p, int NumLigne, int NumColonne);




void initialiserPlateau(plateau p)
{
	int i, j;

	for(i=0;i<DIM_MAX; i++)
		for(j=0;j<DIM_MAX;j++)
			p[i][j]=0;

	p[(DIM_MAX/2)-1][(DIM_MAX/2)-1]	= 1;
	p[(DIM_MAX/2)-1][(DIM_MAX/2)]	= 2;
	p[(DIM_MAX/2)][(DIM_MAX/2)-1]	= 2;
	p[(DIM_MAX/2)][(DIM_MAX/2)]		= 1;
}

void afficherPlateau(plateau p)
{
	int i,j,k;

	printf("\t");
	for(i=0;i<DIM_MAX;i++)
	printf("  %2c",'a'+i);
	printf("\n");
	
	for(i=0;i<DIM_MAX;i++)
	{
		printf("\t  ");
		for(k=0;k<DIM_MAX;k++)
		{
			printf("+---");
		}
		
		printf("+\n\t%d |",i+1);
		
		for(j=0;j<DIM_MAX;j++)
		{
			if(p[i][j]==0)
				printf("   |");
			else if (p[i][j]==1)
					printf(" 1 |");
				else
					printf(" 2 |");
		}
		printf("\n");
	}
	printf("\t  ");

	for(k=0;k<DIM_MAX;k++)
	{
		printf("+---");
	}
	printf("+\n\n\n");
}

int existeCoupPourJoueur(plateau p,int joueur)//OK
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

int partieTerminee(plateau p) //La partie est terminée si les deux joueurs ne peuvent plus jouer
{
   if ((existeCoupPourJoueur(p,1) == 0) && (existeCoupPourJoueur(p,2) == 0)) 
		return 1;
	else
		return 0;
}

void comptePions(plateau p, int *NbPions1, int *NbPions2)//Compte le nombre de pions pour chaque joueurs
{
   int i,j;

   for(i=0;i<DIM_MAX;i++)
   {
      for(j=0;j<DIM_MAX;j++)
      {
         if(p[i][j]==1)
			(*NbPions1)++;
		else
			(*NbPions2)++;
      }
   }
}

/*void demandeDIM_MAX(int* DIM_MAX)
{

   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Entrez la dimension du reversi (4,6 ou 8)\n");
      scanf("%d",DIM_MAX);


   } while(DIM_MAX!=4 && DIM_MAX!=6 && DIM_MAX!=8);
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}*/

int renvoieContenuCase(plateau p, int NumLigne, int NumColonne)
{
	return (p[NumLigne][NumColonne]);
}


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

void joueLeCoup(plateau p, int NumLigne, int NumColonne, int joueur)//Joue un coup
{
      p[NumLigne][NumColonne]=joueur;								//Retourne le pion avec la couleur du joueur

      retournePions(joueur,p,NumLigne,NumColonne);					//Appel de la fonction retournePions

      afficherPlateau(p);											//Affichage du plateau
}

int coupValide(int joueur, plateau p, int NumLigne, int NumColonne)//OK
{
   
   if((faitPrise(joueur,p,NumLigne,NumColonne)==1) && (renvoieContenuCase(p,NumLigne,NumColonne)==0))
		return 1;
	else
		return 0;
}

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
                    printf("malloc null: newMaillon,donneTousLesCoupsValides \n");
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

   return cpt;
}

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
      printf("Alloc:null coups donneStringCoupsValides\n"); 
      exit(1);
   }
   
   index=0;
   
   
   printf("Il y a %i ",
   donneTousLesCoupsValides(p,joueur,&teteMaillon));
   
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

void videStdin()
{

     char c;
     c = getchar();

     if (c != '\n')
       while ( (getchar()) != '\n');
 
}

void saisiUnCoup(int joueur, int * NumLigne, int * NumColonne)
{
      char tmp[4];

      printf("->Veuillez entrez une case pour le joueur numéro %d (exemple: a 1)\nPuis appuyer sur Entrée\n",joueur);

      fgets(tmp, sizeof tmp, stdin);

      *NumLigne=tmp[2]-'0'-1;
      *NumColonne=tmp[0]-'a';
      
      videStdin();
}

void tourJoueur(plateau p, int joueur)
{
   int testL;
   int testC;
   char c;
   
   if(!existeCoupPourJoueur(p,joueur)) 
   {
      printf("Vous devez passer, joueur numéro %d ! \nAppuyez sur une touche pour continuer\n",joueur);
      
      fgets(&c,1,stdin);
      videStdin();
   } 
   else
   {
      do 
      {  
         testL=DIM_MAX;
         testC=DIM_MAX;
   
         printf("CoupsValides--: %s\n",donneStringCoupsValides(p, joueur)); 
         
         saisiUnCoup(joueur,&testL,&testC);
            

      } while(((testL >= DIM_MAX )
                 || ( testC >= DIM_MAX )            
                 || ( testL < 0 )   
                 || ( testC < 0 ) ) 
              	 || ( coupValide(joueur, p,testL,testC)==0 ) 
             );
         
        joueLeCoup(p,testL,testC,joueur);    

   }      
}

void joueHumainHumain()
{
	plateau p;  
	int tour=2,Point1=0,Point2=0; 
   
	//demandeDIM_MAX(&DIM_MAX);

	initialiserPlateau(p);

	afficherPlateau(p);
	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);    
		else 
			tourJoueur(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est Joueur 1 : %i - Joueur 2 : %i\n",Point1,Point2);
}

int main()
{
	joueHumainHumain();

	return 0;
}
