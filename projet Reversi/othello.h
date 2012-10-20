/*****************************************************************************
 *       name :  othello.c
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 (correction de la prise de coups en dim <8)
 *   
 *****************************************************************************/

   typedef struct _FeuillePartie  
   {  
       int * lignes;
       int * colonnes;
       int nbCoups; 

   } FeuillePartie;

extern int DIMENSION_MAX;    /* dimension de l'othellier égale à 4,6 ou 8
                                variable globale définie par l'utilisateur */





/*******************************************************************
 *                                                    othello
 *    Nom : void moteur(char -grille, char +camp)
 *                          
 * Entrée : char -grille, 
 *          char +camp
 *
 * Sortie : void
 *
 *          fait jouer un tour a un joueur
 *        
 ******************************************************************/

extern void moteur(char * grille, char camp,FeuillePartie * feuillepartie);




/*******************************************************************
 *                                              
 *    Nom : void rejouePartie(
 *                              FeuillePartie +fp,
 *                              int +tailleOthellier
 *                           )
 *                          
 * Entrée : FeuillePartie +fp,
 *          int +tailleOthellier
 *
 * Sortie : void
 *
 *          rejoue la partie
 *        
 ******************************************************************/
extern void rejouePartie(FeuillePartie fp, int tailleOthellier);
