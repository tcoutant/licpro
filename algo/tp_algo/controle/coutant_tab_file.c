# include <stdio.h>
# define N 10 		/*declaration des constantes*/

/*declaration des variables*/
int tab_file[N];	
int debut; 		//indice du debut de la file
int fin;		//indice de la fin de la file
int i, nbval;

/* declaration des fonctions et procedures */

/* fonction qui retoune si la file est pleine*/
int est_pleine(int x[N])
{
	if (nbval==N) 	return 1; //la file est pleine
	else            return 0;  // la file n'est pas pleine
}

/* fonction qui retourne si la file est vide*/
int est_vide(int x[N])
{
	if (nbval==0)  	return 1; //la file est vide
	else            return 0;  // la file n'est pas vide
}

/* emfiler un élément dans la file*/ 
void emfiler(int x[N], int nb)
{
if (est_pleine(x)==1) 
	printf("La file est pleine, il n'est pas possible d'y placer %d.\n",nb);
else
	{
	if(fin==N)
		{ 
		x[0]=nb; 
		fin=1;
		nbval++;
		}
	else 	{ 
		x[fin]=nb; 
		fin++; 
		nbval++;
		}
	}
}

/* defiler la file*/ 
void defiler(int x[N])
{
if (est_vide(x)==1)
	printf("La file est déjà vide, aucun element ne peut etre enlever.\n");
else
	{
	if (debut==N-1) 
		{
		x[N-1]=0;
		debut=0;
		nbval--;
		}
	else
		{
		x[debut]=0;
		debut++;
		nbval--;
		}
	}
}

/* affiche la file*/
void affiche_file()
{
if (est_vide(tab_file)==1) printf("Aucun element dans la file.");
else
	{
	printf("file :  ");
	if (debut==0)
		{
		for(i=debut;i<fin;i++) printf("%d  ",tab_file[i]);
		}
	else		{
		if (fin>debut) 
			{
			for(i=debut;i<fin;i++) printf("%d  ",tab_file[i]);
			}
		else	{
			for(i=debut;i<N;i++) printf("%d  ",tab_file[i]);
			for(i=0;i<fin;i++) printf("%d  ",tab_file[i]);
			}
		}
	}
printf("\n");
}
/* affiche le tableau() */
void affiche_tableau()
{
printf("tableau:  ");
for (i=0;i<N;i++) printf("%d ",tab_file[i]);
printf("\n");
}

/*programme principal*/	
int main ()			
{
/*initialisation du tableau*/
for (i=0;i<N;i++) tab_file[i]=0;
debut=0;
fin=0;
nbval=0;


printf("\n");
emfiler(tab_file,1);
emfiler(tab_file,2);
emfiler(tab_file,3);
emfiler(tab_file,4);
emfiler(tab_file,5);
emfiler(tab_file,6);
emfiler(tab_file,7);
emfiler(tab_file,8);
emfiler(tab_file,9);
emfiler(tab_file,10);

/* affichage*/
affiche_file(tab_file);
affiche_tableau();

defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
/* affichage*/
affiche_file(tab_file);
affiche_tableau();

emfiler(tab_file,11);
emfiler(tab_file,12);
emfiler(tab_file,13);
emfiler(tab_file,14);
emfiler(tab_file,15);

/* test emfiler la file pleine*/
emfiler(tab_file,16);

/* affichage*/
affiche_file(tab_file);
affiche_tableau();

defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);
defiler(tab_file);

/* affichage*/
affiche_file(tab_file);
affiche_tableau();

/*test defiler la file vide*/
defiler(tab_file);

return 0;
}