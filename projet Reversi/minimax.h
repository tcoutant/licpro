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
extern float trouveCoupQuiMaximise(char * grille, StrCoup * Coup);






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

extern float trouveCoupQuiMinimise(char * grille, StrCoup * Coup);


extern float trouveCoupMinimax(char * grille, char camp, int prof, StrCoup * coup);
