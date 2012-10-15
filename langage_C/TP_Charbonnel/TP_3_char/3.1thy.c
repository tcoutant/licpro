# include <stdio.h>
# include <string.h>
# define N 10
# define VRAI 1
# define FAUX 0 		/*declaration des constantes*/

/*procedure de tri d'un tableau*/
void tri(int t[])
{
int i, permut, temp;
do	{
	permut=FAUX;
	for (i=0;i<N-1;i++)
		if (t[i]>t[i+1])
		{
		temp=t[i];
		t[i]=t[i+1];
		t[i+1]=temp;
		permut=VRAI;
		}
		
	}
while (permut==VRAI);	
}

/* procedure de saisie d'un tableau de valeurs*/
int saisie_tab(int x[N])
{
int tabmax, i;
printf(" Combien de valeurs voulez-vous saisir? \n");
scanf("%d",&tabmax);
for(i=0;i<tabmax;i++)////
{
printf("donner la %dème valeur du tableau : \t",i+1);
scanf("%d",&x[i]);
}
return 0;
}

/* affichage d'un tableau*/
void affiche_tab(int x[N])
{
int i;
for(i=0;i<N;i++)
	{
	if (x[i]!=0)
	printf(" %d \t",x[i]);
	}
}
/* sous-programme de mise en application*/
int main ()
{
int i;
int TAB[N];
for(i=0;i<N;i++) TAB[i]=0;	// initialisation du tableau a zero

saisie_tab(TAB);
tri(TAB);
affiche_tab(TAB);
printf("\n");

}



