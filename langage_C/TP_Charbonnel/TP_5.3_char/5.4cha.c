#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

int ana(char *s1,char *s2)
{
	int i=0, j ;

	if (strlen(s1)!=strlen(s2)) return 0 ;

	for (i=0 ; s1[i] ; i++)
	{
		for (j=0 ; s2[j] ; j++)
			if (s1[i]==s2[j])
			{
				s2[j]=' ' ; // on barre
				break ;     // au suivant
			}	
		if (s2[j]=='\0') return 0 ; // on n'a pas trouvé
	}
	return 1 ;		
}

int main()
{
	char *s1, *s2 ;

	s1 = readline("entrer un premier mot: ") ;
	s2 = readline("entrer un second mot: ") ;
	if (ana(s1,s2))
		printf("ces 2 chaines sont anagrammes\n") ;
	else
		printf("ces 2 chaines ne sont pas anagrammes\n") ;
	free(s1) ;
	free(s2) ;

	return 0 ;
}
