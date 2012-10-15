#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tri(char **t,int n)
{
        int i,permut ;
        char *x ;

        do {
          permut = 0 ;
          for (i=0 ; i<n-1 ; i++)
            if (strcmp(t[i],t[i+1])>0)
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
	int i, n ;
	char* *tab ;
	char buffer[40] ;

	printf("combien y a-t-il de chaine à tier ? ") ;
	scanf("%d",&n) ;
	tab = malloc(n*sizeof(char *)) ;
	if (tab==NULL) { perror("malloc") ; exit(1) ; }
	for (i=0 ; i<n ; i++)
	{
		printf("entrer la chaine n° %d : ",i) ;
		scanf("%39s",buffer) ;
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

	return 0 ;
}