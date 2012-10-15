#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

#define N 10
#define L 40

typedef char string[L] ;

int main()
{
	int i ;
	char *s ;
	string tab[N] ;
 
	for (i=0 ; i<N ; i++)
	{
		s = readline("entrez une chaine: ") ;
		strncpy(tab[i],s,L-1) ;
		free(s) ;
	}
	for (i=N-1 ; i>=0 ; i--) printf("%s\n",tab[i]) ;

	return 0 ;
}
