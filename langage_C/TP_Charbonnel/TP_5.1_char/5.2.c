# include <stdio.h>
# include <string.h>
# define L 30 		/*declaration des constantes*/

/*commentaire*/


int un_a_un(char *S)
{
int i=0;
while(S[i]!='\n') i++;
return i;
}

int main()			
{
char S[L];
printf("ecrivez une chaine de caractere (maxi 28) pour vous donner en reponse sa longueur\n");
fgets(S,L,stdin);
printf("%d\n",un_a_un(S));
return 0;
}

		

