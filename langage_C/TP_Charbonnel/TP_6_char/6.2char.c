#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include "../mylib/mylib.h"

#define FICHIER "/usr/share/dict/words"

int main()
{
	FILE *in ;
	char mot[40], s[40] ;

	printf("entrer un mot: ") ;
	scanf("%39s",mot) ;

	in = fopen(FICHIER,"r") ;
	if (in==NULL) { perror(FICHIER) ; return 1 ; }

	while(fscanf(in,"%39s",s)==1)
	  if (ana(mot,s)) printf("%s\n",s) ;

	fclose(in) ; 
	return 0 ;
}
