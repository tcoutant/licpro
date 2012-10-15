#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, n ;
	char **tab; //delaration d'un pointeur tab qui pointe vers un pointeur de char
	char buffer[40] ;

	printf("combien y a-t-il de chaine à lire ? ") ;
	scanf("%d",&n) ;
	tab = malloc(n*sizeof(char *)) ;
	if (tab==NULL) { perror("malloc") ; exit(1) ; }
	for (i=0 ; i<n ; i++)
	{
		printf("entrer la chaine n° %d : ",i) ;
		scanf("%39s",buffer) ;
		tab[i] = malloc((strlen(buffer)+1)*sizeof(char)) ;
		if (tab[i]==NULL) { perror("malloc") ; exit(2) ; }
		strcpy(tab[i],buffer) ;
	}
	for (i=0 ; i<n ; i++) printf("tab[%d] = %s\n",i,tab[i]) ;
	for (i=0 ; i<n ; i++) free(tab[i]) ;
	free(tab) ;

	return 0 ;
}

