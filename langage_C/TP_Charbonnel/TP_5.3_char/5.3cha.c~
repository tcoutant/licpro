#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

int palin(char *s)
{
	int i=0, j=strlen(s)-1 ;

	while (s[i]==s[j] && i<j) { i++ ; j-- ; }
	return s[i]==s[j] ;
}

int main()
{
	char *s ;

	s = readline("entrer un mot: ") ;
	if (palin(s))
		printf("%s est un palindrome\n",s) ;
	else
		printf("%s n'est pas un palindrome\n",s) ;

	free(s) ;

	return 0 ;
}
