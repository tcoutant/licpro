/****************************************************************
 *
 *      author : Vincent Spiewak & Allaedine Elbanna
 *       login : 2351994
 *      groupe :  6
 *  last modif : 09/03/2005 19h00        
 *           
 *
 *****************************************************************/



extern char adversaire(char camp);

/*****************************************************************
 *                                                         evaluation
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
extern char donneContenuDeCase(char * grille, int NumLigne, int NumColonne);




/*****************************************************************
 *                                                  evaluation
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

extern int caseVide(char * grille, int NumLigne, int NumColonne);



/*******************************************************************
 *                                                       evaluation
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

extern void comptePions(char * grille, int *NbPionsX, int *NbPionsO);




/*******************************************************************
 *                                                      evaluation
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

extern int existeCoupPourCamp(char * grille,char camp);



/*******************************************************************
 *                                                     evaluation
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

extern void joueLeCoup(char * grille, int NumLigne, int NumColonne, char camp);



/*******************************************************************
 *                                                   evaluation
 *    Nom : int partieTerminee(char -grille)  
 *
 * Entrée : char * grille
 *
 * Sortie : 0 ou 1
 *
 *          rend vrai si la partie est terminée
 *        
 ******************************************************************/

extern int partieTerminee(char * grille);


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

extern int valeurQuantitative(char * grille);



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

extern float evalue(char * grille);
