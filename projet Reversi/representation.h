/***************************************************************************
 *       name :  representation.h
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 
 *   
 ***************************************************************************/

typedef struct _StrCoup {
                     
                           int ligne;
                           int colonne;
                           char camp;   
 
                        } StrCoup;

typedef struct _Maillon { 
                        
                          StrCoup coup;
                          struct _Maillon * suivant;
 
                        } Maillon;





extern void free_Maillons(Maillon * teteMaillon);
extern void videStdin(); 

/***************************************************************************
 *                                                          
 *    Nom : void initialiseGrilleDepart(int +taille)
 * Entrée : taille de la grille
 * Sortie : aucune
 *        
 *          Définit la grille de départ du jeu en fonction
 *          de la taille demandée et positionne les pions sur la grille
 *  
 ***************************************************************************/

extern void initialiseGrilleDepart(char * grille);




/*****************************************************************
 *
 *    Nom : void afficheOthellier(char +grille)   (representation)
 * Entrée : pointeur representant la grille du jeu
 * Sortie : aucune
 *
 *          Affichage de l'Othellier 
 *  
 ***************************************************************/

extern void afficheOthellier(char * grille);



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

extern void saisiUnCoup(char camp, int * NumLigne, int * NumColonne);



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

extern int donneTousLesCoupsValides(char * grille, char camp, Maillon ** teteMaillon);





/*******************************************************************
 *                                                    
 *    Nom : char * donneStringCoupsValides(Maillon * teteMaillon)
 *                          
 * Entrée : Maillon * teteMaillon
 *
 * Sortie : char * representant la liste des coups suivit de \0
 *
 *          Liste tous les coups valides pour camp 
 *          et les retournes dans un char *
 *        
 ******************************************************************/


extern char * donneStringCoupsValides(char * grille, char camp);
