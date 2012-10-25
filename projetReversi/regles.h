/*****************************************************************************
 *       name :  othello.c
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 (correction de la prise de coups en dim <8)
 *   
 *****************************************************************************/

/*****************************************************************
 *                                                       regles                                 
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


extern int faitPriseDansDirection(int dir, char camp, char * grille, int NumLigne, int NumColonne);



/*******************************************************************
 *                                                    regles
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

extern int faitPrise(char camp, char * grille, int NumLigne, int NumColonne);




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

extern int coupValide(char camp, char * grille, int NumLigne, int NumColonne);




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

extern int retournePionsDansDirection(int dir, char camp, char * grille, int NumLigne, int NumColonne);




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

extern int retournePions(char camp, char * grille, int NumLigne, int NumColonne);

