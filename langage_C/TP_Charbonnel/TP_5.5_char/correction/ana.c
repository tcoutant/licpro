#include <string.h>
#include <stdlib.h>

int ana(char *s1,char *s2)
{
        int i=0, j ;

        if (strlen(s1)!=strlen(s2)) return 0 ;

	char *s3 = strdup(s2) ; 	// pour préserver s2
        for (i=0 ; s1[i]!=0 ; i++)
        {
                for (j=0 ; s3[j]!=0 ; j++)
                        if (s1[i]==s3[j])
                        {
                                s3[j]=' ' ;
                                break ;
                        }
                if (s3[j]==0) // pas trouvé
		{ 
		  free(s3) ;
		  return 0 ;
		}
        }
	free(s3) ;
        return 1 ;
}
