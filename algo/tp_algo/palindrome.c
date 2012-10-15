# include <stdio.h>
# include <string.h>

char mot[50];
int longueur,i;
 

void main()
{
printf("donner un mot : \n");
scanf("%s",mot);
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

}




