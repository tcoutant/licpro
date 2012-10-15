# include <stdio.h>
# include <stdlib.h>
# define N 10 	/* declaration d'une constante pour la dimension du tableau */

/* definition d'une structure */
struct File
{
int tab_file[N];	
int debut; 		//indice du debut de la file
int fin;		//indice de la fin de la file
int nbval;		//nombre de valeur rentrée dans la file
};
/* definition d'un type File */
typedef struct File File;


/* definition des fonctions et procedures */

/* fonction qui retoune si la file est pleine */
int est_pleine(File *file)
{
	if (file->nbval==N) 	return 1; // la file est pleine
	else            return 0;  // la file n'est pas pleine
}

/* fonction qui retourne si la file est vide */
int est_vide(File *file)
{
	if (file->nbval==0)  	return 1; // la file est vide
	else            return 0;  // la file n'est pas vide
}

/* emfiler un élément dans la file */ 
void emfiler(File *file,int nb)
{
if (est_pleine(file)==1) // test si la liste est pleine
	printf("La file est pleine, il n'est pas possible d'y placer %d.\n",nb);
else
	{
	if(file->fin==N) // test si le dernier element rentré se trouve en fin de tableau
		{ 
		file->tab_file[0]=nb; // dans ce cas,l'élément est placé au début du tabeau
		file->fin=1;
		file->nbval++;
		}
	else 	{ 
		file->tab_file[file->fin]=nb; // l'élément est placé à la suite
		file->fin++; 
		file->nbval++;
		}
	}
}

/* defiler la file */ 
void defiler(File *file)
{
if (est_vide(file)==1) // test si la liste est deja vide avant d'enlever la tete de file
	printf("La file est déjà vide, aucun element ne peut etre enlever.\n");
else
	{
	if (file->debut==N-1) // test si la file démarre en fin de tableau
		{
		file->tab_file[N-1]=0;
		file->debut=0; // dans ce cas la file redémarre en début de tableau
		file->nbval--;
		}
	else
		{
		file->tab_file[file->debut]=0; // enleve la tete de file
		file->debut++; // fait démarrer la file au suivant
		file->nbval--;
		}
	}
}

/* affiche la file*/
void affiche(File *file)
{
int i;
if (est_vide(file)==1) printf("Aucun element à afficher, la file est vide.");
else
	{
	printf("file :  ");
	if (file->debut==0) // si la file démarre au début du tableau
		{
		for(i=file->debut;i<file->fin;i++) printf("%d  ",file->tab_file[i]);
		}
	else		{ // la file ne démarre pas au début du tableau
		if (file->fin> file->debut) // et si la fin de la file se termine avant la fin du tableau (même cas que précédemment)
			{
			for(i=file->debut;i<file->fin;i++) printf("%d  ",file->tab_file[i]);
			}
		else	{  // et dans le cas où la file déborde du tableau et redémarre au début du tableau
			for(i=file->debut;i<N;i++) printf("%d  ",file->tab_file[i]);
			for(i=0;i<file->fin;i++) printf("%d  ",file->tab_file[i]);
			}
		}
	}
printf("\n");
}

/*programme principal*/	
int main ()			
{
/* initialisation d'une structure File*/
File *file = malloc(sizeof(*file)); 
int tab_file[N];	
file->debut=0; 		//indice du debut de la file
file->fin=0;		//indice de la fin de la file
file->nbval=0;		//nombre de valeur dans le tableau


affiche(file);
printf("\n");

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

/* test emfiler la file pleine*/
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

/*test defiler la file vide*/
defiler(file);

return 0;
}
