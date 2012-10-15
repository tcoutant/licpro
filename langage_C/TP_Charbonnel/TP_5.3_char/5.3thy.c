# include <stdio.h>
# include <string.h>
#include<readline/readline.h> 
char mot[20];
int longueur,i;
 

int main()
{
printf(" \n");
char *mot;
mot = readline("donner un mot :");
//scanf("%s",mot);
longueur=strlen(mot); // longueur du mot
i=0;
	while((i<longueur/2)&&(mot[i]==mot[longueur-i-1]))
	{
	i++;
	}
	if(i==longueur/2)
		printf("c'est un palindrome \n");
	else
		printf("ce n'est pas un palindrome \n");
return 0;
}




