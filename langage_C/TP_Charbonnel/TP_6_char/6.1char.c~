#include <stdio.h>
#include <string.h>
#include "../mylib/mylib.h"

#define FICHIER "/usr/share/dict/words"
#define L 40

int main()
{
	FILE *in ;
	char s[L] ;

	in = fopen(FICHIER,"r") ;
	if (in==NULL) { perror(FICHIER) ; return 1 ; }

	while(fscanf(in,"%39s",s)==1)
	  if (palin(s)) printf("%s\n",s) ;

	fclose(in) ; 
	return 0 ;
}
