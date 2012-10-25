#define DIM_MAX 4

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




/*
	Initialise toutes les cases tu tableau à 0, sauf les quatre du centre
*/
void initialiserPlateau(plateau p);



/*
	Affichage du plateau de jeu
*/
void afficherPlateau(plateau p);



void videStdin();
