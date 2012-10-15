# include <stdio.h>
# include <stdlib.h>
# define N 10 	/* declaration d'une constante pour la dimension du tableau */

	/* definition d'une structure */
struct File
{
int tab_file[N];	
int debut; 		//indice du debut de la file
int nbval;		//nombre de valeur rentrée dans la file
};
	/* definition d'un type File */
typedef struct File File;


	/* definition des fonctions et procedures */

	/* fonction qui retourne si la file est pleine */
int est_pleine(File *file)
{
	if (file->nbval==N)
 	return 1; // 1 pour la file est pleine
	else        
	return 0; 
}

	/* fonction qui retourne si la file est vide */
int est_vide(File *file)
{
	if (file->nbval==0)
  	return 1; // 1 pour la file est vide
	else   
        return 0;
}

	/* emfiler un élément dans la file */ 
void emfiler(File *file,int nb)
{
if (est_pleine(file)==1)	 // test si la liste est pleine
	printf("La file est pleine, il n'est pas possible d'y placer %d.\n",nb);
else
	
	{ // place le nouvel element à la suite dans le tableau ou au debut en cas de débordement avec la fonction modulo
	file->tab_file[(file->debut + file->nbval)%N] = nb; 
	file->nbval++;
	}
}

	/* defiler la file */ 
void defiler(File *file)
{
if (est_vide(file)==1) 	// test si la liste est deja vide avant d'enlever la tete de file
	printf("La file est déjà vide, aucun element ne peut etre enlever.\n");
else
	{
	file->tab_file[file->debut]=0;	 // enleve la tete de file
	file->debut= (file->debut + 1)%N; // incremente "debut" et retourne au debut du tableau si necessaire avec la fonction modulo
	file->nbval--;
	}
}

	/* affiche la file */
void affiche(File *file)
{
int i;
if (est_vide(file)==1) 
	printf("Aucun element à afficher, la file est vide.\n");
else
	{
	for(i=0;i<file->nbval;i++) 
	printf("%d  ",file->tab_file[(file->debut + i)%N]);
	printf("\n");
	}

}

	/* programme principal */	
int main ()			
{
	/* initialisation d'une structure File */
File *file = malloc(sizeof(*file)); 
file->tab_file[N];	
file->debut=0; 		//indice du debut de la file
file->nbval=0;		//nombre de valeur dans le tableau

printf("\n");
affiche(file);

emfiler(file,1);
emfiler(file,2);
emfiler(file,3);
emfiler(file,4);
emfiler(file,5);
emfiler(file,6);
emfiler(file,7);
emfiler(file,8);
emfiler(file,9);
emfiler(file,10);

affiche(file);

	/* test emfiler la file pleine */
emfiler(file,11);

defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);

affiche(file);

emfiler(file,12);
emfiler(file,13);
emfiler(file,14);
emfiler(file,15);
emfiler(file,16);

affiche(file);

defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);
defiler(file);

affiche(file);

	/* test defiler la file vide */
defiler(file);
printf("\n");

return 0;
}