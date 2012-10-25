/***************************************************************************
 *       name :  othello.c
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 
 *   
 ***************************************************************************/





/*******************************************************************
 *
 *    Nom : int sauvegardePartie(
 *                                 FeuillePartie -fp,
 *                                 int +tailleOthellier
 *                              )
 *
 * Entrée : descripteur du fichier de sauvegarde FILE -file
 *
 * Sortie : 0 ou -1
 *          
 *          sauvegarde dans le fichier demander via stdin
 *          rend 0 si l'ecriture de la sauvegarde a reussi, -1 sinon
 *        
 ******************************************************************/

extern int sauvegardePartie(FeuillePartie *fp, int tailleOthellier);


/*******************************************************************
 *
 *    Nom : FILE * ouvreFichierLecture(char -nomDuFichier)
 *
 * Entrée : char *, nom du fichier
 *
 * Sortie : rend le descripteur de fichier si l'ouverture a reussi
 *        
 ******************************************************************/


extern FILE * ouvreFichierLecture(char * nomDuFichier);


/*******************************************************************
 *
 *    Nom : int lectureEntete(
 *                                FILE -file
 *                           )
 *
 * Entrée : descripteur du fichier de sauvegarde FILE -file
 *
 * Sortie : rend l'entete du fichier en parametre, -1 sinon
 *        
 ******************************************************************/

extern int lectureEntete(FILE * file);


/*******************************************************************
 *
 *    Nom : int lectureCoup(
 *                                FILE -file, 
 *                                int +NumLigne, 
 *                                int +NumColonne
 *                              )
 *
 * Entrée : descripteur du fichier de sauvegarde FILE -file
 *                                               int +NumLigne, 
 *                                               int +NumColonne
 *
 * Sortie : rend 0 si la lecture du coup a reussi, -1 sinon
 *        
 ******************************************************************/

extern int lectureCoup(FILE * file, int * NumLigne, int * NumColonne);


/*******************************************************************
 *
 *    Nom : int lecturePartie(
 *                               FeuillePartie -fp, 
 *                               int -tailleOthellier
 *                           )
 *
 * Entrée : descripteur du fichier de sauvegarde FeuillePartie -fp,
 *                                               int -tailleOthellier
 *
 * Sortie : rend 0 si la lecture de la partie a reussi, -1 sinon
 *        
 ******************************************************************/

extern int lecturePartie(FILE * file, FeuillePartie * fp, int * tailleOthellier);

