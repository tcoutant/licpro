# include <stdio.h>
# include <string.h>

# define L 30 		/*declaration des constantes*/

/*commentaire*/

 
int un_a_un(char S[]) //meme chose que :  int un_a_un(char *S)
{
char *ptr=S;
int i;
while(*ptr!='\n') 
{
i++;
ptr=ptr+1;
}
return i;
}
 
int main()			
{
char S[L];
printf("ecrivez une chaine de caractere (maxi 30) pour vous donner en reponse sa longueur\n");
fgets(S,L-1,stdin);
printf("%d\n",un_a_un(S));
return 0;
}

		
