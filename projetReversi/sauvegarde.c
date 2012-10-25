/***************************************************************************
 *       name :  othello.c
 *     author :  Vincent Spiewak & Allaedine Elbanna    
 *      login :  2351994 
 *     groupe :  6
 * last modif : 09/03/2005 16:31 
 *   
 ***************************************************************************/



#include <stdlib.h>
#include <stdio.h>
#include "othello.h"
#include "representation.h"




/*******************************************************************
 *
 *    Nom : FILE * ouvreFichierSauvegarde(char -nomDuFichier)
 *
 * Entrée : char *, nom du fichier
 *
 * Sortie : rend le descripteur de fichier si l'ouverture a reussi
 *        
 ******************************************************************/


FILE * ouvreFichierSauvegarde(char * nomDuFichier)
{
   return fopen(nomDuFichier,"w");
}



/*******************************************************************
 *
 *    Nom : int fermeFichierSauvegarde(FILE -file)
 *
 * Entrée : descripteur du fichier de sauvegarde FILE -file
 *
 * Sortie : rend 0 si la fermeture du fichier a reussi, -1 sinon
 *        
 ******************************************************************/

int fermeFichierSauvegarde(FILE * file)
{
  return fclose(file);
}







/*******************************************************************
 *
 *    Nom : int sauvegardeLeCoup(
 *                                FILE -file, 
 *                                int +NumLigne, 
 *                                int +NumColonne
 *                              )
 *
 * Entrée : descripteur du fichier de sauvegarde FILE -file
 *                                               int +NumLigne, 
 *                                               int +NumColonne
 * Sortie : rend 0 si l'ecriture du coup a reussi, -1 sinon
 *        
 ******************************************************************/

int sauvegardeLeCoup(FILE * file, int NumLigne, int NumColonne)
{
   return fprintf(file,"%c %d\n",NumColonne+'a',NumLigne+1);
}






/*******************************************************************
 *
 *    Nom : int sauvegardeEntete(FILE -file)
 *
 * Entrée : descripteur du fichier de sauvegarde FILE -file
 *
 * Sortie : 0 ou -1
 *
 *          rend 0 si l'ecriture de la sauvegarde a reussi, -1 sinon
 *        
 ******************************************************************/

int sauvegardeEntete(FILE * file)
{
       
    return fprintf(file,"%i\n",DIMENSION_MAX);
}





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

int sauvegardePartie(FeuillePartie *fp, int tailleOthellier)
{
       
      char nomfichier[100];
      int i;
      FILE * fichier;    
       
      printf("Veuillez entrez le nom du fichier de sauvegarde\npuis appuyer sur Entrée\n");
      /*  
       fgets(nomfichier, sizeof(*nomfichier), stdin);
      */

      scanf("%s",nomfichier);
      videStdin();
      
  
      fichier=ouvreFichierSauvegarde(nomfichier);
      
      if(fichier==NULL) return -1;
    
      sauvegardeEntete(fichier);

      for(i=0;i<fp->nbCoups;i++)
      {  sauvegardeLeCoup(
                          fichier,
                          *(fp->lignes+i),
                          *(fp->colonnes+i)
                        );  
        
      }   
   return 0;
}





/*******************************************************************
 *
 *    Nom : FILE * ouvreFichierLecture(char -nomDuFichier)
 *
 * Entrée : char *, nom du fichier
 *
 * Sortie : rend le descripteur de fichier si l'ouverture a reussi
 *        
 ******************************************************************/


FILE * ouvreFichierLecture(char * nomDuFichier)
{
   return fopen(nomDuFichier,"r");
}





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

int lectureEntete(FILE * file)
{
   int tmp;
   fscanf(file,"%i\n",&tmp);
   return tmp;
}





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

int lectureCoup(FILE * file, int * NumLigne, int * NumColonne)
{
   char tmp_l, tmp_c;
   int res = fscanf(file,"%c %c\n",&tmp_c,&tmp_l);

   *NumColonne=tmp_c-'a';
   *NumLigne=tmp_l-'0'-1; 
   
   return res;
}






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

int lecturePartie(FILE * file, FeuillePartie * fp, int * tailleOthellier)
{
   int i,
       tmp_c,
       tmp_l, 
       tmp_res=0,
       dimension=lectureEntete(file);
       *tailleOthellier=dimension;
   
   if(dimension<=0) return -1;
 
   printf("Dimension %i\n",dimension);

   for(i=0;i<=(dimension*dimension)-4;i++)
   {
      
      tmp_res+=lectureCoup(file,&tmp_l,&tmp_c);
 
      printf("Lecture du coup %i -> %i %i\n",i+1,tmp_c,tmp_l);
      *(fp->lignes+i)=tmp_l;
      *(fp->colonnes+i)=tmp_c;   
       
   }     
   
   return (tmp_res!=0);
}
