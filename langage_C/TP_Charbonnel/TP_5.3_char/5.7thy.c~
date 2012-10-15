#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

void afficheinverse(char *s)
{
	char *x;
	for (x=s;x-s<strlen(s);x++)
	printf("%c  ",*x);
	printf("\n");
	for (x=s+strlen(s)-1;x>=s;x--)
	printf("%c  ",*x);
	printf("\n");
	
}

int main()
{
	char *s ;
	s = readline("entrer un mot: ") ;
	afficheinverse(s);
return 0 ;
}

