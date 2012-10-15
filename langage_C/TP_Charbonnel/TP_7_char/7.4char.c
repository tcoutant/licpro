#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../mylib/mylib.h"

#define FICHIER "/usr/share/dict/words"
#define L 40

int main()
{
	int i, j, n=0 ;
	char **t ;
	char buffer[L] ;
        FILE *in ;

        in = fopen(FICHIER,"r") ;
        if (in==NULL) { perror(FICHIER) ; return 1 ; }

        while(fscanf(in,"%39s",buffer)==1) n++ ; 
	
	t = malloc(n*sizeof(char *)) ;
	if (t==NULL) { perror("malloc") ; exit(1) ; }
	rewind(in) ;
	for (i=0 ; i<n ; i++)
	{
		fscanf(in,"%39s",buffer) ;
		t[i] = strdup(buffer) ;
		if (t[i]==NULL) { perror("strdup") ; exit(2) ; }
	}

	for (i=1 ; i<n ; i++)
		for (j=0 ; j<i ; j++)
			if (ana(t[i],t[j])) printf("%s,%s\n",t[i],t[j]) ;

	for (i=0 ; i<n ; i++) free(t[i]) ;
	free(t) ;
	fclose(in) ;

	return 0 ;
}
