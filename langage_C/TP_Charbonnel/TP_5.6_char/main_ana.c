#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "../mylib/mylib.h"

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
