#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10], s2[10], x[10] ;

    scanf("%9s %9s",s1,s2) ;
    if (strcmp(s1,s2)>0)
    {
      strcpy(x,s1) ;
      strcpy(s1,s2) ;
      strcpy(s2,x) ;
    }
    printf("s1=%s\ns2=%s\n",s1,s2) ;

    return 0 ;
}
