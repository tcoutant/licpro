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
