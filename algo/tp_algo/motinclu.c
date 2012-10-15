# include <stdio.h>
# include <string.h>
# define  size 30 			/*declaration des constantes*/
int j, test, testl, lg1, lg2, ind; 	/*declaration des variables*/
char mot1[size],mot2[size];
/* donner 2 mots et verifer si le 2eme est contenu dans le premier */

/*programme principal*/			
void main ()			
{
/*saisie des 2 mots*/
printf("Ecrire le premier mot :  \n");
scanf("%s",mot1);
lg1=strlen(mot1);
printf("Ecrire le deuxieme mot :  \n");
scanf("%s",mot2);
lg2=strlen(mot2);

/*analyse*/
j=0; test=0;testl=0;ind=0;
while ((test==0)&&(ind<lg1-lg2+1))
{
	for(j=0;j<lg2;j++)
	{
		if
		(mot1[ind+j]==mot2[j])
			testl=testl+1;
	}

if (testl==lg2) test=1; else testl=0;
j=0;
ind++;
}

/*ecrire la reponse*/
if (test==1)
printf("le mot ( %s )  est imbriqué dans le mot ( %s ).\n",mot2,mot1);
else
printf("le mot ( %s ) n'est pas imbriqué dans le mot ( %s ).\n",mot2,mot1);
}
