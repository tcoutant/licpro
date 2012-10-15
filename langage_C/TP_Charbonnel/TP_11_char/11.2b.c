#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

const int N=10 ;

int compare(const void *a,const void *b)
{
  return strcmp(*(const char**)a,*(const char **)b) ;
}

int main()
{
	int i ;
	char *t[N] ;		// tableau de pointeurs
 
	for (i=0 ; i<N ; i++) t[i] = readline("entrez une chaine: ") ;

	qsort(t,N,sizeof(char *),compare) ;

	for (i=0 ; i<N ; i++) 
	{
		printf("%s\n",t[i]) ;
		free(t[i]) ;
	}

	return 0 ;
}
