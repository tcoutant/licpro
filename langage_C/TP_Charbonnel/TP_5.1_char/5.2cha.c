#include <stdio.h>
#define L 100

int un_a_un(char *s)
{
	char *p=s ;
	while (*++p) ;
	return p-s-1 ;
}

int main()
{
	char s[L] ;

	fgets(s,L-1,stdin) ;
	printf("%d\n",un_a_un(s)) ;

	return 0 ;
}
