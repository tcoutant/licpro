
#include <string.h>


#include "mylib.h"

int palin(char *s)
{
	int i=0, j=strlen(s)-1 ;

	while (s[i]==s[j] && i<j) { i++ ; j-- ; }
	return s[i]==s[j] ;
}


