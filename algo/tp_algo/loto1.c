# include <stdio.h>
# define nbval 49		/*declaration des constantes*/
# define nbtir 7
int a; 				/*declaration des variables*/
typedef int GRILLE[nbval];GRILLE G;
typedef int TIRAGE[nbtir];TIRAGE T;

/*fonction est coché dans la grille*/
/*declaration fonction present*/
int present(GRILLE,int);

/*DEFINITION DE LA FONCTION*/
int present(GRILLE G, int N)
{
	if (G[N-1]==1) return 1;
	else return 0;
}
/*fonction pour retourner le nb numeros gagnants */
int numeros (GRILLE G, TIRAGE T)
{
int a=0;
int i, j;
	for(i=0;i<6;i++)
	{	
	a=a+present(G,T[i]);		
	}
return a;
}

/*sous programme qui affiche le resultat */
void resultats (GRILLE G,TIRAGE T)
{
 if (numeros(G,T)>2)
	 printf("Vous avez %d bons numeros ",numeros(G,T));
else
	printf("Vous avez perdu /n");

if (present(G,T[6])==1)
 	printf("+ le complementaire. \n");
}

/*programme principal */
void main()
{
 GRILLE cout={0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TIRAGE jour ={3,4,5,6,10,12,8};

printf("%d \n" , present(cout,3)); /* controle de calcul*/
printf("%d \n",numeros(cout, jour)); /* controle de calcul*/
resultats (cout,jour);
}
