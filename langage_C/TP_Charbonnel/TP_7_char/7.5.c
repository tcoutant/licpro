#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FICHIER "/usr/share/dict/words"
#define L 40

void tri(char **t,int n)
{
        int i,permut ;
        char *x ;

        do {
            permut = 0 ;
            for (i=0 ; i<n-1 ; i++)
            if (strlen(t[i])>strlen(t[i+1]) || 
		(strlen(t[i])>strlen(t[i+1]) && strcmp(t[i],t[i+1])>0))
            {
              x = t[i] ;
              t[i] = t[i+1] ;
              t[i+1] = x ;
              permut = 1 ;
            }
        } while (permut) ;
}

int main()
{
	int i, n=0 ;
	char **tab ;
	char buffer[40] ;
        FILE *in ;

        in = fopen(FICHIER,"r") ;
        if (in==NULL) { perror(FICHIER) ; return 1 ; }

        while(fscanf(in,"%39s",buffer)==1) n++ ; 
	
	tab = malloc(n*sizeof(char *)) ;
	if (tab==NULL) { perror("malloc") ; exit(1) ; }
	rewind(in) ;
	for (i=0 ; i<n ; i++)
	{
		fscanf(in,"%39s",buffer) ;
		tab[i] = strdup(buffer) ;
		if (tab[i]==NULL) { perror("strdup") ; exit(2) ; }
	}
	tri(tab,n) ;
	for (i=0 ; i<n ; i++) 
	{
		printf("tab[%d] = %s\n",i,tab[i]) ;
		free(tab[i]) ;
	}
	free(tab) ;
	fclose(in) ;

	return 0 ;
}
